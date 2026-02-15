#ifndef _EL_CPOSTIT_H_
#define _EL_CPOSTIT_H_

// _CPostItMemoryBlock is defined in CPostIt.cpp
class _CPostItMemoryBlock;

/*
 * @class CPostIt @brief Class used to transmit information from the game launcher to the game client and receive it from the client.
 */
class CPostIt
{
public:
	/* @brief CPostIt constructor @param [in] szAppName: Enters the name of the game. */
	explicit CPostIt( LPCSTR szAppName );

	/**
	 * @brief	CPostIt destructor
	 */
	~CPostIt( void );

	/* @brief Saves the data held in the CPostIt class to the clipboard. */
	BOOL	Flush( void );

	/*
 * @brief Deletes the data held by the CPostIt class and the contents of the clipboard.
 */
	void	Empty( void );

	/*
 * @brief Reads data. @param [in] lpszKeyName: Key of data to load. Enter “KEY” type content. @param [in] lpszData: Buffer of data to load @param [in] nSize: Maximum size of lpszData buffer
 */
	BOOL	Get( LPCSTR lpszKeyName, LPSTR lpszData, DWORD nSize );

	/*
 * @brief Enter the data to be saved. @param [in] lpBuffer: Data to save. Enter content in the format “KEY=DATA”.
 */
	BOOL	Set( LPCSTR lpszData );

	/*
 * @brief Enter the data to be saved. @param [in] lpszKeyName: Key of data to save. Enter “KEY” type content. @param [in] lpszData: Data to save. Enter “DATA” type content.
 */
	BOOL	Set( LPCSTR lpszKeyName, LPCSTR lpszData );

	/*
 * @brief Enter the data (DWORD) to be saved. @param [in] lpBuffer: Data to save. Enter data in the format “KEY=DATA”. @param [in] dwValue: Data to save. (DWORD)
 */
	BOOL	Set( LPCSTR lpszKeyName, DWORD dwValue );

	/*
 * @brief Copy the CPostIt class. (Because the class constructor has a name argument, a new name must be specified) @param [in] pPostIt : Destination class @param [in] lpszKeyName : Destination class's new app-name
 */
	BOOL	CopyTo( CPostIt *pPostIt, LPCSTR lpszKeyName );

protected:
	BOOL					Init( LPCSTR szAppName );
	void					Destroy( void );

protected:
	BOOL					m_bModified;
	CHAR					m_szClipFormatName[_MAX_PATH];
	_CPostItMemoryBlock*	m_pMemoryBlock;
};

#endif /* _EL_CPOSTIT_H_ */
