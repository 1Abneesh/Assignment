#include<bits/stdc++.h>
using namespace std;

bool isvalid(int row,int col,vector<vector<int>> board,int n){

           int duprow = row;
        int dupcol = col;
        while(row>=0 && col >= 0){
            if(board[row][col] == 1){
                return false;
            }
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(col>=0){
            if(board[row][col] == 1){
                return false;
            }
            col --;
        }
        col = dupcol;
        row = duprow;
        while(row<n && col>=0){
            if(board[row][col] == 1){
                return false;
            }
            row++;
            col--;
        }
        return true;



}


void fun(int n, vector<vector<int>> mat,int indx,vector<vector<vector<int>>> &ds){
    if(indx >= n){
        ds.push_back(mat);
        return ;
    }
    for(int r=0;r<n;r++){
        if(isvalid(r,indx,mat,n)){
            mat[r][indx] = 1;
            fun(n,mat,indx+1,ds);
            mat[r][indx] = 0;
        }
    }
}

int main(){
    int n =8;
    vector<vector<int>> mat(n,vector<int>(n,0));

    vector<vector<vector<int>>> ds;
    

    fun(n,mat,0,ds);
    for(auto it:ds){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<it[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    cout<<"The number of valid solution for the given matrix is:- "<<ds.size();

    return 0;
}