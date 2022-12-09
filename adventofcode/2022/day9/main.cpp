#include <bits/stdc++.h>

using namespace std;
vector< vector<bool> > matrix;
vector<string> instructions;
int res, n, m, s_r, s_c, t_r, t_c, h_r, h_c;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int total_u=0, total_d=0, total_r=0, total_l=0;
    string line;
    while (getline(cin,line) && !line.empty()){
        instructions.push_back(line);
        int dist=atoi(line.substr(2).c_str());
        switch (line[0]){
        case 'U':
            total_u+=dist;
            break;
        case 'D':
            total_d+=dist;
            break;
        case 'L':
            total_l+=dist;
            break;
        case 'R':
            total_r+=dist;
            break;
        }
    }
    n=total_u+total_d+10;
    m=total_l+total_r+10;
    matrix.resize(n,vector<bool>(m,false));
    s_r=total_u+5;
    s_c=total_l+5;

    h_r=s_r;
    h_c=s_c;
    t_r=s_r;
    t_c=s_c;
    matrix[t_r][t_c]=true;
    for (int i=0; i<instructions.size(); i++){
        int dist=atoi(instructions[i].substr(2).c_str());
        switch (instructions[i][0]){
        case 'U':
            while (dist--){
                h_r--;
                if (abs(h_r-t_r)>=2){
                    t_r=h_r+1;
                    t_c=h_c;
                }
                matrix[t_r][t_c]=true;
            }
            break;
        case 'D':
            while (dist--){
                h_r++;
                if (abs(h_r-t_r)>=2){
                    t_r=h_r-1;
                    t_c=h_c;
                }
                matrix[t_r][t_c]=true;
            }
            break;
        case 'L':
            while (dist--){
                h_c--;
                if (abs(h_c-t_c)>=2){
                    t_c=h_c+1;
                    t_r=h_r;
                }
                matrix[t_r][t_c]=true;
            }
            break;
        case 'R':
            while (dist--){
                h_c++;
                if (abs(h_c-t_c)>=2){
                    t_c=h_c-1;
                    t_r=h_r;
                }
                matrix[t_r][t_c]=true;
            }
            break;
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (matrix[i][j]){
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
