#include <bits/stdc++.h>
#define oo 1000000000012345
using namespace std;
typedef long long ll;
int T, R, C, K, S;
vector<int> A, B;
vector< vector<char> > G;
vector< vector<int> > tree;

ll res=0, sumres=0;
bool buildTreeStrip(int strip, int node, int left, int right){
    if (left>right){
        return false;
    }
    if (left==right){
        tree[strip][node]=(G[left][strip]=='.');
        return true;
    }
    bool hasLeft = buildTreeStrip(strip,node*2,left,(left+right)/2);
    bool hasRight = buildTreeStrip(strip,node*2+1,(left+right)/2+1,right);
    if (hasLeft && hasRight){
        tree[strip][node]=tree[strip][node*2]+tree[strip][node*2+1];
    } else if (hasLeft){
        tree[strip][node]=tree[strip][node*2];
    } else if (hasRight){
        tree[strip][node]=tree[strip][node*2+1];
    } else {
        return false;
    }
    return true;
}
int queryTreeStrip(int strip, int node, int left, int right, int left_q, int right_q){
    if (left>right || right_q<left || right<left_q){
        return 0;
    }
    if (left_q<=left && right<=right_q){
        return tree[strip][node];
    }
    return  queryTreeStrip(strip,node*2,left,(left+right)/2,left_q,right_q)
            +queryTreeStrip(strip,node*2+1,(left+right)/2+1,right,left_q,right_q);
}

bool updateTreeStrip(int strip, int node, int left, int right, int ind, int val){
    if (left>right || ind<left || right<ind){
        return false;
    }
    if (left==right && right==ind){
        tree[strip][node]=val;
        return true;
    }
    bool hasLeft = updateTreeStrip(strip,node*2,left,(left+right)/2,ind,val);
    bool hasRight = updateTreeStrip(strip,node*2+1,(left+right)/2+1,right,ind,val);
    if (hasLeft && hasRight){
        tree[strip][node]=tree[strip][node*2]+tree[strip][node*2+1];
    } else if (hasLeft){
        tree[strip][node]=tree[strip][node*2];
    } else if (hasRight){
        tree[strip][node]=tree[strip][node*2+1];
    } else {
        return false;
    }
    return true;
}
vector<ll> treeV, V;
bool buildTreeV(int node, int left, int right){
    if (left>right){
        return false;
    }
    if (left==right){
        treeV[node]=V[left];
        return true;
    }
    bool hasLeft=buildTreeV(node*2,left,(left+right)/2);
    bool hasRight=buildTreeV(node*2+1,(left+right)/2+1,right);
    if (hasLeft && hasRight){
        treeV[node]=min(treeV[node*2],tree[node*2+1]);
    } else if (hasLeft){
        treeV[node]=treeV[node*2];
    } else {
        return false;
    }
    return true;
}
ll queryTreeV(int node, int left, int right, int lq, int rq){
    if (left>right || rq<left || right<lq){
        return oo;
    }
    if (lq<=left && right<=rq){
        return treeV[node];
    }
    return min(queryTreeV(node*2,left,(left+right)/2,lq,rq),
                queryTreeV(node*2+1,(left+right)/2+1,right,lq,rq));
}
bool updateTreeV(int node, int left, int right, int ind, int val){
    if (left>right || ind<left || right<ind){
        return false;
    }
    if (left==right && right==ind){
        return treeV[node]=val;
    }
    bool hasLeft = updateTreeV(node*2,left,(left+right)/2,ind,val);
    bool hasRight = updateTreeV(node*2+1,(left+right)/2+1,right,ind,val);
    if (hasLeft && hasRight){
        treeV[node]=treeV[node*2]+treeV[node*2+1];
    } else if (hasLeft){
        treeV[node]=treeV[node*2];
    } else if (hasRight){
        treeV[node]=treeV[node*2+1];
    } else {
        return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        cin>>R>>C>>K>>S;
        G.resize(0);
        G.resize(R+2,vector<char>(C+2));
        for (int i=1; i<=R; i++){
            for (int j=1; j<=C; j++){
                cin>>G[i][j];
            }
        }
        A.resize(0);
        B.resize(0);
        A.resize(S);
        B.resize(S);
        for (int i=0; i<S; i++){
            cin>>A[i]>>B[i];
        }
        for (int i=0; i<=R+1; i++){
            G[i][0]='.';
            G[i][C+1]='.';
        }
        for (int j=0; j<=C+1; j++){
            G[0][j]='.';
            G[R+1][j]='.';
        }
        tree.resize(0);
        tree.resize(C+2,vector<int>(4*(R+2),0));
        for (int j=0; j<=C+1; j++){
            buildTreeStrip(j,1,0,R+1);
        }

        sumres=0;

        res=0;
        for (int i=1; i<=C; i++){
            if (G[K][i]=='X'){
                res++;
            }
        }
        V.resize(0);
        V.resize(R+2);
        V[K]=res;
        for (int i=1; i<=R-K+1; i++){
            ll tmp=i;
            for (int j=1; j<=C; j++){
                //debugcnt=queryTreeStrip(j,1,0,R+1,1,K+i;
                if (queryTreeStrip(j,1,0,R+1,1,K+i)<=i || G[K+i][j]=='X'){
                    //after moving up "i" times, this G[K][j] = 'X'
                    //thus, we need to remove it
                    tmp++;
                }
            }
            V[K+i]=tmp;
        }
        for (int i=1; i<=K; i++){
            ll tmp=i;
            for (int j=1; j<=C; j++){
                //debugcnt=queryTreeStrip(j,1,0,R+1,K-i,R);
                if (queryTreeStrip(j,1,0,R+1,K-i,R)<=i || G[K-i][j]=='X'){
                    //after moving down "i" times, this G[K][j] = 'X'
                    //thus, we need to remove it
                    tmp++;
                }
            }
            V[K-i]=tmp;
        }
        treeV.resize(0);
        treeV.resize(4*V.size());
        buildTreeV(1,0,R+1);
        res=0;
        for (int s=0; s<S; s++){
            if (G[A[s]][B[s]]=='X'){
                G[A[s]][B[s]]='.';
            } else {
                G[A[s]][B[s]]='X';
            }
            int val=(G[A[s]][B[s]]=='.');
            updateTreeStrip(B[s],1,0,R+1,A[s],val);
            //init res val = remove all cars in K
            if (A[s]<K){
                //change is above K
                int delt=0;

            } else if (A[s]>K){
                //change is below K
            } else {

            }
        }
        cout<<"Case #"<<casenum<<": "<<sumres<<endl;
    }
    return 0;
}
