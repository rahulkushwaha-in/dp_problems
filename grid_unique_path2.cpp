#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>>&matrix,vector<vector<int>>&dp){
    if(i>0 && j>0 && matrix[i][j] == -1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i<0 || j<0 ) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] =  f(i-1,j,matrix,dp) + f(i,j-1,matrix,dp); 
}

int memoFunc(int n,int m, vector<vector<int>>&matrix){
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(n-1,m-1,matrix,dp);
}


int main(){
    vector<vector<int>>matrix{{0,0,0},
                              {0,-1,0},
                              {0,0,0}
                             };
    int n = matrix.size();
    int m = matrix[0].size();
   cout<<memoFunc(n,m,matrix);


}


// for tabluation same code for normal grid path without obstacle
// just add the one base case