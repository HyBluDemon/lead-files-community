#ifndef __INC_METIN_II_GAME_CSkillManager_H__
#define __INC_METIN_II_GAME_CSkillManager_H__

#include "../../libpoly/Poly.h"

enum ESkillFlags
{
	SKILL_FLAG_ATTACK			= (1 << 0),	// attack skills
	SKILL_FLAG_USE_MELEE_DAMAGE		= (1 << 1),	// Basic melee hit value b used as value
	SKILL_FLAG_COMPUTE_ATTGRADE		= (1 << 2),	// Calculate attack rating
	SKILL_FLAG_SELFONLY			= (1 << 3),	// Can only be used by yourself
	SKILL_FLAG_USE_MAGIC_DAMAGE		= (1 << 4),	// Basic magic hit b used as value
	SKILL_FLAG_USE_HP_AS_COST		= (1 << 5),	// HP cast SP write instead
	SKILL_FLAG_COMPUTE_MAGIC_DAMAGE	= (1 << 6),
	SKILL_FLAG_SPLASH			= (1 << 7),
	SKILL_FLAG_GIVE_PENALTY		= (1 << 8),	// After writing it, for a while (3 candle ) 2 Take double damage .
	SKILL_FLAG_USE_ARROW_DAMAGE		= (1 << 9),	// Basic arrow hit value b used as value
	SKILL_FLAG_PENETRATE		= (1 << 10),	// Ignore defense
	SKILL_FLAG_IGNORE_TARGET_RATING	= (1 << 11),	// Ignore opponent rating
	SKILL_FLAG_SLOW			= (1 << 12),	// slow attack
	SKILL_FLAG_STUN			= (1 << 13),	// stun attack
	SKILL_FLAG_HP_ABSORB		= (1 << 14),	// HP absorption
	SKILL_FLAG_SP_ABSORB		= (1 << 15),	// SP absorption
	SKILL_FLAG_FIRE_CONT		= (1 << 16),	// FIRE Continuous Damage
	SKILL_FLAG_REMOVE_BAD_AFFECT	= (1 << 17),	// Remove bad effects
	SKILL_FLAG_REMOVE_GOOD_AFFECT	= (1 << 18),	// Remove bad effects
	SKILL_FLAG_CRUSH			= (1 << 19),	// knock the opponent away
	SKILL_FLAG_POISON			= (1 << 20),	// poison attack
	SKILL_FLAG_TOGGLE			= (1 << 21),	// toggle
	SKILL_FLAG_DISABLE_BY_POINT_UP	= (1 << 22),	// I can't take a picture and upload it .
	SKILL_FLAG_CRUSH_LONG		= (1 << 23),	// throw the opponent away
	SKILL_FLAG_WIND		= (1 << 24),	// wind properties 
	SKILL_FLAG_ELEC		= (1 << 25),	// electrical properties
	SKILL_FLAG_FIRE		= (1 << 26),	// fire attribute
};

enum
{
	SKILL_PENALTY_DURATION = 3,
	SKILL_TYPE_HORSE = 5,
};

enum ESkillIndexes
{
	SKILL_RESERVED = 0,

	// warrior warrior series
	// A
	SKILL_SAMYEON = 1,		// 3 years old ( Three cuts )
	SKILL_PALBANG,		// All winds and rain
	// S
	SKILL_JEONGWI,		// ex-ghost marriage
	SKILL_GEOMKYUNG,		// speculum
	SKILL_TANHWAN,		// bullet hit

	// Musa Qigong series
	// A
	SKILL_GIGONGCHAM = 16,	// Technician
	SKILL_GYOKSAN,		// Gyeoksan Tau
	SKILL_DAEJINGAK,		// Daejingak
	// S
	SKILL_CHUNKEON,		// Cheongeunchu
	SKILL_GEOMPUNG,		// sword wind

	// Assassin Assassination Series
	// A
	SKILL_AMSEOP = 31,		// sneak attack 
	SKILL_GUNGSIN,		// Gungsin Tanyeong 
	SKILL_CHARYUN,		// wheel spokes 
	// S
	SKILL_EUNHYUNG,		// silver criminal law 
	SKILL_SANGONG,		// industrial division

	// Assassin Archer series
	// A
	SKILL_YEONSA = 46,		// speaker 
	SKILL_KWANKYEOK,		// vasculature 
	SKILL_HWAJO,		// Harmony and Harmony
	// S
	SKILL_GYEONGGONG,		// light surgery 
	SKILL_GIGUNG,		// GiGung

	// Sura Sword
	// A
	SKILL_SWAERYUNG = 61,	// Saeryeongji 
	SKILL_YONGKWON,		// Dragon Fists 
	// S
	SKILL_GWIGEOM,		// ghost sword
	SKILL_TERROR,		// horror 
	SKILL_JUMAGAP,		// Jumagap 
	SKILL_PABEOB,		// Pabeopjutsu

	// Sura Magic
	// A
	SKILL_MARYUNG = 76,		// devil 
	SKILL_HWAYEOMPOK,		// flame width 
	SKILL_MUYEONG,		// Youngjin Mu 
	// S
	SKILL_MANASHILED,		// Dark God Guardian
	SKILL_TUSOK,		// Tusokmaryeong 
	SKILL_MAHWAN,		// demon fight

	// Shaman Yongsin
	// A
	SKILL_BIPABU = 91,
	SKILL_YONGBI,		// Yongbi Gwangsapa 
	SKILL_PAERYONG,		// Paeryongna Hanmu
	// S
	//SKILL_BUDONG,		// floating nail 
	SKILL_HOSIN,		// self defense 
	SKILL_REFLECT,		// protect
	SKILL_GICHEON,		// Grand Duke Gicheon

	// shaman thunder god
	// A
	SKILL_NOEJEON = 106,	// thunder messenger 
	SKILL_BYEURAK,		// thunderbolt 
	SKILL_CHAIN,		// Chain Lightning 
	// S
	SKILL_JEONGEOP,		// full-time businessman 
	SKILL_KWAESOK,		// Movement speed up
	SKILL_JEUNGRYEOK,		// Augmentation

	// common skills
	// 7
	SKILL_7_A_ANTI_TANHWAN = 112,
	SKILL_7_B_ANTI_AMSEOP,
	SKILL_7_C_ANTI_SWAERYUNG,
	SKILL_7_D_ANTI_YONGBI,

	// 8
	SKILL_8_A_ANTI_GIGONGCHAM,
	SKILL_8_B_ANTI_YEONSA,
	SKILL_8_C_ANTI_MAHWAN,
	SKILL_8_D_ANTI_BYEURAK,

	// Secondary Skill

	SKILL_LEADERSHIP = 121,	// leadership
	SKILL_COMBO	= 122,		// Linker
	SKILL_CREATE = 123,		// manufacturing
	SKILL_MINING = 124,

	SKILL_LANGUAGE1 = 126,	// New word ability
	SKILL_LANGUAGE2 = 127,	// Thousands of words ability
	SKILL_LANGUAGE3 = 128,	// Jinnor Abilities
	SKILL_POLYMORPH = 129,	// disguise

	SKILL_HORSE			= 130,	// horse riding skills
	SKILL_HORSE_SUMMON		= 131,	// horse summoning skill
	SKILL_HORSE_WILDATTACK	= 137,	// dance wildly
	SKILL_HORSE_CHARGE		= 138,	// charge
	SKILL_HORSE_ESCAPE		= 139,	// escape
	SKILL_HORSE_WILDATTACK_RANGE = 140,	// dance wildly ( bow )

	SKILL_ADD_HP	=	141,			// blood clotting
	SKILL_RESIST_PENETRATE	=	142,	// ironclad

	GUILD_SKILL_START = 151,
	GUILD_SKILL_EYE = 151,
	GUILD_SKILL_BLOOD = 152,
	GUILD_SKILL_BLESS = 153,
	GUILD_SKILL_SEONGHWI = 154,
	GUILD_SKILL_ACCEL = 155,
	GUILD_SKILL_BUNNO = 156,
	GUILD_SKILL_JUMUN = 157,
	GUILD_SKILL_TELEPORT = 158,
	GUILD_SKILL_DOOR = 159,
	GUILD_SKILL_END = 162,

	GUILD_SKILL_COUNT = GUILD_SKILL_END - GUILD_SKILL_START + 1,

};

class CSkillProto
{
	public:
		char	szName[64];
		DWORD	dwVnum;			// number

		DWORD	dwType;			// 0: previous job , 1: safe , 2: assassin , 3: Sura , 4: psychic
		BYTE	bMaxLevel;		// maximum training degree
		BYTE	bLevelLimit;		// level limit
		int	iSplashRange;		// Splash distance limit

		BYTE	bPointOn;		// Where to apply the results ? ( Hit value , MAX HP, HP REGEN And so on and so forth. )
		CPoly	kPointPoly;		// Formula for generating result values

		CPoly	kSPCostPoly;		// use SP official
		CPoly	kDurationPoly;		// duration formula
		CPoly	kDurationSPCostPoly;	// continue SP official
		CPoly	kCooldownPoly;		// Cooldown time formula
		CPoly	kMasterBonusPoly;	// Bonus formula when master
		CPoly	kSplashAroundDamageAdjustPoly;	// Damage reduction rate to nearby enemies in case of splash attack

		DWORD	dwFlag;			// Skill Options
		DWORD	dwAffectFlag;		// Applies when hit by a skill Affect

		BYTE	bLevelStep;		// Number of skill points required to raise at one time
		DWORD	preSkillVnum;		// Skills that need to be learned before
		BYTE	preSkillLevel;		// Level of skills to be learned previously

		long	lMaxHit;

		BYTE	bSkillAttrType;

		// 2 tea application
		BYTE	bPointOn2;		
		CPoly	kPointPoly2;		
		CPoly	kDurationPoly2;		
		DWORD	dwFlag2;			
		DWORD	dwAffectFlag2;		

		DWORD   dwTargetRange;

		bool	IsChargeSkill()
		{
			return dwVnum == SKILL_TANHWAN || dwVnum == SKILL_HORSE_CHARGE; 
		}

		// 3 tea application
		BYTE bPointOn3;
		CPoly kPointPoly3;
		CPoly kDurationPoly3;

		CPoly kGrandMasterAddSPCostPoly;

		void SetPointVar(const std::string& strName, double dVar);
		void SetDurationVar(const std::string& strName, double dVar);
		void SetSPCostVar(const std::string& strName, double dVar);
};

class CSkillManager : public singleton<CSkillManager>
{
	public:
		CSkillManager();
		virtual ~CSkillManager();

		bool Initialize(TSkillTable * pTab, int iSize);
		CSkillProto * Get(DWORD dwVnum);
		CSkillProto * Get(const char * c_pszSkillName);

	protected:
		std::map<DWORD, CSkillProto *> m_map_pkSkillProto;
};

#endif
