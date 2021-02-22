/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        queue<TreeNode*> q;
        
        if (root == NULL) {
            return ret;
        }
        
        for (q.push(root); !q.empty();) {
            for (int size = q.size(); size > 0; --size) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
                ret += "<";
                if (node->val == 0) {
                    ret += "0";
                } else {
                    string str;
                    for (int i = node->val; i > 0; i /= 10) {
                        str = (char)(i % 10 + '0') + str;
                    }
                    ret += str;
                }
            }
        }
        return ret;
    }
    
    TreeNode* pushNode(TreeNode* node, int val) {
        if (node == NULL) {
            return new TreeNode(val);
        } else if (node->val > val) {
            node->left = pushNode(node->left, val);
        } else {
            node->right = pushNode(node->right, val);
        }
        return node;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        
        for (int i = 1; i < data.length(); ++i) {
            int val = 0;

            while (i < data.length() && data[i] >= '0' && data[i] <= '9') {
                val = val * 10 + data[i] - '0';
                ++i;
            }
            
            root = pushNode(root, val);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
