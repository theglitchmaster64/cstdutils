#include<stdint.h>

// data structs
typedef struct StackNode{
  void *data;
  struct StackNode *next;
} StackNode;

typedef struct Stack{
  StackNode *top;
  StackNode *base;
  uint64_t size;
} Stack;

//fx protoypes
Stack *STACK_INIT();
Stack *STACK_PUSH(Stack *,void *);
void *STACK_POP(Stack *);
void STACK_TRAVERSE(Stack *, void (*)(void *));
void STACK_DESTROY(Stack *);
