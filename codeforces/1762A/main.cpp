#include <bits/stdc++.h>

using namespace std;
int t, n;
vector<int> a, make_odd, make_even;
int sum;
int main()
{
    cin>>t;
    while (t--){
        int res=0;
        cin>>n;
        a.resize(n);
        make_odd.resize(0);
        make_odd.resize(n,0);
        make_even.resize(0);
        make_even.resize(n,0);
        sum=0;
        for (int i=0; i<n; i++){
            cin>>a[i];
            sum+=(a[i]&1);
        }
        if (sum&1){
            for (int i=0; i<n; i++){
                int tmp=a[i];
                if (tmp&1){
                    while (tmp>0 && tmp&1){
                        tmp>>=1;
                        make_even[i]++;
                    }
                } else {
                    while (tmp>0 && !(tmp&1)){
                        tmp>>=1;
                        make_odd[i]++;
                    }
                }
            }
            res=INT_MAX;
            for (int i=0; i<n; i++){
                if (a[i]&1){
                    res=min(res,make_even[i]);
                } else {
                    res=min(res,make_odd[i]);
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
