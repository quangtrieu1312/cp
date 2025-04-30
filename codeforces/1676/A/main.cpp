#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, first_half, second_half;
    string num;
    cin>>t;
    while (t--){
        cin>>num;
        first_half=0;
        second_half=0;
        for (int i=0; i<6; i++){
            if (i<=2){
                first_half+=num[i]-'0';
            } else {
                second_half+=num[i]-'0';
            }
        }
        if (first_half==second_half){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
    return 0;
}
