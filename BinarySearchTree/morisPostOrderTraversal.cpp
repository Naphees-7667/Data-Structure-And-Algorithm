#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;    
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// here the postOrder Traversal is LEFT RIGHT ROOT
// it is difficult to do this traversal so we can do 
// ROOT RIGHT LEFT - and the reverse the result we
//get the postOrder Traversal using Moris Traversal

//In recursion we can come to the previous state but here we dont so we always try to connect them with link and then traverse at last we remove that link - we can do moris traversal in O(1) space and it is done for in,pre and post order traversal and concept for all are same only we have to think about how to connect the link and how to remove it

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> postOrder;
    while(root != NULL){
        if(root->right == NULL){
            postOrder.push_back(root->val);
            root = root->left;
        }
        else{
            TreeNode* curr = root->right;
            while(curr->left && curr->left != root){
                curr = curr->left;
            }
            if(curr->left == NULL){
                postOrder.push_back(root->val);
                curr->left = root;
                root = root->right;
            }
            else{
                curr->left = NULL;
                root = root->left;
            }
        }
    }
    reverse(postOrder.begin(),postOrder.end());
    return postOrder;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> postOrder = postorderTraversal(root);
    for(int i=0;i<postOrder.size();i++){
        cout<<postOrder[i]<<" ";
    }
    return 0;
}