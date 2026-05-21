#ifndef SYNC_H
#define SYNC_H

#include <semaphore.h>

extern sem_t emptySlots;
extern sem_t fullSlots;
extern sem_t bufferMutex;

void init_sync();
void destroy_sync();

#endif
