/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private :
    TreeNode *m_target;
    int m_k;
    int getAnswer(vector<int> &answer, TreeNode *node, int dist) {
        int ret = -1;

        if (node == NULL) {
            return -1;
        }
        
        if (m_target == node) {
            if (m_k > 0) {
                getAnswer(answer, node->left, 1);
                getAnswer(answer, node->right, 1);
                return 1;
            } else {
                answer.push_back(node->val);
                return -1;
            }
        }

        if (dist == 0) {
            int retLeft = getAnswer(answer, node->left, 0);
            int retRight = getAnswer(answer, node->right, 0);
            if (retLeft > 0) {
                getAnswer(answer, node->right, retLeft + 1);
                ret = retLeft + 1;
            } else if (retRight > 0) {
                getAnswer(answer, node->left, retRight + 1);
                ret = retRight + 1;
            }
            
            if (retLeft == m_k || retRight == m_k) {
                answer.push_back(node->val);
            }
        } else if (dist == m_k) {
            answer.push_back(node->val);
        } else {
            getAnswer(answer, node->left, dist + 1);
            getAnswer(answer, node->right, dist + 1);
        }

        return ret;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> answer;
        m_target = target;
        m_k = K;
        getAnswer(answer, root, 0);
        return answer;
    }
};
