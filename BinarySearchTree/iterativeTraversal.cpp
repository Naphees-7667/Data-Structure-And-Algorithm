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

vector<int> inOrderTraversal(TreeNode* root){
    vector<int> inOrder;
    stack<TreeNode*> st;
    stack<bool> isVisited;
    st.push(root);
    isVisited.push(false);
    while(!st.empty()){
        TreeNode* curr = st.top();
        bool visited = isVisited.top();
        st.pop();
        isVisited.pop();
        if(!visited){
            
            if(curr->right != NULL){
                st.push(curr->right);
                isVisited.push(false);
            }
            st.push(curr);
            isVisited.push(true);
            if(curr->left != NULL){
                st.push(curr->left);
                isVisited.push(false);
            }
        }
        else{
            inOrder.push_back(curr->val);
        }
    }
    return inOrder;
}

vector<int> preOrderTraversal(TreeNode* root) {
    vector<int> preOrder;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        preOrder.push_back(curr->val);
        if(curr->right != NULL){
            st.push(curr->right);
        }
        if(curr->left != NULL){
            st.push(curr->left);
        }
    }
    return preOrder;
}

vector<int> postOrderTraversal(TreeNode* root) {
    vector<int> postOrder;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        postOrder.push_back(curr->val);

        if(curr->left != NULL){
            st.push(curr->left);
        }
        //here we store ans in reverse - Node Right Left
        if(curr->right != NULL){
            st.push(curr->right);
        }
    }
    //reverse the answer 
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
    vector<int> preOrder = preOrderTraversal(root);
    vector<int> inOrder = inOrderTraversal(root);
    vector<int> postOrder = postOrderTraversal(root);
    for(int i=0;i<preOrder.size();i++){
        cout<<preOrder[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<inOrder.size();i++){
        cout<<inOrder[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<postOrder.size();i++){
        cout<<postOrder[i]<<" ";
    }
    cout<<endl;
    return 0;
}