/**************************************
 *   Name : QPastebinQuery            *
 *   Role :  Qt Pastebin Publisher    *
 *   Author : FoxiesCuties            *
 *   Licence : GPLv3                  *
 *  --------------------------------  *
 *   File : gpl-3.0.txt               *
 *   File : gpl-3.0.fr.txt            *
 *   File : QPastebinQuery.cpp        *
 *   File : QPastebinQuery.hpp        *
 *                                    *
 **************************************/

#include "QPastebinQuery.hpp"

//CONSTRUCTORS
QPastebinQuery::QPastebinQuery() : QObject()
{
    m_APIKey = "", m_Code = "", m_Name = "", m_Expire = "", m_Format = "", m_Private = "";

    m_Manager = new QNetworkAccessManager();
    m_Request = new QNetworkRequest(QUrl("http://pastebin.com/api/api_post.php"));

    QObject::connect(m_Manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyPaste(QNetworkReply*)));
}

QPastebinQuery::QPastebinQuery(QString apikey)
{
    m_APIKey = apikey, m_Code = "", m_Name = "", m_Expire = "", m_Format = "", m_Private = "";

    m_Manager = new QNetworkAccessManager();
    m_Request = new QNetworkRequest(QUrl("http://pastebin.com/api/api_post.php"));

    QObject::connect(m_Manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyPaste(QNetworkReply*)));
}

//SETTERS
void QPastebinQuery::setKey(QString apikey)
{
    m_APIKey = apikey;
}

void QPastebinQuery::setCode(QString code)
{
    m_Code = code;
}

void QPastebinQuery::setName(QString name)
{
    m_Name = name;
}

void QPastebinQuery::setExpire(QString expire)
{
    m_Expire = expire;
}

void QPastebinQuery::setFormat(QString format)
{
    m_Format = format;
}

void QPastebinQuery::setPrivate(QString priv)
{
    m_Private = priv;
}

//METHOD
void QPastebinQuery::publishPaste(QString code, QString name, QString expire, QString format, QString visibility)
{
    if(!code.isEmpty())
    {
        m_Code = code;

        if(!name.isEmpty())
            m_Name = name;
        if(!expire.isEmpty())
            m_Expire = name;
        if(!format.isEmpty())
            m_Format = name;
        if(!visibility.isEmpty())
            m_Private = name;

        m_Params = new QUrlQuery;
            m_Params->addQueryItem("api_dev_key", m_APIKey);
            m_Params->addQueryItem("api_option", "paste");
            m_Params->addQueryItem("api_paste_code", m_Code);

        if(!m_Name.isEmpty())
            m_Params->addQueryItem("api_paste_name", m_Name);
        if(!m_Expire.isEmpty())
            m_Params->addQueryItem("api_paste_expire_date", m_Expire);
        if(!m_Format.isEmpty())
            m_Params->addQueryItem("api_paste_format", m_Format);
        if(!m_Private.isEmpty())
            m_Params->addQueryItem("api_paste_private", m_Private);

        m_ErrorReply = m_Manager->post(*m_Request, m_Params->toString().toUtf8());
    }
}

//SLOTS
void QPastebinQuery::replyPaste(QNetworkReply* reply)
{
    m_PReply = reply->readAll();
    emit rawReply(m_PReply);

    if(m_PReply.contains("Bad API request"))
    {
        m_PError = m_PReply;
        emit errorAcquiered(m_PError);
    }
    else if(m_PReply.contains("Post limit"))
    {
        m_PLimit = m_PReply;
        emit postLimit();
        emit postLimitDetails(m_PLimit);
    }
    else
    {
        m_PLink = m_PReply;
        emit linkAcquiered(m_PLink);
    }
}
