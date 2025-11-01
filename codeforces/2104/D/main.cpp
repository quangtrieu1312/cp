#include <bits/stdc++.h>
#define PMAX 10000007
using namespace std;

int t, n;
vector<int> a, p, pr;
vector<long long> prs, postfix;

void init() {
    p.resize(PMAX, 0);
    pr.resize(0);
    prs.resize(0);

    for (int i=2; i<PMAX; i++) {
        if (p[i]==0) {
            pr.push_back(i);
            if (pr.size()==1) {
                prs.push_back(i);
            } else {
                prs.push_back(prs.back()+i);
            }
            for (long long j=1LL*i*i; j<1LL*PMAX; j+=i) {
                p[j]=i;
            }
        }
    }
}

int main() {
    init();
    cin>>t;
    while (t--) {
        cin>>n;
        a.resize(n);
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        postfix.resize(0);
        postfix.resize(n+1,0);
        for (int i=n-1; i>=0; i--) {
            postfix[i]=postfix[i+1]+a[i];
        }
        for (int i=0; i<n; i++) {
            if (postfix[i]>=prs[n-1-i]) {
                cout<<i<<endl;
                break;
            }
        }

    }
    return 0;
}
