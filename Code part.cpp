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



//CHECKING FOR BALANCED BINARY TREE

//Naive approach

//Time complexity --> O(N^2)

class Solution {
public:
    int depth(TreeNode* root) {
        if(root == NULL)
            return false;
        
        int l = depth(root -> left);
        int r = depth(root -> right);
        
        return 1 + max(l , r);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        int l = depth(root -> left);
        int r = depth(root -> right);
        
        if(abs(l - r) > 1)
            return false;
        
        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);
        
        if(!left or !right)
            return false;
        
        return true;
    }
};

//OPTIMISED APPROACH

/*
We can modify the deoth function to check weatgher the height difference between the left subtree and right subtree.
if the difference is greater then 1 return -1 else the function simply going to return the height of subtree.

*/

class Solution {
public:
    int depth(TreeNode* root) {
        if(root == NULL)
            return false;
        
        int l = depth(root -> left);
        int r = depth(root -> right);
        
        if(l == -1 or  r == -1)
            return -1;
        
        if(abs(l - r) > 1)
            return -1;
        return 1 + max(l , r);
    }
    bool isBalanced(TreeNode* root) {
        return (depth(root) == -1)? false : true;
    }
};


//Diameter of a binary tree

// Iterating over each node to find the max height of left and right subtree respectively

// Time complexity --> O(n*n)

class Solution {
public:
    int depth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int l = depth(root -> left);
        int r = depth(root -> right);
        
        return 1 + max(l , r);
    }
    
    int diameter(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int l = depth(root -> left);
        int r = depth(root -> right);
        
        int currDiameter = l + r;
        return currDiameter;
    }
    
    void preorder(TreeNode* root , int& maxDiameter) {
        if(root == NULL) return;
        
        //processing
        maxDiameter = max(maxDiameter , diameter(root));
        
        preorder(root -> left , maxDiameter);
        preorder(root -> right, maxDiameter);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        preorder(root , maxDiameter);
        
        return maxDiameter;
    }
};

//Optimised approach

//calculating the calue of max height of left and right subtree already in the depth function
//just pass a maxi variable that will compute the max value of height of left and right subtree respectively.

class Solution {
public:
    int depth(TreeNode* root , int& maxi) {
        if(root == NULL)
            return 0;
        
        int l = depth(root -> left , maxi);
        int r = depth(root -> right , maxi);
        
        maxi = max(maxi , l + r);
        
        return 1 + max(l , r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        int Maxheightoftree = depth(root , maxDiameter);
        
        return maxDiameter;
    }
};



//Maximum path sum in a BInary Tree

class Solution {
public:
    int depth(TreeNode* root , int& maxi) {
        if(root == NULL)
            return 0;
        
        int l = max(0 , depth(root -> left , maxi));
        int r = max(0 , depth(root -> right , maxi));
        
        maxi = max(maxi , l + r +  root -> val);
        
        return root -> val + max(l , r);
    }
    int maxPathSum(TreeNode* root) {
      int maxi = INT_MIN;
      depth(root , maxi);
        
      return maxi;
    }
};


//CHECK IF TWO TREES ARE IDNETICAL

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL or q == NULL) {
            if(p == q)
                return true;
            return false;
        }
        
        bool ok = (p->val == q-> val) and isSameTree(p -> left , q -> left);
        bool oks =(p->val == q-> val) and isSameTree(p -> right , q -> right);
        
        return ok and oks;
    }
};

//ZIGZAG TRAVERSAL OF TREE

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> Zigzag;
        queue<TreeNode*> Q;
        if(root != NULL) {
            Q.push(root);
        } 
        int direction = 0;
        while(!Q.empty()) {
            int sz = Q.size();
            vector<int> level;
            for(int i = 0; i < sz; i++) {
                TreeNode* node = Q.front();
                Q.pop();
                level.push_back(node -> val);
                if(node -> left != NULL) {
                    Q.push(node -> left);
                }
                if(node -> right != NULL) {
                    Q.push(node -> right);
                }
            }
            if(!direction) {
                Zigzag.push_back(level);
            }
            else {
                reverse(level.begin() , level.end());
                Zigzag.push_back(level);
            }
            direction = 1 - direction;
        }
        return Zigzag;
    }
};


//Boundary taversal of a binary Tree

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
private:
    bool leafNode(Node* root) {
        if(root -> left == NULL and root -> right == NULL) return true;
        return false;
    }
    void addLeftNode(Node* root , vector<int>& arr) {
        Node* curr = root;
        while(curr != NULL) {
            if(!leafNode(curr))
            arr.push_back(curr -> data);
            if(curr -> left != NULL) {
                curr = curr -> left;
            }
            else {
                curr = curr -> right;
            }
        }
    }
    
    void addRightNode(Node* root , vector<int>& arr) {
        Node* curr = root;
        vector<int> temp;
        while(curr != NULL) {
            if(!leafNode(curr)) {
                temp.push_back(curr -> data);
            }
            if(curr -> right != NULL) {
                curr = curr -> right;
            }
            else {
                curr = curr -> left;
            }
        }
        reverse(temp.begin() , temp.end());
        for(auto &i: temp) arr.push_back(i);
    }
    
    void addLeafNode(Node* root , vector<int>& arr) {
        if(leafNode(root)) {
            arr.push_back(root -> data);
        }
        if(root -> left != NULL) 
          addLeafNode(root -> left , arr);
        if(root -> right != NULL)
          addLeafNode(root -> right , arr);
    }
public:
    vector <int> boundary(Node *root) {
        vector<int> boundaryTraversal;
        if(root == NULL)
          return boundaryTraversal;
        if(!leafNode(root)) {
            boundaryTraversal.push_back(root -> data);
        }
        addLeftNode(root -> left, boundaryTraversal);
        addLeafNode(root , boundaryTraversal);
        addRightNode(root -> right, boundaryTraversal);
        return boundaryTraversal;
    }
};


// VERTICAL ORDER TRAVERSAL OF A BINARY TREE

/*
   assigning each node of the tree a level and rows 
   level vary from form -n , -(n - 1) , ... 0 , 1 , 2 , .. (n).
   row vary form 0 , 1 , 2 .. .. n
   
   then iterating the row and level in ascending order
   for similar elements we can stoe them in a multiset
   
   creating a queue - > queue< pair< node , pai<int,int>>>
   map -- > map<int,map<int,multiset<int>>> m;
   
   for left child - > store (level -1 , row + 1)
   for right child - > store (level + 1 , row + 1)
   
   for inserting a multiset element in a vector
   
   temp -> vector
   
   ms -> multiset
   
   temp.insert(temp.end() , ms.begin() , ms.end());
*/


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> vertical;
        queue<pair<TreeNode* , pair<int,int>>> Q;
        map<int , map<int , multiset<int>>> m;
        if(root != NULL)
        Q.push({root , {0 , 0}});
        while(!Q.empty()) {
            auto x = Q.front();
            Q.pop();
            TreeNode* node = x.first;
            int level = x.second.first;
            int row = x.second.second;
            
            m[level][row].insert(node -> val);
            
            if(node -> left != NULL) {
                Q.push({node -> left , {level - 1 , row + 1}});
            }
            
            if(node -> right != NULL) {
                Q.push({node -> right , {level + 1 , row + 1}});
            }
        }
        for(auto &i: m) {
          vector<int> temp;
            for(auto &it: i.second) {
                for(auto &its: it.second){
                    temp.push_back(its);
                }
            }
            vertical.push_back(temp);
        }
        return vertical;
    }
};

 
// TOP VIEW OF A BINARY TREE

/*
APPROACH

We can use the line method for accesing the top elemnts only

we can use a Queue to store the level root and level respectively

and a map that is going to stoe the level and node data 

and before inserting the node data in the map we are going to compae if it's already 
exsists i the map and if not then we are going to insert in the map

AFTER WE SIMPLY COPY MAP CONTENT IN THE VECTOE AND REUTRN IT
*/


 /*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        
        vector<int> TopView;
        queue<pair<Node* , int>> Q;
        map<int,int> m;
        Q.push({root , 0});
        
        while(!Q.empty()) {
            
            auto x = Q.front();
            Q.pop();
            int level = x.second;
            Node* node = x.first;
            
            if(m.find(level) == m.end()) {
                m[level] = node -> data;
            }
            
            if(node -> left != NULL) {
                Q.push({node -> left , level - 1});
            }
            if(node -> right != NULL) {
                Q.push({node -> right , level + 1});
            }
        }
        
        for(auto &i: m) TopView.push_back(i.second);
        return TopView;
    }

};

