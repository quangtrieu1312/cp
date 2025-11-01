#include <bits/stdc++.h>

using namespace std;

int t, n, k, cnt_one, cnt_zero;
string s;

int main() {
    cin>>t;
    while (t--) {
        cin>>n>>k;
        cin>>s;
        cnt_one=0;
        cnt_zero=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='0') {
                cnt_zero++;
            } else {
                cnt_one++;
            }
        }
        int minres=abs(cnt_one-cnt_zero)/2;
        int maxres=cnt_zero/2 + cnt_one/2;
        if (minres<=k && k<=maxres && (k&1)==(minres&1)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
