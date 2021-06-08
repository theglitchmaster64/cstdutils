#include<stdint.h>

//data structs
typedef struct QNode{
  void *data;
  struct QNode *next;
  struct QNode *prev;
} QNode;

typedef struct Queue{
  QNode *front;
  QNode *back;
  uint64_t size;
} Queue;

//fx protoypes
Queue *QUEUE_INIT();
void QUEUE_ENQ(Queue *, void *, int8_t); //mode=0 for enqueue at back, non zero mode for enqueue at front
void *QUEUE_DEQ(Queue *, int8_t); //mode=0 for dequeue at front, non zero mode for dequeue at back
void QUEUE_TRAVERSE(Queue *, void (*)(void *), int8_t); //mode=0 for front to back, mode non zero for back to front
void QUEUE_DESTROY(Queue *);
