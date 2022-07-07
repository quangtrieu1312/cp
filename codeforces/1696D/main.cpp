#include <bits/stdc++.h>
#define Nmax 250005

using namespace std;
typedef pair<int, int> pii;

int t, n, a[Nmax];
pii maxtree[4*Nmax], mintree[4*Nmax];

bool buildMinTree(int node, int left, int right){
    if (left>right){
        return false;
    }
    if (left==right){
        mintree[node]=pii(a[left],left);
        return true;
    }
    bool hasLeftNode=buildMinTree(node*2,left,(left+right)/2);
    bool hasRightNode=buildMinTree(node*2+1,(left+right)/2+1,right);
    if (hasLeftNode && hasRightNode){
        if (mintree[node*2].first<mintree[node*2+1].first){
            //left node is smaller
            mintree[node]=mintree[node*2];
        } else {
            //right node is <= left node
            mintree[node]=mintree[node*2+1];
        }
    } else if (hasLeftNode){
        mintree[node]=mintree[node*2];
    } else if (hasRightNode){
        mintree[node]=mintree[node*2+1];
    } else {
        return false;
    }
    return true;
}

bool buildMaxTree(int node, int left, int right){
    if (left>right){
        return false;
    }
    if (left==right){
        maxtree[node]=pii(a[left],left);
        return true;
    }
    bool hasLeftNode=buildMaxTree(node*2,left,(left+right)/2);
    bool hasRightNode=buildMaxTree(node*2+1,(left+right)/2+1,right);
    if (hasLeftNode && hasRightNode){
        if (maxtree[node*2].first>maxtree[node*2+1].first){
            //left node is larger
            maxtree[node]=maxtree[node*2];
        } else {
            //right node is >= left node
            maxtree[node]=maxtree[node*2+1];
        }
    } else if (hasLeftNode){
        maxtree[node]=maxtree[node*2];
    } else if (hasRightNode){
        maxtree[node]=maxtree[node*2+1];
    } else {
        return false;
    }
    return true;
}

pii queryMaxTree(int node, int left, int right, int left_q, int right_q){
    if (left>right || right<left_q || right_q<left){
        return pii(-1,-1);
    }
    if (left_q<=left && right<=right_q){
        return maxtree[node];
    }
    pii leftQuery=queryMaxTree(node*2,left,(left+right)/2,left_q,right_q);
    pii rightQuery=queryMaxTree(node*2+1,(left+right)/2+1,right,left_q,right_q);
    if (leftQuery.second!=-1 && rightQuery.second!=-1){
        if (leftQuery.first>rightQuery.first){
            //left query is >
            return leftQuery;
        } else {
            //right query is >=
            return rightQuery;
        }
    } else if (leftQuery.second!=-1){
        return leftQuery;
    } else if (rightQuery.second!=-1){
        return rightQuery;
    } else {
        return pii(-1,-1);
    }
}

pii queryMinTree(int node, int left, int right, int left_q, int right_q){
    if (left>right || right<left_q || right_q<left){
        return pii(-1,-1);
    }
    if (left_q<=left && right<=right_q){
        return mintree[node];
    }
    pii leftQuery=queryMinTree(node*2,left,(left+right)/2,left_q,right_q);
    pii rightQuery=queryMinTree(node*2+1,(left+right)/2+1,right,left_q,right_q);
    if (leftQuery.second!=-1 && rightQuery.second!=-1){
        if (leftQuery.first<rightQuery.first){
            //left query is <
            return leftQuery;
        } else {
            //right query is <=
            return rightQuery;
        }
    } else if (leftQuery.second!=-1){
        return leftQuery;
    } else if (rightQuery.second!=-1){
        return rightQuery;
    } else {
        return pii(-1,-1);
    }
}

int solve(int left, int right){
    pii maxnode, minnode;
    maxnode=queryMaxTree(1,0,n-1,left,right);
    minnode=queryMinTree(1,0,n-1,left,right);
    if ((left==maxnode.second && right==minnode.second) || (left==minnode.second && right==maxnode.second)){
        return 1;
    } else if (left==maxnode.second){
        return 1+solve(minnode.second,right);
    } else if (left==minnode.second){
        return 1+solve(maxnode.second,right);
    } else if (right==maxnode.second){
        return solve(left,minnode.second)+1;
    } else if (right==minnode.second){
        return solve(left,maxnode.second)+1;
    } else {
        return solve(left,min(maxnode.second,minnode.second))+1+solve(max(maxnode.second,minnode.second),right);
    }
}

int main()
{
    cin>>t;
    while(t--){
        int res=0;
        cin>>n;
        for (int i=0; i<n; i++){
            cin>>a[i];
        }
        if (n<=2){
            cout<<n-1<<endl;
            continue;
        }

        buildMaxTree(1,0,n-1);
        buildMinTree(1,0,n-1);
        res=solve(0,n-1);

        cout<<res<<endl;
    }
    return 0;
}

/*
5
1
1
2
1 2
5
1 4 2 3 5
5
2 1 5 3 4
10
7 4 8 1 6 10 3 5 2 9


1
10
7 4 8 1 6 10 3 5 2 9

*/
