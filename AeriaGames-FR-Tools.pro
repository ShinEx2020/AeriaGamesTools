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
    utils/threads/DxDiagPastebin.cpp    \
    utils/threads/ThemeExtract.cpp      \
    utils/threads/FilesCompress.cpp     \
    utils/threads/ServerPing.cpp        \
    utils/FreeUpload.cpp                \
    dialogs/edeneternal/ThemeTab.cpp    \
    dialogs/ToolDialog.cpp              \
    dialogs/edeneternal/RescueTab.cpp   \
    utils/ServerStatut.cpp              \
    utils/widgets/NlsStatut.cpp         \
    utils/widgets/LogShare.cpp          \
    utils/Settings.cpp                  \
    dialogs/edeneternal/GameplayTab.cpp

HEADERS +=                              \
    Config.hpp                          \
    AeriaToolMain.hpp                   \
    EdenEternalTool.hpp                 \
    utils/DSlider.hpp                   \
    utils/TPushButton.hpp               \
    utils/SPushButton.hpp               \
    utils/QPastebinQuery.hpp            \
    utils/threads/DxDiagPastebin.hpp    \
    utils/threads/ThemeExtract.hpp      \
    utils/threads/FilesCompress.hpp     \
    utils/threads/ServerPing.hpp        \
    utils/FreeUpload.hpp                \
    dialogs/edeneternal/ThemeTab.hpp    \
    dialogs/ToolDialog.hpp              \
    dialogs/edeneternal/RescueTab.hpp   \
    utils/ServerStatut.hpp              \
    utils/widgets/NlsStatut.hpp         \
    utils/widgets/LogShare.hpp          \
    utils/Settings.hpp                  \
    dialogs/edeneternal/GameplayTab.hpp

RESOURCES +=                            \
    assets.qrc
