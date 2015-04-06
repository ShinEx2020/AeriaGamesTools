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

#ifndef QPASTEBINQUERY_HPP
#define QPASTEBINQUERY_HPP

#include <QString>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class QPastebinQuery : public QObject
{
    Q_OBJECT

public:
    QPastebinQuery();// If you use this, you must define API key with method "setKey(QString apikey)"
    QPastebinQuery(QString apikey);// Define the API key in constructor

// List of setters
    void setKey(QString apikey);
    void setCode(QString code);
    void setName(QString name);
    void setExpire(QString expire);
    void setFormat(QString format);
    void setPrivate(QString priv);

// Send code to Pastebin.com / Optional params can be added for custom paste
    void publishPaste(QString code, QString name = "", QString expire = "", QString format = "", QString visibility = "");

signals:
    void postLimit();                       // emit if post limit is reached
    void rawReply(QString rawreply);        // emit the reply message "m_PReply"
    void linkAcquiered(QString pastelink);  // emit the link message "m_PLink"
    void postLimitDetails(QString details); // emit the limit message "m_PLimit"
    void errorAcquiered(QString errorcode); // emit the error message "m_PError"

private slots:
    void replyPaste(QNetworkReply* reply);// Get and store the reply in "m_PReply"

private:
// Method variables
    QString                 m_APIKey;
    QString                 m_Code;
    QString                 m_Name;
    QString                 m_Expire;
    QString                 m_Format;
    QString                 m_Private;
// Reply variables
    QString                 m_PReply;
    QString                 m_PLink;
    QString                 m_PLimit;
    QString                 m_PError;
// Objects pointers
    QNetworkAccessManager   *m_Manager;
    QNetworkReply           *m_ErrorReply;
    QNetworkRequest         *m_Request;
    QUrlQuery               *m_Params;
};

#endif // QPASTEBINQUERY_HPP
