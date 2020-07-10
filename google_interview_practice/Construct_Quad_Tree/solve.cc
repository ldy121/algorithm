class Solution {
private:
   Node* createTreeNode(vector<vector<int> >&grid, int left, int top, int right, int bottom) {
    Node *node = new Node();
    node->isLeaf = true;
       
    for (int i = top; (i <= bottom) && (node->isLeaf); ++i) {
	    for (int j = left; (j <= right) && (node->isLeaf); ++j) {
		    if (grid[top][left] != grid[i][j]) {
    			node->isLeaf = false;
	    	}
	    }
    }

    if (node->isLeaf == false) {
	    int middle = (left + right) / 2;
	    int center = (top + bottom) / 2;
	    node->topLeft = 
            createTreeNode(grid, left, top, middle, center);
	    node->bottomLeft =
            createTreeNode(grid, left, center + 1, middle, bottom);        
	    node->topRight =
            createTreeNode(grid, middle + 1, top, right, center);
	    node->bottomRight =
            createTreeNode(grid, middle + 1, center + 1, right, bottom);
    } else {
    	node->val = grid[top][left];
    }

    return node;
   }

public:
    Node* construct(vector<vector<int>>& grid) {
        return createTreeNode(grid, 0, 0, grid[0].size() - 1, grid.size() - 1);
    }
};

