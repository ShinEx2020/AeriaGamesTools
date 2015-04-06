/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "AeriaToolMain.hpp"

AeriaToolMain::AeriaToolMain(QWidget *parent) : QMainWindow(parent)
{
    bar = new QProgressBar;
        bar->hide();
        bar->setFixedSize(100, 25);
        bar->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        bar->setStyleSheet("QProgressBar{background: #aaa; border-radius: 12px; border: 4px solid #aaa; color: black; font-weight: bold; text-align: center; margin-right: 4px;}"
                           "QProgressBar::chunk{margin:3px; background-color: #d33;}");


    qss = new QFile(":/qss/style");
        qss->open(QIODevice::ReadOnly | QIODevice::Text);

    qApp->setStyleSheet(qss->readAll());

//---------------------------------------------------------
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(520, 280);
    setWindowTitle("AERIA GAMES TOOLS");
    setContentsMargins(-17, 0, 0, 0);

    createButtons();

    QHBoxLayout *barLayout = new QHBoxLayout;
        barLayout->addWidget(titleButton);
        barLayout->addWidget(minimizeButton, Qt::AlignRight);
        barLayout->addWidget(closeButton, Qt::AlignRight);
        barLayout->setContentsMargins(16, 0, 0, 0);

    QGridLayout *gridLayout = new QGridLayout;
        gridLayout->addWidget(mGrandFantasiaButton, 0, 0);
        gridLayout->addWidget(mEdenEternalButton, 0, 1);
        gridLayout->addWidget(mAuraKingdomButton, 0, 2);
        gridLayout->addWidget(mS4LeagueButton, 1, 0);
        gridLayout->addWidget(mWolfTeamButton, 1, 1);
        gridLayout->addWidget(mShaiyaButton, 1, 2);
        gridLayout->setVerticalSpacing(12);

//----------
    //QBitmap tinyMask(":/mask/mask");

    colapseButton = new QPushButton();
        colapseButton->setIcon(QIcon(":/icons/collapse"));
        colapseButton->setFixedSize(35, 25);
        colapseButton->setObjectName("colapseButton");
        colapseButton->hide();

    localButton = new QPushButton(QCoreApplication::applicationVersion());
        localButton->setIcon(QIcon(":/icons/local"));
        localButton->setFixedSize(60, 25);
        localButton->setObjectName("localButton");
        localButton->hide();

    onlineButton = new QPushButton("...");
        onlineButton->setIcon(QIcon(":/icons/online"));
        onlineButton->setFixedSize(60, 25);
        onlineButton->setObjectName("onlineButton");
        onlineButton->hide();

    vcheckButton = new QPushButton("Connexion...");

    QHBoxLayout *hbox = new QHBoxLayout;
        hbox->addWidget(bar);
        hbox->setContentsMargins(0,0,0,0);

        vcheckButton->setContentsMargins(-10,0,0,0);
        vcheckButton->setLayout(hbox);
        vcheckButton->setFixedSize(100, 25);
        vcheckButton->setObjectName("vcheckButton");
        vcheckButton->hide();

//----------

    QHBoxLayout *buttonsHBox = new QHBoxLayout();
        buttonsHBox->addWidget(infoButton, 0, Qt::AlignLeft);
        buttonsHBox->addWidget(settingsButton, 0, Qt::AlignLeft);
        buttonsHBox->addWidget(updateButton, 1, Qt::AlignLeft);
        //
        buttonsHBox->addWidget(colapseButton, 0, Qt::AlignRight);
        buttonsHBox->addWidget(localButton, 0, Qt::AlignRight);
        buttonsHBox->addWidget(onlineButton, 0, Qt::AlignRight);
        buttonsHBox->addWidget(vcheckButton, 0, Qt::AlignRight);
        buttonsHBox->addWidget(bar, 0, Qt::AlignRight);
        //
        buttonsHBox->setContentsMargins(25,0,5,0);


    m_toolButton = new QPushButton("<\n\nO\nU\nT\nI\nL\nS\n\n<", this);
        m_toolButton->setObjectName("toolsButton");
        m_toolButton->setFixedWidth(25);

    m_tilesHBox = new QHBoxLayout;
        m_tilesHBox->addWidget(m_toolButton);
        m_tilesHBox->addLayout(gridLayout);



    m_toolDialog = new ToolDialog();

    connect(m_toolButton, SIGNAL(clicked()), this, SLOT(openTools()));


    QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addLayout(barLayout);
        mainLayout->addLayout(m_tilesHBox);
        mainLayout->addLayout(buttonsHBox);

    QWidget *mainWidget = new QWidget;
        mainWidget->setLayout(mainLayout);

    createConnections();

    setCentralWidget(mainWidget);

    //------------TEST MASK-----------------

    setMask(QBitmap(":/mask/uimask"));

    //----------------test---------------

    mPathsFile = new QFile(QCoreApplication::applicationDirPath()+"/logs/paths.lst");
        mPathsFile->open(QIODevice::ReadOnly | QIODevice::Text);

    QSettings mPathsSettings(mPathsFile->fileName(), QSettings::IniFormat);
        m_EdenPath = mPathsSettings.value("Paths/EdenEternal").toString();
}

void AeriaToolMain::createButtons()
{
    QBitmap tinyMask(":/mask/mask");
    QSize mButtonsSize(150, 75);

    titleButton = new TPushButton(windowTitle());
        titleButton->setFixedSize(370, 25);
        titleButton->setObjectName("titleButton");
        titleButton->setMask(QBitmap(":/mask/masktitle"));

    minimizeButton = new QPushButton("-");
        minimizeButton->setFixedSize(40, 25);
        minimizeButton->setObjectName("minimizeButton");
        minimizeButton->setMask(tinyMask);

    closeButton = new QPushButton("X");
        closeButton->setFixedSize(40, 25);
        closeButton->setObjectName("closeButton");
        closeButton->setMask(tinyMask);


    mGrandFantasiaButton = new QPushButton();
        mGrandFantasiaButton->setFixedSize(mButtonsSize);
        mGrandFantasiaButton->setIcon(QIcon(":/logos/fanta"));
        mGrandFantasiaButton->setIconSize(mButtonsSize);
        mGrandFantasiaButton->setObjectName("fantaButton");
        mGrandFantasiaButton->setMask(QBitmap(":/mask/maskbig"));

    mEdenEternalButton = new QPushButton();
        mEdenEternalButton->setFixedSize(mButtonsSize);
        mEdenEternalButton->setIcon(QIcon(":/logos/eden"));
        mEdenEternalButton->setIconSize(mButtonsSize);
        mEdenEternalButton->setObjectName("edenButton");
        mEdenEternalButton->setMask(QBitmap(":/mask/maskbig"));

    mAuraKingdomButton = new QPushButton();
        mAuraKingdomButton->setFixedSize(mButtonsSize);
        mAuraKingdomButton->setIcon(QIcon(":/logos/aura"));
        mAuraKingdomButton->setIconSize(mButtonsSize);
        mAuraKingdomButton->setObjectName("auraButton");
        mAuraKingdomButton->setMask(QBitmap(":/mask/maskbig"));

    mWolfTeamButton = new QPushButton();
        mWolfTeamButton->setFixedSize(mButtonsSize);
        mWolfTeamButton->setIcon(QIcon(":/logos/wolf"));
        mWolfTeamButton->setIconSize(mButtonsSize);
        mWolfTeamButton->setObjectName("wolfButton");
        mWolfTeamButton->setMask(QBitmap(":/mask/maskbig"));

    mShaiyaButton = new QPushButton();
        mShaiyaButton->setFixedSize(mButtonsSize);
        mShaiyaButton->setIcon(QIcon(":/logos/shaiya"));
        mShaiyaButton->setIconSize(mButtonsSize);
        mShaiyaButton->setObjectName("shaiyaButton");
        mShaiyaButton->setMask(QBitmap(":/mask/maskbig"));

    mS4LeagueButton = new QPushButton();
        mS4LeagueButton->setFixedSize(mButtonsSize);
        mS4LeagueButton->setIcon(QIcon(":/logos/s4"));
        mS4LeagueButton->setIconSize(mButtonsSize);
        mS4LeagueButton->setObjectName("s4Button");
        mS4LeagueButton->setMask(QBitmap(":/mask/maskbig"));

    settingsButton = new QPushButton();
        settingsButton->setIcon(QIcon(":/icons/settings"));
        settingsButton->setFixedSize(40, 25);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setMask(tinyMask);

    updateButton = new QPushButton();
        updateButton->setIcon(QIcon(":/icons/update"));
        updateButton->setFixedSize(40, 25);
        updateButton->setObjectName("updateButton");
        updateButton->setMask(tinyMask);

    infoButton = new QPushButton();
        infoButton->setIcon(QIcon(":/icons/info"));
        infoButton->setFixedSize(40, 25);
        infoButton->setObjectName("infoButton");
        infoButton->setMask(tinyMask);
}

void AeriaToolMain::createConnections()
{
    connect(minimizeButton, SIGNAL(clicked()), this, SLOT(minimizeTool()));
    connect(closeButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    connect(mEdenEternalButton, SIGNAL(clicked()), this, SLOT(openEdenEternalTool()));

    connect(mGrandFantasiaButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));
    connect(mAuraKingdomButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));
    connect(mWolfTeamButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));
    connect(mShaiyaButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));
    connect(mS4LeagueButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));

    connect(settingsButton, SIGNAL(clicked()), this, SLOT(openSettings()));
    connect(updateButton, SIGNAL(clicked()), this, SLOT(openUpdates()));
    connect(infoButton, SIGNAL(clicked()), this, SLOT(openAbout()));
    //------------------------------------------------------------------------------------
    connect(colapseButton, SIGNAL(clicked()), this, SLOT(closeUpdates()));

    //------------------------------------------------------------------------------------
}

void AeriaToolMain::minimizeTool()
{
    setWindowState(Qt::WindowMinimized);
}

void AeriaToolMain::openEdenEternalTool()
{
    if(!gamePath(1).isEmpty())
    {
        mEdenEternalTool = new EdenEternalTool();
        mEdenEternalTool->exec();
    }
    else
    {
        QMessageBox e;
            e.setIcon(QMessageBox::Warning);
            e.setText("Le repertoire du jeu 'EdenEternal' n'est pas defini");
            e.setInformativeText("Cliquez sur les engrenages pour le definir");
            e.exec();
    }
}

void AeriaToolMain::openWorkInProgress()
{
    QSpacerItem* horizontalSpacer = new QSpacerItem(350, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    QPushButton *butab = new QPushButton("OK");
        butab->setFixedSize(40, 25);
        butab->setObjectName("wipButton");

    QMessageBox wip;
        wip.setIcon(QMessageBox::Warning);
        wip.setWindowTitle("Work In Progress");
        wip.setText("Cette fonction n'est pas ma priorité en ce momment");
        wip.setInformativeText("Contactez FoxiesCuties pour toutes sugestions");
        wip.addButton(butab, QMessageBox::AcceptRole);
        wip.setObjectName("wipBox");
        wip.setWindowFlags(Qt::FramelessWindowHint);

        QGridLayout* layout = (QGridLayout*)wip.layout();
        layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());

        wip.exec();
}

void AeriaToolMain::openSettings()
{
    QDialog *mSettingsDialog = new QDialog();

    QLabel *mGrandFantasiaLabel = new QLabel("Grand Fantasia");
        mGrandFantasiaLabel->setObjectName("gamenameLabel");
    QLineEdit *mGrandFantasiaEdit = new QLineEdit;
        mGrandFantasiaEdit->setObjectName("gamenameEdit");
    sGrandFantasiaButton = new QPushButton("...");
        sGrandFantasiaButton->setObjectName("gamenameButton");

    QLabel *mEdenEternalLabel = new QLabel("Eden Eternal");
        mEdenEternalLabel->setObjectName("gamenameLabel");
    mEdenEternalEdit = new QLineEdit;
        mEdenEternalEdit->setObjectName("gamenameEdit");
    sEdenEternalButton = new QPushButton("...");
        sEdenEternalButton->setObjectName("gamenameButtonE");

    QLabel *mAuraKingdomLabel = new QLabel("Aura Kingdom");
        mAuraKingdomLabel->setObjectName("gamenameLabel");
    QLineEdit *mAuraKingdomEdit = new QLineEdit;
        mAuraKingdomEdit->setObjectName("gamenameEdit");
    sAuraKingdomButton = new QPushButton("...");
        sAuraKingdomButton->setObjectName("gamenameButton");

    QLabel *mS4LeagueLabel = new QLabel("S4 League");
        mS4LeagueLabel->setObjectName("gamenameLabel");
    QLineEdit *mS4LeagueEdit = new QLineEdit;
        mS4LeagueEdit->setObjectName("gamenameEdit");
    sS4LeagueButton = new QPushButton("...");
        sS4LeagueButton->setObjectName("gamenameButton");

    QLabel *mWolfTeamLabel = new QLabel("Wolf Team");
        mWolfTeamLabel->setObjectName("gamenameLabel");
    QLineEdit *mWolfTeamEdit = new QLineEdit;
        mWolfTeamEdit->setObjectName("gamenameEdit");
    sWolfTeamButton = new QPushButton("...");
        sWolfTeamButton->setObjectName("gamenameButton");

    QLabel *mShaiyaLabel = new QLabel("Shaiya");
        mShaiyaLabel->setObjectName("gamenameLabel");
    QLineEdit *mShaiyaEdit = new QLineEdit;
        mShaiyaEdit->setObjectName("gamenameEdit");
    sShaiyaButton = new QPushButton("...");
        sShaiyaButton->setObjectName("gamenameButton");


    QGridLayout *mSettingsGrid = new QGridLayout;

        mSettingsGrid->setSpacing(0);

        mSettingsGrid->addWidget(mGrandFantasiaLabel, 0, 0);
        mSettingsGrid->addWidget(mGrandFantasiaEdit, 0, 1);
        mSettingsGrid->addWidget(sGrandFantasiaButton, 0, 2);

        mSettingsGrid->addWidget(mEdenEternalLabel, 1, 0);
        mSettingsGrid->addWidget(mEdenEternalEdit, 1, 1);
        mSettingsGrid->addWidget(sEdenEternalButton, 1, 2);

        mSettingsGrid->addWidget(mAuraKingdomLabel, 2, 0);
        mSettingsGrid->addWidget(mAuraKingdomEdit, 2, 1);
        mSettingsGrid->addWidget(sAuraKingdomButton, 2, 2);

        mSettingsGrid->addWidget(mS4LeagueLabel, 3, 0);
        mSettingsGrid->addWidget(mS4LeagueEdit, 3, 1);
        mSettingsGrid->addWidget(sS4LeagueButton, 3, 2);

        mSettingsGrid->addWidget(mWolfTeamLabel, 4, 0);
        mSettingsGrid->addWidget(mWolfTeamEdit, 4, 1);
        mSettingsGrid->addWidget(sWolfTeamButton, 4, 2);

        mSettingsGrid->addWidget(mShaiyaLabel, 5, 0);
        mSettingsGrid->addWidget(mShaiyaEdit, 5, 1);
        mSettingsGrid->addWidget(sShaiyaButton, 5, 2);

    titleSettingsButton = new SPushButton("SETTINGS");
        titleSettingsButton->setFixedHeight(25);
        titleSettingsButton->setObjectName("titleButton");

    QPushButton *mclose = new QPushButton("X");
        mclose->setFixedSize(40, 25);
        mclose->setObjectName("closeButton");
        mclose->setMask(QBitmap(":/mask/mask"));

    QHBoxLayout *mhset = new QHBoxLayout;
        mhset->addWidget(titleSettingsButton);
        mhset->addWidget(mclose);

    QGroupBox *mSettingsGroup = new QGroupBox("Emplacements");
        mSettingsGroup->setLayout(mSettingsGrid);

    QVBoxLayout *mSettingsBox = new QVBoxLayout;
        mSettingsBox->addLayout(mhset);
        mSettingsBox->addWidget(mSettingsGroup);

    //------------------------

    QSettings mPathsSettings(mPathsFile->fileName(), QSettings::IniFormat);
        //mPathsSettings.beginGroup("Paths");

    if(mPathsSettings.contains("Paths/EdenEternal"))
    {
        mEdenEternalEdit->setText(mPathsSettings.value("Paths/EdenEternal").toString());
        mEdenEternalEdit->setStyleSheet("QLineEdit{background-color: #5a5}");
    }

    //-------------------------

    connect(sEdenEternalButton, SIGNAL(clicked()), this, SLOT(setDir()));
    connect(mclose, SIGNAL(clicked()), mSettingsDialog, SLOT(close()));

    connect(sGrandFantasiaButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));
    connect(sAuraKingdomButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));
    connect(sWolfTeamButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));
    connect(sShaiyaButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));
    connect(sS4LeagueButton, SIGNAL(clicked()), this, SLOT(openWorkInProgress()));

    mSettingsDialog->setWindowFlags(Qt::FramelessWindowHint);
    mSettingsDialog->setLayout(mSettingsBox);
    mSettingsDialog->setFixedSize(500, 300);
    mSettingsDialog->exec();
}

void AeriaToolMain::openAbout()
{
    QDialog *mAboutDialog = new QDialog();

    QFile *mTodoListFile = new QFile(":/texts/todolist");
        mTodoListFile->open(QIODevice::ReadOnly | QIODevice::Text);

    SPushButton *mPushInfo = new SPushButton("A PROPOS DE AERIAGAMES-TOOLS");
        mPushInfo->setFixedHeight(25);
        mPushInfo->setObjectName("titleButton");

    QPushButton *mPushClose = new QPushButton("X");
        mPushClose->setFixedSize(40, 25);
        mPushClose->setMask(QBitmap(":/mask/mask"));
        mPushClose->setObjectName("closeButton");

    QHBoxLayout *mHboxTitle = new QHBoxLayout;
        mHboxTitle->addWidget(mPushInfo);
        mHboxTitle->addWidget(mPushClose);
        mHboxTitle->setContentsMargins(10, 10, 10, 20);

    QPushButton *mLabel = new QPushButton();
        mLabel->setIcon(QIcon(":/misc/avatar"));
        mLabel->setIconSize(QSize(80,80));
        mLabel->setObjectName("avatarButton");
    QLabel *mLabelpseudo = new QLabel("FoxiesCuties");
        mLabelpseudo->setObjectName("pseudoLabel");

    QLabel *mLabelInfo2 = new QLabel("Outil dédié aux problèmes AeriaGames");
    QLabel *mLabelInfo3 = new QLabel("Compiler sous Qt "+QString(qVersion()));
    QLabel *mLabelInfo4 = new QLabel("Logiciel sous licence GPLv3");

    QGridLayout *mGridInfo = new QGridLayout;
        mGridInfo->addWidget(mLabel, 2, 0, 3, 0, Qt::AlignLeft);
        mGridInfo->addWidget(mLabelpseudo, 5, 0);
        mGridInfo->addWidget(mLabelInfo2, 2, 1, Qt::AlignLeft);
        mGridInfo->addWidget(mLabelInfo3, 3, 1, Qt::AlignLeft);
        mGridInfo->addWidget(mLabelInfo4, 4, 1, Qt::AlignLeft);

    QTextEdit *mTextEdit = new QTextEdit;
        mTextEdit->setReadOnly(true);
        mTextEdit->setHtml(mTodoListFile->readAll());

    QVBoxLayout *vBox = new QVBoxLayout;
        vBox->addLayout(mHboxTitle);
        vBox->addLayout(mGridInfo);
        vBox->addWidget(mTextEdit);

    connect(mPushClose, SIGNAL(clicked()), mAboutDialog, SLOT(close()));

    mAboutDialog->setWindowFlags(Qt::FramelessWindowHint);
    mAboutDialog->setFixedWidth(550);
    mAboutDialog->setFixedHeight(430);
    mAboutDialog->setLayout(vBox);
        mAboutDialog->exec();
}

void AeriaToolMain::openTools()
{
    if(!m_toolDialog->isVisible())
    {
        m_toolDialog->show();

        m_toolDialog->move(pos().x() - m_toolDialog->width(), pos().y());

        this->move(pos().x() + m_toolDialog->width() / 2, pos().y());

        if(m_updateIsOpen)
            setMask(QBitmap(":/mask/exp_full"));
        else
            setMask(QBitmap(":/mask/uimaskt"));
    }
    else
    {
        m_toolDialog->close();

        this->move(pos().x() - m_toolDialog->width() / 2, pos().y());

        if(m_updateIsOpen)
            setMask(QBitmap(":/mask/uimaskf"));
        else
            setMask(QBitmap(":/mask/uimask"));
    }
}

void AeriaToolMain::openUpdates()
{
    m_updateIsOpen = true;

    if(m_toolDialog->isVisible())
        setMask(QBitmap(":/mask/exp_full"));
    else
        setMask(QBitmap(":/mask/uimaskf"));

    colapseButton->show();
    localButton->show();
    onlineButton->show();
    vcheckButton->show();

    QSslConfiguration sslconfig = QSslConfiguration::defaultConfiguration();

    if(sslconfig.isNull())
    {
        vcheckButton->setText("Erreur SSL");
        vcheckButton->setStyleSheet("#vcheckButton{background-color: red;}");
    }
    else
    {
        sslconfig.setProtocol(QSsl::TlsV1_2);

        QNetworkRequest netReq(QUrl(m_settings.LAST_PUBLIC_BUILD, QUrl::StrictMode));
            netReq.setSslConfiguration(sslconfig);

        QNetworkAccessManager *manager = new QNetworkAccessManager;
            manager->get(netReq);

        connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getCurrentVersion(QNetworkReply*)));
    }
}
void AeriaToolMain::closeUpdates()
{
    m_updateIsOpen = false;

    if(m_toolDialog->isVisible())
        setMask(QBitmap(":/mask/uimaskt"));
    else
        setMask(QBitmap(":/mask/uimask"));

    colapseButton->hide();
    localButton->hide();
    onlineButton->hide();
    vcheckButton->hide();
}

void AeriaToolMain::setGamePath(QString path)
{
    QSettings mPathsSettings(mPathsFile->fileName(), QSettings::IniFormat);
        mPathsSettings.beginGroup("Paths");

    if(sender() == sEdenEternalButton)
    {
        QFile *cltax = new QFile(QDir(path).absolutePath() + "/cltax.xmf");
        QFile *ftrace = new QFile(QDir(path).absolutePath() + "/ftrace.dos");

        if(cltax->exists() && ftrace->exists())
        {
            cltax->close();
            ftrace->close();

            m_EdenPath = path;

            mEdenEternalEdit->setText(path);
            mEdenEternalEdit->setStyleSheet("QLineEdit{background-color: #5a5}");

            mPathsSettings.setValue("EdenEternal", path);
        }
    }

    mPathsFile->close();
}
QString AeriaToolMain::gamePath(int nb)
{
    if(nb == 1)
    {
        return m_EdenPath;
    }
}

void AeriaToolMain::getCurrentVersion(QNetworkReply* rep)
{
    QString *test = new QString(rep->readAll());

    streamS = new QTextStream(test);

    onlineButton->setText(streamS->readLine());

    if(localButton->text() == onlineButton->text())
    {
        vcheckButton->setText("App à jour");
        vcheckButton->setStyleSheet("#vcheckButton{background-color: green;}");
    }
    else if(localButton->text() < onlineButton->text())
    {
        QFile vcheck(":/qss/vcheck_upd");
            vcheck.open(QIODevice::ReadOnly | QIODevice::Text);

        vcheckButton->setText("Mettre à jour");
        vcheckButton->setStyleSheet(vcheck.readAll());

        connect(vcheckButton, SIGNAL(clicked()), this, SLOT(getCurrentApplication()));
    }
    else if(localButton->text() > onlineButton->text())
    {
        QFile vcheck(":/qss/vcheck_upd");
            vcheck.open(QIODevice::ReadOnly | QIODevice::Text);

        vcheckButton->setText("What the fox ?");
        vcheckButton->setStyleSheet(vcheck.readAll());
    }
}
void AeriaToolMain::getCurrentApplication()
{
    QSslConfiguration sslConf = QSslConfiguration::defaultConfiguration();
        sslConf.setProtocol(QSsl::TlsV1_2);

    QNetworkRequest latExe(QUrl(streamS->readLine(), QUrl::StrictMode));
        latExe.setSslConfiguration(sslConf);

    QNetworkAccessManager *manExe = new QNetworkAccessManager();

    QNetworkReply *reply = manExe->get(latExe);

    connect(manExe, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateApplication(QNetworkReply*)));
    //----
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downStatut(qint64,qint64)));


    vcheckButton->hide();
    bar->show();
}
void AeriaToolMain::downStatut(qint64 rec, qint64 tol)
{
    bar->setMaximum(tol);
    bar->setValue(rec);
    bar->show();
}

void AeriaToolMain::updateApplication(QNetworkReply* reply)
{
    QFile clearoldupd(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools-new.exe");
        clearoldupd.remove();

    QFile *newupd = new QFile(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools-new.exe");
    //QFile *newupd = new QFile(QCoreApplication::applicationDirPath()+"/test.zip");
        newupd->open(QIODevice::WriteOnly);
        newupd->write(reply->readAll());
        newupd->close();

    QFile old(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools.exe");
        old.rename(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools-old.exe");

    QFile upd(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools-new.exe");
        upd.rename(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools.exe");
}

void AeriaToolMain::setDir()
{
    QPushButton *button = qobject_cast<QPushButton*>(QObject::sender());

    QPoint testS = QPoint(690, 105);

    QFile *qssDialog = new QFile(":/qss/file_dialog");
        qssDialog->open(QIODevice::ReadOnly | QIODevice::Text);

    QFileDialog *dialog = new QFileDialog;
        dialog->setContentsMargins(10,10,140,10);
        dialog->setStyleSheet(qssDialog->readAll());
        dialog->setWindowFlags(Qt::FramelessWindowHint);
        dialog->setFileMode(QFileDialog::Directory);
        dialog->setOptions(QFileDialog::ShowDirsOnly | QFileDialog::DontUseNativeDialog);
        dialog->setFixedSize(700, 400);
        dialog->move(button->parentWidget()->parentWidget()->geometry().topLeft() + button->geometry().topLeft() - testS);
        dialog->setMask(QBitmap(":/mask/maskset"));
        dialog->setSizeGripEnabled(false);
        dialog->setLabelText(QFileDialog::Reject, "Annuler");


        QDialogButtonBox *box = dialog->findChild<QDialogButtonBox*>();

            QPushButton *openButton = box->button(QDialogButtonBox::Open);
                openButton->setStyleSheet("QPushButton{background-color: #484;} QPushButton:hover{background-color: #4b4;}");

            QPushButton *cancelButton = box->button(QDialogButtonBox::Cancel);
                cancelButton->setStyleSheet("QPushButton{background-color: #844;} QPushButton:hover{background-color: #d44;}");


        if(dialog->exec() == 1)//On vérifie le repertoire uniquement si on clique sur "Choisir"
        {
            setGamePath(dialog->directory().absolutePath());
        }
}

void AeriaToolMain::moveEvent(QMoveEvent *event)
{
    if(m_toolDialog->isVisible())
    {
        m_toolDialog->move(event->pos().x() - m_toolDialog->width(), event->pos().y());
    }
}
