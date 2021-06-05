#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include "stack.h"

Stack *STACK_INIT(){
  Stack *stack = malloc(sizeof(Stack));
  stack->base = NULL;
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

Stack *STACK_PUSH(Stack *stack, void *data){
  StackNode *tmpnode = malloc(sizeof(StackNode));
  if (stack->size == 0){
    stack->base = tmpnode;
  }
  tmpnode->data = data;
  tmpnode->next = stack->top;
  stack->top = tmpnode;
  stack->size++;
  return stack;
}

void STACK_TRAVERSE(Stack *stack, void (*fx)(void *data)){
  StackNode *top = stack->top;
  while(top!=NULL){
    fx(top->data);
    top = top->next;
  };
}
