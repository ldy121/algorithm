class SubrectangleQueries {
private :
  vector<vector<int> > m_rectangle;

public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        for (int i = 0; i < rectangle.size(); ++i) {
            m_rectangle.push_back(rectangle[i]);
        }        
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; ++i) {
	        for (int j = col1; j <= col2; ++j) {
    	        m_rectangle[i][j] = newValue;
    	    }
        }
    }
    
    int getValue(int row, int col) {
        return m_rectangle[row][col];
    }

};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
