#include <iostream>
using namespace std;

struct ListNode {
int value;
ListNode* next;
};

ListNode* Process(ListNode* head, unsigned k) {
if (head == nullptr || k == 0) {
return head;
}

ListNode* first = head;
ListNode* second = head;

for (unsigned i = 0; i < k; i++) {
if (first == nullptr) {
return head;
}
first = first->next;
}

if (first == nullptr) {
ListNode* temp = head;
head = head->next;
delete temp;
return head;
}

while (first->next != nullptr) {
first = first->next;
second = second->next;
}

ListNode* temp = second->next;
second->next = temp->next;
delete temp;

return head;
}

int main() {
int n;
cin >> n;

ListNode* head = nullptr;
ListNode* last = nullptr;

for (int i = 0; i < n; i++) {
int x;
cin >> x;

ListNode* p = new ListNode;
p->value = x;
p->next = nullptr;

if (head == nullptr) {
head = p;
last = p;
}
else {
last->next = p;
last = p;
}
}

unsigned k;
cin >> k;

head = Process(head, k);

ListNode* p = head;

while (p != nullptr) {
cout << p->value << " ";
p = p->next;
}

return 0;
}
