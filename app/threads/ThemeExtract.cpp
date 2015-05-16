/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "ThemeExtract.hpp"

ThemeExtract::ThemeExtract()
{
}

void ThemeExtract::setPath(QString path)
{
    m_path = path;
}
void ThemeExtract::setArchive(QString archive)
{
    m_archive = "\""+archive+"\"";;
}

void ThemeExtract::run()
{
    m_ExtractThemePro = new QProcess();
        m_ExtractThemePro->execute("bin/7z.exe x "+m_archive+ " -y -o"+"\""+m_path+"/themes\"");
}
