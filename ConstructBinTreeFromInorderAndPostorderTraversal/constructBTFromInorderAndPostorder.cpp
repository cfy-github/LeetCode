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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n=postorder.size();
        if(postorder.empty()) return NULL;
        int rootVal=postorder[n-1];
        TreeNode *curr=new TreeNode(rootVal);
        vector<vector<int>::iterator> orderList;
        getSubtreeXorder(rootVal, inorder, postorder, orderList);
        curr->left=buildTree(orderList[0],orderList[1],orderList[4],orderList[5]);
        curr->right=buildTree(orderList[2],orderList[3],orderList[6],orderList[7]);
        return curr;
    }
    template<typename InputIterator, typename OutputIterator>
        OutputIterator safeCopy(InputIterator first, InputIterator last, OutputIterator result) {
            while(first<last) {
                *result=*first;
                ++result;++first;
            }
            return result;
        }
    TreeNode *buildTree(vector<int>::iterator inFirst, vector<int>::iterator inLast,
        vector<int>::iterator postFirst, vector<int>::iterator postLast) {
        TreeNode *curr=NULL;
        if(inFirst<inLast) {
            int rootVal=*(prev(postLast));
            curr=new TreeNode(rootVal);
            vector<vector<int>::iterator> orderList;
            getSubtreeXorder(rootVal, inFirst, inLast, postFirst, postLast, orderList);
            curr->left=buildTree(orderList[0],orderList[1],orderList[4],orderList[5]);
            curr->right=buildTree(orderList[2],orderList[3],orderList[6],orderList[7]);
        }
        return curr;
    }
    void getSubtreeXorder(int rval, 
        vector<int>::iterator in0, vector<int>::iterator in1, 
        vector<int>::iterator post0, vector<int>::iterator post1,
        vector<vector<int>::iterator> &l) {
            auto rit=find(in0,in1,rval);
            l.push_back(in0);l.push_back(rit);
            l.push_back(next(rit));l.push_back(in1);
            auto it=next(post0,distance(in0,rit));
            l.push_back(post0);l.push_back(it);
            l.push_back(it);l.push_back(prev(post1));
        }
    void getSubtreeXorder(int rval, vector<int> &in, vector<int> &post, vector<vector<int>::iterator> &l) {
        auto rit=find(in.begin(),in.end(),rval);
        l.push_back(in.begin());l.push_back(rit);
        l.push_back(next(rit));l.push_back(in.end());
        auto it=next(post.begin(),distance(in.begin(),rit));
        l.push_back(post.begin());l.push_back(it);
        l.push_back(it);l.push_back(prev(post.end()));
    }
};
