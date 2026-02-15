#ifndef __INC_LIBTHECORE_HANGUL_H__
#define __INC_LIBTHECORE_HANGUL_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __WIN32__
#define isdigit iswdigit
#define isspace iswspace
#endif

#define ishan(ch)       (((ch) & 0xE0) > 0x90)
#define ishanasc(ch)    (isascii(ch) || ishan(ch))
#define ishanalp(ch)    (isalpha(ch) || ishan(ch))
#define isnhdigit(ch)   (!ishan(ch) && isdigit(ch))
#define isnhspace(ch)   (!ishan(ch) && isspace(ch))

    extern const char *	first_han(const BYTE * str);	// vowel of first two letters ( Korean consonants (g/n/d) ) pull it out / me / all /.. returns .
    extern int		check_han(const char * str);	// If it's Hangul true Check all strings
    extern int		is_hangul(const BYTE * str);	// If it's Hangul true (2 Check only bytes )
    extern int		under_han(const void * orig);	// If there is a stand true

#define UNDER(str)	under_han(str)

#ifdef __cplusplus
};
#endif

#endif
