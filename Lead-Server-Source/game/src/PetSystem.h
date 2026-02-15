#ifndef	__HEADER_PET_SYSTEM__
#define	__HEADER_PET_SYSTEM__


class CHARACTER;

// TODO: Abilities as a pet ? Or intimacy , hunger, etc. ... black eye
struct SPetAbility
{
};

/**
*/
class CPetActor //: public CHARACTER
{
public:
	enum EPetOptions
	{
		EPetOption_Followable		= 1 << 0,
		EPetOption_Mountable		= 1 << 1,
		EPetOption_Summonable		= 1 << 2,
		EPetOption_Combatable		= 1 << 3,		
	};


protected:
	friend class CPetSystem;

	CPetActor(LPCHARACTER owner, DWORD vnum, DWORD options = EPetOption_Followable | EPetOption_Summonable);
//	CPetActor(LPCHARACTER owner, DWORD vnum, const SPetAbility& petAbility, DWORD options = EPetOption_Followable | EPetOption_Summonable);

	virtual ~CPetActor();

	virtual bool	Update(DWORD deltaTime);

protected:
	virtual bool	_UpdateFollowAI();				///< following the owner AI treatment
	virtual bool	_UpdatAloneActionAI(float fMinDist, float fMaxDist);			///< Playing alone near the owner AI treatment

	/// @TODO
	//virtual bool	_UpdateCombatAI();

private:
	bool Follow(float fMinDistance = 50.f);

public:
	LPCHARACTER		GetCharacter()	const					{ return m_pkChar; }
	LPCHARACTER		GetOwner()	const						{ return m_pkOwner; }
	DWORD			GetVID() const							{ return m_dwVID; }
	DWORD			GetVnum() const							{ return m_dwVnum; }

	bool			HasOption(EPetOptions option) const		{ return m_dwOptions & option; }

	void			SetName(const char* petName);

	bool			Mount();
	void			Unmount();

	DWORD			Summon(const char* petName, LPITEM pSummonItem, bool bSpawnFar = false);
	void			Unsummon();

	bool			IsSummoned() const			{ return 0 != m_pkChar; }
	void			SetSummonItem (LPITEM pItem);
	DWORD			GetSummonItemVID () { return m_dwSummonItemVID; }
	// Functions that give and remove buffs .
	// This is a bit weird , Because the server sucks , 
	// POINT_MOV_SPEED, POINT_ATT_SPEED, POINT_CAST_SPEED Is PointChange() There is no use trying to change it using only the function . ,
	// PointChange() somewhere after that ComputePoints() If you do this, everything will be reset. , 
	// What's funnier is , ComputePoints() If you don't call, POINT does not change at all .
	// So giving a buff is ComputePoints() from the inside petsystem->RefreshBuff() I asked them to call ,
	// Removing the buff is ClearBuff() call , ComputePoints It is done by doing .
	void			GiveBuff();
	void			ClearBuff();

private:
	DWORD			m_dwVnum;
	DWORD			m_dwVID;
	DWORD			m_dwOptions;
	DWORD			m_dwLastActionTime;
	DWORD			m_dwSummonItemVID;
	DWORD			m_dwSummonItemVnum;

	short			m_originalMoveSpeed;

	std::string		m_name;

	LPCHARACTER		m_pkChar;					// Instance of pet(CHARACTER)
	LPCHARACTER		m_pkOwner;

//	SPetAbility		m_petAbility;				// ability
};

/**
*/
class CPetSystem
{
public:
	typedef	boost::unordered_map<DWORD,	CPetActor*>		TPetActorMap;		/// <VNUM, PetActor> map. ( one character is the same vnum Is it possible to have multiple pets? ..??)

public:
	CPetSystem(LPCHARACTER owner);
	virtual ~CPetSystem();

	CPetActor*	GetByVID(DWORD vid) const;
	CPetActor*	GetByVnum(DWORD vnum) const;

	bool		Update(DWORD deltaTime);
	void		Destroy();

	size_t		CountSummoned() const;			///< currently summoned ( with embodied characters ) Number of pets

public:
	void		SetUpdatePeriod(DWORD ms);

	CPetActor*	Summon(DWORD mobVnum, LPITEM pSummonItem, const char* petName, bool bSpawnFar, DWORD options = CPetActor::EPetOption_Followable | CPetActor::EPetOption_Summonable);

	void		Unsummon(DWORD mobVnum, bool bDeleteFromList = false);
	void		Unsummon(CPetActor* petActor, bool bDeleteFromList = false);

	// TODO: Implemented when the real pet system is implemented . ( When adding information about a pet owned by a character ...)
	CPetActor*	AddPet(DWORD mobVnum, const char* petName, const SPetAbility& ability, DWORD options = CPetActor::EPetOption_Followable | CPetActor::EPetOption_Summonable | CPetActor::EPetOption_Combatable);

	void		DeletePet(DWORD mobVnum);
	void		DeletePet(CPetActor* petActor);
	void		RefreshBuff();

private:
	TPetActorMap	m_petActorMap;
	LPCHARACTER		m_pkOwner;					///< of the pet system Owner
	DWORD			m_dwUpdatePeriod;			///< update cycle (ms unit )
	DWORD			m_dwLastUpdateTime;
	LPEVENT			m_pkPetSystemUpdateEvent;
};

/**
// Summon Pet
CPetSystem* petSystem = mainChar->GetPetSystem();
CPetActor* petActor = petSystem->Summon(~~~);

DWORD petVID = petActor->GetVID();
if (0 == petActor)
{
	ERROR_LOG(...)
};


// Unsummon Pet
petSystem->Unsummon(petVID);

// Mount Pet
petActor->Mount()..


CPetActor::Update(...)
{
	// AI : Follow, actions, etc...
}

*/



#endif	//__HEADER_PET_SYSTEM__