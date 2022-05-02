#include <bits/stdc++.h>
#define Nmax 200005
#define Amax 1000006
#define oo 5*Amax
using namespace std;
typedef long long ll;

int n, a[Nmax], dp[Nmax][2];

int main()
{
    cin >> n;
    a[0]=oo;
    a[n+1]=oo;
    for (int i=1; i<=n; i++){
        cin>>a[i];
    }

    int res=oo;
    dp[0][0]=oo;
    dp[0][1]=oo;
    dp[n+1][0]=oo;
    dp[n+1][1]=oo;
    int smallest = oo, second_smallest = oo;
    for (int i=1; i<=n; i++){
        dp[i][0] = min((a[i]+1)/2,min(a[i-1],a[i+1]));
        if (smallest > dp[i][0]){
            second_smallest = smallest;
            smallest = dp[i][0];
        } else if (second_smallest == oo){
            second_smallest = dp[i][0];
        }
    }
    res = smallest + second_smallest;
    for (int i=1; i<=n; i++){
        dp[i][1] =
    }

    cout << res;
    return 0;
}
