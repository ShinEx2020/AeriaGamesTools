/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "AeriaToolMain.hpp"

AeriaToolMain::AeriaToolMain(QWidget *parent) : QWidget(parent)
{
    createObjects();


    bar->hide();
    bar->setFixedSize(100, 25);
    bar->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    bar->setStyleSheet("QProgressBar{background: #aaa; border-radius: 12px; border: 4px solid #aaa; color: black; font-weight: bold; text-align: center; margin-right: 4px;}"
                       "QProgressBar::chunk{margin:3px; background-color: #d33;}");

    qss->setFileName(":/qss/style");
    qss->open(QIODevice::ReadOnly | QIODevice::Text);

//---------------------------------------------------------

    createButtons();

    QHBoxLayout *barLayout = new QHBoxLayout;
        barLayout->addWidget(titleButton, 0);
        barLayout->addWidget(minimizeButton, 0, Qt::AlignRight);
        barLayout->addWidget(closeButton, 0, Qt::AlignRight);
        barLayout->setSpacing(0);

    colapseButton->setIcon(QIcon(":/icons/collapse"));
    colapseButton->setFixedSize(35, 25);
    colapseButton->setObjectName("colapseButton");
    colapseButton->hide();

    localButton->setText(QCoreApplication::applicationVersion());
    localButton->setIcon(QIcon(":/icons/local"));
    localButton->setFixedSize(60, 25);
    localButton->setObjectName("localButton");
    localButton->hide();

    onlineButton->setText("...");
    onlineButton->setIcon(QIcon(":/icons/online"));
    onlineButton->setFixedSize(60, 25);
    onlineButton->setObjectName("onlineButton");
    onlineButton->hide();

    vcheckButton->setText("Connexion...");

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
        buttonsHBox->addWidget(colapseButton, 0, Qt::AlignRight);
        buttonsHBox->addWidget(localButton, 0, Qt::AlignRight);
        buttonsHBox->addWidget(onlineButton, 0, Qt::AlignRight);
        buttonsHBox->addWidget(vcheckButton, 0, Qt::AlignRight);
        buttonsHBox->addWidget(bar, 0, Qt::AlignRight);
        buttonsHBox->setContentsMargins(25,0,5,0);


    for(int i = 0; i<5; i++)
    {
        QLabel *lablogo = new QLabel;
            lablogo->setPixmap(QPixmap(":/misc/wip"));
        QHBoxLayout *logo = new QHBoxLayout;
            logo->addWidget(lablogo);

        m_widgetList.append(new QWidget);
        m_widgetList.last()->setLayout(logo);
        m_widgetList.last()->setObjectName("mTabWidget");
        m_widgetList.last()->setContentsMargins(-10,-11,-18,-10);
    }
    QTabWidget *m_mainTab = new QTabWidget;
        m_mainTab->addTab(m_toolDialog, "");
        m_mainTab->addTab(mEdenEternalTool, QIcon(":/logos/eden"), "");
        m_mainTab->addTab(m_widgetList.at(0), QIcon(":/logos/aura"), "");
        m_mainTab->addTab(m_widgetList.at(1), QIcon(":/logos/s4"), "");
        m_mainTab->addTab(m_widgetList.at(2), QIcon(":/logos/fanta"), "");
        m_mainTab->addTab(m_widgetList.at(3), QIcon(":/logos/wolf"), "");
        m_mainTab->addTab(m_widgetList.at(4), QIcon(":/logos/shaiya"), "");
        m_mainTab->setTabPosition(QTabWidget::West);
        m_mainTab->tabBar()->setObjectName("mTabBar");
        m_mainTab->tabBar()->setIconSize(QSize(60,60));
        m_mainTab->setObjectName("mTabMain");


    QHBoxLayout *m_headerHBox = new QHBoxLayout;
        m_headerHBox->addWidget(updateButton, 1, Qt::AlignRight);
        m_headerHBox->addWidget(settingsButton, 0, Qt::AlignRight);
        m_headerHBox->addWidget(infoButton, 0, Qt::AlignRight);
        m_headerHBox->setContentsMargins(0, 2, 10, 0);
        m_headerHBox->setSpacing(1);

    QVBoxLayout *m_headerVBox = new QVBoxLayout;
        m_headerVBox->addLayout(barLayout);
        m_headerVBox->addLayout(m_headerHBox);
        m_headerVBox->setContentsMargins(0, 0, 0, -10);

    m_headerWidget->setObjectName("headerWidget");
    m_headerWidget->setLayout(m_headerVBox);

    m_mainLayout->addWidget(m_headerWidget);
    m_mainLayout->addWidget(m_mainTab);
    m_mainLayout->addLayout(buttonsHBox);
    m_mainLayout->setSpacing(0);

    createConnections();

    mPathsFile->setFileName(QCoreApplication::applicationDirPath()+"/logs/paths.lst");
    mPathsFile->open(QIODevice::ReadOnly | QIODevice::Text);

    createSettings();
}

void AeriaToolMain::createObjects()
{
    m_headerWidget      = new QWidget;
    mPathsFile          = new QFile;
    mPathsSettings      = new QSettings(mPathsFile->fileName(), QSettings::IniFormat);
    bar                 = new QProgressBar;
    qss                 = new QFile;
    m_toolDialog        = new ToolDialog;
    mEdenEternalTool    = new EdenEternalTool;
    m_settingsS         = new Settings;
    m_mainLayout        = new QVBoxLayout;
    titleButton         = new TPushButton(this);
    minimizeButton      = new QPushButton;
    closeButton         = new QPushButton;
    colapseButton       = new QPushButton;
    localButton         = new QPushButton;
    onlineButton        = new QPushButton;
    settingsButton      = new QPushButton;
    updateButton        = new QPushButton;
    infoButton          = new QPushButton;
    vcheckButton        = new QPushButton;
}

void AeriaToolMain::initSettings()
{
    m_EdenPath = mPathsSettings->value("Paths/EdenEternal").toString();
}

void AeriaToolMain::createSettings()
{
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(800, 600);
    setWindowTitle(titleButton->text());
    setContentsMargins(-11, -12, -11, -11);
    setLayout(m_mainLayout);
    qApp->setStyleSheet(qss->readAll());
}

void AeriaToolMain::createButtons()
{
    titleButton->setText("AERIA GAMES TOOLS");
    titleButton->setFixedHeight(25);
    titleButton->setObjectName("titleButton");
    titleButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    minimizeButton->setText("-");
    minimizeButton->setFixedSize(40, 25);
    minimizeButton->setObjectName("minimizeButton");
    minimizeButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    closeButton->setText("X");
    closeButton->setFixedSize(40, 25);
    closeButton->setObjectName("closeButton");
    closeButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    settingsButton->setIcon(QIcon(":/icons/settings"));
    settingsButton->setFixedSize(40, 25);
    settingsButton->setObjectName("settingsButton");

    updateButton->setIcon(QIcon(":/icons/update"));
    updateButton->setFixedSize(40, 25);
    updateButton->setObjectName("updateButton");

    infoButton->setIcon(QIcon(":/icons/info"));
    infoButton->setFixedSize(40, 25);
    infoButton->setObjectName("infoButton");
}

void AeriaToolMain::createConnections()
{
    connect(minimizeButton, SIGNAL(clicked()), this, SLOT(minimizeTool()));
    connect(closeButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(settingsButton, SIGNAL(clicked()), m_settingsS, SLOT(show()));
    connect(updateButton, SIGNAL(clicked()), this, SLOT(openUpdates()));
    connect(infoButton, SIGNAL(clicked()), this, SLOT(openAbout()));
    connect(colapseButton, SIGNAL(clicked()), this, SLOT(closeUpdates()));
}

void AeriaToolMain::minimizeTool()
{
    setWindowState(Qt::WindowMinimized);
}

void AeriaToolMain::openAbout()
{
    QDialog *mAboutDialog = new QDialog();

    QFile *mTodoListFile = new QFile(":/texts/todolist");
        mTodoListFile->open(QIODevice::ReadOnly | QIODevice::Text);

    TPushButton *mPushInfo = new TPushButton("A PROPOS DE AERIAGAMES-TOOLS", mAboutDialog);
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

void AeriaToolMain::moveEvent(QMoveEvent *event)
{
    if(m_toolDialog->isVisible())
    {
        m_toolDialog->move(event->pos().x() - m_toolDialog->width(), event->pos().y());
    }
}
