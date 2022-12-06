#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int T;
string S;
int Q;
vector<int> L, R;
int res;
vector< vector<int> > cnt;
vector<int> getCnt(int l, int r){
    vector<int> ans;
    ans.resize(26,0);
    for (int c='a'; c<='z'; c++){
        if (l!=0){
            ans[c-'a']=cnt[c-'a'][r]-cnt[c-'a'][l-1];
        } else {
            ans[c-'a']=cnt[c-'a'][r];
        }
    }
    return ans;
}
bool isAlmostBalance(int l, int r){
    vector<int> l_cnt, r_cnt;
    if ((r-l+1)&1){
        //len is odd
        //try removing left half
        //cout<<S.substr(l,(r-l+1))<<endl;
        int mid=(l+r)/2;
        l_cnt = getCnt(l,mid);
        r_cnt = getCnt(mid+1,r);
        int diff=0;
        for (char c='a'; c<='z'; c++){
            if (l_cnt[c-'a']<r_cnt[c-'a']){
                diff=0;
                break;
            }
            diff+=l_cnt[c-'a']-r_cnt[c-'a'];

        }
        if (diff==1){
            return true;
        }
        //try removing right half
        diff=0;
        l_cnt = getCnt(l,mid-1);
        r_cnt = getCnt(mid,r);
        for (char c='a'; c<='z'; c++){
            if (l_cnt[c-'a']>r_cnt[c-'a']){
                return false;
            }
            diff+=r_cnt[c-'a']-l_cnt[c-'a'];

        }
        return (diff==1);
    }
    return false;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        cin>>S;
        cin>>Q;
        L.resize(Q);
        R.resize(Q);
        for (int i=0; i<Q; i++){
            cin>>L[i];
            cin>>R[i];
        }
        cnt.resize(0);
        cnt.resize(26,vector<int>(S.length(),0));
        cnt[S[0]-'a'][0]++;
        for (int i=1; i<S.length(); i++){
            for (int c='a'; c<='z'; c++){
                cnt[c-'a'][i]=cnt[c-'a'][i-1];
            }
            cnt[S[i]-'a'][i]++;
        }
        res=0;
        for (int i=0; i<Q; i++){
            if (isAlmostBalance(L[i]-1,R[i]-1)){
                res++;
            }
        }
        cout<<"Case #"<<casenum<<": "<<res<<endl;
    }
    return 0;
}
