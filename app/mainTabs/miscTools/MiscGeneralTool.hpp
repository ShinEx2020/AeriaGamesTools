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

#include "app/mainTabs/miscTools/classCustom/DxDiagGroup.hpp"

class MiscGeneralTool : public QWidget
{
    Q_OBJECT

public:

    MiscGeneralTool(QWidget *parent = 0);

    void createObjects();
    void createInterface();

private:

    DxDiagGroup     *m_DxGroupGrp;
    QGridLayout     *m_MiscToolGrd;
};

#endif // MISCGENERALTOOL_HPP
