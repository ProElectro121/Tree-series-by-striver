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



//BOTTOM VIEW OF A BINARY TREE

/*
 USING THE SAME LINE APPROACH AS DONE EARLIER
 
 SIMPLY STORING THE LAST ELEMNT IN A LINE WITH THE HELP OF A MAP
*/

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> BottomView;
        queue<pair<Node* , int>> Q;
        map<int , int> m;
        if(root != NULL) {
            Q.push({root , 0});
        }
        
        while(!Q.empty()) {
            auto x = Q.front();
            Q.pop();
            Node* node = x.first;
            int level = x.second;
            
            auto it = m.find(level);
            if(it == m.end()) {
                m.insert({level , node -> data});
            }
            else {
                (*it).second = node -> data;
            }
            
            if(node -> left != NULL) {
                Q.push({node -> left , level - 1});
            }
            if(node -> right != NULL) {
                Q.push({node -> right , level + 1});
            }
        }
        for(auto &i: m) {
            BottomView.push_back(i.second);
        }
        return BottomView;
    }
};



// Right Side view of a binary Tree

/*
  using the same level and row approach we can store the rown and node data in a map
  and at last we can simply reutrn the vector
  
  Iterative way
  
  time complexity - > O(n)
  
  space complexity ->  int max case == no of leaf node .. ie in wose cae it full binary tree .. >= n/2 ~ O(n)
  
*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> RightSideView;
        queue<pair<TreeNode* , pair<int,int>>> Q;
        map<int,int> m;
        if(root != NULL)
        Q.push({root , {0 , 0}});
        
        while(!Q.empty()) {
            auto x = Q.front();
            TreeNode* node = Q.front().first;
            Q.pop();
            
            int level = x.second.first;
            int row = x.second.second;
            
            int data = node -> val;
            
            auto it = m.find(row);
            
            if(it == m.end()) {
                m.insert({row , data});
            }
            else {
                (*it).second = data;
            }
            
            if(node -> left != NULL) {
                Q.push({node -> left , {level - 1 , row + 1}});
            }
            
            if(node -> right != NULL) {
                Q.push({node -> right , {level + 1 , row + 1}});
            }
        }
        for(auto &i: m) {
            RightSideView.push_back(i.second);
        }
        return RightSideView;
    }
};


// recursice way 

/*
  Time complexity = O(n)
  space complexity = O(heigh(tree)) 
*/

class Solution {
private: 
    void traverse(TreeNode* root, int level , vector<int>& RightSideView) {
        if(root == NULL) {
            return;
        }
        
        if(level == RightSideView.size()) {
            RightSideView.push_back(root -> val);
        }
        
        traverse(root -> right , level + 1 , RightSideView);
        traverse(root -> left , level + 1 , RightSideView);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> RightSideView;
        
        traverse(root , 0 , RightSideView);
        
        return RightSideView;
    }
};

// CHECK FOR A SYMNTERIC BINARY TREE

class Solution {
private: 
    bool check(TreeNode* left , TreeNode* right) {
        if(left == NULL or right == NULL) {
            return left == right;
            
        }
            if(left -> val != right -> val) return false;
            
            bool first = check(left -> left , right -> right);
            bool second = check(left -> right , right -> left);
            
            return (first and second);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        
        return check(root -> left , root -> right);
    }
};


// Find a path from root Node to the given Node

approach --> perform a simple preorder traversal and if we find the Node at any instant we simpy reutrn 
and we try to maintain a list as we maintain in recurrsion.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool solves(TreeNode* root , int node , vector<int>& ans) {
    if(root == NULL) {
        return false;
    }
    if(root -> val == node) {
        ans.push_back(node);
        return true;
    }
    ans.push_back(root -> val);
    if(solves(root -> left , node , ans) == true) return true;
    if(solves(root -> right , node , ans) == true) return true;
    
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    if(A -> val == B) {
        return vector<int> (1 , A -> val);
    }
    vector<int> ans;
    solves(A , B , ans);
    
    return ans;
}


/*

236. Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

basically what is lca Path from the given Node to root
and for two nodes it is the lowermost intersection Node in their respective path from them to Root Node
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool findPath(TreeNode* root , vector<TreeNode*>& ans, TreeNode* Node) {
        if(root == NULL) return false;
        if(Node == root) {
            ans.push_back(Node);
            return true;
        } 

        ans.push_back(root);
        if(findPath(root -> left , ans , Node) or findPath(root -> right , ans , Node)) {
            return true;
        }
        ans.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a , b;
        findPath(root , a , p);
        findPath(root , b , q);

        TreeNode* ans;
        int n = min(a.size() , b.size());
        for(int i = 0; i < n; i++) {
            if(a[i] == b[i]) {
                ans = a[i];
            }
            else break;
        }
        return ans;
    }
};

// FInding lca recurrsive solution
/*
  Case when one of the Node is the lca we are not gona tht parent of the the lca
  ex [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
  ans --> 3 
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* dfs(TreeNode* root , TreeNode* p , TreeNode* q) {
        if(root == NULL or root == p or root == q) return root;

        TreeNode* parent1 = dfs(root -> left , p , q);
        TreeNode* parent2 = dfs(root -> right , p , q);

        if(parent1 != NULL and parent2 != NULL) return root;
        if(parent1 == NULL and parent2 != NULL) return parent2;
        if(parent1 != NULL and parent2 == NULL) return parent1;

        return NULL; 
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root , p , q);
    }
};


/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes that would be present in a complete binary tree extending 
down to that level are also counted into the length calculation.
*/

/*
 Just do indxing like ew do in segmen tree and rest is just implemtntation
*/
/*
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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , pair<int,int>>> q;
        int ans = 0;

        if(root) {
            q.push({root , {0 , 1}});
        }
        map< int, pair<int, int>> mp;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();

                TreeNode* Node = node.first;
                int index = node.second.second;
                int row = node.second.first;

                if(mp.find(row) == mp.end()) {
                    mp[row] = {index , index};
                }
                else {
                    mp[row].first = min(mp[row].first , index);
                    mp[row].second = max(mp[row].second ,index);
                }

                if(Node -> right) {
                    q.push({Node -> right , {row + 1 , 2 *1ll*(index - 1) + 1}});
                }
                if(Node -> left) {
                    q.push({Node -> left , {row + 1 , 2 *1ll* (index - 1)}});
                }
            }
        }
        for(auto &i: mp) {
            ans = max(1ll*ans , 1ll*i.second.second - 1ll*i.second.first + 1);
        }
        return (int)ans;
    }
};



/*
Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
You can return the answer in any order.
*/

/*
   Basic graph traversl problem finding Node that are at a distance of K unit
   but the problem here is that we can't traverse the parent in a Tree 
   so for this we have to maintain a pointer to the parent
   
   One method is that you can make a graph and perform either a bfs or dfs
   or you can keep track of parent of all Nodes in a map and that we can perform 
   dfs in three diection and get all nodes that are k distance apart
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root , int& n) {
        if(root == NULL) return;
        n = max(n , root -> val);
        dfs(root -> left , n);
        dfs(root -> right , n);
    }

    void dfs2(TreeNode* root , vector<int> graph[]) {
        if(root == NULL) return;

        if(root -> left != NULL) {
            int u = root -> val;
            int v = root -> left -> val;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        
        if(root -> right != NULL) {
            int u = root -> val;
            int v = root -> right -> val;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs2(root -> left , graph);
        dfs2(root -> right , graph);
    }

    void dfs3(int node , int level , vector<int>& vis , vector<int> graph[] , int k , vector<int>& ans) {
        vis[node] = 1;
        if(level == k) {
            ans.push_back(node);
        }
        for(auto &child: graph[node]) {
            if(!vis[child] and level < k ) {
                dfs3(child , level + 1 , vis , graph , k , ans);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int V = 0;
        dfs(root , V);
        vector<int> graph[V + 1];

        dfs2(root , graph);
        vector<int> ans;
        vector<int> vis(V + 1 , 0);
        dfs3(target -> val , 0 , vis , graph ,k , ans);

        return ans;
    }
};


/*
  Optimising the space by not making a graph
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root , map<TreeNode* , TreeNode*>& parent) {
        if(root == NULL) return;

        if(root -> left != NULL) {
            parent[root -> left] = root;
        }
        if(root -> right != NULL) {
            parent[root -> right] = root;
        }

        dfs(root -> left , parent);
        dfs(root -> right , parent);
    }

    void dfs2(TreeNode* node , int level , map<TreeNode* , TreeNode*>& parent, map<TreeNode* ,int> vis , vector<int>& ans , int k) {
        vis[node] = 1;
        if(level == k) {
            ans.push_back(node -> val);
        }
        if(parent.find(node) != parent.end() and level < k and vis[parent[node]] == 0) {
            dfs2(parent[node] , level + 1 , parent , vis , ans , k);
        }
        if(node -> left != NULL and level < k and vis[node -> left] == 0) {
            dfs2(node -> left , level + 1 , parent , vis , ans , k);
        }
        if(node -> right != NULL and level < k and vis[node -> right] == 0) {
            dfs2(node -> right ,level + 1 , parent , vis , ans , k);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode* , TreeNode*> parent;

        dfs(root , parent);
        vector<int> ans;
        map<TreeNode* , int> vis;
        dfs2(target , 0 , parent , vis , ans , k);
        return ans;
    }
};


// Using bfs




class Solution {
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target) {
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) { 
            TreeNode* current = queue.front(); 
            queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        markParents(root, parent_track, target); 
        
        unordered_map<TreeNode*, bool> visited; 
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};


/*
Count number of Nodes in a complete Bianry Tree --> O(2logn) approach
we can take the advantage that if a tree is complete is all nodes are there then 
the number of Nodes will be 2^(height of Tree) - 1
*/

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
class Solution {
private:
    int height_left(TreeNode* root) {
        int cnt = 0;
        while(root != NULL) {
            cnt++;
            root = root -> left;
        }
        return cnt;
    }
    int height_right(TreeNode* root) {
        int cnt = 0;
        while(root != NULL) {
            cnt++;
            root = root -> right;
        }
        return cnt;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int l = height_left(root);
        int r = height_right(root);
        
        if(l == r) return ((1 << r) - 1);

        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};

