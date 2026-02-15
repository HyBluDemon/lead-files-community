
#ifndef METIN2_TABLE_BY_SKILL_
#define METIN2_TABLE_BY_SKILL_

class CTableBySkill : public singleton<CTableBySkill>
{
	public:
		CTableBySkill()
			: m_aiSkillDamageByLevel(NULL)
		{
			// Reset additional damage per skill level
			for ( int job = 0; job < JOB_MAX_NUM * 2; ++job )
				m_aiSkillPowerByLevelFromType[job] = NULL;
		}

		~CTableBySkill()
		{
			DeleteAll();
		}

		// Table setting check
		bool 	Check() const;

		// delete
		void 	DeleteAll();

		// Skill level unit skill power table
		int 	GetSkillPowerByLevelFromType( int job, int skillgroup, int skilllevel, bool bMob ) const;
		void 	SetSkillPowerByLevelFromType( int idx, const int* aTable );
		void	DeleteSkillPowerByLevelFromType( int idx );

		// Additional skill damage table per level
		int 	GetSkillDamageByLevel( int Level ) const;
		void	SetSkillDamageByLevelTable( const int* aTable );
		void 	DeleteSkillDamageByLevelTable();

	private:
		int * m_aiSkillPowerByLevelFromType[JOB_MAX_NUM*2];
		int * m_aiSkillDamageByLevel;
};

#endif /* METIN2_TABLE_BY_SKILL_ */

