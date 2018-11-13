//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#include "CCallbackMgr.h"

CCallbackMgr::CCallbackMgr(): 
	m_bRunning(false), m_bInitialized(false)
{
}

CCallbackMgr::~CCallbackMgr()
{
}

void CCallbackMgr::Init()
{
	if (m_bInitialized)
	{
		return;
	}

	m_steamApiCallCompleteCb.Register(this, &CCallbackMgr::OnAPICallComplete);
	m_bInitialized = true;
}

bool CCallbackMgr::BRunningCallbacks()
{
	return m_bRunning;
}

void CCallbackMgr::RunCallbacks(HSteamPipe hPipe, bool bServer)
{
	if (m_bRunning || !m_bInitialized) 
	{
		return;
	}

	m_bRunning = true;
	m_hCurrentPipe = hPipe;

	CallbackMsg_t msg;
	while (Steam_BGetCallback(hPipe, &msg))
	{
		auto matched = m_registeredCallbacks.equal_range(msg.m_iCallback);
		for (auto it = matched.first; it != matched.second; ++it)
		{
			it->second->Run(msg.m_pubParam);
		}

		Steam_FreeLastCallback(hPipe);
	}

	m_hCurrentPipe = 0;
	m_bRunning = false;
}

void CCallbackMgr::RegisterCallback(CCallbackBase * pCallback, int iCallback)
{
	if (pCallback->m_nCallbackFlags & CCallbackBase::k_ECallbackFlagsRegistered)
	{
		return;
	}

	m_registeredCallbacks.insert(std::pair<int, CCallbackBase*>(iCallback, pCallback));
	pCallback->m_nCallbackFlags |= CCallbackBase::k_ECallbackFlagsRegistered;
}

void CCallbackMgr::UnregisterCallback(CCallbackBase * pCallback)
{
	if (!(pCallback->m_nCallbackFlags & CCallbackBase::k_ECallbackFlagsRegistered))
	{
		return;
	}

	for (auto it = m_registeredCallbacks.begin(); it != m_registeredCallbacks.end(); ++it)
	{
		if (it->second == pCallback)
		{
			m_registeredCallbacks.erase(it);
			pCallback->m_nCallbackFlags &= ~CCallbackBase::k_ECallbackFlagsRegistered;
			break;
		}
	}
}

// anything related to callresults is not tested... at all
void CCallbackMgr::RegisterCallResult(CCallbackBase * pCallback, SteamAPICall_t hCallResult)
{
	m_registeredCallResults.insert(std::pair<SteamAPICall_t, CCallbackBase*>(hCallResult, pCallback));
}

void CCallbackMgr::UnregisterCallResult(CCallbackBase * pCallResult, SteamAPICall_t hCallResult)
{
	auto matched = m_registeredCallResults.equal_range(hCallResult);
	for (auto it = matched.first; it != matched.second; ++it)
	{
		if (it->second == pCallResult)
		{
			m_registeredCallResults.erase(it);
			break;
		}
	}
}

void CCallbackMgr::OnAPICallComplete(SteamAPICallCompleted_t * cbMsg)
{
	auto matched = m_registeredCallResults.equal_range(cbMsg->m_hAsyncCall);
	if (matched.first == matched.second)
	{
		return;
	}

	CCallbackBase * callResult = matched.first->second;
	char * buf = new char[callResult->GetCallbackSizeBytes()];
	bool failed;
	if (Steam_GetAPICallResult(m_hCurrentPipe, cbMsg->m_hAsyncCall, buf, callResult->GetCallbackSizeBytes(), callResult->m_iCallback, &failed))
	{
		for (auto it = matched.first; it != matched.second;)
		{
			it->second->Run(buf, failed, cbMsg->m_hAsyncCall);
			it = m_registeredCallResults.erase(it);
		}
	}
	delete[] buf;
}

CCallbackMgr& GCallbackMgr()
{
	static CCallbackMgr mgr;
	return mgr;
}