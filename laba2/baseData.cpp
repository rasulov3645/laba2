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

	// ввыдавать идентификатор записи
	record.id = global;
	// добавить запись в базу данных
	Data.insert(record.id, record);

	QMutableListIterator<unsigned int> ite(Sorting);

	ite.toFront();
	directorySettlements _item;
	int pos = 0;

	// сортировать идентификаторы 
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

	// добавить новый идентификатор в QList Sorting
	ite.insert(record.id);

	// возвращается количество записей
	return pos;
}

void baseData::remove(unsigned int id)
{
	Sorting.removeAll(id);
	Data.remove(id);
}

int baseData::update(const directorySettlements &record)
{
	// удалить старую записью в базу данных
	remove(record.id);
	// добавить новую записью в базу данных 
	Data.insert(record.id, record);

	/*QMutableListIterator<unsigned int> ite(Sorting);

	ite.toFront();
	directorySettlements _item;
	int pos = 0;

	// сортировать идентификаторы
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

	// добавить новый идентификатор в QList Sorting
	ite.insert(record.id);*/


	QList <unsigned int>::iterator ite;
	ite = Sorting.begin();
	directorySettlements _item;
	int pos = 0;

	// сортировать идентификаторы 
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

	// добавить новый идентификатор в QList Sorting
	ite = Sorting.insert(ite, record.id);


	// возвращается позицию записей в базе данных
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

	// возвратить  вектор  записей
	return _vector;
}

bool baseData::save(QString fileName)
{
	QListIterator<unsigned int> it(Sorting);
	//Привязка файла к имени файла
	QFile File(fileName);
	//Открытие файла на запись
	if (File.open(QIODevice::WriteOnly | QIODevice::Truncate))
	{
		//Создание потока
		QDataStream Out(&File);
		Out.setVersion(QDataStream::Qt_4_3);
		//Запись количества записей в файл
		Out << count();

		it.toFront();
		directorySettlements _item;

		while (it.hasNext())
		{
			//вынимать идентификатор записей
			unsigned int valuee = it.next();
			//Получение записи по идентификатору
			record(valuee, _item);
			//Запись в файл полей записи
			Out << _item;
		}
		//Закрытие файла
		File.close();
		return true;
	}

	return false;
}

bool baseData::load(QString fileName)
{
	QFile File(fileName);	//Привязка файла к имени файла
	if (File.open(QIODevice::ReadOnly))	//Открытие файла на чтение
	{
		int S_conut;

		QDataStream In(&File);	//Создание потока
		In.setVersion(QDataStream::Qt_4_3);

		In >> S_conut;	//Получение количества записей из файла

		for (int i = 0; i < S_conut; i++)
		{
			//Считывание полей записи
			directorySettlements _item;
			In >> _item;
			//Добавление записи в контейнер записей
			append(_item);
		}
		//Закрытие файла
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