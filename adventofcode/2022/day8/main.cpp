#include <bits/stdc++.h>

using namespace std;
vector< vector<int> > trees;
vector< vector<bool> > visi;
vector<int> maxc, maxr;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string line;
    int n, m;
    while (cin>>line) {
        vector<int> row;
        for (int i=0; i<line.size(); i++){
            row.push_back(line[i]-'0');
        }
        trees.push_back(row);
    }
    n=trees.size();
    m=trees[0].size();

    //visi[i][j]=true tree at [i][j] is visible
    visi.resize(n, vector<bool>(m,false));

    for (int i=0; i<n; i++){
        visi[i][0]=true;
        visi[i][m-1]=true;
    }
    for (int j=0; j<m; j++){
        visi[0][j]=true;
        visi[n-1][j]=true;
    }

    // iterate from top left corner to bottom right corner
    // init maxr, maxc
    maxr.resize(0);
    maxc.resize(0);
    maxr.resize(n,0);
    maxc.resize(m,0);
    for (int i=1; i<n-1; i++){
        maxr[i]=trees[i][0];
    }
    for (int j=1; j<m-1; j++){
        maxc[j]=trees[0][j];
    }
    for (int i=1; i<n-1; i++){
        for (int j=1; j<m-1; j++){
            visi[i][j]=(trees[i][j]>maxr[i] || trees[i][j]>maxc[j]);
            maxr[i]=max(maxr[i],trees[i][j]);
            maxc[j]=max(maxc[j],trees[i][j]);
        }
    }
    // iterate from bottom right corner to top left corner
    // init maxr, maxc
    maxr.resize(0);
    maxc.resize(0);
    maxr.resize(n,0);
    maxc.resize(m,0);
    for (int i=1; i<n-1; i++){
        maxr[i]=trees[i][m-1];
    }
    for (int j=1; j<m-1; j++){
        maxc[j]=trees[n-1][j];
    }
    for (int i=n-2; i>=1; i--){
        for (int j=m-2; j>=1; j--){
            visi[i][j]=visi[i][j] || (trees[i][j]>maxr[i] || trees[i][j]>maxc[j]);
            maxr[i]=max(maxr[i],trees[i][j]);
            maxc[j]=max(maxc[j],trees[i][j]);
        }
    }
    //count result
    int res=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (visi[i][j]){
                //is visible
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
