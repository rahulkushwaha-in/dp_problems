 
 // Memoized function on  01 knapsack problem
 int f(int ind, int W,int wt[],int val[],vector<vector<int>>&dp){
       //base case
       if(ind == 0){
           if(wt[0] <= W)
            return val[0];
        return 0;
       }
       if(dp[ind][W] != -1)
       return dp[ind][W];
       
       int notTake = f(ind-1,W,wt,val,dp);
       int Take = INT_MIN;
       if(wt[ind] <= W){
           Take = val[ind] + f(ind-1,W-wt[ind],wt,val,dp);
       }
       return dp[ind][W] =max(notTake,Take);
   }

   // main 
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return f(n-1,W,wt,val,dp);
    
    }