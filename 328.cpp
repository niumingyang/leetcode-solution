#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        int cnt = 1;
        ListNode* count = head;
        while (count->next != nullptr){
            count = count->next;
            cnt++;
        }
        if (cnt%2 == 1) count->next = new ListNode();
        ListNode* last = head;
        ListNode* now = head->next;
        ListNode* tail = head;
        while (tail->next->next != nullptr) tail = tail->next;
        ListNode* critical = tail;
        while (last != critical){
            last->next = now->next;
            now->next = tail->next;
            tail->next = now;
            tail = tail->next;
            last = last->next;
            now = last->next;
        }
        if (cnt%2 == 1) tail->next = nullptr;
        return head;
    }
};

int main(){
    return 0;
}