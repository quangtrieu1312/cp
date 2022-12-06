#include <bits/stdc++.h>

using namespace std;
int N, T;
vector<string> C;
string getNext(string x){
    string ans=x;
    int r=1;
    for (int i=ans.size()-1; i>=0; i--){
        if (ans[i]=='.'){
            ans[i]='-';
            r=0;
            break;
        } else {
            ans[i]='.';
        }
    }
    return ans;
}
set<string> s;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        cin>>N;
        C.resize(N+1);
        cin>>C[1];
        s.clear();
        if (C[1].length()>10){
            while (C[1].length()<100){
                C[1]="."+C[1];
            }
            for (int i=0; i<=90; i++){
                s.insert(C[1].substr(i,10));
            }
            C[0]="..........";
            for (int i=2; i<=N; i++){
                while (s.find(C[0])!=s.end()){
                    C[0]=getNext(C[0]);
                }
                C[i]=C[0];
                C[0]=getNext(C[0]);
            }
        } else {
            C[0]="..........";
            for (int i=2; i<=N; i++){
                while (C[0].substr(10-C[1].length(),C[1].length()).compare(C[1])==0){
                    C[0]=getNext(C[0]);
                }
                C[i]=C[0];
                C[0]=getNext(C[0]);
            }
        }

        cout<<"Case #"<<casenum<<": "<<endl;
        for (int i=2; i<=N; i++){
            cout<<C[i]<<endl;
        }
    }
    return 0;
}
