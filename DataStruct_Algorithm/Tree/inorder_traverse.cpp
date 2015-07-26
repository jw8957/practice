#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Inorder_Nonrecursive(TreeNode *root) {
    if(NULL == root) {
        return;
    }
    stack<TreeNode*> node_stack;
    TreeNode *pt = root;
    bool ispop = false;
    while(NULL != pt) {
        if(!ispop && pt->left) {
            node_stack.push(pt);
            pt = pt -> left;
            ispop = false;
        } else {
            cout << pt->val;
            if(pt -> right) {
                pt = pt->right;
                ispop = false;
            } else {
                if(!node_stack.empty()) {
                    pt = node_stack.top();
					node_stack.pop();
                    ispop = true;
                } else {
					pt = NULL;
				}
            }
        }
    }
}

int main() {
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(1);
    TreeNode *t4 = new TreeNode(2);
    TreeNode *t5 = new TreeNode(3);
    TreeNode *t6 = new TreeNode(6);
    t1->left = t2;
    t2->left = t3;
    t3->right = t4;
    t4->right = t5;
    t1->right = t6;
    
    TreeNode *root = t1;
    Inorder_Nonrecursive(root);

    return 0;
}
