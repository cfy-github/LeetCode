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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num.begin(), num.end());
    }
    template<typename RandomAccessIterator>
    TreeNode *sortedArrayToBST(RandomAccessIterator first, RandomAccessIterator last) {
        const auto len=distance(first, last);
        if(len<=0) return NULL;
        auto mid=first+len/2;
        TreeNode *curr=new TreeNode(*mid);
        curr->left=sortedArrayToBST(first,mid);
        curr->right=sortedArrayToBST(mid+1,last);
        return curr;
    }
};
