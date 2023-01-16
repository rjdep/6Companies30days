/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode*> mp;
        ListNode* cur = head;
        int sum = 0;
        while(cur){
            sum += cur->val;
            if(sum==0){
                ListNode*  temp = head;
                int s = 0;
                while(temp != cur){
                    s += temp->val;
                    mp.erase(mp.find(s));
                    temp = temp->next;
                }
                head = cur->next;
                cur = cur->next;
                sum = 0;
            }else if(mp.find(sum) != mp.end()){
                ListNode*  temp = mp[sum];
                int s = sum;
                temp = temp->next;
                while(temp != cur){
                    s += temp->val;
                    mp.erase(mp.find(s));
                    temp = temp->next;
                }
                temp = mp[sum];
                temp->next = cur->next;
                cur = cur->next;
            }else{
                mp[sum]=cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
