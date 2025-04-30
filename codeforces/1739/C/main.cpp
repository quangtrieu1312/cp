#include <bits/stdc++.h>
#define MODULO 998244353
using namespace std;
typedef long long ll;
int t, n;
vector<ll> alex_win, boris_win, draw;
vector<ll> total_combination;
vector< vector<ll> > C;
void init(){
    C.resize(0);
    C.resize(61,vector<ll>(61,0));

    for (int i=1; i<=60; i++){
        C[0][i]=1;
        C[i][i]=1;
    }
    for (int j=2; j<=60; j++){
        for (int i=1; i<j; i++){
            C[i][j]=(C[i-1][j-1]+C[i][j-1])%MODULO;
        }
    }

    total_combination.resize(0);
    total_combination.resize(61);
    for (int i=2; i<=60; i+=2){
        total_combination[i]=C[i/2][i];
    }

    alex_win.resize(0);
    draw.resize(0);
    boris_win.resize(0);

    alex_win.resize(61);
    draw.resize(61);
    boris_win.resize(61);
    for (int i=2; i<=60; i+=2){
        alex_win[i]=(C[i/2-1][i-1]+boris_win[i-2])%MODULO;
        draw[i]=1;
        boris_win[i]=(total_combination[i]+MODULO-alex_win[i]-draw[i])%MODULO;
    }

}
int main()
{
    init();
    cin>>t;
    while (t--){
        cin>>n;
        cout<<alex_win[n]<<" "<<boris_win[n]<<" "<<draw[n]<<endl;
    }
    return 0;
}
