#include <bits/stdc++.h>

using namespace std;
int t;
int n, m;
vector<long long> a, l, r;
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        a.resize(n+1);
        for (int i=1; i<=n; i++){
            cin>>a[i];
        }
        l.resize(0);
        r.resize(0);
        m=0;

        //step 1: make a[1] and a[n] the same
        if (n!=1){
            l.push_back(1);
            r.push_back(n);
            m=1;
        }
        long long tmp=a[1];
        for (int i=2; i<n; i++){
            if ((a[i]+tmp)&1){
                //odd, copy left
                l.push_back(1);
                r.push_back(i);
            } else {
                //even, copy right
                l.push_back(i);
                r.push_back(n);
            }
            m++;
        }

        cout<<m<<endl;
        for (int i=0; i<m; i++){
            cout<<l[i]<<" "<<r[i]<<endl;
        }
    }
    return 0;
}
