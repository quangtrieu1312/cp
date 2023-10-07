#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t, n;
vector<int> a;
ll cnt_max, cnt_min;
ll res;
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        a.resize(0);
        a.resize(n);
        for (int i=0; i<n; i++){
            cin>>a[i];
        }
        int a_min=a[0], a_max=a[0];
        res=0;
        for (int i=1; i<n; i++){
            a_min=min(a_min,a[i]);
            a_max=max(a_max,a[i]);
        }
        cnt_min=0;
        cnt_max=0;
        for (int i=0; i<n; i++){
            if (a[i]==a_min){
                cnt_min++;
            }
            if (a[i]==a_max){
                cnt_max++;
            }
        }
        if (a_min==a_max){
            res=1LL*n*(n-1);
        } else {
            res=1LL*cnt_max*cnt_min*2;
        }
        cout<<res<<endl;
    }
    return 0;
}
/*
3
5
6 2 3 8 1
6
7 2 8 3 2 10
6
1 1 1 1 1 1
*/
