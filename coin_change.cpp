// memoization method


long long f(int ind, int n,int S[],vector<vector<long long>>&dp){
      //base case
     if(n == 0) return 1;
     if(n<0) return 0;
     if(ind <= 0) return 0;
     if(dp[ind][n] != -1) return dp[ind][n];
      return dp[ind][n] =f(ind-1,n,S,dp) + f(ind,n-S[ind-1],S,dp);
  }


//main
long long int count(int S[], int m, int n) {

        // code here.
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,-1));
        return f(m,n,S,dp);
    }

