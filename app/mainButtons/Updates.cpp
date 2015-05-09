/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "Updates.hpp"

Updates::Updates()
{
    createObjects();

    m_checkVersionBtn->setText("Vérifier maintenant");
    m_checkVersionBtn->setObjectName("greenButton");

    m_installVersion->setText(QCoreApplication::applicationVersion());
    m_onlineVersion->setText("...");

    m_updateGrid->addWidget(new QLabel("Version Installé :"), 0, 0, Qt::AlignLeft | Qt::AlignTop);
    m_updateGrid->addWidget(m_installVersion, 0, 1, Qt::AlignLeft | Qt::AlignTop);
    m_updateGrid->addWidget(new QLabel("Version En ligne :"), 1, 0, Qt::AlignLeft | Qt::AlignTop);
    m_updateGrid->addWidget(m_onlineVersion, 1, 1, Qt::AlignLeft | Qt::AlignTop);
    m_updateGrid->addWidget(m_detailsVersion, 2, 0, 1, 0, Qt::AlignTop);
    m_updateGrid->addWidget(m_checkVersionBtn, 3, 0, 1, 0, Qt::AlignTop);

    m_releaseUpdatesWidget->setLayout(m_updateGrid);


    m_releasesTabWidget->setFocusPolicy(Qt::NoFocus);
    m_releasesTabWidget->setStyleSheet("QTabWidget::pane{border: none;}"
                                       "QTabWidget::tab-bar{alignment:center;}"
                                       "QTabBar::tab{width: 50px; padding: 5px; margin-right: 5px; border: none; background: #333;}"
                                       "QTabBar::tab:selected{background: #373;}");
    m_releasesTabWidget->setTabPosition(QTabWidget::South);
    m_releasesTabWidget->addTab(m_releaseUpdatesWidget,"M.a.J");
    m_releasesTabWidget->addTab(m_releaseNotesWidget,"Notes");



    TPushButton *mPushInfo = new TPushButton("PARAMETRES", this);
        mPushInfo->setFixedHeight(25);
        mPushInfo->setObjectName("titleButton");

    m_closeBtn = new QPushButton("X");
    m_closeBtn->setFixedSize(40, 25);
    m_closeBtn->setObjectName("closeButton");

    QHBoxLayout *mHboxTitle = new QHBoxLayout;
        mHboxTitle->addWidget(mPushInfo);
        mHboxTitle->addWidget(m_closeBtn);
        mHboxTitle->setSpacing(0);

    QVBoxLayout *m_mainVbx = new QVBoxLayout;
        m_mainVbx->addLayout(mHboxTitle);
        m_mainVbx->addWidget(m_releasesTabWidget);



    createConnexions();

    setLayout(m_mainVbx);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowModality(Qt::ApplicationModal);
    setContentsMargins(-11, -11, -11, -11);
}

void Updates::createObjects()
{
    m_installVersion        = new QLabel;
    m_onlineVersion         = new QLabel;
    m_detailsVersion        = new QLabel;
    m_checkVersionBtn       = new QPushButton;
    m_updateGrid            = new QGridLayout;
    m_releaseNotesWidget    = new QWidget;
    m_releaseUpdatesWidget  = new QWidget;
    m_releasesTabWidget     = new QTabWidget;
}
void Updates::createConnexions()
{
    connect(m_checkVersionBtn, SIGNAL(clicked()), this, SLOT(checkUpdates()));
    connect(m_closeBtn, SIGNAL(clicked()), this, SLOT(close()));
}

void Updates::checkUpdates()
{
    QSslConfiguration sslconfig = QSslConfiguration::defaultConfiguration();

    if(sslconfig.isNull())
    {
        m_detailsVersion->setText("Erreur SSL");
    }
    else
    {
        m_detailsVersion->setText("Verification...");

        sslconfig.setProtocol(QSsl::TlsV1_2);

        QNetworkRequest netReq(QUrl(m_settingsHdr.LAST_PUBLIC_BUILD, QUrl::StrictMode));
            netReq.setSslConfiguration(sslconfig);

        QNetworkAccessManager *manager = new QNetworkAccessManager;
            manager->get(netReq);

        connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getCurrentVersion(QNetworkReply*)));
    }
}

void Updates::getCurrentVersion(QNetworkReply *reply)
{
    m_onlineVersion->setText(reply->readLine());

    if(m_installVersion->text().toInt() == m_onlineVersion->text().toInt())
        m_detailsVersion->setText("Votre version est à jour");
    else if(m_installVersion->text().toInt() < m_onlineVersion->text().toInt())
        m_detailsVersion->setText("Une mise à jour est disponible");
    else if(m_installVersion->text().toInt() > m_onlineVersion->text().toInt())
        m_detailsVersion->setText("Votre version est erroné");
}








//void Updates::getCurrentApplication()
//{
//    QSslConfiguration sslConf = QSslConfiguration::defaultConfiguration();
//        sslConf.setProtocol(QSsl::TlsV1_2);

//    QNetworkRequest latExe(QUrl(streamS->readLine(), QUrl::StrictMode));
//        latExe.setSslConfiguration(sslConf);

//    QNetworkAccessManager *manExe = new QNetworkAccessManager();

//    QNetworkReply *reply = manExe->get(latExe);

//    connect(manExe, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateApplication(QNetworkReply*)));
//    //----
//    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downStatut(qint64,qint64)));


//    //vcheckButton->hide();
//    bar->show();
//}
//void Updates::downStatut(qint64 rec, qint64 tol)
//{
//    bar->setMaximum(tol);
//    bar->setValue(rec);
//    bar->show();
//}

//void Updates::updateApplication(QNetworkReply* reply)
//{
//    QFile clearoldupd(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools-new.exe");
//        clearoldupd.remove();

//    QFile *newupd = new QFile(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools-new.exe");
//    //QFile *newupd = new QFile(QCoreApplication::applicationDirPath()+"/test.zip");
//        newupd->open(QIODevice::WriteOnly);
//        newupd->write(reply->readAll());
//        newupd->close();

//    QFile old(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools.exe");
//        old.rename(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools-old.exe");

//    QFile upd(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools-new.exe");
//        upd.rename(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools.exe");
//}
