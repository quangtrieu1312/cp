#include <bits/stdc++.h>
using namespace std;
int T, N;
vector<long long> X;
double res;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int caseNum=1; caseNum<=T; caseNum++){
        cin>>N;
        X.resize(0);
        X.resize(N);
        for (int i=0; i<N; i++){
            cin>>X[i];
        }
        sort(X.begin(),X.end());
        res=0.0L;
        double dist=0.0L;
        //first and last group size = 2
        dist=1.0L*(X[N-1]+X[N-2])/2-1.0L*(X[1]+X[0])/2;
        res=dist;
        if (N>=5){
            //first group size = 2 => last group size = 3
            dist=1.0L*(X[N-1]+X[N-3])/2-1.0L*(X[1]+X[0])/2;
            res=max(res,dist);
            //first group size = 3 => last group size = 2
            dist=1.0L*(X[N-1]+X[N-2])/2-1.0L*(X[2]+X[0])/2;
            res=max(res,dist);
        }
        if (N>=6){
            //first and last group size = 3
            dist=1.0L*(X[N-1]+X[N-3])/2-1.0L*(X[2]+X[0])/2;
            res=max(res,dist);
        }
        printf("Case #%d: %.7f\n",caseNum,res);
    }
    return 0;
}
