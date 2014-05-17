/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    struct Item {
        TreeNode *p;
        int begin;
        int end;
        Item(TreeNode *ptr, int a, int b):p(ptr),begin(a),end(b) {}
    };
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int size=num.size();
        if(size==0) return NULL;
        int begin=0;
        int end=size-1;
        TreeNode *pre;
        queue<Item *> q;
        TreeNode *root=new TreeNode(num[(begin+end)/2]);
        q.push(new Item(root, begin, end));
        while(!q.empty()) {
            begin=q.front()->begin;
            end=q.front()->end;
            pre=q.front()->p;
            q.pop();
            int mid=(begin+end)/2;
            if(begin==end) {
                //DO nothing
            }else if(end-begin==1) {//LEAF:Only left child
                pre->right=new TreeNode(num[end]);
            } else if(end-begin==2) {//LEAF: Both left and right
                pre->left=new TreeNode(num[begin]);
                pre->right=new TreeNode(num[end]);
            } else {//Non-leaf
                pre->left=new TreeNode(num[(begin+mid-1)/2]);
                q.push(new Item(pre->left,begin,mid-1));
                pre->right=new TreeNode(num[(mid+1+end)/2]);
                q.push(new Item(pre->right,mid+1,end));
            }
        }
        return root;
    }
};
