#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include "queue.h"

Queue *QUEUE_INIT(){
  Queue *q = malloc(sizeof(Queue));
  q->front = NULL;
  q->back = NULL;
  q->size = 0;
  return q;
}

void QUEUE_ENQ(Queue *q, void *data,int8_t mode){
  QNode *qn = malloc(sizeof(QNode));
  qn->data = data;
  if (q->size == 0){
    qn->next = NULL;
    qn->prev = NULL;
    q->front = qn;
    q->back = qn;
    q->size++;
  }
  else{
    if (mode == 0){
      //enq to back
      qn->next = q->back;
      q->back = qn;
      qn->prev = NULL;
      q->size++;
    }
    else{
      //enq to front
      qn->next = NULL;
      qn->prev = q->front;
      q->front = qn;
      q->size++;
    }
  }
  return q;
}
