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

class LogShare : public QWidget
{
    Q_OBJECT

public:
    LogShare();

public slots:
    void logCompress();

    void logUpload();

    void logUrl(QString);

    void logClip();

private:

    Settings        *m_settingsHdr;

    FilesCompress   *m_compress;

    QString         m_url;

    FreeUpload      *m_uplo;
    QLineEdit       *m_line;
    QPushButton     *m_push;
};

#endif // LOGSHARE_HPP
