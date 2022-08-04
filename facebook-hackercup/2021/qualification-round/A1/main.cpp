#include <bits/stdc++.h>
#define oo 5003
using namespace std;
int t, k;
string s;
vector<int> cnt, grp;
int main()
{
    freopen("output.txt","w",stdout);
    cin>>t;
    for (int cassenum=0; cassenum<t; cassenum++){
        int res=oo;

        cin>>s;

        cnt.resize(0);
        grp.resize(0);
        cnt.resize(26,0);
        grp.resize(26,0);
        for (char c='A'; c<='Z'; c++){
            if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                grp[c-'A']=0;
            } else {
                grp[c-'A']=1;
            }
        }
        for (int i=0; i<s.length(); i++){
            cnt[s[i]-'A']++;
        }

        for (char ci='A'; ci<='Z'; ci++){
            int tmp=0;
            for (char cj='A'; cj<='Z'; cj++){
                if (ci==cj) continue;
                int destgrp=grp[ci-'A'];
                int srcgrp=grp[cj-'A'];
                if (destgrp==srcgrp){
                    tmp+=2*cnt[cj-'A'];
                } else {
                    tmp+=cnt[cj-'A'];
                }
            }
            res=min(res,tmp);
        }

        cout<<"Case #"<<cassenum+1<<": "<<res<<endl;
    }
    return 0;
}
