/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include <QApplication>

#include "AeriaToolMain.hpp"

#include "utils/FilesCompress.hpp"


int main(int argc, char *argv[])
{
    QTranslator translator;
        translator.load(":/texts/fr");

    QApplication appTool(argc, argv);
        appTool.installTranslator(&translator);
        appTool.setApplicationVersion(PUBLIC_BUILD);

    AeriaToolMain mainTool;
        mainTool.show();

    QFile old(QCoreApplication::applicationDirPath()+"/AeriaGames-FR-Tools-old.exe");
        old.open(QIODevice::ReadOnly);

    if(old.exists())
        old.remove();

    return appTool.exec();
}
