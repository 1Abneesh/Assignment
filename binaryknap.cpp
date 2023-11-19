#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt,vector<int> val,int cap,int ind,int n,vector<vector<int>> &dp){
    if(ind == 0 ){
        if(cap >= wt[ind]){
            return val[0];
        }
        else return 0;
    }
    if(dp[ind][cap] !=-1){
        return dp[ind][cap];
    }
    int taken = 0;
    int notaken = 0;
    notaken = knapsack(wt,val,cap,ind-1,n,dp);
    if(wt[ind]<=cap){
        taken = val[ind] + knapsack(wt,val,cap-wt[ind],ind-1,n,dp);
    }
    return dp[ind][cap] =  max(taken,notaken);
}
int knapsack(vector<int> wt,vector<int> val,int cap,int n){
    vector<vector<int>> dp(n,vector<int>(cap+1,0));

    for(int i=wt[0];i<=cap;i++){
        dp[0][i] = val[0];
    }

    for(int ind = 1;ind<n;ind++){
        for(int j=0;j<=cap;j++){
            int taken = 0;
            int notaken = 0;
            notaken = dp[ind-1][j];
            if(wt[ind]<=j){
                taken = val[ind] + dp[ind-1][j-wt[ind]];;
            }
             dp[ind][j] =  max(taken,notaken);
        }
    }

    return dp[n-1][cap] ;
}

// int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
//     // Create a 2D DP table with dimensions n x W+1 and initialize it with zeros
//     vector<vector<int>> dp(n, vector<int>(W + 1, 0));

//     // Base condition: Fill in the first row for the weight of the first item
//     for (int i = wt[0]; i <= W; i++) {
//         dp[0][i] = val[0];
//     }

//     // Fill in the DP table using a bottom-up approach
//     for (int ind = 1; ind < n; ind++) {
//         for (int cap = 0; cap <= W; cap++) {
//             // Calculate the maximum value by either excluding the current item or including it
//             int notTaken = dp[ind - 1][cap];
//             int taken = INT_MIN;

//             // Check if the current item can be included without exceeding the knapsack's capacity
//             if (wt[ind] <= cap) {
//                 taken = val[ind] + dp[ind - 1][cap - wt[ind]];
//             }

//             // Update the DP table
//             dp[ind][cap] = max(notTaken, taken);
//         }
//     }

//     // The final result is in the last cell of the DP table
//     return dp[n - 1][W];
// }



int main(){
    vector<int> wt = {2,3,4,5,2,9};
    vector<int> val = {30,32,40,50,50,70};
    int W = 7;
    int n = wt.size();
    vector<vector<int>> dp(n,vector<int>(W+1,-1));

    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, W,n-1,n,dp);
    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, W,n);


    return 0;
}