class Solution {
public:

  bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p==NULL  && q==NULL) return true;

    if( p==NULL  || q==NULL ) return false;

     if(p->val != q->val)     return false;

    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);

    }


   bool isSubtree(TreeNode* s, TreeNode* t) {

         if(!s){

             //if main tree is null then return false
             return false;
         }
         else if(isSameTree(s,t)){
             //check if s and t are same, if yes return true
             return true;
         }
         else{
             //if s and t are not same then pass left and right nodes, and check same for that nodes as well as its child nodes.
             //je kono ekta true holei hoise
             return isSubtree(s->left,t) || isSubtree(s->right,t);
         }
   }
};
