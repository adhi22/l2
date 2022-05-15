// #include <iostream>
// #include <vector>

// using namespace std;

// bool solve()

// int main()
// {
//     int n;
//     cout << "Enter n : "; cin >> n;
//     vector<vector<int>> board(n, vector<int> (n, 0));
//     solve();
//     return 0;
// }








#include <iostream>
#include <vector>
using namespace std;

void printSolution(vector<vector<int>> &board, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

bool isSafe(int row, int col, vector<vector<int>> slashCode, vector<vector<int>> backSlashCode, vector<int> slashLookUp, vector<int> backSlashLookUp, vector<int> rowLookUp){
    if(slashLookUp[slashCode[row][col]] || backSlashLookUp[backSlashCode[row][col]] || rowLookUp[row]){
        return false;
    }
    return true;
}

bool solveNQN(vector<vector<int>> &board,int col,vector<vector<int>> &slashCode,vector<vector<int>> &backSlashCode,vector<int> &slashLookUp,vector<int> &backSlashLookUp,vector<int> rowLookUp, int n){
    if(col >= n){
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if(isSafe(i,col,slashCode,backSlashCode,slashLookUp,backSlashLookUp,rowLookUp)){
            board[i][col] = 1;
            rowLookUp[i] = 1;
            slashLookUp[slashCode[i][col]] = 1;
            backSlashLookUp[backSlashCode[i][col]] = 1;
            if(solveNQN(board,col+1,slashCode,backSlashCode,slashLookUp,backSlashLookUp,rowLookUp,n)){
                return true;
            }
            board[i][col] = 0;
            rowLookUp[i] = 0;
            slashLookUp[slashCode[i][col]] = 0;
            backSlashLookUp[backSlashCode[i][col]] = 0;
        }
    }
    return false;
    
}

bool solve(){
    int n;
    cin >> n;
    vector<vector<int>> board(n,vector<int>(n,0));

    vector<vector<int>> slashCode(n, vector<int>(n, 0));
    vector<vector<int>> backSlashCode(n, vector<int>(n, 0));
    vector<int> rowLookUp(n,0);

    vector<int> slashCodeLookUp(2*n-1,0);
    vector<int> backSlashCodeLookUp(2*n-1 , 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            slashCode[i][j] = i + j;
            backSlashCode[i][j] = i - j + n - 1;
        }
        
    }
    if(solveNQN(board,0,slashCode,backSlashCode,slashCodeLookUp,backSlashCodeLookUp,rowLookUp,n) == false){
        cout<<"Solution does not exists"<<endl;
        return false;
    }
    printSolution(board,n);
    return true;
    
}   

int main(){
    solve();
}