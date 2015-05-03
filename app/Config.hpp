/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QString>

class Config
{
public:
    //Dropbox links
    QString LAST_PUBLIC_BUILD       = "https://dl.dropboxusercontent.com/s/e42m49i2hl7g98c/version.txt?dl=1";
    //QString LAST_PUBLIC_BUILD       = "http://127.0.0.1/version.txt";

    //Themes Links
    QString THEME_LIST_URL          = "https://dl.dropboxusercontent.com/s/cdbplssr38gfkgs/themes.list?dl=1";
    QString THEME_INFO_URL          = "https://dl.dropboxusercontent.com/s/zmw1vvu7f4d4dv5/themes.info?dl=1";

    //Pastebin settings
    QString PASTEBIN_API_KEY        = "4e8086d7db1d3bc8a8824db245a88f1d";
    QString PASTEBIN_PASTE_NAME     = "Diagnostic DirectX - AeriaGamesTools";
    QString PASTEBIN_PASTE_DELAY    = "1W";
    QString PASTEBIN_PASTE_FORMAT   = "";
    QString PASTEBIN_PASTE_PRIVACY  = "1";
};

#endif // CONFIG_HPP
