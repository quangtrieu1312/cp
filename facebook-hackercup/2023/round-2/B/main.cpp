#include <bits/stdc++.h>
#define MODULO 1000000007LL
#define PRIME 5LL

using namespace std;
typedef long long ll;
int T, N;
vector<ll> A, B, diff;
vector<int> cntPosDiff;
int res;
vector<ll> myHash, reverseMyHash;
vector<ll> pow_p, inverse_pow_p;

ll calcPow(ll a, ll b){
    if (b==0){
        return 1;
    }
    if (a==0){
        return 0;
    }
    if (b==1){
        return a%MODULO;
    }
    ll tmp=calcPow(a,b/2);
    ll tmp2=(tmp*tmp)%MODULO;
    if (b&1){
        return (tmp2*a)%MODULO;
    } else {
        return tmp2;
    }
}

ll divideInMod(ll a, ll b){
    // a divides b in mode MODULO
    ll reverseMod = calcPow(b,MODULO-2);
    return (a*reverseMod)%MODULO;
}

ll hashRange(int l, int r){
    if (l==0){
        return myHash[r];
    } else {
        return (((myHash[r]-myHash[l-1]+MODULO)%MODULO)*inverse_pow_p[l])%MODULO;
    }
}

ll reverseHashRange(int l, int r){
    if (r==4*N-1){
        return reverseMyHash[l];
    } else {
        return (((reverseMyHash[l]-reverseMyHash[r+1]+MODULO)%MODULO)*inverse_pow_p[4*N-1-r])%MODULO;
    }
}

int cntPosDiffRange(int l, int r){
    if (l==0){
        return cntPosDiff[r];
    } else {
        return cntPosDiff[r]-cntPosDiff[l-1];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("meta_game_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int testCase=1; testCase<=T; testCase++){
        cin>>N;
        A.resize(0);
        A.resize(4*N);
        B.resize(0);
        B.resize(4*N);

        myHash.resize(0);
        myHash.resize(4*N);
        reverseMyHash.resize(0);
        reverseMyHash.resize(4*N);
        pow_p.resize(0);
        pow_p.resize(4*N+1);
        pow_p[0]=1;

        inverse_pow_p.resize(0);
        inverse_pow_p.resize(4*N+1);

        for (int i=1; i<pow_p.size(); i++){
            pow_p[i]=(pow_p[i-1]*PRIME)%MODULO;
        }

        inverse_pow_p[0]=1;
        inverse_pow_p[1]=calcPow(PRIME,MODULO-2);
        for (int i=2; i<inverse_pow_p.size(); i++){
            inverse_pow_p[i]=(inverse_pow_p[i-1]*inverse_pow_p[1])%MODULO;
        }

        diff.resize(0);
        diff.resize(4*N);
        cntPosDiff.resize(0);
        cntPosDiff.resize(4*N);
        for (int i=0; i<N; i++){
            cin>>A[i];
            myHash[i]=(pow_p[i]*A[i])%MODULO;
        }
        for (int i=0; i<N; i++){
            cin>>B[i];
            reverseMyHash[i]=(pow_p[4*N-1-i]*B[i])%MODULO;
            diff[i]=A[i]-B[i];
        }
        for (int i=N; i<2*N; i++){
            A[i]=B[i-N];
            B[i]=A[i-N];

            myHash[i]=(pow_p[i]*A[i])%MODULO;
            reverseMyHash[i]=(pow_p[4*N-1-i]*B[i])%MODULO;

            diff[i]=A[i]-B[i];
        }
        for (int i=2*N; i<4*N; i++){
            A[i]=A[i-2*N];
            B[i]=B[i-2*N];

            myHash[i]=(pow_p[i]*A[i])%MODULO;
            reverseMyHash[i]=(pow_p[4*N-1-i]*B[i])%MODULO;

            diff[i]=A[i]-B[i];
        }

        cntPosDiff[0]=(diff[0]>0);
        for (int i=1; i<4*N; i++){
            myHash[i]=(myHash[i]+myHash[i-1])%MODULO;
            cntPosDiff[i]=cntPosDiff[i-1]+(diff[i]>0);
        }
        for (int i=4*N-2; i>=0; i--){
            reverseMyHash[i]=(reverseMyHash[i]+reverseMyHash[i+1])%MODULO;
        }

        int left=0;
        int right;
        int mid;
        ll forwardRange, reverseRange;
        int numOfPosDiffLeft, numOfPosDiffRight;
        res=-1;
        while (left<2*N){
            right=left+N-1;
            forwardRange=hashRange(left,right);
            reverseRange=reverseHashRange(left,right);
            if (forwardRange!=reverseRange){
                left++;
                continue;
            }
            mid=(left+right)/2;
            if (N&1){
                numOfPosDiffLeft=cntPosDiffRange(left,mid-1);
                numOfPosDiffRight=cntPosDiffRange(mid+1,right);
                if (numOfPosDiffLeft==0 && numOfPosDiffRight==N/2){
                    res=left;
                    break;
                }
            } else {
                numOfPosDiffLeft=cntPosDiffRange(left,mid);
                numOfPosDiffRight=cntPosDiffRange(mid+1,right);
                if (numOfPosDiffLeft==0 && numOfPosDiffRight==N/2){
                    res=left;
                    break;
                }
            }
            left++;
        }

        cout<<"Case #"<<testCase<<": "<<res<<endl;
    }
    return 0;
}
