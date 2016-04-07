/********************************************************************************
** Form generated from reading UI file 'laba2.ui'
**
** Created: Thu 7. Apr 01:19:47 2016
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABA2_H
#define UI_LABA2_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_laba2Class
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionSaveTo;
    QWidget *centralWidget;
    QLabel *label_10;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *create;
    QPushButton *save;
    QPushButton *fill;
    QPushButton *Delete;
    QGroupBox *groupBox;
    QStackedWidget *dateOrYear;
    QWidget *page_5;
    QLabel *label_4;
    QSpinBox *yearOfFound;
    QWidget *page_6;
    QLabel *label_5;
    QDateEdit *dateOfFound;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QCheckBox *isKnownFoundDate;
    QComboBox *subOfFed;
    QLineEdit *name;
    QComboBox *type;
    QLabel *label_6;
    QSpinBox *countOfPeople;
    QLabel *label_7;
    QTextEdit *oldName;
    QListWidget *list;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *laba2Class)
    {
        if (laba2Class->objectName().isEmpty())
            laba2Class->setObjectName(QString::fromUtf8("laba2Class"));
        laba2Class->resize(944, 405);
        actionNew = new QAction(laba2Class);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(laba2Class);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(laba2Class);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(laba2Class);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionSaveTo = new QAction(laba2Class);
        actionSaveTo->setObjectName(QString::fromUtf8("actionSaveTo"));
        centralWidget = new QWidget(laba2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(170, 0, 161, 29));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(12);
        label_10->setFont(font);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 10, 46, 13));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 0, 111, 29));
        label_9->setFont(font);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(350, 0, 71, 29));
        label_11->setFont(font);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(460, 310, 481, 33));
        horizontalLayoutWidget->setFont(font);
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        create = new QPushButton(horizontalLayoutWidget);
        create->setObjectName(QString::fromUtf8("create"));
        create->setFont(font);

        horizontalLayout->addWidget(create);

        save = new QPushButton(horizontalLayoutWidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setFont(font);

        horizontalLayout->addWidget(save);

        fill = new QPushButton(horizontalLayoutWidget);
        fill->setObjectName(QString::fromUtf8("fill"));
        fill->setFont(font);

        horizontalLayout->addWidget(fill);

        Delete = new QPushButton(horizontalLayoutWidget);
        Delete->setObjectName(QString::fromUtf8("Delete"));
        Delete->setFont(font);

        horizontalLayout->addWidget(Delete);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(460, 10, 481, 291));
        groupBox->setFont(font);
        dateOrYear = new QStackedWidget(groupBox);
        dateOrYear->setObjectName(QString::fromUtf8("dateOrYear"));
        dateOrYear->setGeometry(QRect(10, 120, 461, 31));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        label_4 = new QLabel(page_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 141, 29));
        label_4->setFont(font);
        yearOfFound = new QSpinBox(page_5);
        yearOfFound->setObjectName(QString::fromUtf8("yearOfFound"));
        yearOfFound->setGeometry(QRect(200, 0, 261, 29));
        yearOfFound->setFont(font);
        yearOfFound->setMaximum(2015);
        dateOrYear->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        label_5 = new QLabel(page_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 181, 29));
        label_5->setFont(font);
        dateOfFound = new QDateEdit(page_6);
        dateOfFound->setObjectName(QString::fromUtf8("dateOfFound"));
        dateOfFound->setGeometry(QRect(290, 0, 261, 29));
        dateOfFound->setFont(font);
        dateOfFound->setMaximumDate(QDate(2015, 1, 1));
        dateOrYear->addWidget(page_6);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 182, 29));
        label->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 182, 29));
        label_2->setFont(font);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 182, 29));
        label_3->setFont(font);
        isKnownFoundDate = new QCheckBox(groupBox);
        isKnownFoundDate->setObjectName(QString::fromUtf8("isKnownFoundDate"));
        isKnownFoundDate->setGeometry(QRect(10, 100, 191, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Comic Sans MS"));
        font1.setPointSize(10);
        isKnownFoundDate->setFont(font1);
        subOfFed = new QComboBox(groupBox);
        subOfFed->setObjectName(QString::fromUtf8("subOfFed"));
        subOfFed->setGeometry(QRect(210, 10, 261, 29));
        subOfFed->setFont(font);
        name = new QLineEdit(groupBox);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(210, 40, 261, 29));
        name->setFont(font);
        name->setMaxLength(20);
        type = new QComboBox(groupBox);
        type->setObjectName(QString::fromUtf8("type"));
        type->setGeometry(QRect(210, 70, 261, 29));
        type->setFont(font);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 160, 191, 29));
        label_6->setFont(font);
        countOfPeople = new QSpinBox(groupBox);
        countOfPeople->setObjectName(QString::fromUtf8("countOfPeople"));
        countOfPeople->setGeometry(QRect(210, 160, 261, 29));
        countOfPeople->setFont(font);
        countOfPeople->setMinimum(1);
        countOfPeople->setMaximum(20000000);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 220, 181, 31));
        label_7->setFont(font);
        oldName = new QTextEdit(groupBox);
        oldName->setObjectName(QString::fromUtf8("oldName"));
        oldName->setEnabled(true);
        oldName->setGeometry(QRect(210, 190, 261, 91));
        oldName->setFont(font);
        oldName->setTabStopWidth(80);
        list = new QListWidget(centralWidget);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(10, 30, 441, 321));
        laba2Class->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(laba2Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        laba2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(laba2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        laba2Class->setStatusBar(statusBar);
        menuBar = new QMenuBar(laba2Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 944, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        laba2Class->setMenuBar(menuBar);
        QWidget::setTabOrder(list, subOfFed);
        QWidget::setTabOrder(subOfFed, name);
        QWidget::setTabOrder(name, type);
        QWidget::setTabOrder(type, isKnownFoundDate);
        QWidget::setTabOrder(isKnownFoundDate, yearOfFound);
        QWidget::setTabOrder(yearOfFound, countOfPeople);
        QWidget::setTabOrder(countOfPeople, oldName);
        QWidget::setTabOrder(oldName, create);
        QWidget::setTabOrder(create, save);
        QWidget::setTabOrder(save, fill);
        QWidget::setTabOrder(fill, Delete);
        QWidget::setTabOrder(Delete, dateOfFound);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionSaveTo);

        retranslateUi(laba2Class);

        dateOrYear->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(laba2Class);
    } // setupUi

    void retranslateUi(QMainWindow *laba2Class)
    {
        laba2Class->setWindowTitle(QApplication::translate("laba2Class", "MyProject", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("laba2Class", "New", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("laba2Class", "Open", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("laba2Class", "Save", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("laba2Class", "Save As", 0, QApplication::UnicodeUTF8));
        actionSaveTo->setText(QApplication::translate("laba2Class", "SaveTo", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("laba2Class", "\320\241\321\203\320\261\321\212\320\265\320\272\321\202 \321\204\320\265\320\264\320\265\321\200\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        label_9->setText(QApplication::translate("laba2Class", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("laba2Class", "\320\232\320\276\320\273. \320\266\320\270\321\202.", 0, QApplication::UnicodeUTF8));
        create->setText(QApplication::translate("laba2Class", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        save->setText(QApplication::translate("laba2Class", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        fill->setText(QApplication::translate("laba2Class", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        Delete->setText(QApplication::translate("laba2Class", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_4->setText(QApplication::translate("laba2Class", "\320\223\320\276\320\264 \320\276\321\201\320\275\320\276\320\262\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("laba2Class", "\320\224\320\260\321\202\320\260 \320\276\321\201\320\275\320\276\320\262\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("laba2Class", "\320\241\321\203\320\261\321\212\320\265\320\272\321\202 \321\204\320\265\320\264\320\265\321\200\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("laba2Class", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("laba2Class", "\320\242\320\270\320\277", 0, QApplication::UnicodeUTF8));
        isKnownFoundDate->setText(QApplication::translate("laba2Class", "\320\230\320\267\320\262\320\265\321\201\321\202\320\275\320\260 \320\264\320\260\321\202\320\260 \320\276\321\201\320\275\320\276\320\262\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        subOfFed->clear();
        subOfFed->insertItems(0, QStringList()
         << QApplication::translate("laba2Class", "\320\234\320\276\321\201\320\272\320\276\320\262\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("laba2Class", "\320\222\320\276\320\273\320\263\320\276\320\263\321\200\320\260\320\264\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("laba2Class", "\320\241\320\260\321\200\320\260\321\202\320\276\320\262\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8)
        );
        type->clear();
        type->insertItems(0, QStringList()
         << QApplication::translate("laba2Class", "\320\263\320\276\321\200\320\276\320\264", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("laba2Class", "\320\277\320\276\321\201\320\265\320\273\320\276\320\272", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("laba2Class", "\320\264\320\265\321\200\320\265\320\262\320\275\321\217", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("laba2Class", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\266\320\270\321\202\320\265\320\273\320\265\320\271", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("laba2Class", "\320\243\321\201\321\202\320\260\321\200\320\265\320\262\321\210\320\265\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("laba2Class", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class laba2Class: public Ui_laba2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABA2_H
