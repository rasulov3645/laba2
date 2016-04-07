#include "directorySettlements.h"

directorySettlements::directorySettlements()	//Конструктор
{
	sub_of_fed = Москва;
	_name = QString("UNKNOWN");
	_type = город;
	is_known_found_date = false;
	year_of_found = 0;
	date_of_found = QDate(01, 01, 2000);
	count_of_people = 2000;
	old_name = QString("\0");
}
directorySettlements directorySettlements::operator =(const directorySettlements & other)
{
	sub_of_fed = other.sub_of_fed;
	_name = other._name;
	_type = other._type;
	is_known_found_date = other.is_known_found_date;
	year_of_found = other.year_of_found;
	date_of_found = other.date_of_found;
	count_of_people = other.count_of_people;
	old_name = other.old_name;

	return other;
}
bool directorySettlements::operator ==(const directorySettlements & other)
{
	bool dateOrYear;

	if (is_known_found_date == true && other.is_known_found_date == true){ dateOrYear = (date_of_found == other.date_of_found); }
	else if (is_known_found_date == false && other.is_known_found_date == false) { dateOrYear = (year_of_found == other.year_of_found); }
	else dateOrYear = false;

	return sub_of_fed == other.sub_of_fed && _name == other._name &&
		_type == other._type && dateOrYear && count_of_people ==
		other.count_of_people && old_name == other.old_name;
}
bool directorySettlements::operator !=(const directorySettlements & other)
{
	bool dateOrYear;
	if (is_known_found_date == true && other.is_known_found_date == true){ dateOrYear = !(date_of_found == other.date_of_found); }
	else if (is_known_found_date == false && other.is_known_found_date == false) { dateOrYear = !(year_of_found == other.year_of_found); }
	else dateOrYear = true;

	return sub_of_fed != other.sub_of_fed || _name != other._name ||
		_type != other._type || dateOrYear || count_of_people !=
		other.count_of_people || old_name != other.old_name;
}
bool directorySettlements::operator >(const directorySettlements & other)
{
	if (*this == directorySettlements())
		return false;

	return sub_of_fed > other.sub_of_fed ||
		(sub_of_fed == other.sub_of_fed && _name > other._name);
}
bool directorySettlements::operator >=(const directorySettlements & other)
{
	return operator>(other) || operator==(other);
}
bool directorySettlements::operator <(const directorySettlements & other)
{
	if (*this == directorySettlements())
		return false;

	return sub_of_fed < other.sub_of_fed ||
		(sub_of_fed == other.sub_of_fed && _name < other._name);
}
bool directorySettlements::operator <=(const directorySettlements & other)
{
	return operator<(other) || operator==(other);
}
directorySettlements::~directorySettlements()
{
}