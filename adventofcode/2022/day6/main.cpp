#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    vector<int> cnt;
    for (int i=13; i<s.length(); i++){
        cnt.resize(0);
        cnt.resize(26,0);
        for (int j=i; j>=i-13; j--){
            cnt[s[j]-'a']++;
        }
        bool ok=true;
        for (int j=0; j<26; j++){
            ok=ok && (cnt[j]<2);
        }
        if (ok) {
            cout<<i+1<<endl;
            break;
        }
    }
    return 0;
}
