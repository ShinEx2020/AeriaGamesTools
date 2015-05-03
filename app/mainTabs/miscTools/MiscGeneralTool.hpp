/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef MISCGENERALTOOL_HPP
#define MISCGENERALTOOL_HPP

#include <QtWidgets>

#include "app/threads/DxDiagPastebin.hpp"
#include "app/libs/QPastebinQuery.hpp"
#include "app/Config.hpp"

class MiscGeneralTool : public QWidget
{
    Q_OBJECT

public:
    MiscGeneralTool(QWidget *parent = 0);


public slots:
    void directx();
    void pastebinLink();

private:
    QWidget *f;

    QPastebinQuery  *m_pasteQuery;

    DxDiagPastebin  *m_directxDiag;

    QLineEdit       *m_pastebinLineEdit;

    QFile           *diagTXT;

    Config          m_settingsHdr;
};

#endif // MISCGENERALTOOL_HPP
