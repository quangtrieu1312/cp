#include <bits/stdc++.h>

using namespace std;
int T, N, K;
vector<int> A, B, C;
string res;
bool possible;
vector<int> z_function(vector<int> s) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        possible=false;
        cin>>N>>K;
        A.resize(N);
        B.resize(N);
        for (int i=0; i<N; i++){
            cin>>A[i];
        }
        for (int i=0; i<N; i++){
            cin>>B[i];
        }
        C.resize(0);
        for (int i=0; i<N; i++){
            C.push_back(A[i]);
        }
        C.push_back(-1);
        for (int i=0; i<N; i++){
            C.push_back(B[i]);
        }
        for (int i=0; i<N; i++){
            C.push_back(B[i]);
        }
        vector<int> zf = z_function(C);
        for (int i=N+1; i<zf.size(); i++){
            if (zf[i]==N){
                int diff=i-(N+1);
                if (diff==0 && K!=1){
                    possible=true;
                    break;
                } else if (diff!=0 && K!=0){
                    possible=true;
                    break;
                }
            }
        }

        res=possible?"YES":"NO";
        cout<<"Case #"<<casenum<<": "<<res<<endl;
    }
    return 0;
}
