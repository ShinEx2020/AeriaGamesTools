/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "FilesCompress.hpp"

FilesCompress::FilesCompress(QString path)
{
    m_path = path;
}

void FilesCompress::run()
{
    QProcess *process = new QProcess();
        process->execute("bin/7z.exe a "+QCoreApplication::applicationDirPath()+""
            "/logs/edenlogs.7z "+m_path+"/*.log "+m_path+"/*.txt "+m_path+"/*.ini");
}
