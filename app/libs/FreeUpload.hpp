/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef FREECLIENT_HPP
#define FREECLIENT_HPP

#include <QtWidgets>
#include <QtNetwork>

class FreeUpload : public QWidget
{
    Q_OBJECT

public:
    FreeUpload(QWidget *parent = 0);
    FreeUpload(QFile *file, QWidget *parent = 0);

    void setUploadFile(QFile *file);

signals:
    void replyLink(QString);

public slots:
    void auth(QNetworkReply*, QAuthenticator*);
    void upload();
    void finish(QNetworkReply*);

private:
    QString                 m_timeStamp;
    QUrl                    m_uplUrl;

    QLineEdit               *m_linkEdt;
    QFile                   *m_logsFile;
    QNetworkAccessManager   *m_uplMan;

    QString                 m_uplMail;
};

#endif // FREECLIENT_HPP
