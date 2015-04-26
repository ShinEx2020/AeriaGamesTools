/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=209434            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef TOOLDIALOG_HPP
#define TOOLDIALOG_HPP

#include <QtWidgets>

#include "utils/threads/DxDiagPastebin.hpp"
#include "utils/QPastebinQuery.hpp"
#include "Config.hpp"

class ToolDialog : public QWidget
{
    Q_OBJECT

public:
    ToolDialog(QWidget *parent = 0);


public slots:
    void directx();
    void pastebinLink();

private:
    QWidget *f;

    QPastebinQuery  *m_pasteQuery;

    DxDiagPastebin  *m_directxDiag;

    QLineEdit       *m_pastebinLineEdit;

    QFile           *diagTXT;

    Config          m_settings;
};

#endif // TOOLDIALOG_HPP
