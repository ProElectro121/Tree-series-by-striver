// Implementation of binary trees in cpp

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


int main() {

    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Recurrsive Preorder traversal

void Preorder(TreeNode* root , vector<int>& ans){
        if(root == NULL)
            return;
        
        // Process the output
    
        // Calling left child
        Preorder(root -> left , ans);
    
        // Calling right child
        preorder(root -> right , ans);

}

//Recurrsive Inorder traversal

 void inorder(TreeNode* root , vector<int> &ans){
        if(root == NULL)
            return;
        
        // Calling left child
        inorder(root -> left , ans);
     
       //processing the output
        ans.push_back(root -> val);
     
       // calling right child
        inorder(root -> right , ans);
 }



//Recursive Postoder travesal


 void Postorder(TreeNode* root , vector<int> &ans){
        if(root == NULL)
            return;
        
        // Calling left child
        inorder(root -> left , ans);
     
       // calling right child
        inorder(root -> right , ans);
     
       
       //processing the output
        ans.push_back(root -> val);
     
 }

// Breath First Search traversal of Trees
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> BFS;
        queue<TreeNode*> Q;
        if(root != NULL)
         Q.push(root);
        while(!Q.empty()) {
            int Queue_curr_size = Q.size();
            vector<int> level;
            for(int i = 0; i < Queue_curr_size; i++) {
                
                //accesing the top element and popping it
                TreeNode* node = Q.front();
                Q.pop();
                
                // Pushing left and right child respectively
                if(node -> left != NULL)
                    Q.push(node -> left);
                if(node -> right != NULL)
                    Q.push(node -> right);
                
                level.push_back(node -> val);
            }
            BFS.push_back(level);
        }
        return BFS;
    }
};


// ITERATIVE PREORDER TRAVERSAL 

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> st;
        if(root != NULL)
        st.push(root);
        
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            preorder.push_back(node -> val);
            
            if(node -> right != NULL) {
                st.push(node -> right);
            }
            
            if(node -> left != NULL) {
                st.push(node -> left);
            }
               
        }
        return preorder;
    }
};



// MAXIMUM DEPTH OF BINARY TREE

//RECURRSIVE

int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int l = maxDepth(root -> left);
        int r = maxDepth(root -> right);
        
        return 1 + max(l , r);
    }

//ITERATIVE

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int width = 0;
        queue<TreeNode*> Q;
        if(root != NULL)
        Q.push(root);
        while(!Q.empty()) {
            int sz = Q.size();
            for(int i = 0; i < sz; i++) { 
              TreeNode* node = Q.front();
              Q.pop();
              if(node -> left != NULL)
                Q.push(node -> left);
              if(node -> right != NULL)  
              Q.push(node -> right);
            }
            width++;
        }
        return width;
    }
};

