#ifndef MYPROJECT_H
#define MYPROJECT_H

#include <QtGui/QMainWindow>
#include "ui_laba2.h"
#include "directorySettlements.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include "baseData.h"

class laba2 : public QMainWindow
{
	Q_OBJECT

public:
	laba2(QWidget *parent = 0, Qt::WFlags flags = 0);
	~laba2();

	bool file_saved;
	QString tmpFileName;

	baseData db;
	bool saveChanges();

	directorySettlements getItemInPos(int pos);

private:
	Ui::laba2Class ui;

	private slots:
	void FoundationDate();
	void SaveNote();
	void AddItem();
	void DeleteItem();
	void ShowNotes(int);
	void Fill();

	void fileNew();
	void fileOpen();
	void fileSave();
	void fileSaveAs();
	void SaveTo();

protected:
	virtual void closeEvent(QCloseEvent *event);

};

#endif // MYPROJECT_H

