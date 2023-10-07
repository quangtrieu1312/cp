#include <iostream>

using namespace std;
int n, t, res;
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        int numofdigit=0;
        int tmp=n;
        while (tmp>0){
            if (tmp<10){
                n=tmp;
            }
            numofdigit++;
            tmp/=10;
        }

        res=9*(numofdigit-1)+n;
        cout<<res<<endl;
    }
    return 0;
}
