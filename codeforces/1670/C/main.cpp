#include <bits/stdc++.h>
#define MODULO 1000000007
using namespace std;
int t, n;
vector<int> a, b, c, p;
vector< vector<int> > ind;
int findNextInd(int curVal, int curInd){
    for (int i=0; i<2; i++){
        if (ind[curVal][i]!=curInd){
            return ind[curVal][i];
        }
    }
    return -1;
}
int findNextVal(int curVal, int curInd){
    int nxtInd = findNextInd(curVal,curInd);
    if (a[nxtInd]!=curVal){
        return a[nxtInd];
    } else {
        return b[nxtInd];
    }
}
void dfs(int group, int curVal, int curInd){
    p[curInd]=group;
    int nxtInd = findNextInd(curVal, curInd);
    int nxtVal = findNextVal(curVal,curInd);
    if (p[nxtInd]==0){
        dfs(group,nxtVal,nxtInd);
    }
}
int main()
{
    cin>>t;
    while (t--){
        long long res = 1;
        cin>>n;
        ind.resize(0);
        ind.resize(n+1,vector<int>(0));
        a.resize(n);
        b.resize(n);
        c.resize(n);
        p.resize(0);
        p.resize(n,0);
        for (int i=0; i<n; i++){
            cin>>a[i];
            ind[a[i]].push_back(i);
        }
        for (int i=0; i<n; i++){
            cin>>b[i];
            ind[b[i]].push_back(i);
        }

        int neg_group=-1, pos_group=1;
        for (int i=0; i<n; i++){
            cin>>c[i];
            if (a[i]==b[i]){
                c[i]=a[i];
            }
        }

        for (int i=0; i<n; i++){
            if (p[i]==0){
                if (c[i]!=0){
                    dfs(neg_group,c[i],i);
                    neg_group--;
                }
            }
        }

        for (int i=0; i<n; i++){
            if (p[i]==0){
                dfs(pos_group,a[i],i);
                pos_group++;
            }
        }

        for (int i=1; i<pos_group ; i++){
            res=(res*2L)%MODULO;
        }

        cout<<res<<endl;
    }
    return 0;
}
