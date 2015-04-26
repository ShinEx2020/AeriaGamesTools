#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QtWidgets>
#include "utils/SPushButton.hpp"

class Settings : public QWidget
{
    Q_OBJECT

public:

    enum {
            EdenPath
         };

    Settings();

    void createObjects();
    void createConnexions();
    void createSettings();
    void createParams();

    void loadSettings();
    QString loadStylesheet();

public slots:

    void setEEDir();
    void setGamePath(QString path);
    void openWorkInProgress();
    QVariant gamePath(int nb);

private:

    QFile           *m_styleFile;

    QString         m_styleString;

    QSettings       *mPathsSettings;

    QFile           *mPathsFile;

    QVBoxLayout     *mSettingsBox;
    QPushButton     *mclose;

    SPushButton     *titleSettingsButton;
    QGridLayout     *mSettingsGrid;

    QLabel          *mGrandFantasiaLabel;
    QLineEdit       *mGrandFantasiaEdit;

    QLabel          *mEdenEternalLabel;
    QLineEdit       *mEdenEternalEdit;

    QLabel          *mAuraKingdomLabel;
    QLineEdit       *mAuraKingdomEdit;

    QLabel          *mS4LeagueLabel;
    QLineEdit       *mS4LeagueEdit;

    QLabel          *mWolfTeamLabel;
    QLineEdit       *mWolfTeamEdit;

    QLabel          *mShaiyaLabel;
    QLineEdit       *mShaiyaEdit;

    QPushButton     *sGrandFantasiaButton;
    QPushButton     *sEdenEternalButton;
    QPushButton     *sAuraKingdomButton;
    QPushButton     *sWolfTeamButton;
    QPushButton     *sShaiyaButton;
    QPushButton     *sS4LeagueButton;
    QPushButton     *sAVAButton;

    QString         m_EdenPath;
};

#endif // SETTINGS_HPP
