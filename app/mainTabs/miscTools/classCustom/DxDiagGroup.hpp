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

    void createObjects();
    void createConnexions();
    void createInterface();

public slots:

    //DIAG
    void launchDxDiag();
    void finishDxDiag();
    void timeoutDxDiag();
    void statutDiag();
    //PASTEBIN
    void launchPastebin();
    void finishPastebin(QString link);
    void timeoutPastebin();
    void clipboardPastebin();

private:

    //GENERAL
    Config          m_dxDiagConf;
    QClipboard      *m_UploadLinkClp;
    QFile           *m_dxDiagFil;
    QMovie          *m_waitMov;
    DirectXDiag     *m_directxDiag;
    QPastebinQuery  *m_pasteQuery;
    QGridLayout     *m_DxDiagGrd;
    //DIAG
    QTimer          *m_DxDiagTim;
    QLabel          *m_dxDiagIconLbl;
    QPushButton     *m_DiagLaunchBtn;
    QLabel          *m_DiagDateLbl;
    //PASTEBIN
    QTimer          *m_PastUpTim;
    QLabel          *m_UploadStatutLbl;
    QPushButton     *m_UploadStatutBtn;
    QPushButton     *m_pastebinClipBtn;
    QLineEdit       *m_pastebinLineEdit;
};

#endif // DXDIAGGROUP_HPP
