#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
   unordered_map<int,bool> rowCheck;
   unordered_map<int,bool> upperLeftDiagnolCheck;
   unordered_map<int,bool> bottomLeftDiagnolCheck;
bool safe(vector<vector<char>> &board,int row, int col, int n){
         if(rowCheck[row] == true )
            return false;
            
        if(upperLeftDiagnolCheck[n-1+col-row] == true)
            return false;
            
        if(bottomLeftDiagnolCheck[row+col] == true)
            return false;

        return true;

}
void printsol(vector<vector<char>> &board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void solve(vector<vector<char>> &board,int col, int n){
    // Base Case
    if(col>=n){
        printsol(board,n);
        return;
    }
    // Placing First Queen
    for(int row = 0; row <n; row++) {
        if(safe(board,row, col, n)) {
        board[row][col] = 'Q';
        rowCheck[row] = true;
        upperLeftDiagnolCheck[n-1+col-row] = true;
        bottomLeftDiagnolCheck[row+col] = true;
            

        solve(board, col+1, n);
        //backtracking
        board[row][col] = '-';
        rowCheck[row] = false;
        upperLeftDiagnolCheck[n-1+col-row] = false;
        bottomLeftDiagnolCheck[row+col] = false;
        }

    }
}
int main(){
    int n=4;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    int col=0;
    solve(board,col,n);
}