#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t, n;
vector<ll> a, x, ind;
ll nearestLargerGood(ll num){
    ll ans=num-1;
    ans|=ans>>1;
    ans|=ans>>2;
    ans|=ans>>4;
    ans|=ans>>8;
    ans|=ans>>16;
    ans|=ans>>32;
    ans++;
    return ans;

}
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        a.resize(n+1);
        ind.resize(0);
        x.resize(0);
        for (int i=1; i<=n; i++){
            cin>>a[i];
            ll tmp=nearestLargerGood(a[i]);
            ind.push_back(i);
            x.push_back(tmp-a[i]);
        }


        cout<<ind.size()<<endl;
        for (int i=0; i<ind.size(); i++){
            cout<<ind[i]<<" "<<x[i]<<endl;
        }
    }
    return 0;
}
/*
1
4
1 1 1 1

1
8
1 2 4 8 17 536870912 536870910 536870913
*/
