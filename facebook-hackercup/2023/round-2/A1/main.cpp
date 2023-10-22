#include <bits/stdc++.h>

using namespace std;
int T, R, C;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
vector< vector<int> > A;
bool res;
int cnt[203];

void dfs(int r, int c, int mark){
    A[r][c]=mark;
    int new_r, new_c;
    for (int i=0; i<4; i++){
        new_r=r+dx[i];
        new_c=c+dy[i];
        if (new_r<0 || new_r>=R || new_c<0 || new_c>=C){
            continue;
        }
        if (A[new_r][new_c]==0){
            //is white and not marked
            dfs(new_r,new_c,mark);
        }
    }
}
int main()
{
    freopen("ready_go_part_1_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int testCase=1; testCase<=T; testCase++){
        cin>>R>>C;
        A.resize(0);
        A.resize(R,vector<int>(C));
        char tmp;
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                cin>>tmp;
                if (tmp=='.'){
                    A[i][j]=-2;
                } else if (tmp=='B'){
                    A[i][j]=-1;
                } else {
                    A[i][j]=0;
                }
            }
        }
        memset(cnt,0,sizeof(cnt));
        res=false;
        int mark=1;
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                if (A[i][j]==0){
                    dfs(i,j,mark);
                    mark++;
                }
            }
        }

        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                if (A[i][j]==-2){
                    int adj_x;
                    int adj_y;
                    set<int> s;
                    for (int k=0; k<4; k++){
                        adj_x=i+dx[k];
                        adj_y=j+dy[k];
                        if (adj_x<0 || adj_x>=R || adj_y<0 || adj_y>=C){
                            continue;
                        }
                        if (A[adj_x][adj_y]>0){
                            s.insert(A[adj_x][adj_y]);
                        }
                    }
                    for (auto ele: s){
                        cnt[ele]++;
                    }
                }
            }
        }



        for (int i=0; i<203; i++){
            if (cnt[i]==1){
                res=true;
            }
        }
        if (res){
            cout<<"Case #"<<testCase<<": YES"<<endl;
        } else {
            cout<<"Case #"<<testCase<<": NO"<<endl;
        }

    }
    return 0;
}
