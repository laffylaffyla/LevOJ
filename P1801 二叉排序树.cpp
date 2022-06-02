/* 二叉排序树

二叉排序树（Binary Search Tree），也称为二叉查找树、有序二叉树（ordered binary tree）或排序二叉树（sorted binary tree），是指一棵空树或者具有下列性质的二叉树：

若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
若任意节点的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
任意节点的左、右子树也分别为二叉查找树；
本题要求你基于二叉查找树，实现一个支持下面操作的数据结构：

插入一个数 x。
回答 x 有多少个。
输入描述

第一行一个整数 n，表示一共有 n 次操作。

接下来 n 行，每行两个整数，形如 opt x ，代表一次操作。

n≤10^5 ，opt∈{1,2}，1≤x≤1000，保证输入数据随机。

输出描述

对于操作 1，输出一行，包含你在二叉排序树中访问节点的路径。

对于操作 2，输出两行，第一行为你在二叉排序树中访问节点的路径，第二行一个整数表示被询问数的个数。

样例输入

Copy to Clipboard
9
1 5
2 5
1 1
1 10
1 2
1 2
2 2
2 10
2 11
样例输出

Copy to Clipboard


1
<-
->
<-->
<-->
<-->
2
->
1
->->
0
解释：

输入 1 5 ，路径为空。(注意输出空行)

输入 2 5 ，路径为空，然后输出个数 1。

输入 1 1 ，路径为 <- 。

输入 1 10 ，路径为 -> 。

输入 1 2 ，路径为 <--> 。

输入 1 2 ，路径为 <--> 。

输入 2 2 ，路径为 <--> ，然后输出个数 2。

输入 2 10 ，路径为 -> ，然后输出个数 1。

输入 2 11 ，路径为 ->-> ，然后输出个数 0。 */
