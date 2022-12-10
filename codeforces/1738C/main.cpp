#include <bits/stdc++.h>
#define alice 0
#define bob 1
using namespace std;
typedef long long ll;
int t, n;
vector<int> a;
int odd, even;
vector< vector< vector< vector<bool> > > >dp;
bool alice_win;
void init(){
    dp.resize(0);
    dp.resize(2, vector< vector< vector<bool> > >(2, vector< vector<bool> >(101,vector<bool>(101,false)));
    //dp[who turn][goal][odd][even] = alice win?
    for (int i=0; i<=100; i++){
        dp[alice][0][0][i]=true;
        dp[bob][0][0][i]=true;
        if (i!=0 && i%4==3 || i%4==0){
            dp[alice][0][i][0]=true;
        }
        if (i!=0 && (i+4-1)%4==3 || (i+4-1)%4==0){
            dp[bob][0][i][0]=true;
        }
    }
}
int main()
{
    init();
    cin>>t;
    while (t--){
        cin>>n;
        a.resize(n+1);
        odd=0;
        even=0;
        for (int i=1; i<=n; i++){
            cin>>a[i];
            if (a[i]&1){
                odd++;
            } else {
                even++;
            }
        }

        alice_win=dp[alice][0][odd][even];

        if (alice_win){
            cout<<"Alice"<<endl;
        } else {
            cout<<"Bob"<<endl;
        }
    }
    return 0;
}
