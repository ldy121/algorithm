/*
 * Complete the swapNodes function below.
 */

void in_order_travers(vector<int>& tree, int idx, vector<int> & output)
{
    if (tree[idx * 2] != -1)    in_order_travers(tree, tree[idx * 2], output);
    output.push_back(idx);
    if (tree[idx * 2 + 1] != -1)    in_order_travers(tree, tree[idx * 2 + 1], output);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<int> tree(indexes.size() * 2 + 1, -1);
    vector<vector<int> > ret;

    tree[1] = 1;
    for (int i = 0; i < indexes.size(); ++i) {
        int j = i + 1;
        tree[j * 2] =       indexes[i][0];
        tree[j * 2 + 1] =   indexes[i][1];
    }

    for (int i = 0; i < queries.size(); ++i) {
        queue<int> q;
        q.push(1);
        for (int next_level = 1; !q.empty(); ++next_level) {
            for (int size = q.size(); size > 0; --size) {
                int idx = q.front();
                q.pop();
                if ((next_level % queries[i]) == 0) {
                    int k = tree[idx * 2];

                    tree[idx * 2] = tree[idx * 2 + 1];
                    tree[idx * 2 + 1] = k;

                }

                if (tree[idx * 2] != -1) q.push(tree[idx * 2]);
                if (tree[idx * 2 + 1] != -1) q.push(tree[idx * 2 + 1]);
            }
        }

        vector<int> out;

        in_order_travers(tree, 1, out);
        ret.push_back(out);
    }

    return ret;
}
