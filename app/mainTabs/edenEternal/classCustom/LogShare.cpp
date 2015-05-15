/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "LogShare.hpp"

LogShare::LogShare()
{
    createObjects();
    createConnexions();
    createInterface();

    statutZipLogs();
}

void LogShare::createObjects()
{
    //GENERAL
    m_settingsSet       = new Settings;
    m_zipLinkClp        = QApplication::clipboard();
    m_zipLogsFil        = new QFile;
    m_waitMov           = new QMovie;
    m_filesCompress     = new FilesCompress(FilesCompress::GameName::Eden, m_settingsSet->gamePath(Settings::GamePath::Eden).toString());
    m_freeUpload        = new FreeUpload;
    m_logsGameGrd       = new QGridLayout;
    //LOGS
    m_zipLogsTim        = new QTimer;
    m_zipLogsIconLbl    = new QLabel;
    m_zipLogsLaunchBtn  = new QPushButton;
    m_zipLogsDateLbl    = new QLabel;
    //UPLOAD
    m_uploadLogsTim     = new QTimer;
    m_uploadLogsIconLbl = new QLabel;
    m_SendLogsBtn       = new QPushButton;
    m_UploadClipBtn     = new QPushButton;
    m_LinkUploadEdt     = new QLineEdit;
}
void LogShare::createConnexions()
{
    //LOGS
    connect(m_zipLogsLaunchBtn, SIGNAL(clicked()), this, SLOT(launchZipLogs()));
    connect(m_filesCompress, SIGNAL(finished()), this, SLOT(finishZipLogs()));
    connect(m_zipLogsTim, SIGNAL(timeout()), this, SLOT(timeoutZipLogs()));
    //UPLOAD
    connect(m_SendLogsBtn, SIGNAL(clicked()), this, SLOT(launchUploadLogs()));
    connect(m_freeUpload, SIGNAL(replyLink(QString)), this, SLOT(finishUploadLogs(QString)));
    connect(m_uploadLogsTim, SIGNAL(timeout()), this, SLOT(timeoutUploadLogs()));
    connect(m_UploadClipBtn, SIGNAL(clicked()), this, SLOT(clipboardUploadLogs()));
}
void LogShare::createInterface()
{
    //GENERAL
    m_zipLogsFil->setFileName(QCoreApplication::applicationDirPath()+"/Storage/EdenEternal_Logs.7z");

    m_waitMov->setFileName(":/icons/wait");

    m_logsGameGrd->addWidget(new QLabel("Journaux :"),0,0,Qt::AlignRight);
    m_logsGameGrd->addWidget(m_zipLogsIconLbl,0,1,Qt::AlignLeft);
    m_logsGameGrd->addWidget(m_zipLogsLaunchBtn,0,2,Qt::AlignRight);
    m_logsGameGrd->addWidget(new QLabel("Dernier :"),1,0,Qt::AlignRight);
    m_logsGameGrd->addWidget(m_zipLogsDateLbl,1,1,1,2,Qt::AlignRight);
    m_logsGameGrd->addWidget(new QLabel("Uploadé :"),2,0,Qt::AlignRight);
    m_logsGameGrd->addWidget(m_uploadLogsIconLbl,2,1,Qt::AlignLeft);
    m_logsGameGrd->addWidget(m_SendLogsBtn,2,2,Qt::AlignRight);
    m_logsGameGrd->addWidget(new QLabel("Partage :"),3,0,Qt::AlignRight);
    m_logsGameGrd->addWidget(m_UploadClipBtn,3,1,Qt::AlignRight);
    m_logsGameGrd->addWidget(m_LinkUploadEdt,3,2,Qt::AlignRight);


    //ZIP
    m_zipLogsLaunchBtn->setObjectName("greenButton");


    //UPLOAD
    m_uploadLogsIconLbl->setPixmap(QPixmap(":/icons/bad"));

    m_SendLogsBtn->setText("Envoyer");
    m_SendLogsBtn->setObjectName("greenButton");

    m_UploadClipBtn->setIcon(QIcon(":/icons/clip"));
    m_UploadClipBtn->setObjectName("noBorder");

    m_LinkUploadEdt->setObjectName("customLine");
    m_LinkUploadEdt->setReadOnly(true);


    //SETTINGS
    setTitle(("Logs du jeu"));
    setLayout(m_logsGameGrd);
    setFixedSize(280,150);
}

//SLOTS
void LogShare::launchZipLogs()
{
    m_zipLogsIconLbl->setMovie(m_waitMov);
    m_waitMov->start();

    m_filesCompress->start();
    m_zipLogsTim->start(m_settingsConf.ZIP_TIMEOUT);

    m_zipLogsLaunchBtn->setEnabled(false);
}
void LogShare::finishZipLogs()
{
    m_zipLogsTim->stop();

    m_zipLogsLaunchBtn->setEnabled(true);
    statutZipLogs();
}
void LogShare::timeoutZipLogs()
{
    finishZipLogs();

    m_filesCompress->terminate();
    m_filesCompress->wait();

    QToolTip::showText(m_zipLogsLaunchBtn->mapToGlobal(QPoint()), tr("Temps ecoulé, veuillez réessayer"));
}
void LogShare::statutZipLogs()
{
    if(m_zipLogsFil->exists())
    {
        m_zipLogsIconLbl->setPixmap(QPixmap(":/icons/good"));

        m_zipLogsLaunchBtn->setText("Rezipper Logs");

        m_zipLogsDateLbl->setText(QFileInfo(*m_zipLogsFil).lastModified().toString("Le dddd d MMMM yyyy à hh:mm:ss"));
    }
    else
    {
        m_zipLogsIconLbl->setPixmap(QPixmap(":/icons/bad"));

        m_zipLogsLaunchBtn->setText("Zipper Logs");

        m_zipLogsDateLbl->setText("Aucune archive de logs existante");
    }
}

void LogShare::launchUploadLogs()
{
    if(m_zipLogsFil->exists())
    {
        m_uploadLogsIconLbl->setMovie(m_waitMov);
        m_waitMov->start();

        m_uploadLogsTim->start(m_settingsConf.TIMEOUT);

        m_SendLogsBtn->setEnabled(false);

        m_freeUpload->setGameName(FreeUpload::GameName::Eden);
        m_freeUpload->setUploadFile(m_zipLogsFil);
        m_freeUpload->upload();
    }
    else
    {
        QToolTip::showText(m_zipLogsLaunchBtn->mapToGlobal(QPoint()), tr("Générer d'abord votre archive !"));
    }
}
void LogShare::finishUploadLogs(QString url)
{
    m_uploadLogsTim->stop();

    m_LinkUploadEdt->setText(url);

    m_uploadLogsIconLbl->setPixmap(QPixmap(":/icons/good"));
}
void LogShare::timeoutUploadLogs()
{
    m_uploadLogsTim->stop();

    QToolTip::showText(m_SendLogsBtn->mapToGlobal(QPoint()), tr("Temps ecoulé, veuillez réessayer"));

    m_uploadLogsIconLbl->setPixmap(QPixmap(":/icons/bad"));

    m_SendLogsBtn->setEnabled(true);
}
void LogShare::clipboardUploadLogs()
{
    if(!m_LinkUploadEdt->text().isEmpty())
    {
        m_zipLinkClp->setText(m_LinkUploadEdt->text());

        if(m_zipLinkClp->text() == m_LinkUploadEdt->text())
            QToolTip::showText(m_LinkUploadEdt->mapToGlobal(QPoint()), tr("Lien dans le presse papier"));
        else
            QToolTip::showText(m_LinkUploadEdt->mapToGlobal(QPoint()), tr("Erreur de presse papier"));
    }
    else
        QToolTip::showText(m_LinkUploadEdt->mapToGlobal(QPoint()), "Rien à copier");
}
