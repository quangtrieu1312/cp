#include <bits/stdc++.h>

using namespace std;
int t, n, m;
vector< vector<int> > p;
int main()
{
    cin>>t;
    while (t--){
        int res = 0;

        cin>>m>>n;
        p.resize(0);
        p.resize(m,vector<int>(n,0));

        vector<int> maxF;
        maxF.resize(n,0);

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                cin>>p[i][j];
                maxF[j] = max(maxF[j], p[i][j]);
            }
        }

        //cout<<"-----------\n";
        //for (int i=0; i<n; i++){
        //    cout<<"maxF["<<i<<"]="<<maxF[i]<<"\n";
        //}

        for (int i=0; i<m; i++){
            int largest = 0, second_largest = -1;
            for (int j=1; j<n; j++){
                if (p[i][j]>p[i][largest]){
                    second_largest = largest;
                    largest = j;
                } else if (second_largest == -1 || p[i][j]>p[i][second_largest]){
                    second_largest = j;
                }
            }
            int tmp = p[i][second_largest];
            //cout<<"largest="<<largest<<", second_largest="<<second_largest<<"\n";
            //cout<<p[i][largest]<<" "<<p[i][second_largest]<<"\n";
            for (int j=0; j<maxF.size(); j++){
                if (j==largest || j==second_largest){
                    continue;
                }
                tmp = min(tmp,maxF[j]);
            }
            //cout<<"tmp="<<tmp<<"\n";
            res = max(res,tmp);
        }

        cout<<res<<"\n";
    }
    return 0;
}
