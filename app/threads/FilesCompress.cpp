/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "FilesCompress.hpp"

FilesCompress::FilesCompress(GameName name, QString path)
{
    if(name == GameName::Eden)
        m_GameName = "EdenEternal_Logs";
    else if(name == GameName::Aura)
        m_GameName = "AuraKingdom_Logs";
    else if(name == GameName::S4)
        m_GameName = "S4League_Logs";
    else if(name == GameName::Fant)
        m_GameName = "GrandFantasia_Logs";
    else if(name == GameName::Wolf)
        m_GameName = "WolfTeam_Logs";
    else if(name == GameName::Shai)
        m_GameName = "Shaiya_Logs";
    else if(name == GameName::AVA)
        m_GameName = "AVA_Logs";
    else if(name == GameName::Trib)
        m_GameName = "TribesAscend_Logs";
    else if(name == GameName::Maes)
        m_GameName = "Maestia_Logs";
    else if(name == GameName::Echo)
        m_GameName = "EchoOfSoul_Logs";

    m_GamePath = path;
}

void FilesCompress::run()
{
    m_LogsCompressPro = new QProcess();
        m_LogsCompressPro->execute("bin/7z.exe a "+QCoreApplication::applicationDirPath()+"/Storage/"+m_GameName+".7z "
                                    ""+m_GamePath+"/*.log "+m_GamePath+"/*.txt "+m_GamePath+"/*.ini");
}
