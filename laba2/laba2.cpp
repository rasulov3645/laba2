#include "laba2.h"
#include <QMessageBox>

laba2::laba2(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	ui.setupUi(this);
	ui.Delete->setEnabled(false);
	ui.save->setEnabled(false);
	ui.groupBox->setEnabled(false);
	ui.list->setEnabled(false);
	ui.create->setEnabled(false);
	ui.fill->setEnabled(false);

	connect(ui.isKnownFoundDate, SIGNAL(stateChanged(int)), this, SLOT(FoundationDate()));
	connect(ui.list, SIGNAL(currentRowChanged(int)), this, SLOT(ShowNotes(int)));
	connect(ui.create, SIGNAL(clicked()), this, SLOT(AddItem()));
	connect(ui.save, SIGNAL(clicked()), this, SLOT(SaveNote()));
	connect(ui.fill, SIGNAL(clicked()), this, SLOT(Fill()));
	connect(ui.Delete, SIGNAL(clicked()), this, SLOT(DeleteItem()));

	connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(fileNew()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(fileOpen()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(fileSave()));
	connect(ui.actionSave_As, SIGNAL(triggered()), this, SLOT(fileSaveAs()));
	connect(ui.actionSaveTo, SIGNAL(triggered()), this, SLOT(SaveTo()));

	file_saved = true;
}

//Слот, добавляет записи по умолчанию в браузер (QListWidget)
void laba2::AddItem()
{
	directorySettlements directory;
	int current = db.append(directory);

	QString str = directory._name + QString("\t\t") + ui.subOfFed->itemText((int)directory.sub_of_fed) + QString("\t") + QString::number(directory.count_of_people);
	ui.list->insertItem(current, str);
	ui.list->item(current)->setData(Qt::UserRole, directory.id);
	ui.list->setCurrentRow(current);

	file_saved = false;
}

//Слот, работающий при нажатии кнопки "Сохранить"
void laba2::SaveNote()
{
	int current = ui.list->currentRow();

	if (current < 0 || current >= db.count())
		return;

	directorySettlements settlement;

	settlement.sub_of_fed = (SubOfFed)ui.subOfFed->currentIndex();
	settlement._name = ui.name->text();
	settlement._type = (Type)ui.type->currentIndex();
	settlement.is_known_found_date = ui.isKnownFoundDate->isChecked();
	settlement.year_of_found = ui.yearOfFound->value();
	settlement.date_of_found = ui.dateOfFound->date();
	settlement.count_of_people = ui.countOfPeople->value();
	settlement.old_name = ui.oldName->toPlainText();

	settlement.id = ui.list->item(current)->data(Qt::UserRole).toUInt();

	int pos = db.update(settlement);

	QString str = settlement._name + QString("\t\t") + ui.subOfFed->itemText((int)settlement.sub_of_fed) + QString("\t") + QString::number(settlement.count_of_people);

	ui.list->takeItem(current);
	ui.list->insertItem(pos, str);
	ui.list->item(pos)->setData(Qt::UserRole, settlement.id);
	ui.list->setCurrentRow(pos);

	file_saved = false;
}
//Функция слот показывает значение сохраненных в переменнах.
void laba2::ShowNotes(int i)
{
	if (i < -1 || i >= db.count()) return;

	int current = i;

	directorySettlements settlement = getItemInPos(current);

	if (current == -1)
	{
		ui.subOfFed->setCurrentIndex(0);
		ui.name->setText("\0");
		ui.type->setCurrentIndex(0);
		ui.isKnownFoundDate->setChecked(false);
		if (ui.isKnownFoundDate->isChecked() == false)
		{
			ui.yearOfFound->setValue(0);
		}
		else { ui.dateOfFound->setDate(QDate(01, 01, 2000)); }
		ui.countOfPeople->setValue(0);
		ui.oldName->setText("\0");
		ui.Delete->setEnabled(false);
		ui.save->setEnabled(false);
		ui.groupBox->setEnabled(false);
		return;
	}
	else
	{
		ui.subOfFed->setCurrentIndex(settlement.sub_of_fed);
		ui.name->setText(settlement._name);
		ui.type->setCurrentIndex(settlement._type);
		ui.isKnownFoundDate->setChecked(settlement.is_known_found_date);
		if (ui.isKnownFoundDate->isChecked() == false)
		{
			ui.yearOfFound->setValue(settlement.year_of_found);
		}
		else { ui.dateOfFound->setDate(settlement.date_of_found); }
		ui.countOfPeople->setValue(settlement.count_of_people);
		ui.oldName->setText(settlement.old_name);

		ui.Delete->setEnabled(true);
		ui.save->setEnabled(true);
		ui.groupBox->setEnabled(true);
	}
}

//Удаляет выбранной запись и массив
void laba2::DeleteItem()
{
	int cur = ui.list->currentRow();

	if (cur < 0 || cur >= db.count())
	{
		return;
	}

	int _id = ui.list->item(cur)->data(Qt::UserRole).toUInt();

	db.remove(_id);
	ui.list->takeItem(cur);

	if (db.count() == 0)
	{
		ShowNotes(-1);
		ui.list->setEnabled(false);
		ui.groupBox->setEnabled(false);
		return;
	}

	if (cur == db.count())
		cur--;

	ui.list->setCurrentRow(cur);

	file_saved = false;


}
//Слот, добавляет 10 записей в баузер
void laba2::Fill()
{

	directorySettlements settlement;
	int pos;

	settlement = directorySettlements();

	settlement.sub_of_fed = (SubOfFed)Москва;
	settlement._name = QString("Samarkand");
	settlement.count_of_people = 2000;

	pos = db.append(settlement);
	QString str = settlement._name + QString("\t\t") + ui.subOfFed->itemText((int)settlement.sub_of_fed) + QString("\t") + QString::number(settlement.count_of_people);
	ui.list->insertItem(pos, str);
	ui.list->item(pos)->setData(Qt::UserRole, settlement.id);
	ui.list->setCurrentRow(pos);


	settlement = directorySettlements();

	settlement.sub_of_fed = (SubOfFed)Саратов;
	settlement._name = QString("Moskva");
	settlement.count_of_people = 2000;

	pos = db.append(settlement);
	str = settlement._name + QString("\t\t") + ui.subOfFed->itemText((int)settlement.sub_of_fed) + QString("\t") + QString::number(settlement.count_of_people);
	ui.list->insertItem(pos, str);
	ui.list->item(pos)->setData(Qt::UserRole, settlement.id);
	ui.list->setCurrentRow(pos);


	settlement = directorySettlements();

	settlement.sub_of_fed = (SubOfFed)Волгоград;
	settlement._name = QString("Tashkent");
	settlement.count_of_people = 2000;

	pos = db.append(settlement);
	str = settlement._name + QString("\t\t") + ui.subOfFed->itemText((int)settlement.sub_of_fed) + QString("\t") + QString::number(settlement.count_of_people);
	ui.list->insertItem(pos, str);
	ui.list->item(pos)->setData(Qt::UserRole, settlement.id);
	ui.list->setCurrentRow(pos);


	settlement = directorySettlements();

	settlement.sub_of_fed = (SubOfFed)Саратов;
	settlement._name = QString("Bukhara");
	settlement.count_of_people = 2000;

	pos = db.append(settlement);
	str = settlement._name + QString("\t\t") + ui.subOfFed->itemText((int)settlement.sub_of_fed) + QString("\t") + QString::number(settlement.count_of_people);
	ui.list->insertItem(pos, str);
	ui.list->item(pos)->setData(Qt::UserRole, settlement.id);
	ui.list->setCurrentRow(pos);


	settlement = directorySettlements();

	settlement.sub_of_fed = (SubOfFed)Волгоград;
	settlement._name = QString("London");
	settlement.count_of_people = 2000;

	pos = db.append(settlement);
	str = settlement._name + QString("\t\t") + ui.subOfFed->itemText((int)settlement.sub_of_fed) + QString("\t") + QString::number(settlement.count_of_people);
	ui.list->insertItem(pos, str);
	ui.list->item(pos)->setData(Qt::UserRole, settlement.id);
	ui.list->setCurrentRow(pos);


	settlement = directorySettlements();

	settlement.sub_of_fed = (SubOfFed)Саратов;
	settlement._name = QString("Volgograd");
	settlement.count_of_people = 2000;

	pos = db.append(settlement);
	str = settlement._name + QString("\t\t") + ui.subOfFed->itemText((int)settlement.sub_of_fed) + QString("\t") + QString::number(settlement.count_of_people);
	ui.list->insertItem(pos, str);
	ui.list->item(pos)->setData(Qt::UserRole, settlement.id);
	ui.list->setCurrentRow(pos);


	settlement = directorySettlements();

	settlement.sub_of_fed = (SubOfFed)Волгоград;
	settlement._name = QString("Saratov");
	settlement.count_of_people = 2000;

	pos = db.append(settlement);
	str = settlement._name + QString("\t\t") + ui.subOfFed->itemText((int)settlement.sub_of_fed) + QString("\t") + QString::number(settlement.count_of_people);
	ui.list->insertItem(pos, str);
	ui.list->item(pos)->setData(Qt::UserRole, settlement.id);
	ui.list->setCurrentRow(pos);



	settlement = directorySettlements();

	settlement.sub_of_fed = (SubOfFed)Москва;
	settlement._name = QString("Ufa");
	settlement.count_of_people = 2000;

	pos = db.append(settlement);
	str = settlement._name + QString("\t\t") + ui.subOfFed->itemText((int)settlement.sub_of_fed) + QString("\t") + QString::number(settlement.count_of_people);
	ui.list->insertItem(pos, str);
	ui.list->item(pos)->setData(Qt::UserRole, settlement.id);
	ui.list->setCurrentRow(pos);


	settlement = directorySettlements();

	settlement.sub_of_fed = (SubOfFed)Волгоград;
	settlement._name = QString("Rim");
	settlement.count_of_people = 2000;

	pos = db.append(settlement);
	str = settlement._name + QString("\t\t") + ui.subOfFed->itemText((int)settlement.sub_of_fed) + QString("\t") + QString::number(settlement.count_of_people);
	ui.list->insertItem(pos, str);
	ui.list->item(pos)->setData(Qt::UserRole, settlement.id);
	ui.list->setCurrentRow(pos);


	settlement = directorySettlements();

	settlement.sub_of_fed = (SubOfFed)Волгоград;
	settlement._name = QString("Tokyo");
	settlement.count_of_people = 2000;

	pos = db.append(settlement);
	str = settlement._name + QString("\t\t") + ui.subOfFed->itemText((int)settlement.sub_of_fed) + QString("\t") + QString::number(settlement.count_of_people);
	ui.list->insertItem(pos, str);
	ui.list->item(pos)->setData(Qt::UserRole, settlement.id);
	ui.list->setCurrentRow(db.count() - 1);

	ui.list->setEnabled(true);
	file_saved = false;
}


//Слот, работающий при изменение положения CheckBox "Известна дата основания"
void laba2::FoundationDate()
{
	if (ui.isKnownFoundDate->isChecked() == false)
	{
		ui.dateOrYear->setCurrentIndex(0);
		ui.dateOfFound->setDate(QDate(2000, 01, 01));
	}
	else
	{
		ui.dateOrYear->setCurrentIndex(1);
		ui.yearOfFound->setValue(0);
	}
	//QMessageBox::warning(this, "Invalid Text entry", "aaaaaaaaaa");
}

laba2::~laba2(){}

directorySettlements laba2::getItemInPos(int pos)
{
	directorySettlements _item;

	if (pos < 0 || pos >= ui.list->count())
		return _item;

	int id = ui.list->item(pos)->data(Qt::UserRole).toUInt();

	db.record(id, _item);

	return _item;
}




void laba2::fileNew()
{
	if (saveChanges())
	{
		tmpFileName = "";
		db.clear();
		ui.list->clear();
		// установить состояние кнопки

		ui.list->setEnabled(true);
		ui.groupBox->setEnabled(true);
		ui.create->setEnabled(true);
		ui.save->setEnabled(false);
		ui.fill->setEnabled(true);
		ui.Delete->setEnabled(false);

		file_saved = false;
	}
}

void laba2::SaveTo()
{

	QFile file("mod_text.txt");

	if (!file.open(QIODevice::WriteOnly)) {

		return;

	}

	QTextStream out(&file);
	int cur;
	for (cur = 0; cur < db.count(); cur++)
	{
		directorySettlements _item = getItemInPos(cur);

		out << _item._name << " " << _item.sub_of_fed << " " << _item.count_of_people << "" << "\r\n" << endl;

		//out « _item.Name « " " « ui.lwcategory->item(_item.Categ)->text() « " " « ui.lwdrain->item(_item.drain)->text() « " " « _item.isname « " " « ui.lwsource->item(_item.source)->text() « " " « ui.lwsalinity->item(_item.salinity)->text()«" " « _item.extension « " " « _item.area1 « " " « _item.area2 « "\r\n";

	}

}

void laba2::fileOpen()
{
	tmpFileName = "";

	if (saveChanges())
	{
		file_saved = true;
		db.clear();

		QString temp;
		temp = QFileDialog::getOpenFileName(this, tr("My file"), QString(), tr("Type of file(*.txt)"));

		bool hasOpen;
		if (temp != "")
		{
			tmpFileName = temp;
			bool hasOpen = db.load(tmpFileName);
		}
		else hasOpen = false;

		if (hasOpen)
		{
			ui.list->clear();
			ui.list->setEnabled(true);
			ui.groupBox->setEnabled(true);
			ui.create->setEnabled(true);
			ui.save->setEnabled(false);
			ui.fill->setEnabled(true);
			ui.Delete->setEnabled(true);

			if (db.count() == 0)
			{
				ui.Delete->setEnabled(false);

				return;
			}

			//showData(0);

			ui.list->clear();

			QVector <DIRECTORY> myVector = db.records();
			QMutableVectorIterator <DIRECTORY> i(myVector);
			int j = 0;

			while (i.hasNext())
			{
				i.next();
				QString str = i.value().NAME + QString("\t\t") + ui.subOfFed->itemText(i.value().SUB_OF_FED) + QString("\t") + QString::number(i.value().COUNT_OF_PEOPLE);
				ui.list->insertItem(j, str);
				ui.list->item(j)->setData(Qt::UserRole, i.value().ID);
				j++;
			}

			/*for(int i=0; i < myVector.size(); i++)
			{
			QString str = myVector[i].NAME + QString("\t\t") + ui.subOfFed->itemText(myVector[i].SUB_OF_FED) + QString("\t") + QString::number(myVector[i].COUNT_OF_PEOPLE);
			ui.list->insertItem( i, str);
			ui.list->item(i)->setData(Qt::UserRole, myVector[i].ID);
			}*/

			ui.list->setCurrentRow(0);
		}
	}
}

void laba2::fileSave()
{
	tmpFileName == "";
	if (tmpFileName == "")
		tmpFileName = QFileDialog::getSaveFileName(this, "Введите имя сохраняемого файла", QString(), tr("Файлы библиографии (*.txt)"));

	db.save(tmpFileName);
	file_saved = true;
}

void laba2::fileSaveAs()
{
	QString tempName = QFileDialog::getSaveFileName(this, "Введите имя сохраняемого файла", QString(), tr("Type of file (*.txt)"));

	if (tempName != "")
		tmpFileName = tempName;
	else
	{
		QMessageBox::warning(this, "Invalid input data  ", " No save file");

		return;
	}

	bool flag = db.save(tmpFileName);

	file_saved = true;
}

bool laba2::saveChanges()
{
	if (!file_saved)
	{
		//Вызов диалогового окна
		QMessageBox::StandardButton ret;

		ret = QMessageBox::warning(this, tr("Application"), tr("Your base has been changed.\n""Save changes?"),
			QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel);

		if (ret == QMessageBox::Save)
			fileSave();	//Сохранение файла
		else
			if (ret == QMessageBox::Cancel)
				return false;
	}

	return true;
}


void laba2::closeEvent(QCloseEvent *event)
{
	if (saveChanges())
		event->accept();	//Событие принятно
	else
		event->ignore();	//Событие проигнорировано
}
