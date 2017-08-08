/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *saveAction;
    QAction *openAction;
    QAction *newAction;
    QAction *saveAsAction;
    QAction *exitAction;
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QFrame *line;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *emitXEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *emitYEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *emitZEdit;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *chargeEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *massEdit;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QLineEdit *currentEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QLineEdit *kineticEnergyEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_10;
    QLineEdit *nbrOfParticleEdit;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_11;
    QLineEdit *freqEdit;
    QPushButton *twissBtn;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayout;
    QLabel *label_14;
    QComboBox *archCb;
    QLabel *label_15;
    QComboBox *scModelCb;
    QLabel *label_16;
    QComboBox *pushCb;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_17;
    QLineEdit *stepCycleEdit;
    QLabel *label_22;
    QLineEdit *maxStepNumEdit;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *dataFileEdit;
    QPushButton *dataOpenBtn;
    QPushButton *structSaveBtn;
    QPushButton *dataNewBtn;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *resultDirEdit;
    QPushButton *resultOpenBtn;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_18;
    QComboBox *dimCb;
    QLabel *label_19;
    QLineEdit *dimXEdit;
    QLineEdit *dimYEdit;
    QLineEdit *dimZEdit;
    QLabel *label_20;
    QLabel *label_21;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_6;
    QLabel *label_23;
    QComboBox *transCb;
    QLabel *label_24;
    QComboBox *longCb;
    QSpacerItem *verticalSpacer;
    QWidget *tab_4;
    QWidget *tab_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 638);
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QStringLiteral("saveAction"));
        QIcon icon;
        icon.addFile(QStringLiteral("save.png"), QSize(), QIcon::Selected, QIcon::On);
        saveAction->setIcon(icon);
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QStringLiteral("openAction"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("open.png"), QSize(), QIcon::Selected, QIcon::On);
        openAction->setIcon(icon1);
        newAction = new QAction(MainWindow);
        newAction->setObjectName(QStringLiteral("newAction"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("new.png"), QSize(), QIcon::Selected, QIcon::On);
        newAction->setIcon(icon2);
        saveAsAction = new QAction(MainWindow);
        saveAsAction->setObjectName(QStringLiteral("saveAsAction"));
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QStringLiteral("exitAction"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(771, 501));
        tabWidget->setIconSize(QSize(32, 32));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 341, 501));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 201, 20));
        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 210, 321, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 90, 196, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        emitXEdit = new QLineEdit(layoutWidget);
        emitXEdit->setObjectName(QStringLiteral("emitXEdit"));

        horizontalLayout->addWidget(emitXEdit);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 130, 196, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        emitYEdit = new QLineEdit(layoutWidget1);
        emitYEdit->setObjectName(QStringLiteral("emitYEdit"));

        horizontalLayout_2->addWidget(emitYEdit);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(40, 170, 196, 30));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        emitZEdit = new QLineEdit(layoutWidget2);
        emitZEdit->setObjectName(QStringLiteral("emitZEdit"));

        horizontalLayout_3->addWidget(emitZEdit);

        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 230, 299, 232));
        gridLayout_2 = new QGridLayout(layoutWidget3);
        gridLayout_2->setSpacing(10);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        chargeEdit = new QLineEdit(layoutWidget3);
        chargeEdit->setObjectName(QStringLiteral("chargeEdit"));

        horizontalLayout_4->addWidget(chargeEdit);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        massEdit = new QLineEdit(layoutWidget3);
        massEdit->setObjectName(QStringLiteral("massEdit"));

        horizontalLayout_5->addWidget(massEdit);


        gridLayout_2->addLayout(horizontalLayout_5, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label_9);

        currentEdit = new QLineEdit(layoutWidget3);
        currentEdit->setObjectName(QStringLiteral("currentEdit"));

        verticalLayout->addWidget(currentEdit);


        gridLayout_2->addLayout(verticalLayout, 2, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_2->addWidget(label_8);

        kineticEnergyEdit = new QLineEdit(layoutWidget3);
        kineticEnergyEdit->setObjectName(QStringLiteral("kineticEnergyEdit"));

        verticalLayout_2->addWidget(kineticEnergyEdit);


        gridLayout_2->addLayout(verticalLayout_2, 2, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_3->addWidget(label_10);

        nbrOfParticleEdit = new QLineEdit(layoutWidget3);
        nbrOfParticleEdit->setObjectName(QStringLiteral("nbrOfParticleEdit"));

        verticalLayout_3->addWidget(nbrOfParticleEdit);


        gridLayout_2->addLayout(verticalLayout_3, 3, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_11 = new QLabel(layoutWidget3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_4->addWidget(label_11);

        freqEdit = new QLineEdit(layoutWidget3);
        freqEdit->setObjectName(QStringLiteral("freqEdit"));

        verticalLayout_4->addWidget(freqEdit);


        gridLayout_2->addLayout(verticalLayout_4, 3, 1, 1, 1);

        twissBtn = new QPushButton(layoutWidget3);
        twissBtn->setObjectName(QStringLiteral("twissBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(twissBtn->sizePolicy().hasHeightForWidth());
        twissBtn->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(twissBtn, 4, 0, 1, 2);

        layoutWidget4 = new QWidget(tab);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(390, 10, 289, 419));
        verticalLayout_8 = new QVBoxLayout(layoutWidget4);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_2);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 0, 0, 1, 2);

        archCb = new QComboBox(groupBox_2);
        archCb->setObjectName(QStringLiteral("archCb"));

        gridLayout->addWidget(archCb, 0, 2, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 1, 0, 1, 2);

        scModelCb = new QComboBox(groupBox_2);
        scModelCb->setObjectName(QStringLiteral("scModelCb"));

        gridLayout->addWidget(scModelCb, 1, 2, 1, 1);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 2, 0, 1, 1);

        pushCb = new QComboBox(groupBox_2);
        pushCb->setObjectName(QStringLiteral("pushCb"));

        gridLayout->addWidget(pushCb, 2, 1, 1, 2);


        horizontalLayout_6->addLayout(gridLayout);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_7->addWidget(label_17);

        stepCycleEdit = new QLineEdit(groupBox_2);
        stepCycleEdit->setObjectName(QStringLiteral("stepCycleEdit"));

        verticalLayout_7->addWidget(stepCycleEdit);

        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_7->addWidget(label_22);

        maxStepNumEdit = new QLineEdit(groupBox_2);
        maxStepNumEdit->setObjectName(QStringLiteral("maxStepNumEdit"));

        verticalLayout_7->addWidget(maxStepNumEdit);


        horizontalLayout_6->addLayout(verticalLayout_7);


        verticalLayout_8->addWidget(groupBox_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_12 = new QLabel(layoutWidget4);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_5->addWidget(label_12);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        dataFileEdit = new QLineEdit(layoutWidget4);
        dataFileEdit->setObjectName(QStringLiteral("dataFileEdit"));

        horizontalLayout_7->addWidget(dataFileEdit);

        dataOpenBtn = new QPushButton(layoutWidget4);
        dataOpenBtn->setObjectName(QStringLiteral("dataOpenBtn"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/open.png"), QSize(), QIcon::Selected, QIcon::On);
        dataOpenBtn->setIcon(icon3);
        dataOpenBtn->setIconSize(QSize(16, 16));

        horizontalLayout_7->addWidget(dataOpenBtn);

        structSaveBtn = new QPushButton(layoutWidget4);
        structSaveBtn->setObjectName(QStringLiteral("structSaveBtn"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/save.png"), QSize(), QIcon::Selected, QIcon::On);
        structSaveBtn->setIcon(icon4);

        horizontalLayout_7->addWidget(structSaveBtn);

        dataNewBtn = new QPushButton(layoutWidget4);
        dataNewBtn->setObjectName(QStringLiteral("dataNewBtn"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/new.png"), QSize(), QIcon::Selected, QIcon::On);
        dataNewBtn->setIcon(icon5);
        dataNewBtn->setIconSize(QSize(16, 16));

        horizontalLayout_7->addWidget(dataNewBtn);


        verticalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout_8->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_13 = new QLabel(layoutWidget4);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_6->addWidget(label_13);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        resultDirEdit = new QLineEdit(layoutWidget4);
        resultDirEdit->setObjectName(QStringLiteral("resultDirEdit"));

        horizontalLayout_8->addWidget(resultDirEdit);

        resultOpenBtn = new QPushButton(layoutWidget4);
        resultOpenBtn->setObjectName(QStringLiteral("resultOpenBtn"));
        resultOpenBtn->setIcon(icon3);
        resultOpenBtn->setIconSize(QSize(24, 24));

        horizontalLayout_8->addWidget(resultOpenBtn);


        verticalLayout_6->addLayout(horizontalLayout_8);


        verticalLayout_8->addLayout(verticalLayout_6);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_3 = new QGroupBox(layoutWidget4);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_4->addWidget(label_18, 0, 0, 1, 1);

        dimCb = new QComboBox(groupBox_3);
        dimCb->setObjectName(QStringLiteral("dimCb"));

        gridLayout_4->addWidget(dimCb, 0, 1, 1, 1);

        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_19, 1, 0, 2, 1);

        dimXEdit = new QLineEdit(groupBox_3);
        dimXEdit->setObjectName(QStringLiteral("dimXEdit"));

        gridLayout_4->addWidget(dimXEdit, 1, 1, 1, 1);

        dimYEdit = new QLineEdit(groupBox_3);
        dimYEdit->setObjectName(QStringLiteral("dimYEdit"));

        gridLayout_4->addWidget(dimYEdit, 2, 1, 2, 1);

        dimZEdit = new QLineEdit(groupBox_3);
        dimZEdit->setObjectName(QStringLiteral("dimZEdit"));

        gridLayout_4->addWidget(dimZEdit, 4, 1, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_20, 3, 0, 1, 1);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_21, 4, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_3, 0, 0, 2, 1);

        groupBox_4 = new QGroupBox(layoutWidget4);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_6 = new QGridLayout(groupBox_4);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_6->addWidget(label_23, 0, 0, 1, 2);

        transCb = new QComboBox(groupBox_4);
        transCb->setObjectName(QStringLiteral("transCb"));

        gridLayout_6->addWidget(transCb, 0, 2, 1, 1);

        label_24 = new QLabel(groupBox_4);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_6->addWidget(label_24, 1, 0, 1, 1);

        longCb = new QComboBox(groupBox_4);
        longCb->setObjectName(QStringLiteral("longCb"));

        gridLayout_6->addWidget(longCb, 1, 1, 1, 2);


        gridLayout_7->addWidget(groupBox_4, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 1, 1, 1, 1);


        verticalLayout_8->addLayout(gridLayout_7);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout_5->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(emitXEdit);
        label_3->setBuddy(emitYEdit);
        label_4->setBuddy(emitZEdit);
        label_5->setBuddy(chargeEdit);
        label_6->setBuddy(massEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        saveAction->setText(QApplication::translate("MainWindow", "&Save", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        saveAction->setStatusTip(QApplication::translate("MainWindow", "Save a file", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        saveAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        openAction->setText(QApplication::translate("MainWindow", "&Open", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        openAction->setStatusTip(QApplication::translate("MainWindow", "Open an existing file", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        openAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        newAction->setText(QApplication::translate("MainWindow", "&New", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        newAction->setStatusTip(QApplication::translate("MainWindow", "Create a new file", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        newAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        saveAsAction->setText(QApplication::translate("MainWindow", "Save &As", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        saveAsAction->setToolTip(QApplication::translate("MainWindow", "Save the project under a new name", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        exitAction->setText(QApplication::translate("MainWindow", "E&xit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        exitAction->setToolTip(QApplication::translate("MainWindow", "Exit the application", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        exitAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        groupBox->setTitle(QApplication::translate("MainWindow", "Input Params", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Norm. rms. emit. (\317\200.mm.mrad)", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Emit. XXp", Q_NULLPTR));
        emitXEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        emitXEdit->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Emit. YYp", Q_NULLPTR));
        emitYEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        emitYEdit->setPlaceholderText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Emit. ZZp", Q_NULLPTR));
        emitZEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        emitZEdit->setPlaceholderText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Particle properties", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Q", Q_NULLPTR));
        chargeEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "m", Q_NULLPTR));
        massEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Current (mA)", Q_NULLPTR));
        currentEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Kinetic Energy (MeV)", Q_NULLPTR));
        kineticEnergyEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Nbr of particle", Q_NULLPTR));
        nbrOfParticleEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Bunch Freq. (MHz)", Q_NULLPTR));
        freqEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        twissBtn->setText(QApplication::translate("MainWindow", "Twiss Parameters", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Multiparticle", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Architeture", Q_NULLPTR));
        archCb->clear();
        archCb->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "SP", Q_NULLPTR)
         << QApplication::translate("MainWindow", "MP", Q_NULLPTR)
        );
        archCb->setCurrentText(QApplication::translate("MainWindow", "SP", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "SC Model", Q_NULLPTR));
        scModelCb->clear();
        scModelCb->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "PIC", Q_NULLPTR)
         << QApplication::translate("MainWindow", "P2P", Q_NULLPTR)
        );
        label_16->setText(QApplication::translate("MainWindow", "Pusher", Q_NULLPTR));
        pushCb->clear();
        pushCb->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Leap Frog", Q_NULLPTR)
         << QApplication::translate("MainWindow", "RK4", Q_NULLPTR)
        );
        label_17->setText(QApplication::translate("MainWindow", "Step per cycle", Q_NULLPTR));
        stepCycleEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "Max Step Num", Q_NULLPTR));
        maxStepNumEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Open or Create Data file", Q_NULLPTR));
        dataFileEdit->setText(QString());
        dataOpenBtn->setText(QString());
        structSaveBtn->setText(QString());
        dataNewBtn->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "Calculation Directory", Q_NULLPTR));
        resultDirEdit->setText(QString());
        resultOpenBtn->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Mesh", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Dim", Q_NULLPTR));
        dimCb->clear();
        dimCb->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3", Q_NULLPTR)
        );
        label_19->setText(QApplication::translate("MainWindow", "x", Q_NULLPTR));
        dimXEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        dimYEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        dimZEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "y", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "z", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Distribution", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "Trans.", Q_NULLPTR));
        transCb->clear();
        transCb->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "KV", Q_NULLPTR)
         << QApplication::translate("MainWindow", "WB", Q_NULLPTR)
         << QApplication::translate("MainWindow", "PB", Q_NULLPTR)
         << QApplication::translate("MainWindow", "GS", Q_NULLPTR)
        );
        label_24->setText(QApplication::translate("MainWindow", "Long.", Q_NULLPTR));
        longCb->clear();
        longCb->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "KV", Q_NULLPTR)
         << QApplication::translate("MainWindow", "WB", Q_NULLPTR)
         << QApplication::translate("MainWindow", "PB", Q_NULLPTR)
         << QApplication::translate("MainWindow", "GS", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Main", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Output", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Charts", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
