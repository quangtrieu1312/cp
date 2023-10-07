#include <bits/stdc++.h>
#define MODULO 998244353
using namespace std;
int t, n, cnt_1, cnt_0;
string s;
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        cin>>s;
        cnt_1=0;
        cnt_0=0;
        if (s[0]=='1'){
            cnt_1++;
        } else {
            cnt_0++;
        }
        for (int i=1; i<s.length(); i++){
            if (s[i]=='1'){
                cnt_1++;
            } else {
                cnt_0++;
            }
        }
    }
    return 0;
}
