
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
   void swap(TreeNode* root)
   {

    if(root==NULL) return;

     swap(root->left);
     swap(root->right);


//concept of swapping two number
    TreeNode *tmp= root->left;
    root->left=root->right;
    root->right=tmp;

   }
    TreeNode* invertTree(TreeNode* root) {


        swap(root);
        return root;
    }
};
