#include "../headers/binarytree.h"
#include <stdlib.h>
namespace btree
{
BinaryTreeNode *createNode(fx::data_t data)
{
    auto pNewNode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    pNewNode->data = data;
    pNewNode->lchild = NULL;
    pNewNode->rchild = NULL;
    pNewNode->parent = NULL;
    return pNewNode;
}
BinaryTreeNode *createLChildOf(BinaryTreeNode *root, fx::data_t data)
{
    auto pNewNode = createNode(data);
    root->lchild = pNewNode;
    pNewNode->parent = root;
    return pNewNode;
}
BinaryTreeNode *createRChildOf(BinaryTreeNode *root, fx::data_t data)
{
    auto pNewNode = createNode(data);
    root->rchild = pNewNode;
    pNewNode->parent = root;
    return pNewNode;
}
void dlr(BinaryTree tree, Visitor visitor)
{
    if (tree != NULL)
    {
        visitor(tree->data);
        dlr(tree->lchild, visitor);
        dlr(tree->rchild, visitor);
    }
}
void ldr(BinaryTree tree, Visitor visitor)
{
    if (tree)
    {
        ldr(tree->lchild, visitor);
        visitor(tree->data);
        ldr(tree->rchild, visitor);
    }
}
void lrd(BinaryTree tree, Visitor visitor)
{
    if (tree)
    {
        lrd(tree->lchild, visitor);
        lrd(tree->rchild, visitor);
        visitor(tree->data);
    }
}
size_t depthOf(BinaryTree tree)
{
    if (tree != NULL)
    {
        size_t ld = depthOf(tree->lchild);
        size_t rd = depthOf(tree->rchild);
        size_t max = ld > rd ? ld : rd;
        return max + 1;
    }
    else
    {
        return 0;
    }
}
size_t leafsOf(BinaryTree tree)
{
    if (tree != NULL)
    {
        if (tree->lchild == NULL && tree->rchild == NULL)
        {
            return 1;
        }
        else
        {
            return leafsOf(tree->lchild) + leafsOf(tree->rchild);
        }
    }
    else
    {
        return 0;
    }
}
} // namespace btree
