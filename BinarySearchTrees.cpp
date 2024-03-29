/*
Search in a Binary Search Tree
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL and root -> val != val) {
            root = root -> val > val ? root -> left : root -> right;
        }
        return root;
    }
};

/*
FLoor and ceil of a binary search tree
*/

int floor(Node* root, int x) {
    int ans = -1;
    while(root != NULL) {
        int ele = root -> data;
        if(ele > x) {
            root = root -> left;
        }
        else {
            ans = max(ans , ele);
            root = root -> right;
        }
    }
    return ans;
}


int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    int ans = INT_MAX;
    while(root != NULL) {
        int ele = root -> data;
        if(ele == input) {
            ans = input;
            break;
        }
        else if(ele > input) {
            ans = min(ans , ele);
            root = root -> left;
        }
        else {
            root = root -> right;
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

/*Insertion in a Binary search tree*/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        if(cur == NULL) {
            return new TreeNode(val);
        }
        while(cur != NULL) {
            int data = cur -> val;
            if(data > val) {
                if(cur -> left != NULL)
                    cur = cur -> left;
                else {
                    cur -> left = new TreeNode(val);
                    break;
                }
            }
            else {
                if(cur -> right != NULL)
                    cur = cur -> right;
                else {
                    cur -> right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};


/*
 Delete a Node in a BST
 
 First we have to maintain the pointer to the Node which we have to delete .
 so we traverse the BST in such that we check for the child first if we it is the key we 
 are looking to delete then we call the helper function
 
 so what helper funcion is doing?
 it takes a node and basically merge it's left and right subtree and reutrn a pointer
 
 so all value in the left subtree are smaller then any value of right substree
 so we append then right substree at then bottom of lastRight child ie to the Node
 havinf then highest value in the left SUbtree
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
    TreeNode* findlastRight(TreeNode* root) {
        while(root -> right != NULL) root = root -> right;
        return root;
    }
    TreeNode* helper(TreeNode* root){
        if(root -> left == NULL) return root -> right;
        if(root -> right == NULL) return root -> left;

        TreeNode* rightChild = root -> right;
        TreeNode* leftRight = findlastRight(root -> left);
        leftRight -> right = rightChild;
        return root -> left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root -> val == key) {
            return helper(root);
        }
        TreeNode* cur = root;
        while(cur != NULL) {
            if(cur -> val > key) {
                if(cur -> left != NULL and cur -> left -> val == key) {
                    cur -> left = helper(cur -> left);
                    break;
                }
                else {
                    cur = cur -> left;
                }
            }
            else {
                if(cur -> right != NULL and cur -> right -> val == key) {
                    cur -> right = helper(cur -> right);
                    break;
                }
                else {
                    cur = cur -> right;
                }
            }
        }
        return root;
    }
};

/*
Kth Smallest Element in a BST
Inorder traveral of a BST gives increasing sequence
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
// private:
public:
    int ans;
    int cnt = 0;

    void inorder(TreeNode* root , int k) {
        if(root == NULL) return;

        inorder(root -> left , k);
        cnt++;
        if(cnt == k) {
            ans = root -> val;
        }
        inorder(root -> right , k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root , k);
        return ans;
    }
};


/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the
lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”


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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int data_P = p -> val;
        int data_q = q -> val;
        int data = root -> val;
        if(data_P > data and data_q > data) {
            return lowestCommonAncestor(root -> right , p , q);
        }
        if(data_P < data and data_q < data) {
            return lowestCommonAncestor(root -> left , p , q);
        }
        return root;
    }
};

// Iterative version

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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int data_P = p -> val;
        int data_q = q -> val;
        while(root != NULL) {
            int data = root -> val;
            if(data > data_P and data > data_q) {
                root = root -> left;
            }
            else if(data < data_P and data < data_q) {
                root = root -> right;
            }
            else {
                break;
            }
        }
        return root;
    }
};


/*
1008. Construct Binary Search Tree from Preorder Traversal

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
    int ptr = 0;
    TreeNode* bst(vector<int> preorder , long bound) {
        if(ptr >= preorder.size() or preorder[ptr] > bound) return NULL;

        TreeNode* root = new TreeNode(preorder[ptr++]);
        root -> left = bst(preorder , root -> val);
        root -> right = bst(preorder , bound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder , LONG_MAX);
    }
};

/*finding inorder succesor and predessor is simila to findinf floor and ceil in a BST

for succesor --> IT is ceil 
for predessor --> IT is floor
*/

