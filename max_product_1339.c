/**
 * Yan To
 * Maximum Product of Splitted Binary Tree
 * https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//helper function to recursively calculate the sum of the entire binary tree
long dfsSum(struct TreeNode* root){
     if (root == NULL){
             return 0;
     }

     return root->val + dfsSum(root->left) + dfsSum(root->right); // recursive call
}

// helper function that calculates the sum of each individual node in the binary tree 
// // and its individual product by subtracting the totalSum by the individual sum and multiplying
// // individual sum is incremented recursively to obtain the product
// // function returns the value of the individual sum for the recurssion to calculate the product
long product(struct TreeNode* root, long totalSum, long* temp){
    if (root == NULL){
        return 0;
    }

    long individualSum = root->val;
    individualSum += product(root->left, totalSum, temp);
    individualSum += product(root->right, totalSum, temp);

    long sumOther = totalSum - individualSum;
    long individualProduct = individualSum * sumOther;

    if (*temp < individualProduct){
        *temp = individualProduct;
    }

    return individualSum;
}

// main function that sets the total sum and a temp to hold the product
long maxProduct(struct TreeNode* root){
    if (root == NULL){
        return 0;
    }

    long totalSum = dfsSum(root);
    long temp = 0;
    product(root, totalSum, &temp);
    return temp % 1000000007;
}
