#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t;
int n;
ll x, y;
string a, b;
ll res=0;
vector<bool> marked;
ll calcCost(int i, int j){
    if (abs(i-j)==1){
        return x;
    } else {
        return y;
    }
}
int main()
{
    cin>>t;
    while (t--){
        cin>>n>>x>>y;
        cin>>a>>b;

        res=0;
        vector<int> indv;
        for (int i=0; i<n; i++){
            if (a[i]!=b[i]){
                indv.push_back(i);
            }
        }
        if (indv.size()&1){
            cout<<-1<<endl;
            continue;
        }
        if (indv.size()==0){
            cout<<0<<endl;
            continue;
        }
        if (indv.size()%4==0){
            res=y*indv.size()*1L/2;
        } else if (indv.size()>2) {
            res=y*indv.size()*1L/2;
        } else {
            int ai=indv[0];
            int bi=indv[1];
            if (ai!=0 && bi!=n-1){
                res=min(calcCost(ai,bi),calcCost(0,ai)+calcCost(0,bi));
                res=min(calcCost(ai,bi),calcCost(ai,n-1)+calcCost(bi,n-1));
            } else if (ai!=0){
                res=min(calcCost(ai,bi),calcCost(0,ai)+calcCost(0,bi));
            } else if (bi!=n-1) {
                res=min(calcCost(ai,bi),calcCost(ai,n-1)+calcCost(bi,n-1));
            } else {
                res=calcCost(ai,bi);
            }
        }

        cout<<res<<endl;
    }
    return 0;
}
/*
1
6 8 4
01010101
10101010
*/
