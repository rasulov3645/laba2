#ifndef DIRECTORYSETTLEMENTS_H
#define DIRECTORYSETTLEMENTS_H

#include <QString>
#include <QDate>
#include <QDataStream>

struct DIRECTORY
{
	QString NAME;
	int SUB_OF_FED;
	int COUNT_OF_PEOPLE;
	unsigned int ID;
};

enum SubOfFed
{
	Москва = 0,
	Волгоград = 1,
	Саратов = 2,
};
enum Type
{
	город = 0,
	поселок = 1,
	деревня = 2,
};
class directorySettlements
{
public:
	directorySettlements();
	~directorySettlements();

	SubOfFed sub_of_fed;
	QString _name;
	Type _type;
	bool is_known_found_date;
	int year_of_found;
	QDate date_of_found;
	int count_of_people;
	QString old_name;
	unsigned int id;

	bool operator ==(const directorySettlements & other);
	bool operator !=(const directorySettlements & other);
	bool operator >(const directorySettlements & other);
	bool operator >=(const directorySettlements & other);
	bool operator <(const directorySettlements & other);
	bool operator <=(const directorySettlements & other);
	directorySettlements operator =(const directorySettlements & other);
};


inline QDataStream & operator>>(QDataStream &in, directorySettlements &item)
{

	int temp1 = item.sub_of_fed;
	int temp2 = item._type;


	in >> temp1
		>> item._name
		>> temp2
		>> item.is_known_found_date
		>> item.year_of_found
		>> item.date_of_found
		>> item.count_of_people
		>> item.old_name
		>> item.id;

	return in;
}


inline QDataStream & operator<<(QDataStream &out, directorySettlements &item)
{
	out << item.sub_of_fed
		<< item._name
		<< item._type
		<< item.is_known_found_date
		<< item.year_of_found
		<< item.date_of_found
		<< item.count_of_people
		<< item.old_name
		<< item.id;

	return out;
}


#endif DIRECTORYFOUNDATION_H