#include <bits/stdc++.h>
#define oo 10000007
using namespace std;

int t, n, a[53], res, amin;

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        amin = oo;
        for (int i=1; i<=n; i++){
            cin>>a[i];
            amin=min(amin,a[i]);
        }
        res=0;
        for (int i=1; i<=n; i++){
            res+=a[i]-amin;
        }
        cout<<res<<"\n";
    }
    return 0;
}
