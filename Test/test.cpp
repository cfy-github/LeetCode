#include <utility>
#include <deque>
#include <iostream>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

int maxDepth(TreeNode *root) {
	deque<pair<TreeNode*,int> > q;//= new deque<pair<TreeNode*,int> >();
        q.push_front(make_pair(root,1));
        pair<TreeNode*, int> curr;
        int max=0;
        while(!q.empty()) {
            int flag=0;
            curr=q.front();
            q.pop_front();
            pair<TreeNode*,int> child;
            if(curr.first->right!=NULL) {
                flag=1;
                child=make_pair(curr.first->right,curr.second+1);
                q.push_front(child);
            }
            if(curr.first->left!=NULL) {
                flag=1;
                child=make_pair(curr.first->left,curr.second+1);
                q.push_front(child);
            }
            if(flag==0 && curr.second>max) max=curr.second;
        }
	return max;
}
int main() {
	struct TreeNode n6(6);
	struct TreeNode n7(7);
	struct TreeNode n3(3);
	struct TreeNode n4(4, &n6, &n7);
	struct TreeNode n5(5);
	struct TreeNode n1(1,&n3, &n4);
	struct TreeNode n2(2, NULL, &n5);
	struct TreeNode n0(0, &n1, &n2);
	deque<pair<TreeNode*, int> > q;
	q.push_front(make_pair(&n0, 1));
	pair<TreeNode*, int> curr;
	curr=q.front();
	q.pop_front();
	q.push_front(make_pair(curr.first->right, curr.second+1));
	q.push_front(make_pair(curr.first->left, curr.second+1));
	//println(q.front().first->left.val);
	cout<<q.front().first->left->val<<'\t'<<q.front().second<<endl;
	cout<<q.back().first->right->val<<'\t'<<q.front().second<<endl;
	cout<<maxDepth(&n0)<<endl;
	return 1;
}
