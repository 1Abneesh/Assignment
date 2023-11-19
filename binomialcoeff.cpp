#include<bits/stdc++.h>
using namespace std;

int bino(int n,int r,vector<vector<int>> &dp){
    if(n==r || r == 0){
        return 1;
    }
    if(dp[n][r]!=-1){
        return dp[n][r];
    }
    return dp[n][r] = bino(n-1,r-1,dp) + bino(n-1,r,dp);
}

int dummy(int n,int r){
    vector<vector<int>> dp(n+1,vector<int>(r+1,0));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,r);j++){
            if(i == j || j == 0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    return dp[n][r];
}


int binomialCoeff(int n, int r) {
    vector<vector<int>> dp(n + 1,vector<int>(r + 1, 0));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= min(i, r); ++j) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][r];
}

int main() {
    int n = 27; // Example values for n and r
    int r = 17;

    cout << "Binomial Coefficient C(" << n << ", " << r << ") = " << dummy(n, r) << "\n";

    return 0;
}



// int main(){
//     int n = 5;
//     int r = 2;
//     vector<vector<int>> dp(n+1,vector<int>(r+1,-1));


//     cout<<bino(n,r,dp);

//     return 0;
// }
