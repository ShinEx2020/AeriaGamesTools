#ifndef SERVERSTATUT_HPP
#define SERVERSTATUT_HPP

#include <QtWidgets>

class ServerStatut : public QWidget
{
    Q_OBJECT
public:
    ServerStatut(QString name, QWidget *parent = 0);

signals:

public slots:
    void setName(QString name);
    void setPing(int ping);
    void setStatut(bool statut);

private:
    QString m_servname;
    int     m_servping;
    bool    m_servstatut;

    QLabel *m_ledLab;
    QLabel *m_nameLab;
    QLabel *m_pingLab;
};

#endif // SERVERSTATUT_HPP
