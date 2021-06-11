#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include "tree.h"


TreeNode *TEST_TREENODE_INIT(TreeNode *tn, uint64_t no_childs) {
  printf("%d\n",sizeof(TreeNode)+(no_childs*sizeof(TreeNode)));
  tn = malloc(sizeof(TreeNode)+(no_childs*sizeof(TreeNode)));
  tn->parent = NULL;
  tn->data = NULL;
  return tn;
}
