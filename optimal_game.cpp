// Remember 2 things:
// 1.Assume worst when things happens to you
// 2.Do best when you can.

//memoized method

class soltion{

public:

int solve(int i,int j, int arr[],vector<vector<long long>>&dp){
        if(i+1 == j)
            return max(arr[i],arr[j]);
        if(dp[i][j] != -1) return dp[i][j];
        long long choice1 = arr[i] + min(solve(i+2,j,arr,dp),solve(i+1,j-1,arr,dp));
        long long choice2 = arr[j] + min(solve(i+1,j-1,arr,dp),solve(i,j-2,arr,dp));
        return dp[i][j] =  max(choice1,choice2);
    }


    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<long long>>dp(n,vector<long long>(n,-1));
        return solve(0,n-1,arr,dp);
    }

};