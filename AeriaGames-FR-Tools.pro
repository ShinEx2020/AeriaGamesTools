#13/02/2015 2:30

QT += widgets core network

QMAKE_CXXFLAGS += -std=c++11

VERSION = 0.0.1.1

DEFINES += \
    PUBLIC_BUILD=\\\"1\\\"

TRANSLATIONS += dialog.ts

SOURCES +=                              \
    main.cpp                            \
    AeriaToolMain.cpp                   \
    EdenEternalTool.cpp                 \
    utils/DSlider.cpp                   \
    utils/TPushButton.cpp               \
    utils/SPushButton.cpp               \
    utils/QPastebinQuery.cpp            \
    utils/DxDiagPastebin.cpp            \
    utils/ThemeExtract.cpp              \
    utils/FilesCompress.cpp             \
    utils/FreeUpload.cpp                \
    dialogs/edeneternal/ThemeTab.cpp    \
    dialogs/edeneternal/GameTab.cpp     \
    dialogs/ToolDialog.cpp              \
    dialogs/edeneternal/PingTab.cpp     \
    dialogs/edeneternal/RescueTab.cpp   \
    utils/ServerStatut.cpp              \
    utils/threads/ServerPing.cpp        \
    utils/widgets/NlsStatut.cpp \
    utils/widgets/LogShare.cpp

HEADERS +=                              \
    Config.hpp                          \
    AeriaToolMain.hpp                   \
    EdenEternalTool.hpp                 \
    utils/DSlider.hpp                   \
    utils/TPushButton.hpp               \
    utils/SPushButton.hpp               \
    utils/QPastebinQuery.hpp            \
    utils/DxDiagPastebin.hpp            \
    utils/ThemeExtract.hpp              \
    utils/FilesCompress.hpp             \
    utils/FreeUpload.hpp                \
    dialogs/edeneternal/ThemeTab.hpp    \
    dialogs/edeneternal/GameTab.hpp     \
    dialogs/ToolDialog.hpp              \
    dialogs/edeneternal/PingTab.hpp     \
    dialogs/edeneternal/RescueTab.hpp   \
    utils/ServerStatut.hpp              \
    utils/threads/ServerPing.hpp        \
    utils/widgets/NlsStatut.hpp \
    utils/widgets/LogShare.hpp

RESOURCES += \
    assets.qrc
