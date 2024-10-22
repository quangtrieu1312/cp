#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string inp_file, out_file;
int T;
string A, B;
ll M;
vector<string> v;

int comp(string x, string y) {
    while (x.length()<y.length()){
        x="0"+x;
    }
    while (x.length()>y.length()){
        y="0"+y;
    }
    for (int i=0; i<x.length(); i++){
        if (x[i]<y[i]) {
            return -1;
        } else if (x[i]>y[i]) {
            return 1;
        }
    }
    return 0;
}
void init() {
    v.resize(0);
    for (char start='9'; start>'0'; start--) {
        string tmp=""+string(1,start);
        v.push_back(tmp);
        for (char end=start-1; end>'0'; end--) {
            string t=""+string(1,end);
            tmp=t+tmp+t;
            v.push_back(tmp);
        }
    }
}
ll convert(string x) {
    ll res=0;
    for (int i=x.length()-1; i>=0; i--){
        res=res*10+(x[i]-'0');    
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    ifstream metadata("metadata.txt");
    metadata>>inp_file>>out_file;
    freopen(inp_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);

    init();
    cin>>T;
    int res=0;
    for (int caseNum=1; caseNum<=T; caseNum++){
        cin>>A>>B>>M;
        res=0;
        for (int i=0; i<v.size(); i++){
            if (comp(A,v[i])<=0 && comp(v[i],B)<=0 && convert(v[i])%M==0){
                res++;
            }
        }
        cout<<"Case #"<<caseNum<<": "<<res<<endl;
    }

    metadata.close();
    fclose(stdin);
    fclose(stdout);
}
