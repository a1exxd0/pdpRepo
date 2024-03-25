#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSafe(int row, int col, vector<vector<char>>& board, int value){
        int n = board.size();

        for(int i =0; i<n; i++){
            // row check
            if(board[row][i] == value) return false;
            //col check
            if(board[i][col] == value) return false;
            //#*3 matrix check
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]== value) 
            return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int n = board.size();

        for(int i = 0; i<n; i++){
            for(int j =0; j<n; j++){
                //check empty spaces 
                if(board[i][j] == '.'){
                    //filling value form 1 to 9
                    for(char value = '1'; value<= '9'; value++){
                        //check for safety 
                        if(isSafe(i,j,board,value)){
                            board[i][j] =  value;
                            // recursion call 
                             bool aageKaSolution = solve(board);
                             if(aageKaSolution == true){
                                 return true;
                             }
                              else{
                                 //backtrack
                                 board[i][j]='.';
                             }
                        }
                    }
                    return false;
                }
            }
        }
        //all cells are filled
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};