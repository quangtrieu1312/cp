#include <bits/stdc++.h>

using namespace std;

int t, n, x, res, zeros;

int main() {
    cin>>t;
    while (t--) {
        cin>>n>>x;
        if (n==1 && !x) {
            cout<<-1<<endl;
            continue;
        }
        res=0;
        zeros=n;
        for (int i=0; i<32; i++) {
            if ((x>>i)&1) {
                zeros=max(0,zeros-1);
            }
        }
        if (zeros==0) {
            res=n;
        } else {
            if ((zeros&1)^(x&1)==0) {
                res+=zeros;
            } else {
                res+=zeros-1;
                res+=4;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
