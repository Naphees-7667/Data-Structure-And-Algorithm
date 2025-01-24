/*
Largest Smaller BST Key
Given a root of a Binary Search Tree (BST) and a number num, implement an efficient function findLargestSmallerKey that finds the largest key in the tree that is smaller than num. If such a number doesn't exist, return -1. Assume that all keys in the tree are non-negative.

Analyze the time and space complexities of your solution.

int findLargestSmallerKey(Node *rootNode, int num) 
{
  int res = -1;
  while(rootNode != nullptr){
   if(rootNode->val < num){
      res = rootNode->val;
      rootNode = rootNode->right;
   }
   else rootNode = rootNode->left;
  }
  return res;
}

*/