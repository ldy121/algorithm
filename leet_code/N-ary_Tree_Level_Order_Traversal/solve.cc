class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		queue<Node*> q;
		vector<vector<int> > ret;

		if (root == NULL) {
			return ret;
		}

		for (q.push(root); !q.empty();) {
			vector<int> vec;
			for (int size = q.size(); size > 0; --size) {
				Node* node = q.front();
				q.pop();
				vec.push_back(node->val);
				for (int i = 0; i < node->children.size(); ++i) {
					Node* nd = node->children[i];
					q.push(nd);
				}
			}
			ret.push_back(vec);
		}
		return ret;
	}
};
