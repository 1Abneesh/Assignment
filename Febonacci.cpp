#include<bits/stdc++.h>
using namespace std;

int rec_feb(int n){
    if(n<=1){
        return n;
    }
    return rec_feb(n-1) + rec_feb(n-2);
}
vector<int> dp(n+1,-1);
int rec_feb(int n){
    
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=rec_feb(n-1) + rec_feb(n-2);
}

int feb(int n){
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){

    cout<<rec_feb(9);
    return 0;
}