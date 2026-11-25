// Last updated: 11/25/2026, 3:50:27 PM
class Solution {
public:
    vector<bool> inValidInRow;
    vector<bool> inValidInCol;
    vector<bool> inValidInBox;

    bool isValid(int row, int col, char ch) {
        int num = ch - '1';  // Use 0-based index
        return !inValidInRow[9 * row + num] &&
               !inValidInCol[9 * col + num] &&
               !inValidInBox[9 * (3 * (row / 3) + col / 3) + num];
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (!isValid(i, j, num)) continue;

                        int n = num - '1';
                        board[i][j] = num;
                        inValidInRow[9 * i + n] = true;
                        inValidInCol[9 * j + n] = true;
                        inValidInBox[9 * (3 * (i / 3) + j / 3) + n] = true;

                        if (solve(board)) return true;

                        // Backtrack
                        board[i][j] = '.';
                        inValidInRow[9 * i + n] = false;
                        inValidInCol[9 * j + n] = false;
                        inValidInBox[9 * (3 * (i / 3) + j / 3) + n] = false;
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        inValidInRow = vector<bool>(81, false);
        inValidInCol = vector<bool>(81, false);
        inValidInBox = vector<bool>(81, false);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '1';
                    inValidInRow[9 * i + n] = true;
                    inValidInCol[9 * j + n] = true;
                    inValidInBox[9 * (3 * (i / 3) + j / 3) + n] = true;
                }
            }
        }

        solve(board);
    }
};

// class Solution {
// public:
//     // isValidRow[row][number] is encoded as isValidRow[9*row + number] similarly for column
//     vector<bool>isValidInRow;
//     vector<bool>isValidInCol;
//     vector<bool>isValidInBox;
//     bool Valid(int row,int col,char ch,vector<vector<char>>& board){
//         for(int i = 0; i < 9; i++){
//             if(board[row][i] == ch) return false;
//             if(board[i][col] == ch) return false;
//             if(board[3 * (row / 3) + i / 3][3*(col / 3) + (i % 3)] == ch) return false;
//         }

//         return true;
//     } 
//     bool solve(vector<vector<char>>& board){
//         for(int i = 0;i < 9;i++){
//             for(int j = 0;j < 9;j++){
//                 if(board[i][j] == '.'){
//                     for(char num = '1';num <= '9';num++){
//                         if(!Valid(i,j,num,board))continue;
//                         board[i][j] = num;
//                         bool res = solve(board);
//                         if(res)return true;
//                         board[i][j] = '.';
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
//     void solveSudoku(vector<vector<char>>& board) {
//         isValidInRow = vector<bool>(90,false);
//         isValidInCol = vector<bool>(90,false);
//         isValidInBox = vector<bool>(90,false);
//         solve(board);
//     }
// };
