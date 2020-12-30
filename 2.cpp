#include <iostream>
#include <vector>
using namespace std;

/*
链表操作：不能用即将消亡对象的地址赋值给指针，要用new在堆区分配空间
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode ret;
        ListNode* now = &ret;
        while (l1 != nullptr && l2 != nullptr){
            ListNode *temp = new ListNode((l1->val+l2->val+carry)%10);
            carry = (l1->val+l2->val+carry)/10;
            now->next = temp;
            now = now->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == nullptr && l2 == nullptr){
            if (carry > 0){
                ListNode* temp0 = new ListNode(carry);
                now->next = temp0;
            }
        }
        else if (l1 == nullptr){
            while (l2 != nullptr){
                ListNode* temp1 = new ListNode((l2->val+carry)%10);
                carry = (l2->val+carry)/10;
                now->next = temp1;
                now = now->next;
                l2 = l2->next;
            }
            if (carry > 0){
                ListNode* temp11 = new ListNode(carry);
                now->next = temp11;
            }
        }
        else if (l2 == nullptr){
            while (l1 != nullptr){
                ListNode* temp2 = new ListNode((l1->val+carry)%10);
                carry = (l1->val+carry)/10;
                now->next = temp2;
                now = now->next;
                l1 = l1->next;
            }
            if (carry > 0){
                ListNode* temp22 = new ListNode(carry);
                now->next = temp22;
            }
        }
        return ret.next;
    }
};

int main(){
    ListNode a7(9);
    ListNode a6(9, &a7);
    ListNode a5(9, &a6);
    ListNode a4(9, &a5);
    ListNode a3(9, &a4);
    ListNode a2(9, &a3);
    ListNode a1(9, &a2);

    ListNode b4(9);
    ListNode b3(9, &b4);
    ListNode b2(9, &b3);
    ListNode b1(9, &b2);

    Solution s;
    ListNode* res = s.addTwoNumbers(&a1, &b1);
    while (res != nullptr){
        cout << res->val << ' ';
        res = res->next;
    }
    return 0;
}