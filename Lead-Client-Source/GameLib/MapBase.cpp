#include "StdAfx.h"
#include "MapBase.h"

CMapBase::CMapBase()
{
	Clear();
}

CMapBase::~CMapBase()
{
	Clear();
}

void CMapBase::Clear()
{
	m_strName = "";
	m_eType = MAPTYPE_INVALID;
	mc_pEnvironmentData = NULL;
	Leave();
}

bool CMapBase::Enter()
{
	m_bReady = true;
	return true;
}

bool CMapBase::Leave()
{
	m_bReady = false;
	return true;
}

void CMapBase::SetEnvironmentDataPtr(const TEnvironmentData * c_pEnvironmentData)
{
	mc_pEnvironmentData = c_pEnvironmentData;
	OnSetEnvironmentDataPtr();
}

void CMapBase::ResetEnvironmentDataPtr(const TEnvironmentData * c_pEnvironmentData)
{
	mc_pEnvironmentData = c_pEnvironmentData;
	OnResetEnvironmentDataPtr();
}

void CMapBase::Render()
{
	if (IsReady())
		OnRender();
}

bool CMapBase::LoadProperty()
{
	std::string strFileName = GetName() + "\\MapProperty.txt";

	CTokenVectorMap stTokenVectorMap;
	
	if (!LoadMultipleTextData(strFileName.c_str(), stTokenVectorMap))
	{
		TraceError("CMapBase::LoadProperty(FileName=%s) - LoadMultipleTextData ERROR Most likely the file does not exist.ile does not exist.ile does not exist.ile does not exist.", strFileName.c_str());
		return false;
	}

	if (stTokenVectorMap.end() == stTokenVectorMap.find("scripttype"))
	{
		TraceError("CMapBase::LoadProperty(FileName=%s) - FIND 'scripttype' - FAILED", strFileName.c_str());
		return false;
	}

	if (stTokenVectorMap.end() == stTokenVectorMap.find("maptype"))
	{
		TraceError("CMapBase::LoadProperty(FileName=%s) - FIND 'maptype' - FAILED", strFileName.c_str());
		return false;
	}

	// NOTE: Work to reduce map distribution capacity when adding a new map that uses the same data as existing map data.
	// If the ParentMapName value is set in the MapProperty.txt file, all data is actually read from ParentMap.
	// Since there is no need for partial sharing (partial overwriting?) of data, all data is read from the Parent Map.
	if (stTokenVectorMap.end() != stTokenVectorMap.find("parentmapname"))
	{
		m_strParentMapName = stTokenVectorMap["parentmapname"][0];
	}

	const std::string & c_rstrType = stTokenVectorMap["scripttype"][0];
	const std::string & c_rstrMapType = stTokenVectorMap["maptype"][0];
	
	if (0 != c_rstrType.compare("MapProperty"))
	{
		TraceError("CMapBase::LoadProperty(FileName=%s) - Resourse Type ERROR", strFileName.c_str());
		return false;
	}

	if (0 == c_rstrMapType.compare("Indoor"))
		SetType(MAPTYPE_INDOOR);
	else if (0 == c_rstrMapType.compare("Outdoor"))
		SetType(MAPTYPE_OUTDOOR);
	else if (0 == c_rstrMapType.compare("Invalid"))
		SetType(MAPTYPE_OUTDOOR);

	return true;
}