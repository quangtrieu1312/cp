#include <bits/stdc++.h>

using namespace std;
int T, N, A, B;
vector<int> res;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>T;
    for (int testCase=1; testCase<=T; testCase++) {
        cin>>N>>A>>B;
        res.resize(0);
        for (int i=0; i<2*N-1; i++) {
            res.push_back(1);
        }
        res.push_back(B);
        cout<<"Case #"<<testCase<<": ";
        for (int i=0; i<res.size(); i++) {
            cout<<res[i];
            if (i<res.size()-1) {
                cout<<" ";
            } else {
                cout<<endl;
            }
        }
    }
}
