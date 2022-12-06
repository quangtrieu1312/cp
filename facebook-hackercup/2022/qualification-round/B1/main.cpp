#include <bits/stdc++.h>

using namespace std;
int T, R, C;
vector<string> matrix;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>T;
    bool res;
    for (int casenum=1; casenum<=T; casenum++){
        cin>>R>>C;
        matrix.resize(R);
        for (int i=0; i<R; i++){
            cin>>matrix[i];
        }
        res=true;

        if (R==1 || C==1){
            for (int i=0; i<R; i++){
                for (int j=0; j<C; j++){
                    if (matrix[i][j]=='^'){
                        res=false;
                    }
                }
            }
        } else {
            for (int i=0; i<R; i++){
                for (int j=0; j<C; j++){
                    matrix[i][j]='^';
                }
            }
        }

        cout<<"Case #"<<casenum<<": ";
        if (res){
            cout<<"Possible"<<endl;
            for (int i=0; i<R; i++){
                cout<<matrix[i]<<endl;
            }
        } else {
            cout<<"Impossible"<<endl;
        }
    }
    return 0;
}
