#include <bits/stdc++.h>
#define Nmax 1003
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;

int n;
vector< vector<int> > cnt;
vector< pic > right_most_pos;

string secret_string="qiibspddrqbxfetjzpysuwtznhcwqzqijffebsrhktjbzysgvbvtquudyhjnsmwzcteifzkdqpoyvfbojcpbmlutzqdkoensyigrzxaifvbjaeknweabnuucwcubkizinlnbftyykqcuznqwygqfrydckqbgbfseyrkuubzoddawrdxbirxbljhyhfltljpcvxtvkvdjqnypuhbbokbwnvrjpeptdspxnorhxnkxhmumqkbamnqkpmevlwuvwatidxcjbvpiwyduqqvcqqojasbvffjoygwulmqwujyrjskqirziurjyebfqnobvjkzmjcrmwbgkyqxzxhnvfdennzoehwlyjrnqdzcbzukhwmbibrhxvlkkyxnvdystwznbvtqdmmdvbkvafdczgfxuvxrgnvnsfyxadwzjpshyvarqifrqdnwdvjcjncbxyaapikfcvhpkfwgyopsrotwibbeidmnbvirjzzbaseghyuvnsqiibspddrqbxfetjzpysuwtznhcwqzqijffebsrhktjbzysgvbvtquudyhjnsdjnczcwgaigncsspmwzcteifzkdqpoyvfbojcpbmlutzqdkoensyigrzxaifvbjaeknwbnuucwcubkizinlnbftyykqcuznqwygqfrydckqgbfseyrkuuboddawrdxbirxbljhyhfltljpcvxtvkvdjqnypuhbbokbwnvrjpeptdspxnorhxnkxhmumqkbamnqkpmevlwuvwatidxcjbvpiwyduqqvcqqojasbvffjoygwulmqwujyrjskqirziurjyebfqnobvjkzmjcrmwbgkyqxzxhnvfdennzoehwlyjrnqdzcbzukhwmbibrhxvlkkyxnvdystwznbvtqdmmdvbkvafdczgfxuvxrgnvnsfyxadwzjpshyvarqifrqdnwdvjcjncbxyaapikfcvhpkfwgyopsrotwibbeidmnbvirjzzbaseghyuvns";
bool use_interal_jury=false;
int q1_cnt=26;
int q2_cnt=6000;

char answer_query_1(int i){
    i--;
    if (i<0 || i>=secret_string.length()) return 0;
    if (q1_cnt==0) { cout<<"!!!!!!!!!!!!! Used up q1 limit !!!!!!!!!!!! Exceeding "<<-q1_cnt<<endl;}
    return secret_string[i];
}

int answer_query_2(int left, int right){
    left--;
    right--;
    if (left>right || right<0 || left>=secret_string.length()) return 0;
    int query_cnt[26];
    memset(query_cnt,0,sizeof(query_cnt));
    for (int i=left; i<=right; i++){
        query_cnt[secret_string[i]-'a']++;
    }
    int ans=0;
    for (int i=0; i<26; i++){
        ans += ( query_cnt[i]>0 );
    }
    if (q2_cnt<=0){ cout<<"!!!!!!! Used up q2 limit !!!!!!!!! Exceeding "<<-q2_cnt+1<<endl;}
    q2_cnt--;
    return ans;
}
// in order to just do 1 q1 => n q2 to preprocess (aka character grouping)
// if every group size = 1 => waste n q2 to preprocess
// aaaa bbbb ccccccc
// abc
// q2 [l, r] = 1 -> r++
// q2 [l, r] = 2 -> group(l,r-1) ; l=r; // after the for loop, we'll need to add the last (l,r-1) value to the group
void update_right_most_pos(char letter, int val){
    int ind;
    for (int i=0; i<right_most_pos.size(); i++){
        if (right_most_pos[i].second==letter){
            right_most_pos[i].first=val;
            ind=i;
            break;
        }
    }
    while (ind>0 && right_most_pos[ind-1].first>right_most_pos[ind].first){
        swap(right_most_pos[ind-1],right_most_pos[ind]);
        ind--;
    }
    while (ind<right_most_pos.size()-1 && right_most_pos[ind].first>right_most_pos[ind+1].first){
        swap(right_most_pos[ind],right_most_pos[ind+1]);
        ind++;
    }
}

char query_1(int i){
    char q1;
    cout<<"? 1 "<<i<<endl;
    q1_cnt--;
    if (use_interal_jury){
        q1=answer_query_1(i);
        cout<<"Using internal jury: "<<q1<<endl;
    } else {
        cin>>q1;
    }
    if (q1=='0'){
        exit(0);
    }
    return q1;
}

int count_diff_char(int left, int right){
    if (left>right){
        return -1;
    }
    int s=0;
    for (int i=0; i<26; i++){
        if (left==0){
            s+=( cnt[i][right]!=0 );
        } else {
            s+=( (cnt[i][right]-cnt[i][left-1])!=0 );
        }
    }
    return s;
}

int query_2(int left, int right){
    int q2;
    cout<<"? 2 "<<left<<" "<<right<<endl;
    if (use_interal_jury){
        q2=answer_query_2(left,right);
        cout<<"Using internal jury: "<<q2<<endl;
    } else {
        cin>>q2;
    }
    if (q2==0){
        exit(0);
    }
    return q2;
}

void binSearch(int left, int right, int i, char &ans){
    if (left>right || right<0 || left>25) return;
    while (left<right && right_most_pos[left].first<0){
        left++;
    }
    int q2, manual_q2;
    pic ind_letter;
    if (left==right){
        ind_letter=right_most_pos[right];
        manual_q2=count_diff_char(ind_letter.first,i-1);
        q2=query_2(ind_letter.first,i);
        if (manual_q2>=q2){
            ans=ind_letter.second;
        }
        return;
    }
    char curAns;
    int mid=(left+right)/2;
    ind_letter=right_most_pos[mid];
    manual_q2=count_diff_char(ind_letter.first,i-1);
    q2=query_2(ind_letter.first,i);
    if (manual_q2<q2){
        //diff [mid,i-1] < diff [mid,i]
        //=> we must have obmit s[i] somewhere before mid
        right=mid-1;
    } else {
        ans=ind_letter.second;
        left=mid+1;
    }
    binSearch(left,right,i,ans);
}

int main()
{
    if (use_interal_jury){
        n=secret_string.length();
        cout<<"Using interal jury: n="<<n<<endl;
        cout<<secret_string<<endl;
        cout<<"............................"<<endl;
    } else {
        cin>>n;
    }

    cnt.resize(0);

    int l=1, r=2;
    char q1;
    int q2;
    right_most_pos.resize(26);
    for (int i=0; i<right_most_pos.size(); i++){
        right_most_pos[i].first=-1;
        right_most_pos[i].second=(char)('a'+i);
    }
    cnt.resize(26, vector<int>(n+1,0));

    string res="";
    q1=query_1(1);
    res+=q1;
    cnt[q1-'a'][1]++;
    update_right_most_pos(q1,1);



    for (int i=2; i<=n; i++){
        q2=query_2(1,i);
        for (int j=0; j<26; j++){
            cnt[j][i] = cnt[j][i-1];
        }
        if (count_diff_char(1,i-1)<q2){
            //from eq_ranges[0] to eq_ranges[i-1] there is X diff chars
            //from eq_ranges[0] to eq_ranges[i] there is X+1 diff chars
            //=> new char encountered
            q1=query_1(i);
            res+=q1;
            cnt[q1-'a'][i]++;
            update_right_most_pos(q1,i);
        } else {
            //we've seen this char before
            //=>bin search to see where did we see it
            char c='.';
            binSearch(0,25,i,c);
            res+=c;
            cnt[c-'a'][i]++;
            update_right_most_pos(c,i);
        }
    }
    cout<<"! "<<res<<endl;
    if (use_interal_jury){
        if (res!=secret_string){
            cout<<"WRONG ANSWER!"<<endl;
            cout<<"ans vs expect"<<endl;
            cout<<res<<endl;
            cout<<secret_string<<endl;
        } else {
            cout<<"RIGHT!!"<<endl;
        }
    }
    return 0;
}
// takes nlog(26)
