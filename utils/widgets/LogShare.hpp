#ifndef LOGSHARE_HPP
#define LOGSHARE_HPP

#include <QtWidgets>

#include "utils/FreeUpload.hpp"
#include "utils/Settings.hpp"
#include "utils/threads/FilesCompress.hpp"

class LogShare : public QWidget
{
    Q_OBJECT

public:
    LogShare();

public slots:
    void logCompress();

    void logUpload();

    void logUrl(QString);

    void logClip();

private:

    Settings        *m_settings;

    FilesCompress   *m_compress;

    QString         m_url;

    FreeUpload      *m_uplo;
    QLineEdit       *m_line;
    QPushButton     *m_push;
};

#endif // LOGSHARE_HPP
