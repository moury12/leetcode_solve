
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    if(head==nullptr)return nullptr;
      ListNode* firstNode =new ListNode(0);
      firstNode->next =head;
        ListNode* curr = firstNode;
        ListNode* temp = head;
        while(curr->next!=nullptr) {
        if(curr->next->val== val){
            temp = curr->next;
            curr->next =curr->next->next;
            temp->next = nullptr;
            delete temp;
        }else{ curr=curr->next;}
       
        }
        
       return firstNode->next;
    }
};