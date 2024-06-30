
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to perform preorder traversal
    // of a binary tree iteratively
    vector<int> inorderTraversal(TreeNode* root) {


        stack<TreeNode* > s;

        TreeNode* node = root;

    vector<int> inorder;

    while (true)
    {
        if (node != NULL){
            s.push(node);
           node = node->left;
        }
        else {
             if (s.empty())  break;
             node = s.top();
              s.pop();
             inorder.push_back(node->val);
             node = node->right;
        }
    }
    return inorder;
    }
};

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Initializing the Solution class
    Solution sol;

    // Getting the preorder traversal
    vector<int> result = sol.inorderTraversal(root);

    // Displaying the preorder traversal result
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}



