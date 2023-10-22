#include <bits/stdc++.h>
#define MAX_GROUP 9000006
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii, int> piii;

int T, R, C;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
vector< vector<int> > A;
int res;
int cnt[MAX_GROUP], group_size[MAX_GROUP];
map<pii, int> cnt_choice;
vector<pii> group_choise;

void dfs(int r, int c, int mark){
    A[r][c]=mark;
    group_size[mark]++;
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
    freopen("ready_go_part_2_input.txt","r",stdin);
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
        memset(group_size,0,sizeof(group_size));
        cnt_choice.clear();
        res=0;
        int mark=1;
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                if (A[i][j]==0){
                    dfs(i,j,mark);
                    mark++;
                }
            }
        }
        group_choise.resize(mark+1,pii(-1,-1));
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
                        if (cnt[ele]==1){
                            group_choise[ele]=pii(i,j);
                        } else {
                            group_choise[ele]=pii(-1,-1);
                        }
                    }
                }
            }
        }

        for (int i=0; i<group_choise.size(); i++){
            int x;
            int y;
            x=group_choise[i].first;
            y=group_choise[i].second;
            if (x<0 || x>=R || y<0 || y>=C){
                continue;
            }
            if (cnt_choice.find(group_choise[i])!=cnt_choice.end()){
                int cur_cnt=cnt_choice[group_choise[i]];
                cnt_choice[group_choise[i]]=cur_cnt+group_size[i];
            } else {
                cnt_choice[group_choise[i]]=group_size[i];
            }
        }

        res=0;
        for (auto ele: cnt_choice){
            res=max(res, ele.second);
        }
        cout<<"Case #"<<testCase<<": "<<res<<endl;

    }
    return 0;
}
