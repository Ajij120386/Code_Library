


/*********************  Approach--1 ********************************************



*/
#include <Node.cpp>
using namespace std;
bool isBST(Node *root, long long min, long long max)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->data > min && root->data < max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}
bool isValidBST(Node *root)
{
    if (root->left == nullptr && root->right == nullptr)
        return true;
    return isBST(root, LONG_MIN, LONG_MAX);
}



/*********************  Approach-2 ********************************************

We can also use Inorder because Inorder of BST is sorted. so we can just do inorder
 transversal and use a previous pointer which track previous number.
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};
