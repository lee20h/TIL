/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    	if(head == nullptr)
    		return head;
    		
        Node* original = head;
        while(original != nullptr) {
        	Node* copyNode = new Node(original->val);
        	copyNode->next = original->next;
        	
        	original->next = copyNode;
        	original = copyNode->next; 
		}
		
		original = head;
		
		while(original != nullptr) {
			if(original->random != nullptr) {
				original->next->random = original->random->next;
			}
			original = original->next->next;
		}
		
		original = head;
		Node* answer = head->next;
		Node* temp = answer;
		while(original != nullptr) {
			original->next = original->next->next;
			if(original->next != nullptr) {
				temp->next = original->next->next;
			}
			original = original->next;
			temp = temp->next;
		}
		return answer;
    }
};
