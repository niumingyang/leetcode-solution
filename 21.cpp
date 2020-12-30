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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode ret;
        ListNode* now = &ret;
        while (l1 != nullptr && l2 != nullptr){
            now->next = new ListNode;
            now = now->next;
            if (l1->val < l2->val){
                now->val = l1->val;
                l1 = l1->next;
            }
            else {
                now->val = l2->val;
                l2 = l2->next;
            }
        }
        if (l1 == nullptr && l2 == nullptr)
            return ret.next;
        else if (l1 == nullptr){
            while(l2 != nullptr){
                now->next = new ListNode;
                now = now->next;
                now->val = l2->val;
                l2 = l2->next;
            }
        }
        else{
            while(l1 != nullptr){
                now->next = new ListNode;
                now = now->next;
                now->val = l1->val;
                l1 = l1->next;
            }
        }
        return ret.next;
    }
};

int main(){
    return 0;
}