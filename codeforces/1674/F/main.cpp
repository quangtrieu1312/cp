#include <bits/stdc++.h>

using namespace std;
int n, m, q, star;
vector< vector< bool > > desktop;
vector<int> cnt_col;
int main()
{
    cin>>n>>m>>q;
    desktop.resize(n,vector<bool>(m));
    cnt_col.resize(m,0);
    star=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            char tmp;
            cin>>tmp;
            desktop[i][j]=(tmp=='*');
            star+=(tmp=='*');
            cnt_col[j]+=(tmp=='*');
        }
    }
    while (q--){
        int x, y, res=0, init_star;
        cin>>x>>y;
        x--;
        y--;
        desktop[x][y]=!desktop[x][y];
        if (desktop[x][y]){
            cnt_col[y]++;
            star++;
        } else {
            cnt_col[y]--;
            star--;
        }
        //DEBUG
        /*
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cout<<desktop[i][j];
            }
            cout<<endl;
        }
        */
        init_star=star;
        for (int i=0; i<m && star>0; i++){
            //cout << "filling column "<<i << endl;
            if (star>=n){
                res+=n-cnt_col[i];
                star-=n;
                //cout << "res=" << res << endl;
                //cout << "star=" << star << endl;
            } else {
                for (int j=0; j<n && star>0; j++){
                    if (!desktop[j][i]){
                        res++;
                    }
                    star--;
                }
                //cout << "res=" << res << endl;
                //cout << "star=" << star << endl;
                break;
            }
        }
        cout<<res<<endl;
        star=init_star;
    }
    return 0;
}
/*
4 4 1
...*
.**.
*...
...*
3 1
*/
