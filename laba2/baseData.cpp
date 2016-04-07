#include "baseData.h"

baseData::baseData(void)
{
	global = 0;
}

baseData::~baseData(void)
{
}


int baseData::count() const
{
	return Data.size();
}

int baseData::append(directorySettlements &record)
{
	global++;

	// ��������� ������������� ������
	record.id = global;
	// �������� ������ � ���� ������
	Data.insert(record.id, record);

	QMutableListIterator<unsigned int> ite(Sorting);

	ite.toFront();
	directorySettlements _item;
	int pos = 0;

	// ����������� �������������� 
	while (ite.hasNext())
	{
		ite.next();
		this->record(ite.value(), _item);

		if (_item < record)
			pos++;
		else
		{
			ite.previous();
			break;
		}
	}

	// �������� ����� ������������� � QList Sorting
	ite.insert(record.id);

	// ������������ ���������� �������
	return pos;
}

void baseData::remove(unsigned int id)
{
	Sorting.removeAll(id);
	Data.remove(id);
}

int baseData::update(const directorySettlements &record)
{
	// ������� ������ ������� � ���� ������
	remove(record.id);
	// �������� ����� ������� � ���� ������ 
	Data.insert(record.id, record);

	/*QMutableListIterator<unsigned int> ite(Sorting);

	ite.toFront();
	directorySettlements _item;
	int pos = 0;

	// ����������� ��������������
	while (ite.hasNext())
	{
	ite.next();
	this->record(ite.value(),_item);

	if (_item < record)
	pos ++;
	else
	{
	ite.previous();
	break;
	}
	}

	// �������� ����� ������������� � QList Sorting
	ite.insert(record.id);*/


	QList <unsigned int>::iterator ite;
	ite = Sorting.begin();
	directorySettlements _item;
	int pos = 0;

	// ����������� �������������� 
	while (ite != Sorting.end())
	{
		this->record(*ite, _item);

		if (_item < record)
			pos++;
		else
		{
			ite--;
			break;
		}
		ite++;
	}

	// �������� ����� ������������� � QList Sorting
	ite = Sorting.insert(ite, record.id);


	// ������������ ������� ������� � ���� ������
	return pos;
}

void  baseData::record(unsigned  int  id, directorySettlements  &record)
{
	record = Data.value(id);
	record.id = id;
}

const QVector<DIRECTORY> baseData::records()
{
	QVector<DIRECTORY> _vector;

	QMutableListIterator <unsigned int> it(Sorting);

	while (it.hasNext())
	{
		it.next();
		directorySettlements temp = Data.value(it.value());
		DIRECTORY _temp;

		_temp.NAME = temp._name;
		_temp.SUB_OF_FED = temp.sub_of_fed;
		_temp.COUNT_OF_PEOPLE = temp.count_of_people;
		_temp.ID = temp.id;

		_vector.append(_temp);
	}

	// ����������  ������  �������
	return _vector;
}

bool baseData::save(QString fileName)
{
	QListIterator<unsigned int> it(Sorting);
	//�������� ����� � ����� �����
	QFile File(fileName);
	//�������� ����� �� ������
	if (File.open(QIODevice::WriteOnly | QIODevice::Truncate))
	{
		//�������� ������
		QDataStream Out(&File);
		Out.setVersion(QDataStream::Qt_4_3);
		//������ ���������� ������� � ����
		Out << count();

		it.toFront();
		directorySettlements _item;

		while (it.hasNext())
		{
			//�������� ������������� �������
			unsigned int valuee = it.next();
			//��������� ������ �� ��������������
			record(valuee, _item);
			//������ � ���� ����� ������
			Out << _item;
		}
		//�������� �����
		File.close();
		return true;
	}

	return false;
}

bool baseData::load(QString fileName)
{
	QFile File(fileName);	//�������� ����� � ����� �����
	if (File.open(QIODevice::ReadOnly))	//�������� ����� �� ������
	{
		int S_conut;

		QDataStream In(&File);	//�������� ������
		In.setVersion(QDataStream::Qt_4_3);

		In >> S_conut;	//��������� ���������� ������� �� �����

		for (int i = 0; i < S_conut; i++)
		{
			//���������� ����� ������
			directorySettlements _item;
			In >> _item;
			//���������� ������ � ��������� �������
			append(_item);
		}
		//�������� �����
		File.close();
		return true;
	}

	return false;
}

void baseData::clear()
{
	Data.clear();
	Sorting.clear();
	global = 0;
}