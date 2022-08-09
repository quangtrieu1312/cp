#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int T, R, C, K;
vector< vector<char> > G;
vector< vector<int> > cnt_slot;
ll res=0;
int count_slot(int start_r, int start_c, int end_r, int end_c){
    int ans=0;
    if (start_r>end_r){
        swap(start_r,end_r);
    }
    if (start_c>end_c){
        swap(start_c,end_c);
    }
    if (start_r>0 && start_c>0){
        ans= cnt_slot[end_r][end_c]-cnt_slot[start_r-1][end_c]-cnt_slot[end_r][start_c-1]+cnt_slot[start_r-1][start_c-1];
    } else if (start_r==0 && start_c==0){
        ans= cnt_slot[end_r][end_c];
    } else if (start_r==0){
        ans= cnt_slot[end_r][end_c]-cnt_slot[end_r][start_c-1];
    } else {
        ans= cnt_slot[end_r][end_c]-cnt_slot[start_r-1][end_c];
    }
    //cout<<"count slot from ("<<start_r<<", "<<start_c<<") to ("<<end_r<<", "<<end_c<<") = "<<ans<<endl;
    return ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        cin>>R>>C>>K;
        G.resize(0);
        G.resize(R+2,vector<char>(C+2));
        for (int i=1; i<=R; i++){
            for (int j=1; j<=C; j++){
                cin>>G[i][j];
            }
        }
        for (int i=0; i<=R+1; i++){
            G[i][0]='.';
            G[i][C+1]='.';
        }
        for (int j=0; j<=C+1; j++){
            G[0][j]='.';
            G[R+1][j]='.';
        }
        cnt_slot.resize(0);
        cnt_slot.resize(R+2,vector<int>(C+2,0));
        for (int i=0; i<R+2; i++){
            for (int j=0; j<C+2; j++){
                if (i==0 && j==0){
                    cnt_slot[i][j]=(G[i][j]=='.');
                } else if (i==0){
                    cnt_slot[i][j]=cnt_slot[i][j-1]+(G[i][j]=='.');
                } else if (j==0){
                    cnt_slot[i][j]=cnt_slot[i-1][j]+(G[i][j]=='.');
                } else {
                    cnt_slot[i][j]=cnt_slot[i-1][j]+cnt_slot[i][j-1]-cnt_slot[i-1][j-1]+(G[i][j]=='.');
                }
                //cout<<cnt_slot[i][j]<<" ";
            }
            //cout<<endl;
        }
        //init res val = remove all cars in K
        res=C-count_slot(K,1,K,C);
        //we want to move up/down first, then clear row K
        for (int i=1; i<=R-K+1; i++){
            ll tmp=i;
            for (int j=1; j<=C; j++){
                //debugcnt=count_slot(K-1,j,1,j);
                if (count_slot(K+i,j,1,j)<=i || G[K+i][j]=='X'){
                    //after moving up "i" times, this G[K][j] = 'X'
                    //thus, we need to remove it
                    tmp++;
                }
            }
            //cout<<"Moving up "<<i<<" times="<<tmp<<endl;
            res=min(res,tmp);
        }
        for (int i=1; i<=K; i++){
            ll tmp=i;
            for (int j=1; j<=C; j++){
                //debugcnt=count_slot(K+1,j,R,j);
                if (count_slot(K-i,j,R,j)<=i || G[K-i][j]=='X'){
                    //after moving down "i" times, this G[K][j] = 'X'
                    //thus, we need to remove it
                    tmp++;
                }
            }
            //cout<<"Moving down "<<i<<" times="<<tmp<<endl;
            res=min(res,tmp);
        }
        cout<<"Case #"<<casenum<<": "<<res<<endl;
    }
    return 0;
}
