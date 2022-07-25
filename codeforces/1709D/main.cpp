#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<int> a, tree;

int queryTree(int node, int l, int r, int lq, int rq){
    if (l>r || rq<l || r<lq){
        return -1;
    }
    if (lq <=l && r<=rq){
        return tree[node];
    }
    int leftQ = queryTree(node*2,l,(l+r)/2,lq,rq);
    int rightQ = queryTree(node*2+1,(l+r)/2+1,r,lq,rq);
    return max(leftQ,rightQ);
}

bool buildTree(int node, int l, int r){
    if (l>r){
        return false;
    }
    if (l==r){
        tree[node]=a[l];
        return true;
    }
    bool hasLeft = buildTree(node*2, l, (l+r)/2);
    bool hasRight = buildTree(node*2+1, (l+r)/2+1, r);
    if (hasLeft && hasRight){
        tree[node]=max(tree[node*2],tree[node*2+1]);
    } else if (hasLeft){
        tree[node]=tree[node*2];
    } else {
        tree[node]=tree[node*2+1];
    }
    return true;

}

bool solve(int xs, int ys, int xf, int yf, int k){
    if ((xs%k)!=(xf%k) || (ys%k)!=(yf%k)){
        return false;
    }
    if (xs==xf && ys==yf){
        return true;
    }
    int max_a=queryTree(1,1,m,min(ys,yf),max(ys,yf));
    if (n==max_a){
        return false;
    }

    int max_mod=n%k;
    int min_mod=(max_a+1)%k;
    if (n-max_a>=k){
        max_mod=k-1;
        min_mod=0;
    }
    if (max_mod>=min_mod){
        return min_mod<=(xs%k) && (xs%k)<=max_mod;
    } else {
        return min_mod<=(xs%k) || (xs%k)<=max_mod;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    int xs, ys, xf, yf, k;

    cin>>n>>m;
    a.resize(m+1);
    tree.resize(4*(m+1));
    for (int i=1; i<=m; i++){
        cin>>a[i];
    }
    buildTree(1,1,m);

    cin>>q;
    for (int i=0; i<q; i++){
        cin>>xs>>ys>>xf>>yf>>k;
        if (solve(xs,ys,xf,yf,k)){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
/*

10 10
2 7 1 5 2 0 6 6 2 7
1
8 9 2 3 6

10 10
2 10 1 5 2 0 6 10 2 7
1
7 7 7 1 3
*/
