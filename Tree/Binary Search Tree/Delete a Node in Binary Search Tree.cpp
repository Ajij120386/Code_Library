

/********************* Approach 1 ********************************************


// Time complexity:O(h)
// Space complexity : O(1)

*/
class Solution
{
public:
    TreeNode *last(TreeNode *root)
    {
        while (root->right == NULL)
        {
            return root;
        }
        return last(root->right);
    }
    TreeNode *helper(TreeNode *root)
    {
        if (root->left == NULL)
        {
            return root->right;
        }
        if (root->right == NULL)
        {
            return root->left;
        }
        TreeNode *rightnode = root->right;
        TreeNode *lastright = last(root->left);
        lastright->right = rightnode;
        return root->left;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val == key)
        {
            return helper(root);
        }
        TreeNode *temp = root;
        while (root != NULL)
        {
            if (root->val > key)
            {
                if (root->left != NULL && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if (root->right != NULL && root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return temp;
    }
};



/********************* Recursive Approach ********************************************


// Time complexity:O(h)
// Space complexity : O(n)

*/


TreeNode* deleteNode(TreeNode* root, int key) {
        if( !root ) return NULL;
        if( root->val < key ) root->right = deleteNode(root->right, key);
        else if( root->val > key ) root->left = deleteNode(root->left, key);
        else{
            if( !root->right && !root->left ) return NULL;
            else if( !root->right ) return root->left;
            else if( !root->left ) return root->right;
            else{
                TreeNode* temp = root->right;
                while( temp->left ) temp = temp->left;
                temp->left = root->left;
                return root->right;
            }
        }
        return root;

    }
