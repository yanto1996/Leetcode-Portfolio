/**
 *Yan To
 *Count Good Nodes
 *https://leetcode.com/problems/count-good-nodes-in-binary-tree/
*/

/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *	int val;
 *      struct TreeNode *left;
 *      struct TreeNode *right;
 *};
 */

// helper function that recursively counts the good nodes in a tree
// // a node is considered good if it is greater than or equal to its parent
int counter(struct TreeNode* root, int count, int prev){
    if (root == NULL){
        return count;
    }

    int current = root->val;

    if (current >= prev){
        prev = current;
        count++;
    }

    count = counter(root->left, count, prev);
    count = counter(root->right, count, prev);
    return count;
}

// main function that sets count to 0 and the prev to be the current value of the root node
// // returns the recursive function that counts the "good nodes" in the tree
int goodNodes(struct TreeNode* root){
    if (root == NULL){
        return 0;
    }

    int count = 0;
    int prev = root->val;
    return counter(root, count, prev);
}
