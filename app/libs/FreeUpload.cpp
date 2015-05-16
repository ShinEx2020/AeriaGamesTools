/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "FreeUpload.hpp"

FreeUpload::FreeUpload() : QObject()
{
    createObjects();
    createConnexions();
}

void FreeUpload::createObjects()
{
    m_uplMan  = new QNetworkAccessManager;
    m_linkEdt = new QLineEdit;

    //Generer un ID en fonction d'une partie du timestamp
    m_timeStamp = QString::number(QDateTime::currentMSecsSinceEpoch()).section("143",1,1);

    m_uplUrl.setScheme("ftp");
    m_uplUrl.setHost("dl.free.fr");
}
void FreeUpload::createConnexions()
{
    connect(m_uplMan, SIGNAL(authenticationRequired(QNetworkReply*, QAuthenticator*)), this, SLOT(auth(QNetworkReply*, QAuthenticator*)));
    connect(m_uplMan, SIGNAL(finished(QNetworkReply*)), this, SLOT(finish(QNetworkReply*)));
}

void FreeUpload::setGameName(GameName name)
{
    if(name == GameName::Eden)
        m_GameName = "EdenLogs_";
    else if(name == GameName::Aura)
        m_GameName = "AuraLogs_";
    else if(name == GameName::S4)
        m_GameName = "S4Logs_";
    else if(name == GameName::Fant)
        m_GameName = "FantaLogs_";
    else if(name == GameName::Wolf)
        m_GameName = "WolfLogs_";
    else if(name == GameName::Shai)
        m_GameName = "ShaiLogs_";
    else if(name == GameName::AVA)
        m_GameName = "AVALogs_";
    else if(name == GameName::Trib)
        m_GameName = "TribLogs_";
    else if(name == GameName::Maes)
        m_GameName = "MaesLogs_";
    else if(name == GameName::Echo)
        m_GameName = "EchoLogs_";
}
void FreeUpload::setUploadFile(QFile *file)
{
    m_logsFile = file;
}

void FreeUpload::auth(QNetworkReply *rep, QAuthenticator *auth)
{
    m_uplMail = m_GameName+m_timeStamp+"@yopmail.com";

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


