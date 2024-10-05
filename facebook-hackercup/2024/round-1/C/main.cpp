#include <bits/stdc++.h>
#define MODULO 998244353

using namespace std;

typedef long long ll;

string inp_file, out_file;
int T;
ll G, W, L, res;



ll calc_mod_pow(ll x, ll pow){
    x = x % MODULO;
    if (pow == 0) {
        return 1;
    }
    if (pow == 1){
        return x;
    }
    ll tmp1 = calc_mod_pow(x, pow/2);
    ll tmp2 = (tmp1 * tmp1) % MODULO;
    if (pow & 1) {
        return (tmp2 * x) % MODULO;
    } else { 
        return tmp2;
    }
}

ll calc_mod_inverse(ll x){
    return calc_mod_pow(x, MODULO - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream metadata("metadata.txt");
    metadata>>inp_file>>out_file;
    freopen(inp_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);

    cin>>T;
    for (int caseNum=1; caseNum<=T; caseNum++){
        cin>>W>>G>>L;
        ll diff=W-G;
        ll tmp=2;
        if (L == 0){
            res = diff;
        } else {
            res = diff + ((L % MODULO) * calc_mod_pow(2, L)) % MODULO;
        }
        res %= MODULO;
        cout<<"Case #"<<caseNum<<": "<<res<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}