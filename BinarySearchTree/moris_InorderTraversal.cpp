#include<bits/stdc++.h>
using namespace std;

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

vector<int> inorderTraversal(Node* root){
    vector<int> inOrder;
    while(root != NULL){
        if(root->left == NULL){
            inOrder.push_back(root->data);
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
                inOrder.push_back(root->data);
                root = root->right;
            }
        }
    }
    return inOrder;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> inOrder = inorderTraversal(root);
    for(int i=0;i<inOrder.size();i++){
        cout<<inOrder[i]<<" ";
    }
    return 0;
}