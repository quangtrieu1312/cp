#include <bits/stdc++.h>

using namespace std;

int t, n, res, tmp;
int cnt[2];
string s;

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        cin>>s;
        cnt[0]=0;
        cnt[1]=0;
        cnt[s[0]-'0']++;
        for (int i=1; i<n; i++) {
            if (s[i]!=s[i-1]) {
                cnt[s[i]-'0']++;
            }
        }
        if (cnt[0]+cnt[1]==1) {
            res=n;
            if (s[0]=='1') {
                res++;
            }
        } else if (cnt[0]+cnt[1]==2) {
            res=n+1;
        } else if (cnt[0]+cnt[1]==3) {
            res=n+1;
        } else if (cnt[0]+cnt[1]>3) {
            res=n+cnt[0]+cnt[1]-1-2;
            if (s[0]=='1') {
                res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
