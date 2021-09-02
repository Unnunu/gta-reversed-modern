/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "ListItem_c.h"
#include "FxSphere_c.h"

class FxSystem_c;

/* FX System BluePrint */

class FxSystemBP_c : public ListItem_c {
public:
    uint32      m_nNameKey;
    float       m_fLength;
    float       m_fLoopIntervalMin;
    float       m_fLoopLength;
    short       m_nCullDist;
    uint8       m_nPlayMode;
    uint8       m_nNumEmitters;
    void**      m_emittersList;
    FxSphere_c* m_pBoundingSphere;

public:
    static void InjectHooks();

    FxSystemBP_c();
    FxSystemBP_c* Constructor();

    ~FxSystemBP_c();
    FxSystemBP_c* Destructor();

    static void* operator new(uint32 size);

    void Load(char* filename, int32 file, int32 version);

    void Unload();
    void Update(float arg0);
    void Render(RwCamera* camera, float dayNightBalance, bool bHeatHaze);
    bool FreePrtFromSystem(FxSystem_c* system);
    FxSphere_c* GetBoundingSphere();
    void SetBoundingSphere(RwV3d* center, float radius);
};

VALIDATE_SIZE(FxSystemBP_c, 0x24);