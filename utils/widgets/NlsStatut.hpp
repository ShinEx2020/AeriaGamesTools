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
