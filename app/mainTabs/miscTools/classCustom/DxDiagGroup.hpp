#ifndef DXDIAGGROUP_HPP
#define DXDIAGGROUP_HPP

#include <QtWidgets>

#include "app/threads/DirectXDiag.hpp"
#include "app/libs/QPastebinQuery.hpp"
#include "app/Config.hpp"

class DxDiagGroup : public QGroupBox
{
    Q_OBJECT
public:
    DxDiagGroup();

    createObjects();
    createConnexions();

    void dxDiagDate();

    void dxDiagUpload();

    void dxDiagGroup();

public slots:

    void refreshDiagStat();

    bool dxDiagExist();

    void linkToClip();

    void uploadSuccessful(QString link);

    void makeDxDiag();
    void timeOutDxDiag();
    void timeOutUpPast();

    void pastebinLink();

private:

    bool            m_DxExist;

    Config          m_settingsHdr;

    QMovie          *m_WaitAnim;

    QClipboard      *m_UploadLinkClp;

    QTimer          *m_DxDiagTim;
    QTimer          *m_PastUpTim;

    QLabel          *m_UploadStatutLbl;
    QPushButton     *m_UploadStatutBtn;
    QPushButton     *m_UploadClipBtn;

    QGridLayout     *m_DxDiagGrd;
    QLabel          *m_DiagStatutLbl;
    QPushButton     *m_DiagStatutBtn;
    QLabel          *m_DiagDateLbl;

    QPastebinQuery  *m_pasteQuery;

    DirectXDiag     *m_directxDiag;

    QLineEdit       *m_pastebinLineEdit;

    QFile           *m_DxDiagFil;
};

#endif // DXDIAGGROUP_HPP
