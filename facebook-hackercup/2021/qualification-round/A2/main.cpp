#include <bits/stdc++.h>
#define oo 1000006
using namespace std;
typedef pair<int, int> pii;
int t, k;
vector<int> A, B, d, head, pos, adj, cnt;
bool visited[26];
string s;
int bfs(int src, int dest){
    memset(visited,false,sizeof(visited));
    queue<pii> q;
    q.push(pii(src,0));
    visited[src]=true;
    while (!q.empty()){
        pii node=q.front();
        if (node.first == dest){
            return node.second;
        }
        for (int i=head[node.first]; i<head[node.first+1]; i++){
            if (!visited[adj[i]]){
                visited[adj[i]]=true;
                q.push(pii(adj[i],node.second+1));
            }
        }
        q.pop();
    }
    return -1;
}
int main()
{
    freopen("output.txt","w",stdout);
    cin>>t;
    for (int casenum=0; casenum<t; casenum++){
        int res=-1;
        cin>>s>>k;
        cnt.resize(0);
        cnt.resize(26,0);
        d.resize(0);
        d.resize(26,0);
        head.resize(0);
        head.resize(27,0);
        pos.resize(0);
        pos.resize(27,0);
        adj.resize(0);
        adj.resize(2*k);
        A.resize(k);
        B.resize(k);

        for (int i=0; i<k; i++){
            string tmp;
            cin>>tmp;
            A[i]=tmp[0]-'A';
            B[i]=tmp[1]-'A';
            d[A[i]]++;
        }
        for (int i=1; i<27; i++){
            head[i]=head[i-1]+d[i-1];
            pos[i]=head[i];
        }
        for (int i=0; i<k; i++){
            adj[pos[A[i]]++]=B[i];
        }
        for (int i=0; i<s.length(); i++){
            cnt[s[i]-'A']++;
        }
        for (int i=0; i<26; i++){
            int tmp=0, dist;
            for (int j=0; j<26; j++){
                if (cnt[j]==0) continue;
                dist=bfs(j,i);
                if (dist==-1){
                    tmp=-1;
                    break;
                }
                tmp+=dist*cnt[j];
            }
            if (tmp!=-1){
                res=(res==-1)?tmp:min(res,tmp);
            }
        }
        cout<<"Case #"<<casenum+1<<": "<<res<<endl;
    }
    return 0;
}
