/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "FreeUpload.hpp"

FreeUpload::FreeUpload(QWidget *parent) : QWidget(parent)
{
    m_timeStamp = QString::number(QDateTime::currentMSecsSinceEpoch());

    m_uplMail = "edenlogs"+m_timeStamp+"@yopmail.com";

    m_uplUrl.setScheme("ftp");
    m_uplUrl.setHost("dl.free.fr");

    m_uplMan  = new QNetworkAccessManager;
    m_linkEdt = new QLineEdit;

    connect(m_uplMan, SIGNAL(authenticationRequired(QNetworkReply*, QAuthenticator*)), this, SLOT(auth(QNetworkReply*, QAuthenticator*)));
    connect(m_uplMan, SIGNAL(finished(QNetworkReply*)), this, SLOT(finish(QNetworkReply*)));
}
FreeUpload::FreeUpload(QFile *file, QWidget *parent) : QWidget(parent)
{
    m_logsFile = file;

    m_timeStamp = QString::number(QDateTime::currentMSecsSinceEpoch());

    m_uplMail = "edenlogs"+m_timeStamp+"@yopmail.com";

    m_uplUrl.setScheme("ftp");
    m_uplUrl.setHost("dl.free.fr");

    m_uplMan  = new QNetworkAccessManager;
    m_linkEdt = new QLineEdit;

    connect(m_uplMan, SIGNAL(authenticationRequired(QNetworkReply*, QAuthenticator*)), this, SLOT(auth(QNetworkReply*, QAuthenticator*)));
    connect(m_uplMan, SIGNAL(finished(QNetworkReply*)), this, SLOT(finish(QNetworkReply*)));
}

void FreeUpload::auth(QNetworkReply *rep, QAuthenticator *auth)
{
    auth->setUser(m_uplMail);
    auth->setPassword("aeriatool");
}

void FreeUpload::upload()
{
    m_uplUrl.setPath("/" + QFileInfo(m_logsFile->fileName()).fileName());

    if(m_logsFile->exists())
        if(m_logsFile->open(QIODevice::ReadOnly))
            m_uplMan->put(QNetworkRequest(m_uplUrl), m_logsFile);
}

void FreeUpload::finish(QNetworkReply* rep)
{
    m_uplMan->deleteLater();
    emit replyLink("http://www.yopmail.com/"+m_uplMail);
}

void FreeUpload::setUploadFile(QFile *file)
{
    m_logsFile = file;
}
