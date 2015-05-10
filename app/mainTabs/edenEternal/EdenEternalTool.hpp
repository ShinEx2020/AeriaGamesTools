/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef EDENETERNALTOOL_HPP
#define EDENETERNALTOOL_HPP

#include <QtWidgets>
#include "app/libs/DSlider.hpp"
#include "edenTabs/DiagnoticsTab.hpp"
#include "edenTabs/ThemeTab.hpp"
#include "edenTabs/configTabs/GameplayTab.hpp"
#include "edenTabs/configTabs/SystemTab.hpp"
#include "app/mainButtons/Settings.hpp"

class EdenEternalTool : public QWidget
{
    Q_OBJECT
public:

    EdenEternalTool(QWidget *parent = 0);

    void createObjects();
    void createConnexions();
    void createConfigTab();
    void createInterface();

public slots:

    void loadAllSettings();
    void applyAllSettings();

private:

    Settings        *mPathsSettings;

    //CONFIGS
    SystemTab       *m_systemWid;
    GameplayTab     *m_gameWid;
    QTabWidget      *m_configsTbw;
    QPushButton     *m_applyBtn;
    QPushButton     *m_cancelBtn;
    QHBoxLayout     *m_buttonsHbx;
    QVBoxLayout     *m_configsVbx;
    //PRIMARY
    ThemeTab        *m_themeWidget;
    QWidget         *m_configsWid;
    DiagnoticsTab   *m_repairWidget;
    QTabWidget      *m_edenPrimaryTbw;
    QVBoxLayout     *m_primaryVbx;
};

#endif // EDENETERNALTOOL_HPP
