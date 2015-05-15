/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#ifndef NLSSTATUT_HPP
#define NLSSTATUT_HPP

#include <QtWidgets>

class NlsStatut : public QGroupBox
{
    Q_OBJECT
public:

    NlsStatut();

    void createObjects();
    void createConnexions();
    void createInterface();

    void checkFile();
    void checkReg();

private:

    QSettings       *m_nlsReg;

    QPushButton     *m_fileIconBtn;
    QPushButton     *m_regIconBtn;
    QPushButton     *m_936FileBtn;
    QPushButton     *m_936RegBtn;
    QPushButton     *m_950FileBtn;
    QPushButton     *m_950RegBtn;
    QPushButton     *m_10002FileBtn;
    QPushButton     *m_10002RegBtn;
    QPushButton     *m_10008FileBtn;
    QPushButton     *m_10008RegBtn;

    QGridLayout     *m_nlsGrd;
};

#endif // NLSSTATUT_HPP
