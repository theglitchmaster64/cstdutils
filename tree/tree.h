#include<stdint.h>

//structs
typedef struct TreeNode{
  void *data;
  struct TreeNode *parent;
  struct TreeNode *childs;
} TreeNode;
// malloc(sizeof(TreeNode)+(n*sizeof(TreeNode)))

//fx prototypes
TreeNode * TEST_TREENODE_INIT(TreeNode *,uint64_t);
