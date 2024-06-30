
//***************Striver Solution Using one stack**********************************

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* temp = nullptr;
        while(curr!=nullptr || !st.empty()) {
            if(curr!=nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                temp = st.top()->right;
                if(temp==nullptr) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right) {
                        temp = st.top(); st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else {
                    curr = temp;
                }
            }
        }
        return ans;
    }



    //***************Simple modification in  USing two stacks **********************************

    //instead of using 2nd stack we can push into ans. And in the end, we can reverse ans.


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st1;
        vector<int> postorder;
        if(root == NULL) return postorder;
        st1.push(root);
        while(!st1.empty())
        {
            root = st1.top();
            st1.pop();
            postorder.push_back(root->val);
            if(root->left != NULL)
            {
                st1.push(root->left);
            }
            if(root->right != NULL)
            {
                st1.push(root->right);
            }
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }
};



    //***************Simple modification in  Preorder Traversal**********************************

    /*
    Postorder is : Left Right Root

Reverse Postorder is: Root Right Left

Try Finding Reverse Postorder like preorder using one stack O(N) time and O(N) space

Then reverse the resultant vector, that will be the answer O(N) time

Overall O(2N) time and O(N) space


*/

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            res.push_back(temp->val);
            if(temp->left) s.push(temp->left);
            if(temp->right) s.push(temp->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
