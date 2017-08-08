#include <QtWidgets>
#include "mainwindow.h"
#include "twissdialog.h"
#include "Beam.h"
#include "Lattice.h"
#include "MethodMP.h"
#include "MethodMT.h"
#include "Initial.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    setupEditor();

    thread = new WorkThread();
    
    thread->setMaster(this);

    createActions();
    createMenus();

    readSettings();

    setCurrentFile("");

    resetBeamParams();

    initMap();

    connect(twissBtn, SIGNAL(clicked()), this, SLOT(setTwissParams()));
    connect(dataOpenBtn, SIGNAL(clicked()), this, SLOT(openStructureFile()));
}

void MainWindow::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    editor = new QTextEdit;
    editor->setFont(font);
    editor->setLineWrapMode(QTextEdit::NoWrap);

    highlighter = new Highlighter(editor->document());

    tabWidget->insertTab(2, editor, "Edit");
}

void MainWindow::initMap()
{
    archMap[0] = "MT";
    archMap[1] = "MP";
    scModelMap[0] = "PIC";
    scModelMap[1] = "PTP";
    pusherMap[0] = "leapfrog";
    pusherMap[1] = "rk4";
    disMap[0] = "KV";
    disMap[1] = "WB";
    disMap[2] = "PB";
    disMap[3] = "GS";
}
void MainWindow::setCurrentFile(const QString& fileName)
{
    curProjectFile = fileName;
    setWindowModified(false);

    QString shownName = tr("Untitled");
    if (!curProjectFile.isEmpty()) {
        shownName = strippedName(curProjectFile);
        recentFiles.removeAll(curProjectFile);
        recentFiles.prepend(curProjectFile);
        updateRecentFileActions();
    }

    setWindowTitle(tr("%1[*] - %2").arg(shownName)
                                   .arg(tr("Project")));
}

void MainWindow::updateRecentFileActions()
{
    QMutableStringListIterator i(recentFiles);
    while (i.hasNext()) {
        if (!QFile::exists(i.next()))
            i.remove();
    }

    for (int j = 0; j < MaxRecentFiles; ++j) {
        if (j < recentFiles.count()) {
            QString text = tr("&%1 %2")
                           .arg(j + 1)
                           .arg(strippedName(recentFiles[j]));
            recentFileActions[j]->setText(text);
            recentFileActions[j]->setData(recentFiles[j]);
            recentFileActions[j]->setVisible(true);
        } else {
            recentFileActions[j]->setVisible(false);
        }
    }
    separatorAction->setVisible(!recentFiles.isEmpty());
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    separatorAction = fileMenu->addSeparator();
    for (int i = 0; i < MaxRecentFiles; ++i)
        fileMenu->addAction(recentFileActions[i]);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    menuBar()->addSeparator();

    processMenu = menuBar()->addMenu(tr("&Process"));
    processMenu->addAction(runAction);
    processMenu->addAction(breakAction);
    processMenu->addAction(stopAction);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void MainWindow::createActions()
{
    newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/images/new.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(tr("&Open..."), this);
    openAction->setIcon(QIcon(":/images/open.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/images/save.png"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the file to disk"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAction = new QAction(tr("Save &As..."), this);
    saveAsAction->setStatusTip(tr("Save the file under a new "
                                  "name"));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

    for (int i = 0; i < MaxRecentFiles; ++i) {
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
        connect(recentFileActions[i], SIGNAL(triggered()),
                this, SLOT(openRecentFile()));
    }

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    runAction = new QAction(tr("&Run"), this);
    runAction->setShortcut(tr("Ctrl+R"));
    runAction->setStatusTip(tr("Run process"));
    connect(runAction, SIGNAL(triggered()), thread, SLOT(start()));
    //connect(runAction, SIGNAL(triggered()), this, SLOT(runProcess()));
    breakAction = new QAction(tr("&Break"), this);
    breakAction->setCheckable(true);
    breakAction->setChecked(thread->getPause());
    breakAction->setShortcut(tr("Ctrl+B"));
    breakAction->setStatusTip(tr("Beak process"));
    connect(breakAction, SIGNAL(toggled(bool)), this, SLOT(breakProcess(bool)));
    stopAction = new QAction(tr("&Stop"), this);
    stopAction->setShortcut(tr("Ctrl+C"));
    stopAction->setStatusTip(tr("Stop process"));
    connect(stopAction, SIGNAL(triggered()), this, SLOT(stopProcess()));

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("Show the application's About box"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}


void MainWindow::runProcess()
{
    //updateBeamParams();
    //Initial initialize;
    //Beam beam;
    //initialize.InitParticle(beam, *this);
    //Lattice lattice;
    //initialize.InitLattice(lattice);

    //cout << initialize.GetMethod() << " method" << endl;

    //if(initialize.GetMethod()=="MP")
    //{
    //    Mesh mesh;
    //    initialize.InitMesh(mesh);

    //    MethodMP MPrun;
    //    initialize.InitMethodMP(MPrun);

    //    if (initialize.GetInternalFieldMethodethod()=="PIC")
    //    {
    //        MPrun.Push(lattice,mesh,beam, paused, toResume);
    //    }
    //    else if (initialize.GetInternalFieldMethodethod()=="PTP")
    //    {
    //        MPrun.Push(lattice,mesh,beam, paused, toResume);
    //    }
    //}

    //else if( initialize.GetMethod()=="MT")
    //{
    //    MethodMT    MTrun;
    //    MTrun.Push(beam,lattice);
    //}
    //cout<<"Complete!"<<endl;
}

void MainWindow::stopProcess()
{
}

void MainWindow::breakProcess(bool checked)
{
    thread->breakProcess(checked);
}

bool MainWindow::save()
{
    if (curProjectFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curProjectFile);
    }
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Project"), "untitled.ini",
            tr("Project files (*.ini)"));
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

void MainWindow::openStructureFile()
{
    if (okToContinue()) {
        QString fileName = QFileDialog::getOpenFileName(this,
                tr("Open Structure data file"), ".",
                tr("Structure files (*.dat)"));
        if (!fileName.isEmpty()) {
            loadStructureFile(fileName);
        }
    }
}

void MainWindow::open()
{
    if (okToContinue()) {
        QString fileName = QFileDialog::getOpenFileName(this,
                tr("Open Project"), ".",
                tr("Project files (*.ini)"));
        if (!fileName.isEmpty()) {
            loadFile(fileName);
        }
    }

}

bool MainWindow::loadStructureFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("Structure"),
                tr("Cannot read file %1:\n%2.")
                .arg(file.fileName())
                .arg(file.errorString()));
        return false;
    }

    QTextStream in(&file);

    QString text;
    text = in.readAll();
    editor->setText(text);
    return true;
}

bool MainWindow::loadFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("Project"),
                tr("Cannot read file %1:\n%2.")
                .arg(file.fileName())
                .arg(file.errorString()));
        return false;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_9);

    quint32 magic;
    in >> magic;
    if (magic != MagicNumber) {
        QMessageBox::warning(this, tr("Project"),
                tr("The file is not a project file."));
        return false;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);

    in >> emitX >> emitY >> emitZ >> chargeNum >> massNum >> current
        >> kEnergy >> particleNum >> freq >> stepNumPerCycle 
        >> maxStepNum >> meshDim >> xDim >> yDim >> zDim
        >> architect >> scModel >> pusher >> transDis >> longDis
        >> dx >> dxPrime >> dy >> dyPrime >> dz >> dzPrime
        >> alphaX >> betaX >> alphaY >> betaY >> alphaZ >> betaZ
        >> curDataFile >> resultDir;

    emitXEdit->setText(QString::number(emitX));
    emitYEdit->setText(QString::number(emitY));
    emitZEdit->setText(QString::number(emitZ));
    chargeEdit->setText(QString::number(chargeNum));
    massEdit->setText(QString::number(massNum));
    currentEdit->setText(QString::number(current));
    kineticEnergyEdit->setText(QString::number(kEnergy));
    nbrOfParticleEdit->setText(QString::number(particleNum));
    freqEdit->setText(QString::number(freq));
    stepCycleEdit->setText(QString::number(stepNumPerCycle));
    maxStepNumEdit->setText(QString::number(maxStepNum));
    dimCb->setCurrentIndex(meshDim);
    dimXEdit->setText(QString::number(xDim));
    dimYEdit->setText(QString::number(yDim));
    dimZEdit->setText(QString::number(zDim));
    archCb->setCurrentIndex(architect);
    scModelCb->setCurrentIndex(scModel);
    pushCb->setCurrentIndex(pusher);
    transCb->setCurrentIndex(transDis);
    longCb->setCurrentIndex(longDis);
    dataFileEdit->setText(curDataFile);
    resultDirEdit->setText(resultDir);
    QApplication::restoreOverrideCursor();
    return true;
}

//void MainWindow::initBeam(Beam& beam)
//{
//
//
//}

void MainWindow::newFile()
{
    if (okToContinue()) {
        resetGUI();
        resetBeamParams();
        setCurrentFile("");
    }
}

bool MainWindow::okToContinue()
{
    return true;
}

void MainWindow::resetGUI()
{
    emitXEdit->setText("0");
    emitYEdit->setText("0");
    emitZEdit->setText("0");
    chargeEdit->setText("0");
    massEdit->setText("0");
    currentEdit->setText("0");
    kineticEnergyEdit->setText("0");
    nbrOfParticleEdit->setText("0");
    freqEdit->setText("0");
    stepCycleEdit->setText("0");
    maxStepNumEdit->setText("0");
    dimXEdit->setText("0");
    dimYEdit->setText("0");
    dimZEdit->setText("0");
    dataFileEdit->setText("");
    resultDirEdit->setText("");
    archCb->setCurrentIndex(0);
    scModelCb->setCurrentIndex(0);
    pushCb->setCurrentIndex(0);
    dimCb->setCurrentIndex(0);
    transCb->setCurrentIndex(0);
    longCb->setCurrentIndex(0);
}

void MainWindow::resetBeamParams()
{
    emitX = 0;
    emitY = 0;
    emitZ = 0;
    chargeNum = 0;
    massNum = 0;
    current = 0;
    kEnergy = 0;
    particleNum = 0;
    freq = 0;
    xDim = 0;
    yDim = 0;
    zDim = 0;
    stepNumPerCycle = 0;
    maxStepNum = 0;
    architect = 0;
    scModel = 0;
    pusher = 0;
    transDis = 0;
    longDis = 0;
    alphaX = 0;
    betaX = 0;
    alphaY = 0;
    betaY = 0;
    alphaZ = 0;
    betaZ = 0;
    dx = 0;
    dxPrime = 0;
    dy = 0;
    dyPrime = 0;
    dz = 0;
    dzPrime = 0;
}

void MainWindow::openRecentFile()
{
}

bool MainWindow::saveFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, tr("Project"),
                tr("Cannot write file %1:\n%2.")
                .arg(file.fileName())
                .arg(file.errorString()));
        return false;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_9);
    out << quint32(MagicNumber);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    updateBeamParams();
    
    out << emitX << emitY << emitZ << chargeNum << massNum << current
        << kEnergy << particleNum << freq << stepNumPerCycle 
        << maxStepNum << meshDim << xDim << yDim << zDim
        << architect << scModel << pusher << transDis << longDis
        << dx << dxPrime << dy << dyPrime << dz << dzPrime
        << alphaX << betaX << alphaY << betaY << alphaZ << betaZ
        << curDataFile << resultDir;
    QApplication::restoreOverrideCursor();
    return true;
}

void MainWindow::updateBeamParams()
{
    emitX = emitXEdit->text().toDouble();
    emitY = emitYEdit->text().toDouble();
    emitZ = emitZEdit->text().toDouble();
    chargeNum = chargeEdit->text().toInt();
    massNum = massEdit->text().toInt();
    current = currentEdit->text().toDouble();
    kEnergy = kineticEnergyEdit->text().toDouble();
    particleNum = nbrOfParticleEdit->text().toDouble();
    freq = freqEdit->text().toDouble();
    stepNumPerCycle = stepCycleEdit->text().toInt();
    maxStepNum = maxStepNumEdit->text().toInt();
    meshDim = dimCb->currentIndex();
    xDim = dimXEdit->text().toInt();
    yDim = dimYEdit->text().toInt();
    zDim = dimZEdit->text().toInt();
    architect = archCb->currentIndex();
    scModel = scModelCb->currentIndex();
    pusher = pushCb->currentIndex();
    transDis = transCb->currentIndex();
    longDis = longCb->currentIndex();
    curDataFile = dataFileEdit->text();
    resultDir = resultDirEdit->text();
}

void MainWindow::setTwissParams()
{
    TwissDialog twissDialog(this);
    twissDialog.alphaXEdit->setText(QString::number(alphaX));
    twissDialog.betaXEdit->setText(QString::number(betaX));
    twissDialog.alphaYEdit->setText(QString::number(alphaY));
    twissDialog.betaYEdit->setText(QString::number(betaY));
    twissDialog.alphaZEdit->setText(QString::number(alphaZ));
    twissDialog.betaZEdit->setText(QString::number(betaZ));
    twissDialog.dxEdit->setText(QString::number(dx));
    twissDialog.dxPrimeEdit->setText(QString::number(dxPrime));
    twissDialog.dyEdit->setText(QString::number(dy));
    twissDialog.dyPrimeEdit->setText(QString::number(dyPrime));
    twissDialog.dzEdit->setText(QString::number(dz));
    twissDialog.dzPrimeEdit->setText(QString::number(dzPrime));
    if (twissDialog.exec()) {
        alphaX = twissDialog.alphaXEdit->text().toDouble();
        betaX = twissDialog.betaXEdit->text().toDouble();
        alphaY = twissDialog.alphaYEdit->text().toDouble();
        betaY = twissDialog.betaYEdit->text().toDouble();
        alphaZ = twissDialog.alphaZEdit->text().toDouble();
        betaZ = twissDialog.betaZEdit->text().toDouble();
        dx = twissDialog.dxEdit->text().toDouble();
        dxPrime = twissDialog.dxPrimeEdit->text().toDouble();
        dy = twissDialog.dyEdit->text().toDouble();
        dyPrime = twissDialog.dyPrimeEdit->text().toDouble();
        dz = twissDialog.dzEdit->text().toDouble();
        dzPrime = twissDialog.dzPrimeEdit->text().toDouble();
    }
}

void MainWindow::readSettings()
{
    QSettings settings("Software Inc.", "PTOPO");

    restoreGeometry(settings.value("geometry").toByteArray());

    recentFiles = settings.value("recentFiles").toStringList();
    updateRecentFileActions();
}

QString MainWindow::strippedName(const QString& fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

void WorkThread::run()
{
    master->updateBeamParams();
    Initial initialize;
    Beam beam;
    initialize.InitParticle(beam, *master);
    Lattice lattice;
    initialize.InitLattice(lattice);

    cout << initialize.GetMethod() << " method" << endl;

    if(initialize.GetMethod()=="MP")
    {
        Mesh mesh;
        initialize.InitMesh(mesh);

        MethodMP MPrun;
        initialize.InitMethodMP(MPrun);

        if (initialize.GetInternalFieldMethodethod()=="PIC")
        {
            MPrun.Push(lattice,mesh,beam, paused, toResume, mutex);
        }
        else if (initialize.GetInternalFieldMethodethod()=="PTP")
        {
            MPrun.Push(lattice,mesh,beam, paused, toResume, mutex);
        }
    }

    else if( initialize.GetMethod()=="MT")
    {
        MethodMT    MTrun;
        MTrun.Push(beam,lattice);
    }
    cout<<"Complete!"<<endl;
}
    
WorkThread::WorkThread(): paused(false)
{
}

void WorkThread::setMaster(MainWindow* mainwindow)
{
    master = mainwindow;
}

void WorkThread::breakProcess(bool checked)
{
    if (checked) {
        paused = true;
    } else {
        paused = false;
        toResume.wakeOne();
    }
}

bool WorkThread::getPause()
{
    return paused;
}
