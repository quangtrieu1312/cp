#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n, k, mina, maxa;
vector<int> a;
ll sum;
string res;

int main() {
    cin>>t;
    while (t--) {
        cin>>n>>k;
        a.resize(n);
        mina=INT_MAX;
        maxa=0;
        sum=0;
        int cntmax=0;
        for (int i=0; i<n; i++) {
            cin>>a[i];
            sum+=a[i];
            mina=min(mina,a[i]);
            maxa=max(maxa,a[i]);
        }
        for (int i=0; i<n; i++) {
            if (a[i]==maxa) {
                cntmax++;
            }
        }
        if (maxa-mina>k+1 || (maxa-mina==k+1 && cntmax>1)) {
            res="Jerry";
        } else if (sum&1) {
            res="Tom";
        } else {
            res="Jerry";
        }
        
        cout<<res<<endl;
    }
    return 0;
}
