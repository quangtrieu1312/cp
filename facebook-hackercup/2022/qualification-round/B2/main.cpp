#include <bits/stdc++.h>

using namespace std;
int T, R, C;
bool res;
vector< vector<bool> > visited;
vector<string> matrix, og;
bool upgood(int x, int y){
    return x>0 && matrix[x-1][y]=='^';
}
bool downgood(int x, int y){
    return x<R-1 && matrix[x+1][y]=='^';
}
bool leftgood(int x, int y){
    return y>0 && matrix[x][y-1]=='^';
}
bool rightgood(int x, int y){
    return y<C-1 && matrix[x][y+1]=='^';
}
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
int cntFriend(int i, int j){
    return upgood(i,j)+downgood(i,j)+leftgood(i,j)+rightgood(i,j);
}
void removeTree(int i, int j){
    visited[i][j]=true;
    matrix[i][j]='.';
    for (int k=0; k<4; k++){
        if (i+dx[k]<0 || i+dx[k]>=R || j+dy[k]<0 || j+dy[k]>=C){
            continue;
        }
        if (matrix[i+dx[k]][j+dy[k]]!='#' && !visited[i+dx[k]][j+dy[k]] && cntFriend(i+dx[k],j+dy[k])<2){
            removeTree(i+dx[k],j+dy[k]);
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        cin>>R>>C;
        matrix.resize(R);
        og.resize(R);
        for (int i=0; i<R; i++){
            cin>>matrix[i];
            og[i]=matrix[i];
        }
        visited.resize(0);
        visited.resize(R,vector<bool>(C,false));
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                if (matrix[i][j]!='#'){
                    matrix[i][j]='^';
                }
            }
        }
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                if (!visited[i][j] && matrix[i][j]=='^' && cntFriend(i,j)<2){
                    removeTree(i,j);
                }
            }
        }

        res=true;
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                if (og[i][j]=='^' && matrix[i][j]!='^'){
                    res=false;
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
