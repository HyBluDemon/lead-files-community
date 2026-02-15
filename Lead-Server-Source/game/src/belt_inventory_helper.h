#ifndef __HEADER_BELT_INVENTORY_HELPER__
#define __HEADER_BELT_INVENTORY_HELPER__

#include "char.h"
#include "item.h"

class CBeltInventoryHelper
{
public:
	typedef BYTE	TGradeUnit;

	static TGradeUnit GetBeltGradeByRefineLevel(int level)
	{
		static TGradeUnit beltGradeByLevelTable[] = 
		{
			0,			// belt +0
			1,			// +1
			1,			// +2
			2,			// +3
			2,			// +4,
			3,			// +5
			4,			// +6,
			5,			// +7,
			6,			// +8,
			7,			// +9
		};

		if (level >= _countof(beltGradeByLevelTable))
		{
			sys_err("CBeltInventoryHelper::GetBeltGradeByRefineLevel - Overflow level (%d", level);
			return 0;
		}

		return beltGradeByLevelTable[level];
	}

	// Based on current belt level , Returns which cells are available
	static const TGradeUnit* GetAvailableRuleTableByGrade()
	{
		/**
			belt is gun +0 ~ +9 can have levels , according to level 7 The inventory is activated by classifying it into stages. .
			The available cells according to belt level are as shown below. . current rating >= Can be used if the level is activated .
			( step , Current level 0 If so, it cannot be used at all , Numbers in parentheses are grades )
			
				2(1)  4(2)  6(4)  8(6)
				5(3)  5(3)  6(4)  8(6)
				7(5)  7(5)  7(5)  8(6)
				9(7)  9(7)  9(7)  9(7)

			The size of the belt inventory is 4x4 (16 Cannes )
		*/

		static TGradeUnit availableRuleByGrade[BELT_INVENTORY_SLOT_COUNT] = {
			1, 2, 4, 6,
			3, 3, 4, 6,
			5, 5, 5, 6,
			7, 7, 7, 7
		};

		return availableRuleByGrade;
	}

	static bool IsAvailableCell(WORD cell, int beltGrade /*int beltLevel*/)
	{
		// Plan changed again .. Oh my ...
		//const TGradeUnit beltGrade = GetBeltGradeByRefineLevel(beltLevel);		
		const TGradeUnit* ruleTable = GetAvailableRuleTableByGrade();

		return ruleTable[cell] <= beltGrade;
	}

	/// pc A function that checks whether at least one item exists in the belt inventory of .
	static bool IsExistItemInBeltInventory(LPCHARACTER pc)
	{
		for (WORD i = BELT_INVENTORY_SLOT_START; i < BELT_INVENTORY_SLOT_END; ++i)
		{
			LPITEM beltInventoryItem = pc->GetInventoryItem(i);

			if (NULL != beltInventoryItem)
				return true;
		}

		return false;
	}

	/// item A function to check whether this type of belt can fit into the inventory. . ( These rules are determined by the planner )
	static bool CanMoveIntoBeltInventory(LPITEM item)
	{
		bool canMove = false;

		if (item->GetType() == ITEM_USE)
		{
			switch (item->GetSubType())
			{
			case USE_POTION:
			case USE_POTION_NODELAY:
			case USE_ABILITY_UP:
				canMove = true;
				break;
			}
		}

		return canMove;
	}

};

#endif //__HEADER_BELT_INVENTORY_HELPER__