#include "sync.h"
#include "buffer.h"

sem_t emptySlots;
sem_t fullSlots;
sem_t bufferMutex;

void init_sync() {
	sem_init(&emptySlots, 0, BUFFER_SIZE);
	sem_init(&fullSlots, 0, 0);
	sem_init(&bufferMutex, 0, 1);
}

void destroy_sync() {
	sem_destroy(&emptySlots);
	sem_destroy(&fullSlots);
	sem_destroy(&bufferMutex);
}
