#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string inp_file, out_file;
int T;
string A, B;
ll M;
vector<string> v;
unordered_map<string,bool> m;

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
void init(string x, char left, char right) {
    if (left<='0' || right<='0' || x.length() >= 17){
        return;
    }
    string tmp=string(1,left)+x+string(1,right);
    v.push_back(tmp);

    string t=string(1,left-1)+x+string(1,right-1);
    if (m.find(t)==m.end()) {
        m[t]=true;
        init(x,left-1,right-1);
    }
    t=string(1,left-1)+x+string(1,right);
    if (m.find(t)==m.end()) { 
        m[t]=true;
        init(x,left-1,right);
    }
    t=string(1,left)+x+string(1,right-1);
    if (m.find(t)==m.end()) {
        m[t]=true;
        init(x,left,right-1);
    }
    t=string(1,left)+tmp+string(1,right);
    if (m.find(t)==m.end()) {
        m[t]=true;
        init(tmp,left,right);
    }
    t=string(1,left-1)+tmp+string(1,right-1);
    if (m.find(t)==m.end()) {
        m[t]=true;
        init(tmp,left-1,right-1);
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
    
    v.resize(0);
    m.clear();
    for (int c='9'; c>'0'; c--){
        m[string(1,c)]=true;
        v.push_back(string(1,c));
        for (char i=c-1; i>'0'; i--){
            for (char j=c-1; j>'0'; j--){
                string t=string(1,i)+string(1,c)+string(1,j);
                if (m.find(t)==m.end()){
                    m[t]=true;
                    init(string(1,c),i,j);
                }
            }
        }
    }
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
