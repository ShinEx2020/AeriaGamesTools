/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "AvaTool.hpp"

AvaTool::AvaTool(QWidget *parent) : QWidget(parent)
{
    QLabel *m_wip = new QLabel;
        m_wip->setPixmap(QPixmap(":misc/wip"));

    QHBoxLayout *m_labwipHbx = new QHBoxLayout;
        m_labwipHbx->addWidget(m_wip);

    setContentsMargins(0,-35,-10,0);
    setLayout(m_labwipHbx);
}

