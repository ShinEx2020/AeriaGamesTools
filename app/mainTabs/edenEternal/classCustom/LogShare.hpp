/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef LOGSHARE_HPP
#define LOGSHARE_HPP

#include <QtWidgets>

#include "app/libs/FreeUpload.hpp"
#include "app/mainButtons/Settings.hpp"
#include "app/threads/FilesCompress.hpp"
#include "app/Config.hpp"

class LogShare : public QGroupBox
{
    Q_OBJECT
public:

    LogShare();

    void createObjects();
    void createConnexions();
    void createInterface();

public slots:

    //LOGS
    void launchZipLogs();
    void finishZipLogs();
    void timeoutZipLogs();
    void statutZipLogs();
    //UPLOAD
    void launchUploadLogs();
    void finishUploadLogs(QString url);
    void timeoutUploadLogs();
    void clipboardUploadLogs();

private:

    //GENERAL
    Config          m_settingsConf;
    QClipboard      *m_zipLinkClp;
    QFile           *m_zipLogsFil;
    QMovie          *m_waitMov;
    Settings        *m_settingsSet;
    FilesCompress   *m_filesCompress;
    FreeUpload      *m_freeUpload;
    QGridLayout     *m_logsGameGrd;
    //LOGS
    QTimer          *m_zipLogsTim;
    QLabel          *m_zipLogsIconLbl;
    QPushButton     *m_zipLogsLaunchBtn;
    QLabel          *m_zipLogsDateLbl;
    //UPLOAD
    QTimer          *m_uploadLogsTim;
    QLabel          *m_uploadLogsIconLbl;
    QPushButton     *m_UploadClipBtn;
    QPushButton     *m_SendLogsBtn;
    QLineEdit       *m_LinkUploadEdt;
};

#endif // LOGSHARE_HPP
