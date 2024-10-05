#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<int> A, B;
long double res;
int main() {
    freopen("subsonic_subway_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>T;
    for (int caseNum=1; caseNum<=T; caseNum++){
        cin>>N;
        A.resize(N+1,0);
        B.resize(N+1,0);
        for (int i=1; i<=N; i++){
            cin>>A[i]>>B[i];
        }

        res=1.0L/B[1];
        long double upper_bound=A[1]==0?1000000.0L:1.0L/A[1];
        for (int i=2; i<=N; i++){
            if (1.0L*i/B[i]>upper_bound) {
                res=-1;
                break;
            }
            res=max(res,1.0L*i/B[i]);
            if (A[i]!=0){
                upper_bound=min(upper_bound,1.0L*i/A[i]);
            }
        }
        cout<<"Case #"<<caseNum<<": "<<setprecision(6)<<fixed<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}