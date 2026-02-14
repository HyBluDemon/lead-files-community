#ifndef __METIN2_BUFF_ON_ATTRIBUTES_H
#define __METIN2_BUFF_ON_ATTRIBUTES_H

class CHARACTER;

class CBuffOnAttributes
{
public:
	CBuffOnAttributes(LPCHARACTER pOwner, BYTE m_point_type, std::vector <BYTE>* vec_buff_targets);
	~CBuffOnAttributes();

	// While being installed , m_p_vec_buff_wear_targets If the item corresponds to , Removes effects from the item .
	void RemoveBuffFromItem(LPITEM pItem);
	// m_p_vec_buff_wear_targets If the item corresponds to , of the item attribute Add effects for .
	void AddBuffFromItem(LPITEM pItem);
	// m_bBuffValue change , The value of the buff also changes .
	void ChangeBuffValue(BYTE bNewValue);
	// CHRACTRE::ComputePoints Because attribute values ​​are initialized and recalculated, , 
	// Forcing buff attribute values owner give to .
	void GiveAllAttributes();

	// m_p_vec_buff_wear_targets All items corresponding to attribute cast type Add up not much ,
	// that attribute field (m_bBuffValue)% Gives a buff equal to the amount .
	bool On(BYTE bValue);
	// After removing the buff , reset
	void Off();

	void Initialize();
private:
	LPCHARACTER m_pBuffOwner;
	BYTE m_bPointType;
	BYTE m_bBuffValue;
	std::vector <BYTE>* m_p_vec_buff_wear_targets;
	
	// apply_type, apply_value map of the fair
	typedef std::map <BYTE, int> TMapAttr;
	// m_p_vec_buff_wear_targets All items corresponding to attribute cast type I have it all together .
	TMapAttr m_map_additional_attrs;

};

#endif
