#ifndef PINGTAB_H
#define PINGTAB_H

#include <QtWidgets>

#include "utils/ServerStatut.hpp"
#include "utils/threads/ServerPing.hpp"

class PingTab : public QWidget
{
    Q_OBJECT
public:
    PingTab();

public slots:
    void alarmSlid(int val);
    void launchPing();
    void readPing(int);

private:

    ServerPing      *m_pingLoginTrd;

    ServerPing      *m_pingCelestia_13Trd;
    ServerPing      *m_pingCelestia_2Trd;

    ServerPing      *m_pingAlbion_135Trd;
    ServerPing      *m_pingAlbion_246Trd;


    ServerStatut    *m_log1;
    ServerStatut    *m_log2;

    ServerStatut    *chara1;
    ServerStatut    *world1;
    ServerStatut    *chara2;
    ServerStatut    *world2;
    ServerStatut    *chara3;
    ServerStatut    *world3;

    ServerStatut    *m_aChar1;
    ServerStatut    *m_aWorld1;
    ServerStatut    *m_aChar2;
    ServerStatut    *m_aWorld2;
    ServerStatut    *m_aChar3;
    ServerStatut    *m_aWorld3;
    ServerStatut    *m_aChar4;
    ServerStatut    *m_aWorld4;
    ServerStatut    *m_aChar5;
    ServerStatut    *m_aWorld5;
    ServerStatut    *m_aChar6;
    ServerStatut    *m_aWorld6;


    QProcess        *m_ping;
    QProcess        *m_ping2;
    QProcess        *m_ping3;
    QProcess        *m_ping4;
    QProcess        *m_ping5;


    QSlider         *m_alarmSli;

    QTimer          *m_pingTimer;
};

#endif // PINGTAB_H
