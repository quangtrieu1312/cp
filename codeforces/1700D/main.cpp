#include <bits/stdc++.h>
#define Nmax 200005

using namespace std;
typedef long long ll;
int n, q, res;
ll sum;
vector<ll> v, t, speed, tree, rem;
vector<int> ind;

int queryTree(int node, int left, int right, int lq, int rq){
    if (left>right) return -1;
    if (lq<=left && right<=rq) return ind[node];
    int leftNode=2*node, ll=left, lr=(left+right)/2;
    int rightNode=2*node+1, rl=(left+right)/2+1, rr=right;
    if (rem[node]!=0){
        if (ll<=lr){
            rem[leftNode]+=rem[node];
        }
        if (rl<=rr){
            rem[rightNode]+=rem[node];
        }
    }
    if (left==right){
        speed[left]+=rem[node];
        tree[node]=ceil(v[left]/speed[left]);
        ind[node]=left;
        rem[node]=0;
        return ind[node];
    }
    rem[node]=0;
    int leftQuery = queryTree(leftNode,ll,lr);
    int rightQuery = queryTree(rightNode,rl,rr);
    if (leftQuery==-1) return rightQuery;
    if (rightQuery==-1) return leftQuery;
    if (v[leftQuery]/speed[leftQuery])
}

void buildTree(int node, int left, int right){
    if (left>right) return;
    int leftNode=2*node, ll=left, lr=(left+right)/2;
    int rightNode=2*node+1, rl=(left+right)/2+1, rr=right;
    if (left==right){
        tree[node]=ceil(v[left]/speed[left]);
        ind[node]=left;
    }
    buildTree(leftNode,ll,lr);
    buildTree(rightNode,rl,rr);
    if (ll>lr){
        tree[node]=tree[rightNode];
        ind[node]=ind[rightNode];
    } else if (rl>rr){
        tree[node]=tree[leftNode];
        ind[node]=ind[leftNode];
    } else {
        int minNode=leftNode;
        if (tree[minNode]>tree[rightNode]){
            minNode=rightNode;
        }
        tree[node]=tree[minNode];
        ind[node]=ind[minNode];
    }
}

int main()
{
    cin>>n;
    v.resize(n);
    speed.resize(n);
    sum=0;
    for (int i=0; i<n; i++){
        cin>>v[i];
        speed[i]=1;
        sum+=v[i];
    }
    tree.resize(4*n,0);
    rem.resize(4*n,0);
    ind.resize(4*n,0);

    cin>>q;
    t.resize(q);
    for (int i=0; i<q; i++){
        cin>>t[i];
        res=ceil(sum*1.0/t[i]);
        if (res>n){
            res=-1;
        }
        cout<<res<<endl;
    }

    return 0;
}
/*

first: smallest v[i]/speed[i]
-> update speed[i+1]..speed[n] = speed[i+1]+1...speed[n]+1

*/
