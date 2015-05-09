/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "MiscGeneralTool.hpp"

MiscGeneralTool::MiscGeneralTool(QWidget *parent) : QWidget(parent)
{
    createObjects();

    m_MiscToolGrd->addWidget(m_DxGroupGrp,0,0,Qt::AlignLeft | Qt::AlignTop);

    setLayout(m_MiscToolGrd);
}

void MiscGeneralTool::createObjects()
{
    m_DxGroupGrp    = new DxDiagGroup;
    m_MiscToolGrd   = new QGridLayout;
}
