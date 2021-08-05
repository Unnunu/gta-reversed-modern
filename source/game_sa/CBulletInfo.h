/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "CVector.h"
#include "eWeaponType.h"
#include "CEntity.h"

class CBulletInfo {
public:
    eWeaponType m_nWeaponType;
    CEntity*    m_pCreator;
    float       m_nDestroyTime;
    bool        m_bExists;
    char        _pad0D[3];
    CVector     m_vecPosition;
    CVector     m_vecVelocity;
    int16       m_nDamage;
    char        _pad2A[2];

    static CBulletInfo(&aBulletInfos)[8]; // MAX_BULLET_INFOS
    static CVector& PlayerSniperBulletStart;
    static CVector& PlayerSniperBulletEnd;

public:
    static void InjectHooks();

    static void Initialise();
    static void Shutdown();
    static void AddBullet(CEntity* creator, eWeaponType weaponType, CVector position, CVector velocity);
    static void Update();

private:
    // NOTSA funcs
    static CBulletInfo* GetFree();
    bool IsTimeToBeDestroyed() const noexcept { return (float)CTimer::GetTimeInMS() > m_nDestroyTime; }
};

VALIDATE_SIZE(CBulletInfo, 0x2C);
