
/********************* Iterative Approach ********************************************


// Time complexity:O(h)
// Space complexity : O(1)

*/
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
        return new TreeNode(val);
    TreeNode *node = root;
    while (true)
    {
        if (node->val > val)
        {
            if (node->left != NULL)
            {
                node = node->left;
            }
            else
            {
                node->left = new TreeNode(val);
                break;
            }
        }
        else
        {
            if (node->right != NULL)
            {
                node = node->right;
            }
            else
            {
                node->right = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}



/********************* Recursive Approach ********************************************


// Time complexity:O(h)
// Space complexity : O(n)

*/


TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            return new TreeNode(val);
        }
        if(val<root->val){
            root->left = insertIntoBST(root->left , val);
        }else{
            root->right = insertIntoBST(root->right , val);
        }
        return root;
    }
