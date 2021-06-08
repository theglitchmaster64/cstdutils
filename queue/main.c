#include<stdio.h>
#include "queue.h"
#include<stdint.h>

void printQNode(QNode *qn){
  printf("data=%d\taddr=%p\tprev=%p\tnext=%p\t\n",qn->data,qn,qn->prev,qn->next);
}

void printQ(Queue *q){
  printf("size=%d\tfront=%p\tback=%p\n",q->size,q->front,q->back);
}

int main(){
  Queue *q = QUEUE_INIT();
  printf("%p\n",q);
  uint64_t mydata[5] = {1738,1739,1990,2020,2021};
  for(int i=0;i<5;i++){
    QUEUE_ENQ(q,mydata[i],1);
  }
  printQ(q);
  QUEUE_TRAVERSE(q,printQNode,0);
  printf("\n");
  QUEUE_DEQ(q,0);QUEUE_DEQ(q,1);
  printQ(q);
  QUEUE_TRAVERSE(q,printQNode,0);
  printf("\nQ\n");
  QUEUE_DESTROY(q);
  return 0;
}
