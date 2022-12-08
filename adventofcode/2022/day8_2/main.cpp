#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
vector< vector<int> > trees;
vector< vector<int> > scenic_scores;
vector< stack<pii> > c_height, r_height;
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

    scenic_scores.resize(n, vector<int>(m,1));

    for (int i=0; i<n; i++){
        scenic_scores[i][0]=0;
        scenic_scores[i][m-1]=0;
    }
    for (int j=0; j<m; j++){
        scenic_scores[0][j]=0;
        scenic_scores[n-1][j]=0;
    }

    // iterate from top left corner to bottom right corner
    // init maxr, maxc
    r_height.resize(0);
    c_height.resize(0);
    r_height.resize(n, stack<pii>());
    c_height.resize(m, stack<pii>());
    for (int i=1; i<n-1; i++){
        r_height[i].push(pii(trees[i][0],0));
    }
    for (int j=1; j<m-1; j++){
        c_height[j].push(pii(trees[0][j],0));
    }
    for (int i=1; i<n-1; i++){
        for (int j=1; j<m-1; j++){
            int cnt_left, cnt_up;
            // look left
            while (!r_height[i].empty() && r_height[i].top().first < trees[i][j]) {
                r_height[i].pop();
            }
            if (r_height[i].empty()){
                cnt_left=j;
            } else {
                cnt_left=j-r_height[i].top().second;
            }
            // look up
            while (!c_height[j].empty() && c_height[j].top().first < trees[i][j]){
                c_height[j].pop();
            }
            if (c_height[j].empty()){
                cnt_up=i;
            } else {
                cnt_up=i-c_height[j].top().second;
            }
            //cout << "lookleft[" << i << "][" << j << "]=" << cnt_left << endl;
            //cout << "lookup[" << i << "][" << j << "]=" << cnt_up << endl;
            scenic_scores[i][j]=scenic_scores[i][j]*cnt_left*cnt_up;
            r_height[i].push(pii(trees[i][j],j));
            c_height[j].push(pii(trees[i][j],i));
        }
    }
    // iterate from bottom right corner to top left corner
    // init maxr, maxc
    r_height.resize(0);
    c_height.resize(0);
    r_height.resize(n, stack<pii>());
    c_height.resize(m, stack<pii>());
    for (int i=1; i<n-1; i++){
        r_height[i].push(pii(trees[i][m-1],m-1));
    }
    for (int j=1; j<m-1; j++){
        c_height[j].push(pii(trees[n-1][j],n-1));
    }
    for (int i=n-2; i>=1; i--){
        for (int j=m-2; j>=1; j--){

            int cnt_right, cnt_down;
            // look right
            while (!r_height[i].empty() && r_height[i].top().first < trees[i][j]) {
                r_height[i].pop();
            }
            if (r_height[i].empty()){
                cnt_right=m-1-j;
            } else {
                cnt_right=r_height[i].top().second-j;
            }
            // look down
            while (!c_height[j].empty() && c_height[j].top().first < trees[i][j]){
                c_height[j].pop();
            }
            if (c_height[j].empty()){
                cnt_down=n-1-i;
            } else {
                cnt_down=c_height[j].top().second-i;
            }
            //cout << "lookright[" << i << "][" << j << "]=" << cnt_right << endl;
            //cout << "lookdown[" << i << "][" << j << "]=" << cnt_down << endl;
            scenic_scores[i][j]=scenic_scores[i][j]*cnt_right*cnt_down;
            r_height[i].push(pii(trees[i][j],j));
            c_height[j].push(pii(trees[i][j],i));
        }
    }
    //count result
    int res=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            //cout << scenic_scores[i][j] << " ";
            res=max(res,scenic_scores[i][j]);
        }
        //cout<<endl;
    }

    cout<<res<<endl;
    return 0;
}
