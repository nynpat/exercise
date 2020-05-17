/**
 * @author  : Nayan Patel
 * @date    : 16th May 2020
 * @brief   : Given a singly linked list, group all odd nodes together followed by the even nodes. 
 *            Please note here we are talking about the node number and not the value in the nodes.
 *            You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 *            for more info use https://leetcode.com/
 */
#include <stdlib.h>
#include <iostream>

using namespace std;

// Definition for singly-linked list.
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
        ListNode *trav = head;
        ListNode *evenTrav = NULL;
        ListNode *evenHead = NULL;
        if(head) {
            while(trav->next) {
                if(evenHead == NULL) {
                    evenHead = trav->next; // take the first even element and make it as head
                    evenTrav = evenHead; // update the eventrav
                } else {
                    evenTrav->next = trav->next; // remove the even node from the list
                    evenTrav = evenTrav->next; // update the eventrav
                }
                trav->next = trav->next->next; // Joint two odd nodes
                evenTrav->next = NULL; // Make the next of last even element null

                if(trav->next == NULL)
                    break;

                trav = trav->next; // update to the next odd node
            }
            trav->next = evenHead; // append the evennumber list to odd ones
        }
        return head;
    }

    ListNode *append(ListNode *head, int value) {
        ListNode *tmp = new ListNode(value, NULL);
        ListNode *trav = head;
        if(head == NULL) {
            head = tmp;
        } else {
            while(trav->next != NULL) {
                trav = trav->next;
            }
            trav->next = tmp;
        }
        return head;
    }

    ListNode *print(ListNode *head) {
        ListNode *trav = head;
        while(trav != NULL) {
            cout << "-> " << trav->val << "\t";
            trav = trav->next;
        }
        cout << endl;
        return head;
    }
};



int main(){
    class Solution *mySolution = new Solution();
    ListNode *head;
    head = mySolution->append(head, 10);
    head = mySolution->append(head, 20);
    head = mySolution->append(head, 30);
    head = mySolution->append(head, 40);
    head = mySolution->append(head, 50);
    // head = mySolution->append(head, 60);
    mySolution->print(head);
    head = mySolution->oddEvenList(head);
    mySolution->print(head);

    delete(mySolution);
}