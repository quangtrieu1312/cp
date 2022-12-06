#include <bits/stdc++.h>
#define red 0
#define blue 1
using namespace std;
int t, n, m;
vector<int> u, v, adj, head, pos, d, id;
vector<int> res;
vector<bool> visited;
void dfs(int x){
    visited[x]=true;
    for (int i=head[x]; i<head[x+1]; i++){
        if (!visited[adj[i]]){
            dfs(adj[i]);
            res[id[i]]=blue;
        }
    }
}
int cntNodes(vector<int> edge_ind){
    set<int> s;
    for (int i=0; i<edge_ind.size(); i++){
        s.insert(u[edge_ind[i]]);
        s.insert(v[edge_ind[i]]);
    }
    return s.size();
}
int main()
{
    cin>>t;
    while (t--){
        cin>>n>>m;
        u.resize(0);
        v.resize(0);
        adj.resize(0);
        head.resize(0);
        pos.resize(0);
        d.resize(0);

        u.resize(m);
        v.resize(m);
        adj.resize(2*m,0);
        head.resize(n+2,0);
        pos.resize(n+2,0);
        d.resize(n+1,0);
        id.resize(2*m,0);
        for (int i=0; i<m; i++){
            cin>>u[i]>>v[i];
            d[u[i]]++;
            d[v[i]]++;
        }

        for (int i=1; i<=n+1; i++){
            head[i]=head[i-1]+d[i-1];
            pos[i]=head[i];
        }

        for (int i=0; i<m; i++){
            id[pos[u[i]]]=i;
            id[pos[v[i]]]=i;
            adj[pos[u[i]]++]=v[i];
            adj[pos[v[i]]++]=u[i];
        }

        res.resize(0);
        res.resize(m,red);
        visited.resize(0);
        visited.resize(n+1,false);
        dfs(1);
        vector<int> reds;
        for (int i=0; i<m; i++){
            if (res[i]==red){
                reds.push_back(i);
            }
        }

        if (false && cntNodes(reds)==3 && reds.size()==3){
            // there is a loop
            bool ok=false;
            for (int i=0; i<reds.size() && !ok; i++){
                int ur = u[reds[i]];
                int vr = v[reds[i]];
                //cout<<"DEBUG res="<<res<<endl;
                for (int j=head[ur]; j<head[ur+1] && !ok; j++){
                    if (res[id[j]]==blue){
                        ok=true;
                        res[id[j]]=red;
                        res[reds[i]]=blue;
                    }
                }
                //cout<<"DEBUG res="<<res<<endl;
                for (int j=head[vr]; j<head[vr+1] && !ok; j++){
                    if (res[id[j]]==blue){
                        ok=true;
                        res[id[j]]=red;
                        res[reds[i]]=blue;
                    }
                }
                //cout<<"DEBUG res="<<res<<endl;
            }
        }


        for (int i=0; i<m; i++){
            cout<<res[i];
        }
        cout<<endl;
    }
    return 0;
}
/*
1
5 7
1 2
2 3
3 4
4 5
5 1
1 3
3 5
*/
