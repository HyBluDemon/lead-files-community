/*
 *    Filename: buffer.h
 * Description: Buffer processing module
 *
 *      Author: Hanjoo Kim (aka. Rain leaves , Cronan), Youngjin Song (aka. myevan, broomstick )
 */
#ifndef __INC_LIBTHECORE_BUFFER_H__
#define __INC_LIBTHECORE_BUFFER_H__

#define SAFE_BUFFER_DELETE(buf)		{ if(buf != NULL) { buffer_delete(buf); buf = NULL; } }

    typedef struct buffer	BUFFER;
    typedef struct buffer *	LPBUFFER;

    struct buffer
    {
	struct buffer * next;

	char *          write_point;
	int             write_point_pos;

	const char *    read_point;
	int             length;

	char *          mem_data;
	int             mem_size;

	long            flag;
    };

	extern LPBUFFER	buffer_new(int size);				// Create new buffer
    extern void		buffer_delete(LPBUFFER buffer);					// delete buffer
    extern void		buffer_reset(LPBUFFER buffer);					// Initialize buffer lengths

    extern DWORD	buffer_size(LPBUFFER buffer);					// Length remaining in buffer
    extern int		buffer_has_space(LPBUFFER buffer);				// Returns the length that can be written

    extern void		buffer_write (LPBUFFER& buffer, const void* src, int length);	// Write to buffer .
    extern void		buffer_read(LPBUFFER buffer, void * buf, int bytes);		// read from buffer .
    extern BYTE		buffer_get_byte(LPBUFFER buffer);
    extern WORD		buffer_get_word(LPBUFFER buffer);
    extern DWORD	buffer_get_dword(LPBUFFER buffer);

    // buffer_proceed The function is buffer_peek There is a need to return and write a pointer for reading.
    // When processing is completed, it is used when you need to be notified of how much processing has been completed. . 
    // (buffer_read, buffer_get_* In the case of the series, it will be handled automatically, but peek would have been handled with
    //  Because it can't be like that )
    extern const void *	buffer_read_peek(LPBUFFER buffer);				// Returns the reading position
    extern void		buffer_read_proceed(LPBUFFER buffer, int length);		// length Processing has been completed

    // likewise write_peek When getting the writing location and notifying how much has been written
    // buffer_write_proceed use .
    extern void *	buffer_write_peek(LPBUFFER buffer);				// Return writing location
    extern void		buffer_write_proceed(LPBUFFER buffer, int length);		// length only increases .

    extern void		buffer_adjust_size(LPBUFFER & buffer, int add_size);		// add_size Secure enough size to add
#endif
