#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, res;
vector<ll> v;
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        int group=ceil(sqrt(1.0*n/6.0));
        int triangle_1, triangle_2, triangle_3, intercept_1, intercept_2, intercept_3;
        intercept_1 = 2*(group-1);
        intercept_2 = intercept_1+1;
        intercept_3 = intercept_2+1;

        triangle_1 = intercept_1*2;
        triangle_2 = intercept_2*2;
        triangle_3 = intercept_3*2;

        int ind=1;
//        cout << "-----" << 6*group*group << " " << triangle_1 << " " << triangle_2 << " " << triangle_3 << endl;
        if (6*group*group-triangle_3-triangle_2>=n){
            ind=1;
        } else if (6*group*group-triangle_3>=n){
            ind=2;
        } else {
            ind=3;
        }
//        cout << "ind = " << ind << endl;
        res=3*(group-1)+ind;
        cout<<res<<endl;
    }
    return 0;
}
/*

0 2 4 4 6 8 6 6

*/
