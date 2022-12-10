#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int t, n;
vector<int> a;
vector<ll> b, frost, fire;
ll res;
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        a.resize(n+1);
        for (int i=1; i<=n; i++){
            cin>>a[i];
        }
        b.resize(n+1);
        for (int i=1; i<=n; i++){
            cin>>b[i];
        }

        frost.resize(0);
        fire.resize(0);
        for (int i=1; i<=n; i++){
            if (a[i]==0){
                frost.push_back(b[i]);
            } else {
                fire.push_back(b[i]);
            }
        }
        if (frost.size()<fire.size()){
            swap(frost,fire);
        }
        //frost array >= fire array
        sort(frost.begin(), frost.end(), greater<ll>());
        sort(fire.begin(), fire.end(), greater<ll>());
        ll tmp=0;
        //fire first
        for (int i=0; i<fire.size(); i++){
            tmp+=2*fire[i];
            if (i!=fire.size()-1){
                tmp+=2*frost[i];
            } else {
                tmp+=frost[i];
            }
        }
        for (int i=fire.size(); i<frost.size(); i++){
            tmp+=frost[i];
        }
        res=tmp;
        tmp=0;
        //frost first
        for (int i=0; i<fire.size(); i++){
            tmp+=2*frost[i];
            if (i!=fire.size()-1 || fire.size()!=frost.size()){
                tmp+=2*fire[i];
            } else {
                tmp+=fire[i];
            }
        }
        for (int i=fire.size(); i<frost.size(); i++){
            tmp+=frost[i];
        }

        res=max(res,tmp);
        cout<<res<<endl;
    }
    return 0;
}
/*
4
4
0 1 1 1
1 10 100 1000
6
0 0 0 1 1 1
3 4 5 6 7 8
3
1 1 1
1000000000 1000000000 1000000000
1
1
1

1
1
1
1
*/
