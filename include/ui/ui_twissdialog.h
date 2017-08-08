/********************************************************************************
** Form generated from reading UI file 'twissdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWISSDIALOG_H
#define UI_TWISSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_TwissDialog
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *alphaXEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *betaXEdit;
    QLabel *label_7;
    QLabel *label_5;
    QLineEdit *alphaYEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QLineEdit *betaYEdit;
    QLabel *label_9;
    QLabel *label_4;
    QLineEdit *alphaZEdit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QLineEdit *betaZEdit;
    QLabel *label_8;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QLineEdit *dxEdit;
    QLabel *label_11;
    QLabel *label_14;
    QLineEdit *dxPrimeEdit;
    QLabel *label_15;
    QLabel *label_20;
    QLineEdit *dyEdit;
    QLabel *label_21;
    QLabel *label_18;
    QLineEdit *dyPrimeEdit;
    QLabel *label_19;
    QLabel *label_16;
    QLineEdit *dzEdit;
    QLabel *label_17;
    QLabel *label_12;
    QLineEdit *dzPrimeEdit;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TwissDialog)
    {
        if (TwissDialog->objectName().isEmpty())
            TwissDialog->setObjectName(QStringLiteral("TwissDialog"));
        TwissDialog->resize(496, 347);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TwissDialog->sizePolicy().hasHeightForWidth());
        TwissDialog->setSizePolicy(sizePolicy);
        TwissDialog->setMinimumSize(QSize(496, 347));
        TwissDialog->setMaximumSize(QSize(496, 347));
        gridLayout_2 = new QGridLayout(TwissDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(TwissDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        alphaXEdit = new QLineEdit(groupBox);
        alphaXEdit->setObjectName(QStringLiteral("alphaXEdit"));

        gridLayout->addWidget(alphaXEdit, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(52, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        betaXEdit = new QLineEdit(groupBox);
        betaXEdit->setObjectName(QStringLiteral("betaXEdit"));

        gridLayout->addWidget(betaXEdit, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        alphaYEdit = new QLineEdit(groupBox);
        alphaYEdit->setObjectName(QStringLiteral("alphaYEdit"));

        gridLayout->addWidget(alphaYEdit, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(52, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        betaYEdit = new QLineEdit(groupBox);
        betaYEdit->setObjectName(QStringLiteral("betaYEdit"));

        gridLayout->addWidget(betaYEdit, 3, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 3, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        alphaZEdit = new QLineEdit(groupBox);
        alphaZEdit->setObjectName(QStringLiteral("alphaZEdit"));

        gridLayout->addWidget(alphaZEdit, 4, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(52, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        betaZEdit = new QLineEdit(groupBox);
        betaZEdit->setObjectName(QStringLiteral("betaZEdit"));

        gridLayout->addWidget(betaZEdit, 5, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 5, 2, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(TwissDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        dxEdit = new QLineEdit(groupBox_2);
        dxEdit->setObjectName(QStringLiteral("dxEdit"));

        gridLayout_3->addWidget(dxEdit, 0, 1, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_3->addWidget(label_11, 0, 2, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_3->addWidget(label_14, 1, 0, 1, 1);

        dxPrimeEdit = new QLineEdit(groupBox_2);
        dxPrimeEdit->setObjectName(QStringLiteral("dxPrimeEdit"));

        gridLayout_3->addWidget(dxPrimeEdit, 1, 1, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_3->addWidget(label_15, 1, 2, 1, 1);

        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_3->addWidget(label_20, 2, 0, 1, 1);

        dyEdit = new QLineEdit(groupBox_2);
        dyEdit->setObjectName(QStringLiteral("dyEdit"));

        gridLayout_3->addWidget(dyEdit, 2, 1, 1, 1);

        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_3->addWidget(label_21, 2, 2, 1, 1);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_3->addWidget(label_18, 3, 0, 1, 1);

        dyPrimeEdit = new QLineEdit(groupBox_2);
        dyPrimeEdit->setObjectName(QStringLiteral("dyPrimeEdit"));

        gridLayout_3->addWidget(dyPrimeEdit, 3, 1, 1, 1);

        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_3->addWidget(label_19, 3, 2, 1, 1);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_3->addWidget(label_16, 4, 0, 1, 1);

        dzEdit = new QLineEdit(groupBox_2);
        dzEdit->setObjectName(QStringLiteral("dzEdit"));

        gridLayout_3->addWidget(dzEdit, 4, 1, 1, 1);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_3->addWidget(label_17, 4, 2, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 5, 0, 1, 1);

        dzPrimeEdit = new QLineEdit(groupBox_2);
        dzPrimeEdit->setObjectName(QStringLiteral("dzPrimeEdit"));

        gridLayout_3->addWidget(dzPrimeEdit, 5, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 5, 2, 1, 1);


        horizontalLayout->addWidget(groupBox_2);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(239, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(TwissDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 1, 1, 1);


        retranslateUi(TwissDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TwissDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TwissDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TwissDialog);
    } // setupUi

    void retranslateUi(QDialog *TwissDialog)
    {
        TwissDialog->setWindowTitle(QApplication::translate("TwissDialog", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TwissDialog", "Twiss parameters", Q_NULLPTR));
        label->setText(QApplication::translate("TwissDialog", "AlphaX", Q_NULLPTR));
        alphaXEdit->setText(QApplication::translate("TwissDialog", "0", Q_NULLPTR));
        alphaXEdit->setPlaceholderText(QString());
        label_2->setText(QApplication::translate("TwissDialog", "BetaX", Q_NULLPTR));
        betaXEdit->setText(QApplication::translate("TwissDialog", "0", Q_NULLPTR));
        betaXEdit->setPlaceholderText(QString());
        label_7->setText(QApplication::translate("TwissDialog", "m/pi.rad", Q_NULLPTR));
        label_5->setText(QApplication::translate("TwissDialog", "AlphaY", Q_NULLPTR));
        alphaYEdit->setText(QApplication::translate("TwissDialog", "0", Q_NULLPTR));
        alphaYEdit->setPlaceholderText(QString());
        label_6->setText(QApplication::translate("TwissDialog", "BetaY", Q_NULLPTR));
        betaYEdit->setText(QApplication::translate("TwissDialog", "0", Q_NULLPTR));
        betaYEdit->setPlaceholderText(QString());
        label_9->setText(QApplication::translate("TwissDialog", "m/pi.rad", Q_NULLPTR));
        label_4->setText(QApplication::translate("TwissDialog", "AlphaZ", Q_NULLPTR));
        alphaZEdit->setText(QApplication::translate("TwissDialog", "0", Q_NULLPTR));
        alphaZEdit->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("TwissDialog", "BetaZ", Q_NULLPTR));
        betaZEdit->setText(QApplication::translate("TwissDialog", "0", Q_NULLPTR));
        betaZEdit->setPlaceholderText(QString());
        label_8->setText(QApplication::translate("TwissDialog", "m/pi.rad", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("TwissDialog", "Beam Center", Q_NULLPTR));
        label_10->setText(QApplication::translate("TwissDialog", "Dx", Q_NULLPTR));
        dxEdit->setText(QApplication::translate("TwissDialog", "0", Q_NULLPTR));
        dxEdit->setPlaceholderText(QString());
        label_11->setText(QApplication::translate("TwissDialog", "m", Q_NULLPTR));
        label_14->setText(QApplication::translate("TwissDialog", "Dx'", Q_NULLPTR));
        dxPrimeEdit->setText(QApplication::translate("TwissDialog", "0", Q_NULLPTR));
        dxPrimeEdit->setPlaceholderText(QString());
        label_15->setText(QApplication::translate("TwissDialog", "rad", Q_NULLPTR));
        label_20->setText(QApplication::translate("TwissDialog", "Dy", Q_NULLPTR));
        dyEdit->setText(QApplication::translate("TwissDialog", "0", Q_NULLPTR));
        dyEdit->setPlaceholderText(QString());
        label_21->setText(QApplication::translate("TwissDialog", "m", Q_NULLPTR));
        label_18->setText(QApplication::translate("TwissDialog", "Dy'", Q_NULLPTR));
        dyPrimeEdit->setText(QApplication::translate("TwissDialog", "0", Q_NULLPTR));
        dyPrimeEdit->setPlaceholderText(QString());
        label_19->setText(QApplication::translate("TwissDialog", "rad", Q_NULLPTR));
        label_16->setText(QApplication::translate("TwissDialog", "Dz", Q_NULLPTR));
        dzEdit->setText(QApplication::translate("TwissDialog", "0", Q_NULLPTR));
        dzEdit->setPlaceholderText(QString());
        label_17->setText(QApplication::translate("TwissDialog", "m", Q_NULLPTR));
        label_12->setText(QApplication::translate("TwissDialog", "Dz'", Q_NULLPTR));
        dzPrimeEdit->setText(QApplication::translate("TwissDialog", "0", Q_NULLPTR));
        dzPrimeEdit->setPlaceholderText(QString());
        label_13->setText(QApplication::translate("TwissDialog", "rad", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TwissDialog: public Ui_TwissDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWISSDIALOG_H
