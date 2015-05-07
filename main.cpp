/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include <QApplication>

#include "app/Config.hpp"
#include "app/AeriaMain.hpp"


void checkDir()
{
    QDir cacheDir(QCoreApplication::applicationDirPath()+"/Storage");

    if(!cacheDir.exists())
        cacheDir.mkdir(QCoreApplication::applicationDirPath()+"/Storage");
}

void cleanUpdate()
{
    QFile old(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools-old.exe");
        old.open(QIODevice::ReadOnly);

    if(old.exists()) {old.remove();}
}

int main(int argc, char *argv[])
{
    Config          m_settingsHdr;

    QTranslator translator;
        translator.load(":/texts/fr");

    QApplication appTool(argc, argv);
        appTool.installTranslator(&translator);
        appTool.setApplicationVersion(m_settingsHdr.CURRENT_BUILD_ID);

    AeriaMain mainTool;
        mainTool.show();

    checkDir();
    cleanUpdate();

    return appTool.exec();
}
