#pragma once
#include "CCSPlayerPawnBase.h"
#include "schemasystem.h"

class CCSPlayerPawn : public CCSPlayerPawnBase
{
public:
    SCHEMA_FIELD(GameTime_t, CCSPlayerPawn, m_flHealthShotBoostExpirationTime);
};