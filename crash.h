#ifndef CRASH_H
#define CRASH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define CRASHES_IN_100 1
#define FALSE 0
#define TRUE  1


pthread_t crash_thread;
pthread_mutex_t crash_mutex;
int crash_now;

void init_crasher();
int crash_write(int vdisk, void * buf, int num_bytes);
void * crash_return(void * args);

#endif
