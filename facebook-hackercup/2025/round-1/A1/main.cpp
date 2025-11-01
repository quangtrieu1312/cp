#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<int> A;
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    cin>>T;
    for (int testCase=1; testCase<=T; testCase++) {
        cin>>N;
        A.resize(N+1);
        int ans=0;
        for (int i=1; i<=N; i++) {
            cin>>A[i];
            if (i>1) {
                ans=max(ans, abs(A[i]-A[i-1]));
            }
        }
        cout<<"Case #"<<testCase<<": "<<ans<<endl;
    }
    return 0;
}
