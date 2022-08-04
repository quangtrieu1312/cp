#include <bits/stdc++.h>

using namespace std;

int n, res;

vector<int> a, x, y, adj, d, head, pos;
vector<int> remove_nodes;
vector<bool> visited;
set<int> sxor;
bool isDebug = true, useAutoGen=false;
void printSet(set<int> s, string message){
    if (!isDebug) return;
    cout<<message<<endl;
    for (auto e: s){
        cout<<e<<" ";
    }
    cout<<endl;
}

int dfs(int start, int dest, int curxor){
    visited[start]=true;
    curxor=curxor^a[start];
    if (start==dest){
        return curxor;
    }
    for (int i=head[start]; i<head[start+1]; i++){
        if (!visited[adj[i]]){
            int adjxor=dfs(adj[i],dest,curxor);
            if (adjxor!=-1){
                return adjxor;
            }
        }
    }
    return -1;
}
int res_checker(){

    int ans=0;
    vector < bool > used;
    used.resize(remove_nodes.size(),false);
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            visited.resize(0);
            visited.resize(n+1,false);
            if (dfs(i,j,0)==0){
                for (int k=0; k<remove_nodes.size(); k++){
                    used[k]=visited[remove_nodes[k]];
                }
            }
        }
    }
    for (int i=0; i<used.size(); i++){
        if (used[i]){
            ans++;
        }
    }
    return ans;
}
void solve(int node, int curxor){
    visited[node]=true;
    curxor=curxor^a[node];
    bool reset=false;
    for (int i=head[node]; i<head[node+1]; i++){
        if (visited[adj[i]]){
            continue;
        }
        solve(adj[i], curxor);
        for (auto e: sxor){
            if (e==curxor){
                if (isDebug) cout<<"Removing node="<<node<<" because child branch " << adj[i]<< "has dup e="<<e<<endl;
                printSet(sxor,"Current val of node=" + to_string(node));
                reset=true;
                break;
            }
            if (sxor.count(e^a[node])>0){
                //exists f=e^a[node], and f is not in vxor[i] set
                //thus, f^e^a[node] = 0
                //=> change a[node], reset sxor
                if (isDebug) cout<<"Removing node="<<node<<" because child branch " << adj[i]<< ", e="<<e<<" e^a[node]="<< (int) (e^a[node]) <<endl;
                printSet(sxor,"Current val of node=" + to_string(node));
                reset=true;
                break;
            }
        }
        for (auto e: sxor){
            printSet(sxor,"Inserting " + to_string(e) + " to node=" + to_string(node));
            sxor.insert(e);
        }
        printSet(sxor,"u, v = " + to_string(node) + ", " + to_string(adj[i]));
    }
    if (reset){
        res++;
        sxor.clear();
        remove_nodes.push_back(node);
    } else {
        sxor.insert(curxor);
    }
    printSet(sxor,"Combined val of node=" + to_string(node));
}

int main()
{
    ios::sync_with_stdio(false);
    if (isDebug && useAutoGen){
        srand(time(0));
        freopen("debug.txt","w",stdout);
        n=10;
        a.resize(n+1);
        for (int i=1; i<=n; i++){
            a[i]=rand()%n+1;
        }
    } else {
        cin>>n;
        a.resize(n+1);
        for (int i=1; i<=n; i++){
            cin>>a[i];
        }
    }

    x.resize(n-1);
    y.resize(n-1);
    d.resize(n+1,0);
    head.resize(n+2,0);
    pos.resize(n+2,0);
    adj.resize(2*(n-1));

    for (int i=0; i<n-1; i++){
        if (isDebug && useAutoGen){
            x[i]=rand()%(i+1)+1;
            y[i]=i+2;
        } else {
            cin>>x[i]>>y[i];
        }

        d[x[i]]++;
        d[y[i]]++;
    }
    for (int i=1; i<=n+1; i++){
        head[i]=head[i-1]+d[i-1];
        pos[i]=head[i];
    }

    for (int i=0; i<n-1; i++){
        adj[pos[x[i]]++]=y[i];
        adj[pos[y[i]]++]=x[i];
    }
    res=0;
    visited.resize(0);
    visited.resize(n+1,false);
    solve(1,0);
    cout<<res<<endl;
    if (isDebug){
        int res_check=res_checker();
        cout<<"Expected res="<<res_check<<endl;
        if (res_check!=res){
            cout<<"Wrong answer for test case:"<<endl;
            cout<<n<<endl;
            for (int i=1; i<=n; i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            for (int i=0; i<n-1; i++){
                cout<<x[i]<<" "<<y[i]<<endl;
            }
        }
    }

    return 0;
}
/*
10
1 6 8 3 2 9 8 6 9 9
1 2
2 10
2 3
3 8
2 4
4 5
4 6
4 7
4 9
*/
