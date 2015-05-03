QT += widgets core network

QMAKE_CXXFLAGS += -std=c++11

VERSION = 0.0.1.1

DEFINES += \
    PUBLIC_BUILD=\\\"1\\\"

TRANSLATIONS += dialog.ts

SOURCES +=                                              \
    main.cpp                                            \
    app/AeriaMain.cpp                                   \
    app/libs/DSlider.cpp                                \
    app/libs/FreeUpload.cpp                             \
    app/libs/TPushButton.cpp                            \
    app/libs/QPastebinQuery.cpp                         \
    app/threads/DxDiagPastebin.cpp                      \
    app/threads/ThemeExtract.cpp                        \
    app/threads/FilesCompress.cpp                       \
    app/mainButtons/Settings.cpp                        \
    app/mainButtons/About.cpp                           \
    app/mainButtons/Updates.cpp                         \
    app/mainTabs/miscTools/MiscGeneralTool.cpp          \
    app/mainTabs/edenEternal/EdenEternalTool.cpp        \
    app/mainTabs/edenEternal/edenTabs/ThemeTab.cpp      \
    app/mainTabs/edenEternal/edenTabs/RescueTab.cpp     \
    app/mainTabs/edenEternal/classCustom/NlsStatut.cpp  \
    app/mainTabs/edenEternal/classCustom/LogShare.cpp   \
    app/mainTabs/edenEternal/edenTabs/GameplayTab.cpp   \
    app/mainTabs/wolfTeam/WolfTeamTool.cpp              \
    app/mainTabs/auraKingdom/AuraKingdomTool.cpp        \
    app/mainTabs/shaiya/ShaiyaTool.cpp                  \
    app/mainTabs/grandFantasia/GrandFantasiaTool.cpp    \
    app/mainTabs/s4League/S4LeagueTool.cpp              \
    app/mainTabs/ava/AvaTool.cpp                        \
    app/mainTabs/tribesascend/TribesAscendTool.cpp      \
    app/mainTabs/maestia/MaestiaTool.cpp                \
    app/mainTabs/echoOfSoul/EchoOfSoulTool.cpp          \

HEADERS +=                                              \
    app/Config.hpp                                      \
    app/AeriaMain.hpp                                   \
    app/libs/DSlider.hpp                                \
    app/libs/FreeUpload.hpp                             \
    app/libs/TPushButton.hpp                            \
    app/libs/QPastebinQuery.hpp                         \
    app/threads/DxDiagPastebin.hpp                      \
    app/threads/ThemeExtract.hpp                        \
    app/threads/FilesCompress.hpp                       \
    app/mainButtons/Settings.hpp                        \
    app/mainButtons/About.hpp                           \
    app/mainButtons/Updates.hpp                         \
    app/mainTabs/miscTools/MiscGeneralTool.hpp          \
    app/mainTabs/edenEternal/EdenEternalTool.hpp        \
    app/mainTabs/edenEternal/edenTabs/ThemeTab.hpp      \
    app/mainTabs/edenEternal/edenTabs/RescueTab.hpp     \
    app/mainTabs/edenEternal/classCustom/NlsStatut.hpp  \
    app/mainTabs/edenEternal/classCustom/LogShare.hpp   \
    app/mainTabs/edenEternal/edenTabs/GameplayTab.hpp   \
    app/mainTabs/wolfTeam/WolfTeamTool.hpp              \
    app/mainTabs/auraKingdom/AuraKingdomTool.hpp        \
    app/mainTabs/shaiya/ShaiyaTool.hpp                  \
    app/mainTabs/grandFantasia/GrandFantasiaTool.hpp    \
    app/mainTabs/s4League/S4LeagueTool.hpp              \
    app/mainTabs/ava/AvaTool.hpp                        \
    app/mainTabs/tribesascend/TribesAscendTool.hpp      \
    app/mainTabs/maestia/MaestiaTool.hpp                \
    app/mainTabs/echoOfSoul/EchoOfSoulTool.hpp          \

RESOURCES +=                                            \
    assets.qrc                                          \
