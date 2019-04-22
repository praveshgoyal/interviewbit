Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

Using recursion is not allowed.



//cpp




/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(vector<int> &ans, TreeNode* A) {
    if(A==NULL) {
        return;
    }
    solve(ans, A->left);
    solve(ans, A->right);
    ans.push_back(A->val);
}
vector<int> Solution::postorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    // solve(ans, A);
    // return ans;
    if(A == NULL) 
        return ans;
    stack<TreeNode*> s;
    s.push(A);
    
    while(s.size() ) {
        TreeNode* prev = s.top();
        ans.push_back(s.top()->val);
        s.pop();
        if(prev->left) {
            s.push(prev->left);
        }
        if(prev->right) {
            s.push(prev->right);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
