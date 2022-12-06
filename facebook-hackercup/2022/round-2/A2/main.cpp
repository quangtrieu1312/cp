#include <bits/stdc++.h>
#define MODULO 1000000007
using namespace std;
typedef long long ll;
int T;
int N;
vector<ll> A;
ll Q, L, R;
ll res;
vector<ll> xortree, sumtree, prodtree;
bool buildXorTree(int node, int l, int r){
    if (l>r){
        return false;
    }
    if (l==r){
        xortree[node]=A[l];
        return true;
    }
    bool hasLeft=buildXorTree(node*2,l,(l+r)/2);
    bool hasRight=buildXorTree(node*2+1,(l+r)/2+1,r);
    if (hasLeft && hasRight){
        xortree[node]=xortree[node*2]^xortree[node*2+1];
    } else if (hasLeft){
        xortree[node]=xortree[node*2];
    } else {
        return false;
    }
    return true;
}

bool buildSumTree(int node, int l, int r){
    if (l>r){
        return false;
    }
    if (l==r){
        sumtree[node]=A[l];
        return true;
    }
    bool hasLeft=buildSumTree(node*2,l,(l+r)/2);
    bool hasRight=buildSumTree(node*2+1,(l+r)/2+1,r);
    if (hasLeft && hasRight){
        sumtree[node]=sumtree[node*2]+sumtree[node*2+1];
    } else if (hasLeft){
        sumtree[node]=sumtree[node*2];
    } else {
        return false;
    }
    return true;
}

bool buildProdTree(int node, int l, int r){
    if (l>r){
        return false;
    }
    if (l==r){
        prodtree[node]=A[l];
        return true;
    }
    bool hasLeft=buildProdTree(node*2,l,(l+r)/2);
    bool hasRight=buildProdTree(node*2+1,(l+r)/2+1,r);
    if (hasLeft && hasRight){
        prodtree[node]=(prodtree[node*2]*prodtree[node*2+1])%MODULO;
    } else if (hasLeft){
        prodtree[node]=prodtree[node*2];
    } else {
        return false;
    }
    return true;
}

void updateXorTree(int node, int l, int r, int ind, ll val){
    if (l>r || ind<l || r<ind){
        return;
    }
    if (l==r){
        A[ind]=val;
        xortree[node]=val;
        return;
    }
    updateXorTree(node*2,l,(l+r)/2,ind,val);
    updateXorTree(node*2+1,(l+r)/2+1,r,ind,val);
    xortree[node]=xortree[node*2]^xortree[node*2+1];
}

void updateSumTree(int node, int l, int r, int ind, ll val){
    if (l>r || ind<l || r<ind){
        return;
    }
    if (l==r){
        A[ind]=val;
        sumtree[node]=val;
        return;
    }
    updateSumTree(node*2,l,(l+r)/2,ind,val);
    updateSumTree(node*2+1,(l+r)/2+1,r,ind,val);
    sumtree[node]=sumtree[node*2]+sumtree[node*2+1];
}

void updateProdTree(int node, int l, int r, int ind, ll val){
    if (l>r || ind<l || r<ind){
        return;
    }
    if (l==r){
        A[ind]=val;
        prodtree[node]=val;
        return;
    }
    updateProdTree(node*2,l,(l+r)/2,ind,val);
    updateProdTree(node*2+1,(l+r)/2+1,r,ind,val);
    prodtree[node]=(prodtree[node*2]*prodtree[node*2+1])%MODULO;
}

ll queryXorTree(int node, int l, int r, int lq, int rq){
    if (l>r || rq<l || r<lq){
        return 0;
    }
    if (lq<=l && r<=rq){
        return xortree[node];
    }
    ll leftQuery=queryXorTree(node*2,l,(l+r)/2,lq,rq);
    ll rightQuery=queryXorTree(node*2+1,(l+r)/2+1,r,lq,rq);
    return leftQuery^rightQuery;
}

ll querySumTree(int node, int l, int r, int lq, int rq){
    if (l>r || rq<l || r<lq){
        return 0;
    }
    if (lq<=l && r<=rq){
        return sumtree[node];
    }
    ll leftQuery=querySumTree(node*2,l,(l+r)/2,lq,rq);
    ll rightQuery=querySumTree(node*2+1,(l+r)/2+1,r,lq,rq);
    return leftQuery+rightQuery;
}

ll queryProdTree(int node, int l, int r, int lq, int rq){
    if (l>r || rq<l || r<lq){
        return 1;
    }
    if (lq<=l && r<=rq){
        return prodtree[node];
    }
    ll leftQuery=queryProdTree(node*2,l,(l+r)/2,lq,rq);
    ll rightQuery=queryProdTree(node*2+1,(l+r)/2+1,r,lq,rq);
    return (leftQuery*rightQuery)%MODULO;
}

int main(){
    freopen("perfectly_balanced_chapter_2_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        cin>>N;
        A.resize(0);
        A.resize(N);
        for (int i=0; i<N; i++){
            cin>>A[i];
        }
        xortree.resize(0);
        sumtree.resize(0);
        prodtree.resize(0);
        xortree.resize(4*N);
        sumtree.resize(4*N);
        prodtree.resize(4*N);
        buildXorTree(1,0,N-1);
        buildSumTree(1,0,N-1);
        buildProdTree(1,0,N-1);
        cin>>Q;
        int type;
        res=0;
        int top=1;
        for (int i=0; i<Q; i++){
            cin>>type>>L>>R;
            if (type==1){
                updateXorTree(1,0,N-1,L-1,R);
                updateSumTree(1,0,N-1,L-1,R);
                updateProdTree(1,0,N-1,L-1,R);
            } else {
                L--;
                R--;
                if ((R-L+1)%2==0){
                    continue;
                }
                //cout<<"Query "<<top++<<endl;
                //for (int i=L; i<=R; i++){
                //    cout<<A[i]<<" ";
                //}
                //cout<<endl;
                //if the whole range is almost palindrome
                //-> need to obmit 1 ele to make XOR range = 0
                //   and sum 1st half = sum 2nd half
                ll diff=queryXorTree(1,0,N-1,L,R);
                ll leftsum, rightsum, leftprod, rightprod;
                //try remove left
                int mid=(L+R)/2;
                leftsum=querySumTree(1,0,N-1,L,mid);
                rightsum=querySumTree(1,0,N-1,mid+1,R);
                leftprod=queryProdTree(1,0,N-1,L,mid);
                rightprod=queryProdTree(1,0,N-1,mid+1,R);
                if (leftsum-rightsum==diff && leftprod==(rightprod*diff)%MODULO){
                    //cout<<"Remove left: "<<diff<<endl<<"sum: "<<leftsum<<" "<<rightsum<<endl<<"prod: "<<leftprod<<" "<<rightprod<<endl;
                    //cout<<L+1<<" "<<R+1<<endl;
                    //cout<<"----------------"<<endl;
                    res++;
                    continue;;
                }
                //try remove right
                leftsum=querySumTree(1,0,N-1,L,mid-1);
                rightsum=querySumTree(1,0,N-1,mid,R);
                leftprod=queryProdTree(1,0,N-1,L,mid-1);
                rightprod=queryProdTree(1,0,N-1,mid,R);
                if (rightsum-leftsum==diff && rightprod==(leftprod*diff)%MODULO){
                    //cout<<"Remove right: "<<diff<<endl<<"sum: "<<leftsum<<" "<<rightsum<<endl<<"prod: "<<leftprod<<" "<<rightprod<<endl;
                    //cout<<L+1<<" "<<R+1<<endl;
                    //cout<<"----------------"<<endl;
                    res++;
                    continue;
                }
            }
        }

        cout<<"Case #"<<casenum<<": "<<res<<endl;
    }
    return 0;
}

