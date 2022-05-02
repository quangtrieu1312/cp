#include <bits/stdc++.h>

using namespace std;
int q;
string s, t;
long long pow_2[51];

bool has_a(string x){
    for (int i=0; i<x.length(); i++){
        if (x[i]=='a'){
            return true;
        }
    }
    return false;
}

long long solve(string s, string t){
    if (has_a(t) && t.length()>1){
        return -1;
    }
    if (has_a(t) && t.length()==1){
        return 1;
    }
    return pow_2[s.length()];
}
void init(){
    pow_2[0]=1L;
    pow_2[1]=2L;
    for (int i=2; i<51; i++){
        pow_2[i] = pow_2[i-1]*2L;
    }
}
int main()
{
    init();
    cin>>q;
    while (q--){
        cin>>s>>t;
        long long res=solve(s,t);
        cout<<res<<endl;
    }
    return 0;
}
