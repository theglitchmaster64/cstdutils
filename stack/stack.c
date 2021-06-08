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
  uint64_t iters = stack->size;
  while(iters>0){
    fx(top->data);
    top = top->next;
    iters--;
  };
}

void *STACK_POP(Stack *stack){
  if (stack->size == 0){
    return;
  }
  StackNode *tmpnode = stack->top;
  void *popdata = stack->top->data;
  stack->top = tmpnode->next;
  free(tmpnode);
  stack->size--;
  return popdata;
}

void STACK_DESTROY(Stack *stack){
  StackNode *tmp = stack->top;
  StackNode *tofree;
  while(tmp != NULL){
    tofree = tmp;
    tmp = tmp->next;
    free(tofree);
  };
  free(stack);
  stack = NULL;
}
