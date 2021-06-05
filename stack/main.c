#include<stdio.h>
#include "stack.h"
#include<stdint.h>

void printStackNode(StackNode *node){
  printf("data=%d\tnode_size=%d\taddr=%p\tnext=%p\n",node->data,sizeof(node),node,&node->next);
}

void printStack(Stack *stack){
  printf("base=%p\t",*stack->base);
  printf("length=%d\tsize=%d\t",stack->size,sizeof(stack));
  printf("top=%p\n",*stack->top);
}

int main(){
  Stack *stack = STACK_INIT();
  uint64_t mydata[5] = {1738,1739,1990,2020,2021};
  for(int i=0;i<5;i++){
    STACK_PUSH(stack,&mydata[i]);
    printStack(stack);
    STACK_TRAVERSE(stack,printStackNode);
    printf("\n");
  }
  return 0;
}
