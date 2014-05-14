/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#include <deque>
#include <utility>

using namespace std;
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL) return 0;
        deque<pair<TreeNode*,int> > q;//= new deque<pair<TreeNode*,int> >();
        q.push_front(make_pair(root,1));
        pair<TreeNode*, int> curr;
        int max=0;
        while(!q.empty()) {
            int flag=0;
            curr=q.front();
            q.pop_front();
            //pair<TreeNode*,int> child;
            if(curr.first->right!=NULL) {
                flag=1;
                q.push_front(make_pair(curr.first->right,curr.second+1));
            }
            if(curr.first->left!=NULL) {
                flag=1;
                q.push_front(make_pair(curr.first->left,curr.second+1));
            }
            if(flag==0 && curr.second>max) max=curr.second;
        }
        return max;
    }
};