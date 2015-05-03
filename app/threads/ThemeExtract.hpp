/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef THEMEEXTRACT_HPP
#define THEMEEXTRACT_HPP

#include <QtWidgets>

class ThemeExtract : public QThread
{
    Q_OBJECT

public:
    ThemeExtract(QString path, QString archive);

    void run();

private:
    QProcess    *m_extThemeProcess;

    QFile       *m_EdenPath;

    QString     m_path;
    QString     m_archive;
};

#endif // THEMEEXTRACT_HPP
