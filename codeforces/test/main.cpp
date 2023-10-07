#include <bits/stdc++.h>

using namespace std;

bool containCharsInRightOrder(string s1, string s2){
    bool ans = false;

    /*
     - String1 = "abcde";
     - String2 = "ab"
    => true

    - String1 = "abcde";
    - String2 = "ba";
    => false

    - String1 = "aaabcde";
    - String2 = "aab";
    => true
    O(len(s1)+len(s2))
    ind_1=0
    ind_2=0
    */

    int ind_1=0, ind_2=0;
    while (ind_1<s1.length() && ind_2<s2.length()){
        //b == b
        //ind_1 4
        //ind_2 3
        if (s1[ind_1]==s2[ind_2]){
            ind_2++;
        }
        ind_1++;
    }
    if (ind_2==s2.length()){
        ans=true;
    }

    return ans;
}

int main()
{
    cout<<containCharsInRightOrder("abcde","ab")<<endl; //true
    cout<<containCharsInRightOrder("abcde","ba")<<endl; //false
    cout<<containCharsInRightOrder("abcde","ace")<<endl; //true
    cout<<containCharsInRightOrder("abcde","adb")<<endl; //false

    cout<<containCharsInRightOrder("uhokakpaaccbbbcde","aab")<<endl; //true
    return 0;
}
