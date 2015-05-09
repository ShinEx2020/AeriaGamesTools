/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef UPDATES_HPP
#define UPDATES_HPP

#include <QtWidgets>
#include <QtNetwork>

#include "app/Config.hpp"
#include "app/libs/TPushButton.hpp"

class Updates : public QDialog
{
    Q_OBJECT

public:
    
    Updates();

    void createObjects();
    void createConnexions();

public slots:
    void checkUpdates();
    void getCurrentVersion(QNetworkReply*);

private:
    Config          m_settingsHdr;

    QLabel          *m_installVersion;
    QLabel          *m_onlineVersion;
    QLabel          *m_detailsVersion;
    QWidget         *m_releaseNotesWidget;
    QWidget         *m_releaseUpdatesWidget;
    QTabWidget      *m_releasesTabWidget;
    QPushButton     *m_checkVersionBtn;
    QGridLayout     *m_updateGrid;

    QPushButton     *m_closeBtn;
};

#endif // UPDATES_HPP
