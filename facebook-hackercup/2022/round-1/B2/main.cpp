#include <bits/stdc++.h>
#define MODULO 1000000007
using namespace std;
typedef long long ll;
int T, N, Q;
vector<int> A, B, X, Y;
ll res;
struct myrange{
    ll last_val;
    ll last_cnt;
    ll sum_asquare;
    ll sum_a;
};

vector<myrange> pre_ra, pre_rb, post_ra, post_rb;
ll solveX(int x){
    ll ans=0;
    return ans;
}

ll solveY(int y){
    ll ans=0;
    return ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        cin>>N;
        A.resize(N);
        B.resize(N);
        for (int i=0; i<N; i++){
            cin>>A[i]>>B[i];
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        cin>>Q;
        X.resize(Q);
        Y.resize(Q);
        for (int i=0; i<Q; i++){
            cin>>X[i]>>Y[i];
        }
        sort(X.begin(),X.end());
        sort(Y.begin(),X.end());
        res=0;

        int top_pre_ra=0;
        pre_ra.resize(1);
        pre_ra[0].last_val=A[0];
        ll og_sum_a=0;
        ll og_sum_asquare=0;
        for (int i=1; i<N; i++){

            if (A[i]==pre_ra[top_pre_ra]){
                pre_ra[top_pre_ra].last_cnt++;
                pre_ra[top_pre_ra].sum_a=(pre_ra[top_pre_ra].sum_a+og_sum_a)%MODULO;
                pre_ra[top_pre_ra].sum_asquare=(pre_ra[top_pre_ra].sum_asquare+og_sum_asquare)%MODULO;
            } else {
                myrange tmp;
                ll b = ((A[i]-pre_ra[top_pre_ra])*i)%MODULO;
                og_sum_a += b;
                og_sum_a %= MODULO;
                ll bsquare = ( b*b ) % MODULO;
                ll twoba = 2*b*pre_ra[top_pre_ra].sum_a;
                og_sum_asquare = pre_ra[top_pre_ra].sum_asquare+twoba+bsquare;
                og_sum_asquare %= MODULO;

                tmp.last_val=A[i];
                tmp.last_cnt=1;
                tmp.sum_a=og_sum_a;
                tmp.sum_asquare=og_sum_asquare;

                pre_ra.push_back(tmp);
                top_pre_ra++;
            }
        }

        int top_pre_rb=0;
        pre_rb.resize(1);
        pre_rb[0].last_val=B[0];
        ll og_sum_a=0;
        ll og_sum_asquare=0;
        for (int i=1; i<N; i++){

            if (B[i]==pre_rb[top_pre_rb]){
                pre_rb[top_pre_rb].last_cnt++;
                pre_rb[top_pre_rb].sum_a=(pre_rb[top_pre_rb].sum_a+og_sum_a)%MODULO;
                pre_rb[top_pre_rb].sum_asquare=(pre_rb[top_pre_rb].sum_asquare+og_sum_asquare)%MODULO;
            } else {
                myrange tmp;
                ll b = ((B[i]-pre_rb[top_pre_rb])*i)%MODULO;
                og_sum_a += b;
                og_sum_a %= MODULO;
                ll bsquare = ( b*b ) % MODULO;
                ll twoba = 2*b*pre_rb[top_pre_rb].sum_a;
                og_sum_asquare = pre_rb[top_pre_rb].sum_asquare+twoba+bsquare;
                og_sum_asquare %= MODULO;

                tmp.last_val=A[i];
                tmp.last_cnt=1;
                tmp.sum_a=og_sum_a;
                tmp.sum_asquare=og_sum_asquare;

                pre_rb.push_back(tmp);
                top_pre_ra++;
            }
        }

        reverse(A.begin(), A.end());
        int top_post_ra=0;
        post_ra.resize(1);
        post_ra[0].last_val=A[0];
        ll og_sum_a=0;
        ll og_sum_asquare=0;
        for (int i=1; i<N; i++){

            if (A[i]==post_ra[top_post_ra]){
                post_ra[top_post_ra].last_cnt++;
                post_ra[top_post_ra].sum_a=(post_ra[top_post_ra].sum_a+og_sum_a)%MODULO;
                post_ra[top_post_ra].sum_asquare=(post_ra[top_post_ra].sum_asquare+og_sum_asquare)%MODULO;
            } else {
                myrange tmp;
                ll b = ((A[i]-post_ra[top_post_ra])*i)%MODULO;
                og_sum_a += b;
                og_sum_a %= MODULO;
                ll bsquare = ( b*b ) % MODULO;
                ll twoba = 2*b*post_ra[top_post_ra].sum_a;
                og_sum_asquare = post_ra[top_post_ra].sum_asquare+twoba+bsquare;
                og_sum_asquare %= MODULO;

                tmp.last_val=A[i];
                tmp.last_cnt=1;
                tmp.sum_a=og_sum_a;
                tmp.sum_asquare=og_sum_asquare;

                post_ra.push_back(tmp);
                top_post_ra++;
            }
        }

        reverse(B.begin(), B.end());
        int top_post_rb=0;
        post_rb.resize(1);
        post_rb[0].last_val=B[0];
        ll og_sum_a=0;
        ll og_sum_asquare=0;
        for (int i=1; i<N; i++){

            if (B[i]==post_rb[top_post_rb]){
                post_rb[top_post_rb].last_cnt++;
                post_rb[top_post_rb].sum_a=(post_rb[top_post_rb].sum_a+og_sum_a)%MODULO;
                post_rb[top_post_rb].sum_asquare=(post_rb[top_post_rb].sum_asquare+og_sum_asquare)%MODULO;
            } else {
                myrange tmp;
                ll b = ((B[i]-post_rb[top_post_rb])*i)%MODULO;
                og_sum_a += b;
                og_sum_a %= MODULO;
                ll bsquare = ( b*b ) % MODULO;
                ll twoba = 2*b*post_rb[top_post_rb].sum_a;
                og_sum_asquare = post_rb[top_post_rb].sum_asquare+twoba+bsquare;
                og_sum_asquare %= MODULO;

                tmp.last_val=A[i];
                tmp.last_cnt=1;
                tmp.sum_a=og_sum_a;
                tmp.sum_asquare=og_sum_asquare;

                post_rb.push_back(tmp);
                top_post_ra++;
            }
        }
        sort(pre_ra.begin(), pre_ra.end());
        sort(post_ra.begin(), post_ra.end());
        sort(pre_rb.begin(), pre_rb.end());
        sort(post_rb.begin(), post_rb.end());

        for (int i=0; i<Q; i++){
            res+=solveX(X[i]);
            res%=MODULO;
            res+=solveY(Y[i]);
            res%=MODULO;
        }
        cout<<"Case #"<<casenum<<": "<<res<<endl;
    }
    return 0;
}
