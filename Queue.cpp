// // Using linked list to implement queue

// #include <iostream>
// #include <vector>
// using namespace std;

// class Node {
//     public:
//     int data;
//     Node* next;

//     Node(int val) {
//         data = val;
//         next = NULL;
//     }
// };
// class Queue {
//     Node* head;
//     Node* tail;

//     public:
//     Queue() {
//         head = NULL;
//         tail = NULL;
//     }

//     void push(int data) {
//         Node* newNode = new Node(data);

//         if(empty()) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     void pop() {
//         if(head == NULL) {
//             cout << "Queue is empty" << endl;
//             return;
//         }

//         Node* toDelete = head;
//         head = head->next;
//         delete toDelete;
//     }

//     int front() {
//         return head->data;
//     }

//     bool empty() {
//         return head == NULL;
//     }
// };    

// int main() {
//     Queue q;
//     q.push(1);  
//     q.push(2);
//     q.push(3);
//     q.push(4);

//     while(!q.empty()) {
//         cout << q.front() << " ";
//         q.pop();
//     }

//     cout << endl;

//     return 0;
// }






// Using queue STL

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    dq.push_front(4);

    while(!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }

    cout << endl;

    return 0;
}