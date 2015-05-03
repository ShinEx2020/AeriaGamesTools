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

class NlsStatut : public QWidget
{
    Q_OBJECT
public:
    NlsStatut(QString filename, QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *m_nameLabel;
    QPushButton *m_filPush;
    QPushButton *m_regPush;
    QLabel *m_checkLabel;

    bool m_exFile;
    bool m_exReg;
};

#endif // NLSSTATUT_HPP
