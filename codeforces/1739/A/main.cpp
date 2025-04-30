#include <iostream>

using namespace std;
int t, n, m;
bool isValid(int x, int y){
    return (0<x && x<=n && 0<y && y<=m);
}
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int main()
{
    cin>>t;
    while (t--){
        cin>>n>>m;
        int resx=1, resy=1;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                int k=0;
                for (; k<8; k++){
                    if (isValid(i+dx[k],j+dy[k])){
                        break;
                    }
                }
                if (k==8){
                    resx=i;
                    resy=j;
                }
            }
        }
        cout<<resx<<" "<<resy<<endl;
    }
    return 0;
}
