#include <bits/stdc++.h>
#define oo 4000006
using namespace std;
typedef pair<int, int> pii;
int T, N, res;
vector<int> A, B, F, adj, head, pos, d, Z, D;
vector<bool> visited;
vector<int> rmq, tree;
map<int, int> F_map;
vector< vector<int> > F_pos_v;
int cur_depth;
bool buildTree(int node, int left, int right){
    if (left>right){
        return false;
    }
    if (left==right){
        tree[node]=rmq[left];
        return true;
    }
    bool hasLeft=buildTree(node*2,left,(left+right)/2);
    bool hasRight=buildTree(node*2+1,(left+right)/2+1,right);
    if (hasLeft && hasRight){
        tree[node]=min(tree[node*2],tree[node*2+1]);
    } else if (hasLeft){
        tree[node]=tree[node*2];
    } else {
        return false;
    }
    return true;
}
int queryTree(int node, int left, int right, int leftq, int rightq){
    if (left>right || rightq<left || right<leftq){
        return oo;
    }
    if (leftq<=left && right<=rightq){
        return tree[node];
    }
    return min(queryTree(node*2,left,(left+right)/2,leftq,rightq),
                queryTree(node*2+1,(left+right)/2+1,right,leftq,rightq));
}
void dfs(int start){
    visited[start]=true;
    rmq.push_back(cur_depth);
    if (F_pos_v[F[start]].size()<2){
        F_pos_v[F[start]].push_back(rmq.size()-1);
    } else {
        F_pos_v[F[start]][1]=rmq.size()-1;
    }
    cur_depth++;
    for (int i=head[start]; i<head[start+1]; i++){

        if (!visited[adj[i]]){
            cout<<start<<" "<<adj[i]<<endl;
            dfs(adj[i]);
            rmq.push_back(cur_depth-1);
            if (F_pos_v[F[start]].size()<2){
                F_pos_v[F[start]].push_back(rmq.size()-1);
            } else {
                F_pos_v[F[start]][1]=rmq.size()-1;
            }
        }
    };
    cur_depth--;
}
void dfs2(int start){
    visited[start]=true;
    cur_depth++;
    for (int i=head[start]; i<head[start+1]; i++){
        if (!visited[adj[i]]){
            dfs2(adj[i]);
            Z[start]=min(Z[start],Z[adj[i]]);
        }
    }
    cur_depth--;
    //cout<<"DFS2 at "<<start<<": D["<<F[start]<<"]="<<D[F[start]]<<", Z["<<start<<"]="<<Z[start]<<endl;
    if (cur_depth==Z[start] && start!=1){
        res++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        res=0;
        cin>>N;
        A.resize(N-1);
        B.resize(N-1);
        F.resize(N+1);
        d.resize(0);
        head.resize(0);
        pos.resize(0);
        adj.resize(0);
        visited.resize(0);
        d.resize(N+1,0);
        head.resize(N+2,0);
        pos.resize(N+2,0);
        adj.resize(2*(N-1));
        visited.resize(N+1,false);
        for (int i=0; i<N-1; i++){
            cin>>A[i]>>B[i];
            d[A[i]]++;
            d[B[i]]++;
        }
        F_map.clear();
        int c=0;
        for (int i=1; i<=N; i++){
            cin>>F[i];
            if (F_map.find(F[i])==F_map.end()){
                F_map[F[i]]=c++;
            }
        }
        for (int i=1; i<=N; i++){
            //cout<<"converting F["<<i<<"] from "<<F[i]<<" to "<<F_map[F[i]]<<endl;
            F[i]=F_map[F[i]];
        }
        for (int i=1; i<=N+1; i++){
            head[i]=head[i-1]+d[i-1];
            pos[i]=head[i];
        }
        for (int i=0; i<N-1; i++){
            adj[pos[A[i]]++]=B[i];
            adj[pos[B[i]]++]=A[i];
        }
        rmq.resize(0);
        F_pos_v.resize(0);
        F_pos_v.resize(c,vector<int>(0));
        cur_depth=0;
        dfs(1);
        tree.resize(0);
        tree.resize(4*rmq.size());
        buildTree(1,0,rmq.size()-1);

        D.resize(0);
        D.resize(c);
        //cout<<"rmq arr:"<<endl;
        //for (int i=0; i<rmq.size(); i++){
        //    cout<<rmq[i].first<<" "<<rmq[i].second<<endl;
        //}
        for (int i=0; i<c; i++){
            D[i]=queryTree(1,0,rmq.size()-1,F_pos_v[i].front(),F_pos_v[i].back());
            //cout<<"query from "<<F_pos_v[i].front()<<" to "<<F_pos_v[i].back()<<" = "<<D[i]<<endl;
        }
        Z.resize(0);
        Z.resize(N+1);
        for (int i=1; i<=N; i++){
            Z[i]=D[F[i]];
            //cout<<"Z["<<i<<"]="<<Z[i]<<endl;
        }
        visited.resize(0);
        visited.resize(N+1,false);
        cur_depth=0;
        dfs2(1);

        cout << "Case #" << casenum << ": "<<res<<endl;
    }
    return 0;
}
