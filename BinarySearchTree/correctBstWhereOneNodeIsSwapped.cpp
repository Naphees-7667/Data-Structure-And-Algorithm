#include<bits/stdc++.h>
using namespace std;

//* GFG Question Link - https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

// You are given the root of a binary search tree(BST), where exactly two nodes were swapped by mistake. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
// Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original linked list.
 
class Node{
    public:
    int data;
    Node* left;
    Node* right;    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// the maximum number of places where the inorder traversal can be swapped is 2 in this questions 
void correctBST(Node* root){
    Node* previousNode = NULL , *currentNode = NULL;
    Node* first = NULL , *second = NULL;
    while(root != NULL){
        if(root->left == NULL){
            previousNode = currentNode;
            currentNode = root;
            if(previousNode && previousNode->data > currentNode->data){
                if(first == NULL){
                    first = previousNode;
                }
                second = currentNode;
            }
            root = root->right;
        }
        else{
            Node* curr = root->left;
            while(curr->right && curr->right != root){
                curr = curr->right;
            }
            if(curr->right == NULL){
                curr->right = root;
                root = root->left;
            }
            else{
                curr->right = NULL;
                previousNode = currentNode;
                currentNode = root;
                if(previousNode && previousNode->data > currentNode->data){
                    if(first == NULL){
                        first = previousNode;
                    }
                    second = currentNode;
                }
                root = root->right;
            }
        }
    }
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
    return;
}