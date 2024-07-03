
/********************* Iterative Approach ********************************************


// Time complexity:O(h)
// Space complexity : O(1)

*/
TreeNode *LCAinaBST(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (root)
    {
        if (root->data > p->data && root->data > q->data)
            root = root->left;
        else if (root->data < q->data && root->data < p->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}


/********************* Recursive Approach ********************************************


// Time complexity:O(h)
// Space complexity : O(n)

*/

class Solution {

     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        int current = root->val;
        if(current<p->val && current<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(current>p->val && current>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else{
            return root;
        }
    }
}

