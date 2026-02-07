#ifndef __INC_METIN_II_LIBSQL_TELLWAIT_H__
#define __INC_METIN_II_LIBSQL_TELLWAIT_H__

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

    void TELL_WAIT();
    void TELL_PARENT(pid_t pid);
    void WAIT_PARENT();
    void TELL_CHILD(pid_t pid);
    void WAIT_CHILD();

#ifdef __cplusplus
}
#endif

#endif
