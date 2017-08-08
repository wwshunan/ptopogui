#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include <string>
#include "ui_mainwindow.h"
#include "twissdialog.h"
#include "highlighter.h"

QT_BEGIN_NAMESPACE
class QAction;
class Initial;
class WorkThread;
class QTextEdit;
QT_END_NAMESPACE


class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent=0);
    void updateBeamParams();
    friend Initial;

//protected:
//    void closeEvent(QCloseEvent *event);
//
private slots:
    void open();
    void newFile();
    bool save();
    bool saveAs();
    void setTwissParams();
    void openRecentFile();
    void runProcess();
    void breakProcess(bool checked);
    void stopProcess();
    void openStructureFile();
//private:
//    void createActions();
//    void createMenus();
private:
    void readSettings();
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    void createMenus();
    void createActions();
    void resetBeamParams();
    void resetGUI();
    bool okToContinue();
    bool saveFile(const QString& fileName);
    bool loadFile(const QString& fileName);
    void initMap();
    void setupEditor();
    bool loadStructureFile(const QString& fileName);
    QString strippedName(const QString& fullFileName);

    WorkThread* thread;
    QStringList recentFiles;
    QString curProjectFile;
    QString curDataFile;
    QString resultDir;
    QTextEdit* editor;
    Highlighter* highlighter;
    enum { MagicNumber = 0x7F51C883, MaxRecentFiles = 5 };

    QMenu *fileMenu;
    QMenu *processMenu;
    QMenu *helpMenu;
    QAction* recentFileActions[MaxRecentFiles];
    QAction* separatorAction;
    QAction* aboutAction;
    QAction* aboutQtAction;
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;
    QAction *runAction;
    QAction *stopAction;
    QAction *breakAction;
    double emitX, emitY, emitZ, current, kEnergy, particleNum,
           freq, alphaX, betaX, alphaY, betaY, alphaZ, betaZ,
           dx, dxPrime, dy, dyPrime, dz, dzPrime, chargeNum, massNum;
    int xDim, yDim, zDim, stepNumPerCycle, maxStepNum, architect,
        scModel, pusher, transDis, longDis, meshDim;
    QMap<int, std::string> archMap, scModelMap, pusherMap, disMap;
};

class WorkThread : public QThread
{
    Q_OBJECT

public:
    WorkThread();
    void setMaster(MainWindow* mainwindow);
    void breakProcess(bool checked);
    bool getPause();
signals:
    void simulateStarted(const QString& message);
    void simulateDone();


protected:
    void run();

private:
    QWaitCondition toResume;
    QMutex mutex;
    MainWindow* master;
    bool paused;
};
#endif
