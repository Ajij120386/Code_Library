


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

public boolean isValidBST(TreeNode root) {
        inorder(root);
        return flag;
    }
    boolean flag = true;
    long prev = Long.MIN_VALUE;
    private void inorder(TreeNode root) {
        if(root == null)    return;
        inorder(root.left);
        if(prev >= root.val){
            flag = false;
            return;
        }
        else    prev = root.val;
        inorder(root.right );
    }
