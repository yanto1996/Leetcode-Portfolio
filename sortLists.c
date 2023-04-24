/**
 *Yan To
 *Sort Lists
 *https://leetcode.com/problems/sort-list/
 */


/**
 *  Definition for singly-linked list.
 *	struct ListNode {
 *	int val;
 * 	struct ListNode *next;
 * };
 */




// helper function that finds the middle node of the LL
// also known as floyd's slow fast pointer algorithm
struct ListNode* middle(struct ListNode* head){
    if (head == NULL || head->next == NULL){
        return NULL;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    // while the fast pointer next or next next is not out of bounds
    // ensures we get the middle node each time
    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// helper function that merges each sub node of the ll and sorts it in order
struct ListNode* merge(struct ListNode* left, struct ListNode* right, struct ListNode* temp){

    // create an iterator that points to the head of empty temp LL
    struct ListNode* itr = temp;

    // sorts the sub LL in order
    // store the beginning of LL starting from the second node to have the head be a dummy node for when head = NULL
    while (left != NULL && right != NULL){
        if (left->val < right->val){
            itr->next = left;
            left = left->next;
        }

        else{
            itr->next = right;
            right = right->next;
        }
        itr = itr->next;
    }

    if (left == NULL){
        itr->next = right;
    }

    if (right == NULL){
        itr->next = left;
    }

    return temp->next;
}

// recursive function that breaks the ll into smaller sub problems and merges it back into a sorted LL
struct ListNode* sortList(struct ListNode* head){
    if (head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode* l = head;
    struct ListNode* m = middle(head);
    struct ListNode* r = m->next;
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    // disconnect the left side of the LL, this way we can seperate into smaller LLs
    m->next = NULL;

    l = sortList(l);
    r = sortList(r);
    return merge(l, r, temp);
}
