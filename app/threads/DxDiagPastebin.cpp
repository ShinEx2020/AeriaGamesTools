/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "DxDiagPastebin.hpp"

DxDiagPastebin::DxDiagPastebin()
{

}

void DxDiagPastebin::run()
{
    m_TXT = new QFile(QCoreApplication::applicationDirPath()+"/logs/dxdiag.txt");

    QString commandtxt = "dxdiag.exe /t "+m_TXT->fileName().section('.',0,0);

    QProcess *process = new QProcess();
        process->start("cmd.exe");
        process->execute(commandtxt);
}
