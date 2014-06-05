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
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n=preorder.size();
        if(n==0) return NULL;
        int rootVal=preorder[0];
        TreeNode *curr=new TreeNode(rootVal);
        auto rit=find(inorder.begin(),inorder.end(),rootVal);
        auto lIn0=inorder.begin(), lInN=rit, rIn0=next(rit), rInN=inorder.end();
        auto lPr0=next(preorder.begin()), lPrN=next(lPr0,distance(lIn0,lInN)),
            rPr0=lPrN, rPrN=preorder.end();
        curr->left=buildTree(lPr0,lPrN,lIn0,lInN);
        curr->right=buildTree(rPr0,rPrN,rIn0,rInN);
        return curr;
    }
    TreeNode *buildTree(vector<int>::iterator pr0, vector<int>::iterator prN,
        vector<int>::iterator in0, vector<int>::iterator inN) {
            if(in0<inN) {
                int rootVal=*pr0;
                TreeNode *curr=new TreeNode(rootVal);
                auto rit=find(in0,inN,rootVal);
                auto lIn0=in0, lInN=rit, rIn0=next(rit), rInN=inN;
                auto lPr0=next(pr0), lPrN=next(lPr0,distance(lIn0,lInN)),
                    rPr0=lPrN, rPrN=prN;
                curr->left=buildTree(lPr0,lPrN,lIn0,lInN);
                curr->right=buildTree(rPr0,rPrN,rIn0,rInN);
            } else return NULL;
        }
};
