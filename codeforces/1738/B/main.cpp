#include <bits/stdc++.h>
#define salt 1000000000
using namespace std;
typedef long long ll;
int t, n, k;
vector<ll> s;
bool res;
int main()
{
    cin>>t;
    while (t--){
        cin>>n>>k;
        s.resize(k);
        for (int i=0; i<k; i++){
            cin>>s[i];
            s[i]=s[i];
        }
        res=true;
        ll min_a=ceil(s[0]*((double)1.0)/(n-k+1));
        ll nxt_a;
        for (int i=1; i<k; i++){
            nxt_a=s[i]-s[i-1];
            if (nxt_a<min_a){
                res=false;
                break;
            } else {
                min_a=nxt_a;
            }
        }
        if (res){
            cout<<"yes"<<endl;
        } else {
            cout<<"no"<<endl;
        }
    }
    return 0;
}
/*
4
5 5
1 2 3 4 5
7 4
-6 -5 -3 0
3 3
2 3 4
3 2
3 4

1
7 4
-6 -5 -3 0

*/
