#include <bits/stdc++.h>

using namespace std;

int T, N;
string S;
struct Node {
    char value;
    Node* next;
    Node* previous;
};
Node *head, *tail;

void freeList() {
    Node *it=head;
    Node *nxt;
    while (it!=NULL) {
        nxt=it->next;
        free(it);
        it=nxt;
    }
    head=NULL;
    tail=NULL;
}

void appendNode(char value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->previous = NULL;
    tmp->next = NULL;
    if (head == NULL) {
        head = tmp;
        tail = head;
    } else {
        tmp->previous = tail;
        tail->next = tmp;
        tail = tmp;
    }
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int testCase=1; testCase<=T; testCase++) {
        cin>>N;
        cin>>S;
        for (int i=0; i<N; i++) {
            appendNode(S[i]);
        }
        Node* it = head;
        while (it != NULL) {
            Node* nxt = it->next;
            if (nxt != NULL && (it->value == 'A' && nxt->value == 'B')) {
                Node* prv = it->previous;
                Node* skip = nxt->next;
                if (prv != NULL) {
                    prv->next = skip;
                }
                if (skip != NULL) {
                    skip->previous = prv;
                }
                if (it==head) {
                    head = skip;
                    free(it);
                    free(nxt);
                    it = skip;
                    continue;
                }
                if (nxt==tail) {
                    tail = prv;
                }
                free(it);
                free(nxt);
                it=prv;
            } else {
                it = nxt;
            }
        }
        cout<<"Case #"<<testCase<<": ";
        if (tail!=NULL && tail->value == 'A') {
            cout<<"Alice"<<endl;
        } else {
            cout<<"Bob"<<endl;
        }
        freeList();
    }
    return 0;
}
