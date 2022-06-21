#include <bits/stdc++.h>

using namespace std;
int t, n, m;
vector<int> ans;
vector< vector<int> > a, b;

int compare_vec(vector<int> &x, vector<int> &y){
    if (x.size()!=y.size()){
        return 2;
    }
    int res=2;
    if (x[0]>y[0]){
        res=1;
    } else if (x[0]<y[0]){
        res=-1;
    } else {
        res=0;
    }
    for (int i=1; i<x.size(); i++){
        int temp=2;
        if (x[i]>y[i]){
            temp=1;
        } else if (x[i]<y[i]){
            temp=-1;
        } else {
            temp=0;
        }
        if (res==0 && temp!=0){
            res=temp;
        }
        if (res!=temp && temp!=0){
            return 2;
        }
    }
    return res;
}

void qsort(int l, int r){
    if (ans.size()!=0) return;
    int x=l, y=r;
    int ind=l+rand()%(r-l+1);
    vector<int> &mid = a[ind];
    while (l<=r){
        while (l<=y && compare_vec(a[l],mid)==-1) l++;
        while (r>=x && compare_vec(a[r],mid)==1) r--;
        if (l<=r){
            if (compare_vec(a[l],a[r])==2){
                ans.push_back(-1);
                return;
            } else {
                swap(a[l],a[r]);
                l++;
                r--;
            }
        }
    }
    if (x<r) qsort(x,r);
    if (l<y) qsort(l,y);
}

int main() {
    cin>>t;
    while (t--){
        cin>>n>>m;
        ans.resize(0);
        a.resize(0);
        a.resize(m,vector<int>(n));
        b.resize(0);
        b.resize(m,vector<int>(n));

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin>>a[j][i];
                b[j][i]=a[j][i];
            }
        }

        qsort(0,m-1);

        if (ans.size()==0){
            for (int i=0; i<m; i++){
                if (compare_vec(a[i],b[i])!=0){
                    ans.push_back(i+1);
                }
            }

            for (int i=1; i<m; i++){
                if (compare_vec(a[i-1],a[i])>0){
                    ans.resize(0);
                    ans.push_back(-1);
                    break;
                }
            }

            if (ans.size()>2){
                ans.resize(0);
                ans.push_back(-1);
            }
            if (ans.size()==0){
                ans.push_back(1);
                ans.push_back(1);
            }
        }

        //cout<<"---------ANS------------"<<endl;
        for (int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        //cout<<"---------END ANS------------"<<endl;
    }
    return 0;
}
/*

1
1 10
1 2 3 2 2 2 2 2 3 3

1
5 1
7
6
4
7
6

*/
