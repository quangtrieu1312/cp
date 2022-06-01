#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, n, q;
vector<ll> a, x, sum;
int res;
int binSearch(ll x, int l, int r){
    if (l>r || r<l){
        return -1;
    }
    int mid=(l+r)/2;
    while (l<r-1){
        mid=(l+r)/2;
        if (sum[mid]<x){
            l=mid+1;
        } else {
            r=mid;
        }
    }
    if (l>r || r<l || sum[r]<x){
        return -1;
    }
    if (sum[l]>=x){
        return l;
    } else {
        return r;
    }
}
int main()
{
    cin>>t;
    while (t--){
        cin>>n>>q;
        a.resize(n+1);
        x.resize(q+1);
        sum.resize(n+1);
        a[0]=0;
        sum[0]=0;
        for (int i=1; i<=n; i++){
            cin>>a[i];
        }
        for (int i=1; i<=q; i++){
            cin>>x[i];
        }

        sort(a.begin(),a.end());
        for (int i=n; i>=1; i--){
            sum[n-i+1]=sum[n-i]+a[i];
        }

        for (int i=1; i<=q; i++){
            cout<<binSearch(x[i],1,n)<<endl;
        }
    }
    return 0;
}
