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
    return;
  }
  else{
    if (mode == 0){
      //enq to back
      if (q->front == q->back){
        q->back = qn;
        qn->prev = NULL;
        qn->next = q->front;
        q->front->prev = qn;
      }
      else{
        qn->prev = NULL;
        qn->next = q->back;
        q->back->prev = qn;
        q->back = qn;
      }
    }
    else{
      //enq to front
      if (q->front == q->back){
        q->front = qn;
        qn->next = NULL;
        qn->prev = q->back;
        q->back->next = qn;
      }
      else{
        qn->next = NULL;
        qn->prev = q->front;
        q->front->next = qn;
        q->front = qn;
      }
    }
    q->size++;
    return;
  }
}

void *QUEUE_DEQ(Queue *q,int8_t mode){
  if (q->size == 0){
    return;
  }
  else{
    QNode *deq;
    void *deq_data;
    if (q->front == q->back){
      deq = q->front;
      q->front = NULL;
      q->back = NULL;
    }
    else{
      if (mode == 0){
        //deq from front
        deq = q->front;
        q->front = deq->prev;
        q->front->next = NULL;
      }
      else{
        //deq from back
        deq = q->back;
        q->back = deq->next;
        q->back->prev = NULL;
      }
    }
    deq_data = deq->data;
    free(deq);
    q->size--;
    return deq_data;
  }
}

void QUEUE_TRAVERSE(Queue *q, void (*fx)(void *data),int8_t mode){
  QNode *start;
  if (mode == 0){
    start = q->front;
  }
  else{
    start = q->back;
  }
  while(start != NULL){
    fx(&start->data);
    if (mode == 0){
      start = start->prev;
    }
    else{
      start = start->next;
    }
  };
}
