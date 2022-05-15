#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> &board, int n, int row, int col) {
    // columns
    for(int i=0; i<col; i++) {
        if(board[row][i]) return false;
    }

    // upper left
    for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
        if(board[i][j]) return false;
    }

    // upper right
    for(int i=row, j=col; j>=0 && i<n; i++, j--) {
        if(board[i][j]) return false;
    }

    return true;
}

bool solveProblem(vector<vector<int>> &board, int col, int n) {
    // iterate every row
    if(col >= n) return true;

    for(int i=0; i<n; i++) {
        if(isSafe(board, n, i, col)) {
            board[i][col] = 1;
            if(solveProblem(board, col+1, n)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void printBoard(vector<vector<int>> &board, int n) {
    if(solveProblem(board, 0, n)) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "No soln exist\n";
    }
}

int main() {
    int n;
    cout << "Enter n : "; cin >> n;
    vector<vector<int>> board(n, vector<int> (n, 0));
    printBoard(board, n);
    return 0;
}






// #include <iostream>
// #include <vector>
// using namespace std;

// bool isSafe(int row, int col, vector<vector<int>> &board, int n){
//     // for columns 
//     for(int i=0;i<=col;i++){
//         if(board[row][i]){
//             return false;
//         }
//     }

//     // upper left
//     for(int i=row,j=col;i>=0&&j>=0;i--,j--){
//         if(board[i][j]){
//             return false;
//         }
//     }

//     // upper right
//     for(int i=row,j=col;i>=0&&j<n;i--,j++){
//         if(board[i][j]){
//             return false;
//         }
//     }

//     return true;
// }

// bool solveNQN(vector<vector<int>> &board, int col, int n){
//     if(col >= n){
//         return true;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if(isSafe(i,col,board,n)){
//             board[i][col] = 1;
//             if (solveNQN(board,col+1,n))
//             {
//                 return true;
//             }
//             board[i][col] = 0;
//         }
//     }
//     return false;
// }

// void printBoard(vector<vector<int>> &board, int n){
//     if(solveNQN(board,0,n)){
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cout<<board[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
//     }
//     else{
//         cout<<"Solution not possible"<<endl;
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> board(n,vector<int>(n,0));
//     printBoard(board,n);
    
// }