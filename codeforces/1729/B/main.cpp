#include <bits/stdc++.h>

using namespace std;
int q, n;
string t, res;
set<string> valid;
bool isValid(string x){
    return valid.count(x)>0;
}
char decode(string x){
    if (!isValid(x)){
        return '?';
    }
    if (x.length()==3){
        x=x.substr(0,2);
    }
    int xi=stoi(x)-1;
    return (char) (xi+(int)'a');
}
string dfs(int x){
    if (x==n){
        return "";
    }
    vector<string> ans;
    int delta[2]={1,3};
    for (int i=0; i<2; i++){
        if (x+delta[i]-1<n && decode(t.substr(x,delta[i]))!='?'){
            ans.push_back(decode(t.substr(x,delta[i]))+dfs(x+delta[i]));
        }
    }

    for (int i=0; i<ans.size(); i++){
        if (ans[i][ans[i].length()-1]!='?'){
            return ans[i];
        }
    }
    return "?";
}
int main()
{
    for (int i='a'-'a'; i<='z'-'a'; i++){
        int v=i+1;
        if (v>=10){
            valid.insert(to_string(v*10));
        } else {
            valid.insert(to_string(v));
        }
    }
    cin>>q;
    while (q--){
        cin>>n;
        cin>>t;
        res=dfs(0);
        cout<<res<<endl;
    }
    return 0;
}
