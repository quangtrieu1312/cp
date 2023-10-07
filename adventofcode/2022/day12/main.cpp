#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
vector<string> matrix;
int res=0;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
vector< vector<bool> > visited;
int start_c, start_r, dest_c, dest_r;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string line;
    while (cin>>line){
        matrix.push_back(line);
    }
    int n=matrix.size();
    int m=matrix[0].length();
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (matrix[i][j]=='E'){
                start_r=i;
                start_c=j;
                matrix[i][j]='z';
            }
            if (matrix[i][j]=='S'){
                matrix[i][j]='a';
            }
        }
    }
    visited.resize(0);
    visited.resize(n,vector<bool>(m,false));

    queue<piii> q;
    q.push(piii(pii(start_r,start_c),0));
    visited[start_r][start_c]=true;
    while (!q.empty()){
        piii tmp=q.front();
        int cur_r=tmp.first.first;
        int cur_c=tmp.first.second;
        int cur_dep=tmp.second;
        if (matrix[cur_r][cur_c]=='a'){
            res=cur_dep;
            break;
        }
        for (int k=0; k<4; k++){
            int new_r=cur_r+dx[k];
            int new_c=cur_c+dy[k];
            if (0<=new_r && new_r<n && 0<=new_c && new_c<m){
                if (!visited[new_r][new_c] && matrix[new_r][new_c]+1>=matrix[cur_r][cur_c]){
                    visited[new_r][new_c]=true;
                    q.push(piii(pii(new_r,new_c),cur_dep+1));
                }
            }
        }
        q.pop();
    }
    cout<<res<<endl;
    return 0;
}
