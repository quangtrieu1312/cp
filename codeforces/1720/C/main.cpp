#include <bits/stdc++.h>

using namespace std;
int t, n, m;
vector< vector<bool> > matrix;
int main()
{
    cin>>t;
    int res;
    while (t--){
        res=0;
        cin>>n>>m;
        matrix.resize(n,vector<bool>(m,0));
        char c;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin>>c;
                matrix[i][j]=(c=='1');
                if (c=='1') res++;
            }
        }
        int least_1=4;
        for (int i=0; i<n-1; i++){
            for (int j=0; j<m-1; j++){
                int cnt_1=matrix[i][j]+matrix[i+1][j]+matrix[i][j+1]+matrix[i+1][j+1];
                least_1=min(least_1,cnt_1);
            }
        }
        if (least_1==3){
            res-=1;
        } else if (least_1==4){
            res-=2;
        }
        cout<<res<<endl;
    }
    return 0;
}
