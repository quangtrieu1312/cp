#include <bits/stdc++.h>
#define oo 500000000001234
using namespace std;
typedef long long ll;

int t, n;
vector<int> a, next_larger_ele, prev_larger_ele;
vector<ll> sum, minTree, maxTree;

ll queryMinTree(int node, int left, int right, int qLeft, int qRight){
    if (left>right || qRight<left || right<qLeft){
        return oo;
    }
    if (qLeft<=left && right<=qRight){
        return minTree[node];
    }
    ll leftQ = queryMinTree(node*2,left,(left+right)/2,qLeft,qRight);
    ll rightQ = queryMinTree(node*2+1,(left+right)/2+1,right,qLeft,qRight);
    return min(leftQ,rightQ);
}

bool buildMinTree(int node, int left, int right){
    if (left>right){
        false;
    }
    if (left==right){
        minTree[node]=sum[left];
        return true;
    }
    bool hasLeft=buildMinTree(node*2,left,(left+right)/2);
    bool hasRight=buildMinTree(node*2+1,(left+right)/2+1,right);
    if (hasLeft && hasRight){
        minTree[node]=min(minTree[node*2],minTree[node*2+1]);
    } else if (hasLeft){
        minTree[node]=minTree[node*2];
    } else {
        return false;
    }
    return true;
}


ll queryMaxTree(int node, int left, int right, int qLeft, int qRight){
    if (left>right || qRight<left || right<qLeft){
        return -oo;
    }
    if (qLeft<=left && right<=qRight){
        return maxTree[node];
    }
    ll leftQ = queryMaxTree(node*2,left,(left+right)/2,qLeft,qRight);
    ll rightQ = queryMaxTree(node*2+1,(left+right)/2+1,right,qLeft,qRight);
    return max(leftQ,rightQ);
}

bool buildMaxTree(int node, int left, int right){
    if (left>right){
        false;
    }
    if (left==right){
        maxTree[node]=sum[left];
        return true;
    }
    bool hasLeft=buildMaxTree(node*2,left,(left+right)/2);
    bool hasRight=buildMaxTree(node*2+1,(left+right)/2+1,right);
    if (hasLeft && hasRight){
        maxTree[node]=max(maxTree[node*2],maxTree[node*2+1]);
    } else if (hasLeft){
        maxTree[node]=maxTree[node*2];
    } else {
        return false;
    }
    return true;
}

bool solve(int i){
    int left=prev_larger_ele[i]+1;
    int right=next_larger_ele[i]-1;
    if (left==right){
        return true;
    }
    ll s;
    if (left==i){
        s=queryMaxTree(1,0,n,i,right)-sum[i];
        return s<=0;
    } else if (right==i){
        s=sum[i-1]-queryMinTree(1,0,n,left-1,i-1);
        return s<=0;
    } else {
        s=queryMaxTree(1,0,n,i,right)-queryMinTree(1,0,n,left-1,i-1)-a[i];
        return s<=0;
    }
}

int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        a.resize(n+1);
        for (int i=1; i<=n; i++){
            cin>>a[i];
        }

        sum.resize(n+1);
        sum[0]=0;
        for (int i=1; i<=n; i++){
            sum[i]=sum[i-1]+a[i];
        }

        next_larger_ele.resize(n+1);
        next_larger_ele[n]=n+1;
        for (int i=n-1; i>=1; i--){
            if (a[i]<a[i+1]){
                next_larger_ele[i]=i+1;
            } else {
                int j=next_larger_ele[i+1];
                while (j<=n && a[i]>=a[j]){
                    j=next_larger_ele[j];
                }
                next_larger_ele[i]=j;
            }
        }

        prev_larger_ele.resize(n+1);
        prev_larger_ele[1]=0;
        for (int i=2; i<=n; i++){
            if (a[i-1]>a[i]){
                prev_larger_ele[i]=i-1;
            } else {
                int j=prev_larger_ele[i-1];
                while (j>=1 && a[i]>=a[j]){
                    j=prev_larger_ele[j];
                }
                prev_larger_ele[i]=j;
            }
        }

        maxTree.resize(4*(n+1));
        buildMaxTree(1,0,n);

        minTree.resize(4*(n+1));
        buildMinTree(1,0,n);

        bool res=true;
        for (int i=1; i<=n; i++){
            res=res&&solve(i);
        }

        if (res){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
/*

6
4
-1 1 -1 2
5
-1 2 -3 2 -1
3
2 3 -1
3
0 1 0
3
0 0 0
3
-1 -1 -1

1
3
2 3 -1

1
3
0 1 0
*/
