#include <bits/stdc++.h>
#define oo 100000008
using namespace std;
int t, n, m, res;
string s[53];
int calc_diff(string a, string b){
    int len = a.length();
    int ans=0;
    for (int i=0; i<len; i++){
        ans+=min(abs(a[i]-b[i]),(max(a[i],b[i])+26-min(a[i],b[i]))%26 );
    }
    return ans;
}
int main()
{
    cin>>t;
    while (t--){
        cin>>n>>m;
        res=oo;
        for (int i=0; i<n; i++){
            cin>>s[i];
        }
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                res=min(res,calc_diff(s[i],s[j]));
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
