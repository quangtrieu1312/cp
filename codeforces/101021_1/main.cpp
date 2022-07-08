#include <bits/stdc++.h>

using namespace std;
string jury;
int x;
void binSearch(int left, int right){
    if (left==right){
        cout<<"! "<<left<<endl;
        return;
    }
    if (left==right-1){
        cout<<right<<endl;
        cin>>jury;
        if(jury=="<"){
            cout<<"! "<<left<<endl;
        } else {
            cout<<"! "<<right<<endl;
        }
        return;
    }
    int mid=(left+right)/2;
    cout<<mid<<endl;
    cin>>jury;
    if (jury=="<"){
        right=mid-1;
    } else {
        left=mid;
    }
    binSearch(left,right);
}
int main()
{
    binSearch(1,1000000);
    return 0;
}
