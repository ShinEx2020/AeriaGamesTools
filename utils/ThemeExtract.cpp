/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "ThemeExtract.hpp"

ThemeExtract::ThemeExtract(QString path, QString archive)
{
    m_path = path;
    m_archive = "\""+archive+"\"";
}

void ThemeExtract::run()
{
    QProcess *process = new QProcess();
        process->execute("bin/7z.exe x "+m_archive+ " -y -o"+"\""+m_path+"/themes\"");
}
