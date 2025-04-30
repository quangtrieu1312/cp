#include <bits/stdc++.h>
#define Nmax 202
using namespace std;
int t, n, m;
int a[Nmax][Nmax];
int diag1[4*Nmax], diag2[4*Nmax];
//diag1 = r+1,c+1 -> r-c = const
//diag2 = r+c,c-1 -> r+c = const
int main()
{
    cin>>t;
    while (t--){
        int res=0;
        cin>>n>>m;
        memset(diag1,0,sizeof(diag1));
        memset(diag2,0,sizeof(diag2));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin>>a[i][j];
                diag1[i-j+Nmax]+=a[i][j];
                diag2[i+j]+=a[i][j];
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                res=max(res,diag1[i-j+Nmax]+diag2[i+j]-a[i][j]);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
