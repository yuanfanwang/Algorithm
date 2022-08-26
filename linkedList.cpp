#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node *prev, *next;
    int num;
    Node(int num_ = -1) : prev(NULL), next(NULL), num(num_) {}
};

Node* nil;

void init() {
    nil = new Node();
    nil->prev = nil;
    nil->next = nil;
}

void printList() {
    Node* cur = nil->next;
    for(; cur != nil; cur = cur->next) {
        cout << cur->num << "->";
    }
    cout << endl;
}

void insert(Node* v, Node* p = nil) {
    v->next = p->next;
    p->next->prev = v;
    p->next = v;
    v->prev = p;
}

void erase(Node *v) {
    if (v==nil) return;
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

int main() {
    int N; cin >> N;
    init();
    vector<int> A(N); for(auto &a : A) cin >> a;
    reverse(A.begin(), A.end());

    for (int i = 0; i < N; ++i) {
        Node* node = new Node(A[i]);
        insert(node);
    }
    printList();
}