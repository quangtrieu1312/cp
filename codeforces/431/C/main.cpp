#include <bits/stdc++.h>
#define NMAX 101
#define MODULO 1000000007

using namespace std;

int n, k, d;

// dp[step]
int dp[NMAX];
int calcNumOfWays(int sum, int maxWeight) {
    if (maxWeight == 0) {
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    dp[1]=1;
    for (int i=2; i<=maxWeight; i++) {
        dp[i]=1;
        for (int j=1; j<=i; j++) {
            dp[i]+=dp[i-j];
            dp[i]%=MODULO;
        }
    }
    for (int i=maxWeight+1; i<=sum; i++) {
        for (int j=1; j<=maxWeight; j++) {
            dp[i]+=dp[i-j];
            dp[i]%=MODULO;
        }
    }
    return dp[sum];
}

int main() {
    cin>>n>>k>>d;
    cout<< (calcNumOfWays(n, k) - calcNumOfWays(n,d-1) + MODULO) % MODULO<< endl;
}
