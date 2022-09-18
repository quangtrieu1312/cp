#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t, n, res;
vector<int> u, v, head, adj, pos, d;
vector<bool> visited;
string s;
stack<int> st;

void dfs(int x){
    visited[x]=true;
    for (int i=head[x]; i<head[x+1]; i++){
        if (!visited[adj[i]]){
            dfs(adj[i]);
        }
    }
}
int main()
{
    cin>>t;
    while (t--){
        cin>>n>>s;

        u.resize(0);
        v.resize(0);
        d.resize(0);
        head.resize(0);
        pos.resize(0);
        adj.resize(0);

        d.resize(2*n,0);
        head.resize(2*n+1,0);
        pos.resize(2*n+1,0);

        for (int i=0; i<2*n; i++){
            if (s[i]=='('){
                st.push(i);

                if (i>0 && s[i-1]==')'){
                    u.push_back(i);
                    v.push_back(i-1);
                }
            } else {
                u.push_back(i);
                v.push_back(st.top());
                st.pop();
            }
        }
        int m=u.size();
        adj.resize(2*m,0);

        for (int i=0; i<m; i++){
            d[u[i]]++;
            d[v[i]]++;
        }

        head[0]=0;
        pos[0]=0;
        for (int i=1; i<=2*n; i++){
            head[i]=head[i-1]+d[i-1];
            pos[i]=head[i];
        }

        for (int i=0; i<m; i++){
            adj[pos[u[i]]++]=v[i];
            adj[pos[v[i]]++]=u[i];
        }

        visited.resize(0);
        visited.resize(2*n,false);

        res=0;
        for (int i=0; i<2*n; i++){
            if (!visited[i]){
                res++;
                dfs(i);
            }
        }

        cout<<res<<endl;
    }
    return 0;
}
