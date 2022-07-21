/*
Observation:
    1. We can rotate s however we want

    2. If we already have a tree, and we construct s, say, s="10101"
        - action (*) = adding a new node, and connect it to the right most node
            => (*) for s ends with "1", makes s append a "0" right before the right most "1"
            => (*) for s ends with "0",makes s delete that tail "0" and add two "1"s

    3. We can build input string s, from "11", the most basic graph

How to build:
    1. add up "1"s
        -------- to do so ------------
        do (*): 11 -> 101
        then rotate right: 101 -> 110
        then do (*) again: 110 -> 1111
    2. add up "0"s with the correct position
        -------- to do so ------------
        do (*) at the correct position
        use rotate right/left if needed
*/
#include <bits/stdc++.h>

using namespace std;
int t, n, c1, c0;
string s;
vector< vector<int> > res;
bool isDebug=false;
struct MyBinLinkedList{
    int val;
    MyBinLinkedList* next;
    MyBinLinkedList* previous;
};
MyBinLinkedList* cur_head;

void print_list(string message=""){
    if (!isDebug) return;
    cout<<"........ PRINT LIST ..........."<<message<<endl;
    if (cur_head==nullptr){
        return;
    }
    cout<<cur_head->val<<" ";
    MyBinLinkedList* it=cur_head->next;
    while (it!=cur_head){
        cout<<it->val<<" ";
        it=it->next;
    }
    cout<<endl;
}

void rotate_right(int x_times){
    for (int i=0; i<x_times; i++){
        cur_head=cur_head->previous;
    }
    print_list("ROTATING RIGHT");
}
void rotate_left(int x_times){
    for (int i=0; i<x_times; i++){
        cur_head=cur_head->next;
    }
    print_list("ROTATING LEFT");
}
void connect_new_node_to_tail(int val){
    if (cur_head == nullptr){
        //list size of 0
        cur_head = (MyBinLinkedList*) malloc(sizeof(MyBinLinkedList));
        cur_head->val = val;
        cur_head->next = cur_head;
        cur_head->previous = cur_head;
        print_list("CREATE HEAD");
        return;
    }

    MyBinLinkedList* cur_tail = cur_head->previous;
    MyBinLinkedList* new_tail = (MyBinLinkedList*) malloc(sizeof(MyBinLinkedList));
    new_tail->val = val;
    new_tail->next = cur_head;
    new_tail->previous = cur_tail;
    cur_head->previous = new_tail;
    cur_tail->next = new_tail;

    print_list("NEW NODE");
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
    for (int i=0; i<n; i++){
        remove_head();
    }
}

int main()
{
    cin>>t;
    while (t--){
        cin>>n>>s;
        res.resize(0);
        res.resize(n, vector<int>(0));
        free_list();
        c1=0;
        c0=0;
        for (int i=0; i<n; i++){
            c1+=(s[i]=='1');
            c0+=(s[i]=='0');
        }

        if (c1<2 || (n&1 != c0&1)){
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
        rotate_right(1);
        //start generating 1s
        for (int i=0; i<(c1-2)/2; i++){
            connect_new_node_to_tail(cur_size);
            cur_size++;
            rotate_right(2);
        }

        //now add 0 at the correct position
        //must ensure tail->val=1 so it's actually adding 0s
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
        for (int i=0; i<n; i++){
            cur_s+=(char)('0'+res[i].size()&1);
        }

        cout<<"YES"<<endl;
        for (int i=0; i<n; i++){
            for (int j=0; j<res[i].size(); j++){
                cout<<i+1<<" "<<res[i][j]+1<<endl;
            }
        }
    }
    return 0;
}

/*
3
4
0110
2
10
6
110110

1
6
110110
*/
