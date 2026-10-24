#pragma once
#include <entity2/entityidentity.h>
#include <entity2/entityinstance.h>
#include <bitvec.h>
#include "schemasystem.h"

class CNetworkTransmitComponent {};

// The SDK's game/server/baseentity.h no longer compiles next to entity2 headers; the plugin only needs
// a CEntityInstance-derived base for its schema accessors.
class CBaseEntity : public CEntityInstance {};

enum LifeState_t : uint8_t
{
	LIFE_ALIVE = 0,
	LIFE_DYING,
	LIFE_DEAD,
	LIFE_RESPAWNABLE,
	LIFE_RESPAWNING
};

class SC_CBaseEntity : public CBaseEntity
{
public:
	SCHEMA_FIELD(int32_t, CBaseEntity, m_iHealth);
	SCHEMA_FIELD(int32_t, CBaseEntity, m_iMaxHealth);
	SCHEMA_FIELD(uint8_t, CBaseEntity, m_iTeamNum);
	SCHEMA_FIELD(LifeState_t, CBaseEntity, m_lifeState);
	SCHEMA_FIELD(float, CBaseEntity, m_flGravityScale);
	SCHEMA_FIELD(float, CBaseEntity, m_lastNetworkChange);
	SCHEMA_FIELD(CBitVec<64>, CBaseEntity, m_isSteadyState);
	SCHEMA_FIELD(CNetworkTransmitComponent, CBaseEntity, m_NetworkTransmitComponent);
};