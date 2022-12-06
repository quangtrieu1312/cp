#include <bits/stdc++.h>
#define MODULO 1000000007
using namespace std;
typedef long long ll;
int T, N, Q;
vector<int> A, B, X, Y;
vector<ll> cntx, cnty, cnta, cntb;
ll res;
int main()
{
    freopen("watering_well_chapter_1_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        cin>>N;
        A.resize(N);
        B.resize(N);
        cntx.resize(0);
        cnty.resize(0);
        cnta.resize(0);
        cntb.resize(0);
        cntx.resize(3001,0);
        cnty.resize(3001,0);
        cnta.resize(3001,0);
        cntb.resize(3001,0);
        for (int i=0; i<N; i++){
            cin>>A[i]>>B[i];
            cnta[A[i]]++;
            cntb[B[i]]++;
        }
        cin>>Q;
        X.resize(Q);
        Y.resize(Q);
        for (int i=0; i<Q; i++){
            cin>>X[i]>>Y[i];
            cntx[X[i]]++;
            cnty[Y[i]]++;
        }
        res=0;
        for (int i=0; i<=3000; i++){
            for (int j=0; j<=3000; j++){
                res+=cntx[i]*cnta[j]*abs(i-j)*abs(i-j);
                res%=MODULO;
            }
        }

        for (int i=0; i<=3000; i++){
            for (int j=0; j<=3000; j++){
                res+=cnty[i]*cntb[j]*abs(i-j)*abs(i-j);
                res%=MODULO;
            }
        }

        cout<<"Case #"<<casenum<<": "<<res<<endl;
    }
    return 0;
}
