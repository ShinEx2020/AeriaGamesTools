/********************************************************************************************
 *                                                                                          *
 *   Auteur : FoxiesCuties                                                                  *
 *   Sujet Officiel : http://www.aeriagames.com/forums/fr/viewtopic.php?t=212476            *
 *   Licence : GPLv3 ( gpl-3.0.txt/gpl-3.0.fr.txt à la racine des sources )                 *
 *                                                                                          *
 ********************************************************************************************/

#include "DirectXDiag.hpp"

DirectXDiag::DirectXDiag()
{
}

void DirectXDiag::setPath(QString path)
{
    m_CommandStr = "dxdiag.exe /t "+path;
}

void DirectXDiag::run()
{
    m_DxDiagPro = new QProcess();
        m_DxDiagPro->start("cmd.exe");
        m_DxDiagPro->execute(m_CommandStr);
}
