#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, m;
vector<ll> a, pre_diff, pre_sum, post_diff, post_sum;
vector<int> s, t;
int main()
{
    cin>>n>>m;
    a.resize(n+2);
    s.resize(m);
    t.resize(m);
    pre_sum.resize(n+2);
    pre_diff.resize(n+2);
    post_sum.resize(n+2);
    post_diff.resize(n+2);
    a[0]=0;
    a[n+1]=0;
    for (int i=1; i<=n; i++){
        cin>>a[i];
    }
    pre_diff[0]=0;
    pre_sum[0]=0;
    for (int i=1; i<=n; i++){
        pre_diff[i]=(a[i]>a[i-1])?0:a[i-1]-a[i];
        pre_sum[i]=pre_sum[i-1]+pre_diff[i];
    }

    post_diff[n+1]=0;
    post_sum[n+1]=0;
    for (int i=n; i>=1; i--){
        post_diff[i]=(a[i]>a[i+1])?0:a[i+1]-a[i];
        post_sum[i]=post_sum[i+1]+post_diff[i];
    }

    for (int i=0; i<m; i++){
        cin>>s[i]>>t[i];
    }



    for (int i=0; i<m; i++){
        if (s[i]<t[i]){
            cout<<pre_sum[t[i]]-pre_sum[s[i]]<<endl;
        } else {
            cout<<post_sum[t[i]]-post_sum[s[i]]<<endl;
        }
    }

    return 0;
}
