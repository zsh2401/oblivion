#ifndef __BTREE
#define __BTREE
#include "fx.h"
#include <functional>
namespace btree
{
typedef struct _btree_node
{
    _btree_node *parent;
    _btree_node *lchild;
    _btree_node *rchild;
    fx::data_t data;
} BinaryTreeNode, *BinaryTree, *BTree, BTreeNode;
typedef std::function<void(fx::data_t)> Visitor;
BinaryTreeNode *createNode(fx::data_t data);
BinaryTreeNode *createLChildOf(BinaryTreeNode *root, fx::data_t data);
BinaryTreeNode *createRChildOf(BinaryTreeNode *root, fx::data_t data);
void dlr(BinaryTree tree, Visitor visitor);
void ldr(BinaryTree tree, Visitor visitor);
void lrd(BinaryTree tree, Visitor visitor);
size_t depthOf(BinaryTree tree);
size_t leafsOf(BinaryTree tree);
} // namespace btree
#endif