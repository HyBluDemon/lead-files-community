#pragma once

#include "ActorInstance.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//
//	CGameEventManager
//
// Note: Events such as explosions, screen shakes, and movement and strikes of range weapons that occur in the game.
// A class that comprehensively manages . - [levites]
//
// Note: Used as a manager to control cinematic events in the game. 2004.07.19 - [levites]
//

class CGameEventManager : public CSingleton<CGameEventManager>, public CScreen
{
	public:
		CGameEventManager();
		virtual ~CGameEventManager();

		void SetCenterPosition(float fx, float fy, float fz);
		void Update();

		void ProcessEventScreenWaving(CActorInstance * pActorInstance, const CRaceMotionData::TScreenWavingEventData * c_pData);

	protected:
		TPixelPosition m_CenterPosition;
};
