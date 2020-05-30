class Solution {
private : 
	inline bool isMine(vector<vector<char>> &board, int row, int col) {
		if (row < 0 || row >= board.size() ) return false;
		if (col < 0 || col >= board[0].size()) return false;
		return (board[row][col] == 'M' || board[row][col] == 'X');
	}        

	void changeBoard(vector<vector<char>> &board, int row, int col) {
		int mineCount = 0;

		if (row < 0 || row >= board.size()) return;
		if (col < 0 || col >= board[0].size()) return;
		if (board[row][col] != 'E') return;

		if (isMine(board, row - 1, col))    ++mineCount;
		if (isMine(board, row + 1, col))    ++mineCount;
		if (isMine(board, row, col - 1))    ++mineCount;
		if (isMine(board, row, col + 1))    ++mineCount;
		if (isMine(board, row - 1, col - 1))++mineCount;
		if (isMine(board, row - 1, col + 1))++mineCount;
		if (isMine(board, row + 1, col - 1))++mineCount;
		if (isMine(board, row + 1, col + 1))++mineCount;

		if (mineCount == 0) {
			board[row][col] = 'B';
			changeBoard(board, row - 1, col);
			changeBoard(board, row + 1, col);
			changeBoard(board, row, col - 1);
			changeBoard(board, row, col + 1);
			changeBoard(board, row - 1, col - 1);
			changeBoard(board, row - 1, col + 1);
			changeBoard(board, row + 1, col - 1);
			changeBoard(board, row + 1, col + 1);            
		} else {
			board[row][col] = '0' + mineCount;
		}
	}

public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		int row = click[0];
		int col = click[1];

		if (board[row][col] == 'E') {
			changeBoard(board, row, col);
		} else {
			board[row][col] = 'X';
		}

		return board;
	}
};
