#ifndef LOGSHARE_H
#define LOGSHARE_H

#include <QtWidgets>

#include "utils/FreeUpload.hpp"

class LogShare : public QWidget
{
    Q_OBJECT
public:
    LogShare();

public slots:
    void logUpload();

    void logUrl(QString);

    void logClip();

private:

    QString        m_url;

    FreeUpload  *m_uplo;
    QLineEdit   *m_line;
    QPushButton *m_push;
};

#endif // LOGSHARE_H
