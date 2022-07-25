 
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

//  Time Complexity: O(N*W)

// Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.

// Space Complexity: O(N*W) + O(N)

// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).










// Tabulation method
 int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,0));
       for(int i =wt[0];i<=W;i++){
           dp[0][i] = val[0];
       }
       
       for(int ind = 1;ind<n;ind++){
           for(int cap = 0;cap<=W;cap++){
               int notTake = 0+ dp[ind-1][cap];
               int take = INT_MIN;
               if(wt[ind] <= cap){
                   take = val[ind] + dp[ind-1][cap-wt[ind]];
               }
               dp[ind][cap] = max(notTake,take);
           }
       }
       
       return dp[n-1][W];
       
    
    }


    // Time Complexity: O(N*W)

Reason: There are two nested loops

// Space Complexity: O(N*W)

// Reason: We are using an external array of size ‘N*W’. Stack Space is eliminated.