#include <iostream>
#include <cstdlib>
using namespace std;

const int ROWS = 8;
const int COLUMNS = 8;

void initilize_false_board(bool board[ROWS][COLUMNS]);
bool check_board(bool board[ROWS][COLUMNS]);
bool check_vertical(bool board[ROWS][COLUMNS], int row, int col);
bool check_diagonal(bool board[ROWS][COLUMNS], int row, int col);

int main()
{
    bool board[ROWS][COLUMNS];
    initilize_false_board(board);
    
    if (check_board(board)) {
        printf("valid\n");
    } else {
        printf("invalid\n");
    }
    return 0;
}

bool check_board(bool board[ROWS][COLUMNS])
{
    int count_queens = 0;
    
    for (int i = 0; i < ROWS; ++i) {
        
        bool row_contains_queen = false;
        
        for (int j = 0; j < COLUMNS; ++j) {
            
            char curr = cin.get();
            while (curr == '\n') {
                curr = cin.get();
            }
            
            if (curr == '*') {
                
                if (row_contains_queen) {
                    return false;
                }
                
                board[i][j] = true;
                row_contains_queen = true;
                count_queens++;
                
                if (!check_vertical(board, i, j)) {
                    return false;
                }
                
                if (!check_diagonal(board, i, j)) {
                    return false;
                }
                
            } else {
                board[i][j] = false;
            }
            
        }
    }
    if (count_queens == 8){
        return true;
    }
    return false;
}

bool check_diagonal(bool board[ROWS][COLUMNS], int row, int col)
{
    for(int k = 0; k < row; ++k) {
        int left = col - row + k;
        int right = col + row - k;
        if (left >= 0 ) {
            if ( board[row][col] == board[k][left]) {
                return false;
            }
        }
        if (right < ROWS) {
            if (board[row][col] == board[k][right]) {
                return false;
            }
        }
    }
    return true;
}

bool check_vertical(bool board[ROWS][COLUMNS], int row, int col)
{
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == board[row][col]){
            return false;
        }
    }
    return true;
}

void initilize_false_board(bool board[ROWS][COLUMNS])
{
    for(int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = false;
        }
    }
}