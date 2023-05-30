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
