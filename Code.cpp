/*
Construction a unique Binary Tree from preorder and postorder traversal

 --> NOT POSSIBLE
 
 you can construct a lot of possible trees which will give same preorder and postorder but still be differnet
 
 ex --> [1 , NULL , 2 , NULL , NULL, 3 , NULL] 
 preorder ->  1 - > 2 - > 3
 Postorder ->  3 -> 2 -> 1
 
 ex --> [1 , 2 , NULL , NULL , NULL , 3 , NULL]
  preorder ->  1 - > 2 - > 3
 Postorder ->  3 -> 2 -> 1
 
 it there are seceral possibilites hence not possible to create a unique binary tree
 
 -----------------------------------------------------------------------------------------------------------
 
 But if inorder traversal is given then it is posisble 
  How does inorder+preorder/postorder construct unique binary tree?
-> Imagine that you have the following pre-order traversal: a,b,c,d,e,f,g. What does that tell you?

You know that a is the root of the tree, this follows from the definition of a pre-order traversal. So far, so good.

You also know that the rest of your list is the traversal of the left subtree followed by the traversal of the right subtree. Unfortunately you don't know where the split is. It could be that all of them belong to the left tree, it could be that all of them belong to the right tree, or b,c go left and d,e,f,g go right and so on.

How to resolve the ambiguity? Well, let's take a look at the in-order traversal, what is its defining property? Any elements in the left subtree of a will come before a in the in-order traversal and any elements in the right subtree will come after a. Again, this follows from the definition of in-order traversal.

So what we need to do is take a look at the in-order traversal (let's say it's c,b,a,d,e,f,g). We can see that b and c come before a, therefore they're in the left subtree, while d,e,f and g are in the right subtree. In other words, as position in the in-order traversal uniquely determines which nodes will be in its left/right subtrees.

And this is great because we can now go on and solve the two subtrees recursively: pre-order b,c/in-order c,b and pre-order d,e,f,g/in-order d,e,f,g.

And you can continue this recursively until all subtrees only contain a single element, where the solution is trivially unique.

And since at each step we could prove that there is only one valid way to continue, the result is that a given pair of in-order and pre-order traversals can only belong to a single tree.

*/



/*

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and 
inorder is the inorder traversal of the same tree, construct and return the binary tree.

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

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
    TreeNode* buildTree(vector<int>& preorder , int startPre , int endPre , vector<int>& inorder , int startind , int endind , map<int,int>& ind) {
        if(startPre > endPre or startind > endind) return NULL;

        TreeNode* root = new TreeNode(preorder[startPre]);
        int index = ind[preorder[startPre]] - startind;

        root -> left = buildTree(preorder , startPre + 1 , startPre + index , inorder , startind , ind[preorder[startPre]] - 1,ind); 

        root -> right = buildTree(preorder , startPre + index + 1 , endPre , inorder , ind[preorder[startPre]] + 1 , endind , ind);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int , int> ind;
        for(int i = 0; i < inorder.size(); i++) {
            ind[inorder[i]] = i;
        }
        int n = preorder.size();
        return buildTree(preorder , 0 , n - 1 , inorder , 0 , n - 1 , ind);
    }
};



/*
Construct Binary Tree from Inorder and Postorder Traversal


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
    TreeNode* buildTree(vector<int>& postorder , int postStart , int postEnd , vector<int>& inorder , int indStart , int indEnd , map<int,int>& ind) {
        if(postStart > postEnd or indStart > indEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int num = indEnd - ind[root -> val];
        
        root -> left = buildTree(postorder , postStart , postEnd - num - 1 , inorder , indStart , ind[root -> val] - 1 , ind);

        root -> right = buildTree(postorder , postEnd - num , postEnd - 1 , inorder , ind[root -> val] + 1 , indEnd , ind);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int , int> ind;
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            ind[inorder[i]] = i;
        }

        return buildTree(postorder , 0 , n - 1 , inorder , 0 , n - 1 , ind);
    }
};


/*
Encode and Decode a binary Tree
first convert Binary tree to string and then to binary tree

using stringstream --> heps in getting substring from a prefix upto a deliminator
and erasing then prefix upto that deliminator

ex-> string s = "1,2,3,4,5"
stringstream str(s);
string temp;
getline(str , temp , ',');

temp will now store 1
temp --> 1
calling the getline function again
getline(str , temp , ','); 
temp --> 2

We can use simple level order traversal to generate the string and converting it back to the tree
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
class Codec {
private:   

public:

    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
                auto node = q.front();
                q.pop();

                if(node == NULL) {
                    ans += "N,";
                    continue;
                }
                else {
                    ans += to_string(node -> val);
                    ans += ",";
                }
                q.push(node -> left);
                q.push(node -> right);
        }
        return ans;
    }

    TreeNode* deserialize(string data) {
        if(data.front() == 'N') return NULL;
        stringstream s(data);

        string str;
        getline(s , str , ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
                auto node = q.front();
                q.pop();

                getline(s , str , ',');
                if(str == "N") {
                    node -> left = NULL;
                }
                else {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node -> left = leftNode;
                    q.push(leftNode);
                }

                getline(s , str , ',');
                if(str == "N") {
                    node -> right = NULL;
                }
                else {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node -> right = leftNode;
                    q.push(leftNode);
                }
        }
        //
        return root;
    }
};



/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and
the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 
 First one is basic : Stroing the preorder Traversal making a Binary tree with that preorder traversal 

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
    void dfs_preorder(TreeNode* root , vector<int>& ans) {
        if(root == NULL) return;
        ans.push_back(root -> val);
        dfs_preorder(root -> left , ans);
        dfs_preorder(root -> right , ans);
    }
public:
    void flatten(TreeNode* root) {
        vector<int> preOrder;
        dfs_preorder(root , preOrder);

        int ptr = 0;
        TreeNode* temp = root;
        int n = preOrder.size();
        while(ptr < n ) {
            temp -> val = preOrder[ptr];
            if(temp -> right == NULL and ptr < n - 1) {
                TreeNode* temps = new TreeNode();
                temp -> right = temps;
            }
            temp -> left = NULL;
            temp = temp -> right;
            ptr++;
        }
    }
};


/*
  Using recurrsion 
  
  main loginc is : maintain a previous gloal pointter initially initiallised to NULL after
  perform some sort of Reverse POst order Traversal ie : (right , left , ROOT)
  
  and at last do then following :
  1. Make the right of currNode to Prev
  2.set the Left Node to NULL
  3.set Prev to currNode
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
    TreeNode* prev = NULL;
private:
    void flattens(TreeNode* root) {
        if(root == NULL) return;

        flattens(root -> right);
        flattens(root -> left);

        root -> right = prev;
        root -> left = NULL;
        prev = root;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* temp = root;
        flattens(temp );
    }
};

/*
 Using iterative method
 Using a stack 
  Using a stack to initially store the root of the Binary Tree
  after each iteration push the first right and then left child back in the stack
  if they are not NULL
  after this check if whether the stack is empty or Not , if Not then make the right child of currNode to node
  which if present at top of the stack
  at last make the left Node of currNode NULL
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
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        if(root != NULL) {
            st.push(root);
        }

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if(node -> right) {
                st.push(node -> right);
            }
            if(node -> left) {
                st.push(node -> left);
            }

            if(!st.empty()) {
                node -> right = st.top();
            }
            node -> left = NULL;
        }
    }
};
