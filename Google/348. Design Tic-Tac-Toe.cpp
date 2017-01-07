class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<int> rows;
    vector<int> cols;
    int left_diag;
    int right_diag;
    int size;
    TicTacToe(int n) {
        rows= vector<int>(n);
        cols= vector<int>(n);
        left_diag = 0;
        right_diag = 0;
        size=n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        rows[row]+=3-2*player;
        cols[col]+=3-2*player;
        if(row==col)
            left_diag+=3-2*player;
        if(row==size-col-1)
            right_diag+=3-2*player;
        if(abs(rows[row])==size || abs(cols[col])==size || abs(left_diag)==size || abs(right_diag)==size)
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
