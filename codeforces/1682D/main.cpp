/*
Define:
(*)         = adding a new node, and connect it to the right most node
intersect   = have a few points in common
a few       = not 1, not all
rotate      = rotating a line a.k.a array means array[i+1]=array[i], or array[i-1]=array[i], and this wraps around

Observation:
    0. The circle can be considered as a straight line. Now the line have segments that does not intersect each other.

    1. We can rotate s, or the line, however we want

    2. If we currently have the line for X nodes that does not have any intersection,
        We can do (1), then (*), then that new line with X+1 nodes is a circle without intersection

    3. Say, s="10101"
            => (*) for s ends with "1", makes s append a "0" right before the right most "1"
       Say, s="10100"
            => (*) for s ends with "0", makes s delete that tail "0" and add two "1"s

    4. We can build input string s, from "11", the most basic graph because of (2), and using (3)

Proof for observation (2):
    0. For 1 edge [x, y] we make, we're coloring every nodes inside (x,y) color A, and outside color B
    1. node[x] and node[y] holds both colors
    2. If you already have solution for X nodes, meaning no edges have 2 different colors for 2 ends
    3. When you add a new node to the right most node, that means you either picking the color of the right most node, or both of them make a new color

How to build with observation (4):
    0. temporary label ids for nodes
    1. add up "1"s
        -------- to do so ------------
        do (*): 11 -> 101
        then rotate right: 101 -> 110
        then do (*) again: 110 -> 1111
    2. add up "0"s with the correct position
        -------- to do so ------------
        do (*) at the correct position
        use rotate right/left if needed
    3. once you know the order of the ids (by rotating until the binary string matches the user input),
        you know which one is 1st->n-th, print out the result

Catch for build (3):
    If you're doubling the string, and compare substring of length n, that's around O(n^2) because substring cost O(n)
    Try hashing, or z-func, or kmp
*/
#include <bits/stdc++.h>

using namespace std;
int t, n, c1, c0;
string s;
vector< vector<int> > res;
vector< int > new_order;

struct MyBinLinkedList{
    int val;
    MyBinLinkedList* next;
    MyBinLinkedList* previous;
};
MyBinLinkedList* cur_head;

void rotate_right(int x_times){
    if (cur_head==nullptr) return;
    for (int i=0; i<x_times; i++){
        cur_head=cur_head->previous;
    }
}
void rotate_left(int x_times){
    if (cur_head==nullptr) return;
    for (int i=0; i<x_times; i++){
        cur_head=cur_head->next;
    }
}
void connect_new_node_to_tail(int val){
    if (cur_head == nullptr){
        //list size of 0
        cur_head = (MyBinLinkedList*) malloc(sizeof(MyBinLinkedList));
        cur_head->val = val;
        cur_head->next = cur_head;
        cur_head->previous = cur_head;
        return;
    }

    MyBinLinkedList* cur_tail = cur_head->previous;
    MyBinLinkedList* new_tail = (MyBinLinkedList*) malloc(sizeof(MyBinLinkedList));
    new_tail->val = val;
    new_tail->next = cur_head;
    new_tail->previous = cur_tail;
    cur_head->previous = new_tail;
    cur_tail->next = new_tail;

    res[cur_tail->val].push_back(new_tail->val);
}
void remove_head(){
    if (cur_head == nullptr){
        return;
    }
    if (cur_head->next == cur_head){
        free(cur_head);
        cur_head=nullptr;
        return;
    }
    MyBinLinkedList* cur_next=cur_head->next;
    MyBinLinkedList* cur_tail=cur_head->previous;
    cur_tail->next = cur_next;
    cur_next->previous = cur_tail;
    free(cur_head);
    cur_head=cur_next;
}

void free_list(){
    while (cur_head!=nullptr){
        remove_head();
    }
}

vector<int> z_function(string x) {
    int n = (int) x.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && x[z[i]] == x[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while (t--){
        cin>>n>>s;
        res.resize(0);
        res.resize(n, vector<int>(0));
        free_list();
        new_order.resize(0);
        new_order.resize(n);
        c1=0;
        c0=0;
        for (int i=0; i<n; i++){
            c1+=(s[i]=='1');
            c0+=(s[i]=='0');
        }

        if (c1<2 || (c1&1)){
            cout<<"NO"<<endl;
            continue;
        }

        // init bin="11";
        int cur_size=0;

        connect_new_node_to_tail(cur_size);
        cur_size++;
        connect_new_node_to_tail(cur_size);
        cur_size++;
        //add just enough 0s to prepare for 1s
        for (int i=0; i<(c1-2)/2; i++){
            connect_new_node_to_tail(cur_size);
            cur_size++;
        }
        //rotate right so it ends with 0
        //in case there is no 0, it ends with 1
        if ((c1-2)/2>0)rotate_right(1);
        //start generating 1s
        for (int i=0; i<(c1-2)/2; i++){
            connect_new_node_to_tail(cur_size);
            cur_size++;
            rotate_right(2);
        }

        //now we only have at most 1 "0"
        //start adding 0 at the correct position
        //must ensure tail->val=1 so it's actually adding 0s
        //to do so, we want the last 2 bits to be "01" since it can add, or rotate left
        //as many time as we want
        vector<int> d;
        d.resize(n,0);
        for (int i=0; i<n; i++){
            for (int j=0; j<res[i].size(); j++){
                d[i]++;
                d[res[i][j]]++;
            }
        }
        if (n&1){
            int c=0;
            while (d[cur_head->previous->previous->val]&1!=0 && c<=cur_size){
                //corner case: there is no 0 in the current binary string
                c++;
                rotate_left(1);
            }
        }

        string double_s=s+s;
        int offset=0;
        while (double_s[offset]=='0') offset++;
        for (int i=offset; i<offset+n; i++){
            if (double_s[i]=='0'){
                connect_new_node_to_tail(cur_size);
                cur_size++;
            } else {
                rotate_left(1);
            }
        }

        string cur_s="";
        d.resize(0);
        d.resize(n,0);
        for (int i=0; i<n; i++){
            for (int j=0; j<res[i].size(); j++){
                d[i]++;
                d[res[i][j]]++;
            }
        }

        MyBinLinkedList* it = cur_head;
        it = cur_head;
        if (d[it->val]&1){
            cur_s+='1';
        } else {
            cur_s+='0';
        }
        it=it->next;
        while (it!=cur_head){
            if (d[it->val]&1){
                cur_s+='1';
            } else {
                cur_s+='0';
            }
            it=it->next;
        }

        offset=0;
        //use z-func
        vector<int> z = z_function(cur_s+"*"+double_s);
        for (int i=cur_s.size()+1; i<z.size(); i++){
            if (z[i]==s.size()){
                offset=i-s.size()-1;
                break;
            }
        }

        rotate_right(offset);
        int cnt=1;
        it=cur_head;
        new_order[it->val]=cnt++;
        it=it->next;
        while (it!=cur_head){
            new_order[it->val]=cnt++;
            it=it->next;
        }
        cout<<"YES"<<endl;
        for (int i=0; i<n; i++){
            for (int j=0; j<res[i].size(); j++){
                cout<<new_order[i]<<" "<<new_order[res[i][j]]<<endl;
            }
        }
        free_list();
    }
    return 0;
}

/*
5
4
0110
2
10
6
110110
4
1010
3
110

*/
