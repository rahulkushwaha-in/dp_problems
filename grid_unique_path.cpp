#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// memoization method
// TC: O(M*N)
//SC:  O((N-1) + (M-1)) + O(M*N)
int grid_path(int i, int j, vector<vector<int>>&dp){
    if(i == 0 && j == 0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int left = grid_path(i,j-1,dp);
    int up = grid_path(i-1,j,dp);
    return dp[i][j] =  left+up;
}

// int countWays(int m, int n){
//     vector<vector<int>>dp(m,vector<int>(n,-1));
//     return grid_path(m-1,n-1,dp);

// }

// int main(){
//  int m =3;
//  int n = 2;
//  cout<<countWays(m,n);
// }


//Tabulation method
int grid_path_tab(int m,int n, vector<vector<int>>&dp){
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            //basee condition
            if(i == 0 && j == 0){
                dp[i][j] =1;
                continue;
            }

            int down =0;
            int right =0;
            if(i>0)
                down = dp[i-1][j];
            if(j>0)
                right = dp[i][j-1];
            
            dp[i][j] = right + down;
            

        }
    }
    return dp[m-1][n-1];
}

int countWays(int m, int n){
    vector<vector<int>>dp(m,vector<int>(n,0));
    return grid_path_tab(m,n,dp);

}

int main(){
 int m =3;
 int n = 2;
 cout<<countWays(m,n);
}