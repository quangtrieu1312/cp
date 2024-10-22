#include <bits/stdc++.h>
#define MODULO 998244353

using namespace std;

typedef long long ll;

string inp_file, out_file;
int T;
ll G, W, L, res;

int main() {
    ios_base::sync_with_stdio(false);
    ifstream metadata("metadata.txt");
    metadata>>inp_file>>out_file;
    freopen(inp_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);

    cin>>T;
    for (int caseNum=1; caseNum<=T; caseNum++){
        cin >> W >> G >> L;
        ll diff=(W - G) % MODULO;
        res = diff * ((1 + 2 * L) % MODULO);
	res %= MODULO;
        cout<<"Case #"<<caseNum<<": "<<res<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
