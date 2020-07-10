/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private :
	list<int> m_list;
	list<int>::iterator m_iter;
	void makeNodeList(TreeNode *node) {
		if (node->left) makeNodeList(node->left);
		m_list.push_back(node->val);
		if (node->right) makeNodeList(node->right);
	}
public:
    BSTIterator(TreeNode* root) {
        if (root != NULL) {
	        makeNodeList(root);
	        m_iter = m_list.begin();
        } else {
            m_iter = m_list.end();
        }
    }
    
    /** @return the next smallest number */
    int next() {
	    int ret = *m_iter;
	    ++m_iter;
	    return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
	    return (m_iter != m_list.end());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
