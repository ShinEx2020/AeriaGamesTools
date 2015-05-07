/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef FILESCOMPRESS_HPP
#define FILESCOMPRESS_HPP

#include <QtWidgets>

class FilesCompress : public QThread
{
    Q_OBJECT

public:

    enum GameName
    {
        Eden,
        Aura,
        S4,
        Fant,
        Wolf,
        Shai,
        AVA,
        Trib,
        Maes,
        Echo
    };

    FilesCompress(GameName name, QString path);

    void run();

private:

    QString     m_GameName;
    QString     m_GamePath;
    QProcess    *m_LogsCompressPro;
};

#endif // FILESCOMPRESS_HPP
