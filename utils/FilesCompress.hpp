/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef FILESCOMPRESS
#define FILESCOMPRESS

#include <QtWidgets>

class FilesCompress : public QThread
{
    Q_OBJECT

public:
    FilesCompress(QString path);

    void run();

private:
    QProcess    *m_extThemeProcess;

    QFile       *m_EdenPath;

    QString     m_path;
    QString     m_archive;
};

#endif // FILESCOMPRESS
