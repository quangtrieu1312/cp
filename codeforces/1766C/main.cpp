#include <bits/stdc++.h>

using namespace std;
int t, m, total_b, cnt_b;
string c[2];
bool res;
int dx[3]={-1,1,0};
int dy[3]={0,0,1};
vector< vector<bool> > visited;
void dfs(int x, int y){
    if (c[x][y]!='B'){
        return;
    }
    visited[x][y]=true;
    cnt_b++;

    for (int i=0; i<3; i++){
        int new_x=x+dx[i];
        int new_y=y+dy[i];
        if (0<=new_x && new_x<2 && 0<=new_y && new_y<m){
            if (c[new_x][new_y]=='B' && !visited[new_x][new_y]){
                dfs(new_x,new_y);
            }
        }
    }
    if (cnt_b==total_b){
        res=true;
    }
    cnt_b--;
}
int main()
{
    cin>>t;
    while (t--){
        cin>>m;
        cin>>c[0];
        cin>>c[1];

        total_b=0;
        for (int i=0; i<m; i++){
            if (c[0][i]=='B'){
                total_b++;
            }
            if (c[1][i]=='B'){
                total_b++;
            }
        }

        if (total_b==2*m || total_b==0){
            cout<<"YES"<<endl;
            continue;
        }

        int start_c=0;
        while (start_c<m && c[0][start_c]!='B' && c[1][start_c]!='B'){
            start_c++;
        }

        //start top left
        visited.resize(0);
        visited.resize(2,vector<bool>(m,false));

        cnt_b=0;
        res=false;
        dfs(0,start_c);
        if (res){
            cout<<"YES"<<endl;
            continue;
        }

        //start bottom left
        visited.resize(0);
        visited.resize(2,vector<bool>(m,false));

        cnt_b=0;
        res=false;
        dfs(1,start_c);

        if (res){
            cout<<"YES"<<endl;
            continue;
        }

        cout<<"NO"<<endl;
    }
    return 0;
}
