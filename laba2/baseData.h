#pragma once

#ifndef BASEDATA_H
#define BASEDATA_H

#include <QMap>
#include <QList>
#include <QMutableMapIterator>
#include <QFile>
#include <QVector>
#include "directorySettlements.h"
#include <QTextStream>

class baseData
{
public:
	baseData(void);
	~baseData(void);

	int count() const;

	int append(directorySettlements &record);

	void remove(unsigned int id);

	int update(const directorySettlements &record);

	void  record(unsigned  int  id, directorySettlements  &record);

	const QVector<DIRECTORY> records();

	bool save(QString fileName);

	bool load(QString fileName);

	void clear();

private:

	QMap<int, directorySettlements> Data;
	QList <unsigned int> Sorting;
	unsigned int global;
};


#endif BASEDATA_H