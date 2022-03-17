/*
题目描述
Farmer John takes the heritage of his cows very seriously. He is not, however, a truly fine bookkeeper. He keeps his cow genealogies as binary trees and, instead of writing them in graphic form, he records them in the more linear tree in-Order" and tree pre-Order" notations.

Your job is to create the `tree post-Order" notation of a cow"s heritage after being given the in-Order and pre-Order notations. Each cow name is encoded as a unique letter. (You may already know that you can frequently reconstruct a tree from any two of the Ordered traversals.) Obviously, the trees will have no more than 26 nodes.

Here is a graphical representation of the tree used in the sample input and output:

              C
            /
           /
          B       G
         /      /
        A   D   H
           /
          E   F

The in-Order traversal of this tree prints the left sub-tree, the root, and the right sub-tree.

The pre-Order traversal of this tree prints the root, the left sub-tree, and the right sub-tree.

The post-Order traversal of this tree print the left sub-tree, the right sub-tree, and the root.

----------------------------------------------------------------------------------------------------------------------------
题目大意：
给出一棵二叉树的前序遍历 (preOrder) 和中序遍历 (inOrder)，求它的后序遍历 (postOrder)。
你需要知道的：
1：二叉树的 相关定义可以在书上或者网上找到。
2：样例 输入输出反映的二叉树在上面。

输入描述
Line 1:
The in-Order representation of a tree.

Line 2:
The pre-Order representation of that same tree.

输出描述
A single line with the post-Order representation of the tree.

样例输入

ABEDFCHG
CBADEFGH

样例输出

AEFDBHGC
*/

#include <iostream>
#include <string>

using namespace std;

void postOrder(string preOrder, string inOrder)
{
    int len = preOrder.length();
    if (len == 0)
        return;
    if (len == 1)
    {
        cout << preOrder[0];
        return;
    }
    int pos = inOrder.find(preOrder[0]);
    postOrder(preOrder.substr(1, pos), inOrder.substr(0, pos));
    postOrder(preOrder.substr(pos + 1, len - pos - 1), inOrder.substr(pos + 1, len - pos - 1));
    cout << preOrder[0];
}

int main()
{
    string preOrder, inOrder;
    while (cin >> inOrder >> preOrder)
    {
        postOrder(preOrder, inOrder);
        cout << endl;
    }
}