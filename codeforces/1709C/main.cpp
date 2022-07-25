#include <bits/stdc++.h>

using namespace std;
int t;
string s;
int main()
{
    cin>>t;
    while (t--){
        bool res=true;
        cin>>s;
        vector<int> open, close;
        int cntopen=0, cntclose=0;
        for (int i=0; i<s.length(); i++){
            cntopen+=(s[i]=='(');
            cntclose+=(s[i]==')');

        }
        for (int i=0; i<s.length(); i++){
            if (s[i]=='?'){
                if (cntopen<s.length()/2){
                    open.push_back(i);
                    s[i]='(';
                    cntopen++;
                } else {
                    close.push_back(i);
                    s[i]=')';
                    cntclose++;
                }
            }
        }

        int sum=0;
        if (open.size()>0 && close.size()>0){
            bool isValid=true;
            for (int i=0; i<s.length(); i++){
                if (i!=open.back() && i!=close.front()){
                    if (s[i]=='('){
                        sum++;
                    } else {
                        sum--;
                    }
                } else {
                    if (s[i]=='('){
                        sum--;
                    } else {
                        sum++;
                    }
                }
                if (sum<0){
                    isValid=false;
                }
            }
            if (isValid) res=false;
        }

        if (res){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
