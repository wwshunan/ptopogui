#ifndef INPUTBEAM_H
#define INPUTBEAM_H

#include <QDialog>
#include "ui_twissdialog.h"

class TwissDialog : public QDialog, public Ui::TwissDialog
{
    Q_OBJECT

public:
    TwissDialog(QWidget* parent = 0);
};

#endif
