#ifndef _SYS_SEM_H
#define _SYS_SEM_H

#include <bits/ansi/time_t.h>
#include <sys/ipc.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SETVAL 16

#define SEM_UNDO 0x1000

struct sembuf {
	unsigned short int sem_num;
	short int sem_op;
	short int sem_flg;
};

struct semid_ds {
	struct ipc_perm sem_perm;
	time_t          sem_otime;
	time_t          sem_ctime;

	unsigned long   sem_nsems;
};

int semget(key_t, int, int);
int semop(int, struct sembuf *, size_t);
int semctl(int, int, int, ...);

#ifdef __cplusplus
}
#endif

#endif // _SYS_SEM_H
