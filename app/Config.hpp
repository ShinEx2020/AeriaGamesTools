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

	//Paramètres Globaux
    int     TIMEOUT                 = 10000;
    int     ZIP_TIMEOUT             = 10000;
    int     DIAG_TIMEOUT            = 10000;
    //-- Temps en millisecondes

    //Paramètres Dropbox
    QString CURRENT_BUILD_ID        = "1";
    QString LAST_PUBLIC_BUILD       = "https://dl.dropboxusercontent.com/s/e42m49i2hl7g98c/version.txt?dl=1";

    //Paramètres Themes
    QString THEME_LIST_URL          = "https://dl.dropboxusercontent.com/s/cdbplssr38gfkgs/themes.list?dl=1";
    QString THEME_INFO_URL          = "https://dl.dropboxusercontent.com/s/zmw1vvu7f4d4dv5/themes.info?dl=1";

    //Paramètres Pastebin
    QString PASTEBIN_API_KEY        = "4e8086d7db1d3bc8a8824db245a88f1d";
    QString PASTEBIN_PASTE_NAME     = "Diagnostic DirectX - AeriaGamesTools";
    QString PASTEBIN_PASTE_DELAY    = "10M";
    QString PASTEBIN_PASTE_FORMAT   = "";
    QString PASTEBIN_PASTE_PRIVACY  = "1";
};

#endif // CONFIG_HPP
