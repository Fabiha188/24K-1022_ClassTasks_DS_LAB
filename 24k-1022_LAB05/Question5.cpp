#include <iostream>
using namespace std;
 
int totalCount=0;

void print(int board[20][20],int N){
    for(int i=0;i<N ;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==1){
                cout<<" Q ";

            }
            else{
                cout<<" . ";
            }
            
        }
        cout<<endl;
    }
    cout<<endl;
}
bool isSafe(int board[20][20],int N,int col,int row){
    for(int r=0;r<row;r++){
        if(board[r][col]==1){
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j<N;i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}

bool solveNQueen(int board[20][20],int N,int row){
    if(row==N){
        totalCount++;
        cout<<"Solution Count: "<<totalCount<<endl;
        print(board,N);
        return true;
    }
bool result=false;
    for(int i=0;i<N;i++){
        if(isSafe(board,N,i,row)){
            board[row][i]=1;
            result=solveNQueen(board,N,row+1) || result;
            board[row][i]=0;
        }
    }
return result;
}
int main(){
    int N;
    cout<<"Enter Value Of N: ";
    cin>>N;
    int board[20][20]={0};
    if(!solveNQueen(board,N,0)){
        cout<<"No Solution Found";
    }
    else{
        cout << "Total number of distinct solutions for N=" << N << " is: " << totalCount << endl;
    }

    return 0;
}
