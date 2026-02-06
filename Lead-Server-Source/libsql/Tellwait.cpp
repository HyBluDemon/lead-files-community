#include "stdafx.h"
#ifndef __WIN32__
    #include <sys/cdefs.h>
    #include <sys/types.h>
    #include "/usr/include/signal.h"
    #include <unistd.h>
#endif

#include <cstdio>
#include <cstdlib>

#ifndef __WIN32__
    static volatile sig_atomic_t sigflag;
    static sigset_t newmask, oldmask, zeromask;

    static void sig_usr(int signo) {
        sigflag = 1;
    }
#endif

extern "C" {

void TELL_WAIT() {
#ifndef __WIN32__
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
        fprintf(stderr, "signal(SIGUSR1) error\n");
        exit(1);
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
        fprintf(stderr, "signal(SIGUSR2) error\n");
        exit(1);
    }

    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGUSR1);
    sigaddset(&newmask, SIGUSR2);

    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
        fprintf(stderr, "SIG_BLOCK error\n");
        exit(1);
    }
#endif
}

void TELL_PARENT(pid_t pid) {
#ifndef __WIN32__
    kill(pid, SIGUSR2);
#endif
}

void WAIT_PARENT(void) {
#ifndef __WIN32__
    while (sigflag == 0)
        sigsuspend(&zeromask);
    sigflag = 0;
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
        fprintf(stderr, "SIG_SETMASK error\n");
        exit(1);
    }
#endif
}

void TELL_CHILD(pid_t pid) {
#ifndef __WIN32__
    kill(pid, SIGUSR1);
#endif
}

void WAIT_CHILD(void) {
#ifndef __WIN32__
    while (sigflag == 0)
        sigsuspend(&zeromask);
    sigflag = 0;
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
        fprintf(stderr, "SIG_SETMASK error\n");
        exit(1);
    }
#endif
}

} // extern "C"
