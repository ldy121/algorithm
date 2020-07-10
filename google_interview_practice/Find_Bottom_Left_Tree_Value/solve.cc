class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
	    int ret;

	    for (q.push(root); !q.empty();) {
	    	ret = q.front()->val;
    		for (int size = q.size(); size > 0; --size) {
	    		TreeNode* node = q.front();
    			q.pop();

		    	if (node->left) {
	    			q.push(node->left);
    			}
		    	if (node->right) {
	    			q.push(node->right);
    			}
		    }
	    }
	    return ret;
    }
};

