#include    <stdio.h>
#include    <string.h>
#include    <ctype.h>
#include    <stdlib.h>


static char *input[] = {"5","2","2","3","1"}; 

typedef struct Node
{
    char *value;
    struct Node *next;
}Node;
Node *head = NULL;

//append the node to the end
void append(char *value)
{
    Node *tail = (Node *) malloc (sizeof(Node));
    tail->value = value;
    tail->next = NULL;
    if (head == NULL)
        head = tail;
    else{
        if(head->next == NULL){
            head->next = tail;
        }
        else{
            Node *tmp = head;
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next = tail;
        }
    }
}

void print_list(){
    Node *tmp = head;
    while(tmp != NULL){
        printf("%s ", tmp->value);
        tmp = tmp->next;
    }
}

//delete node 0: list is empty 1: delete the node 2: the node dose not exist
int delNode(char *value){
    if(head == NULL)
        return 0;
    Node *tmp = head;
    if(head->next == NULL){ 
        if (strcmp(head->value, value)==0){
            head = NULL;
            printf("The list is empty now.\n");
            return 1; 
        }
        else 
            return 2;
    }
    while(tmp->next != NULL){
        if(strcmp(tmp->value, value)==0){
            if(tmp->next->next == NULL)
                tmp->next = NULL;
            else
                tmp->next = tmp->next->next;
            return 1;
        }
    }
    return 2;
}

//swap every two nodes
void swap(){
    Node *tmp, *p, *n;
    if (head->next == NULL){
        printf("There is only one node in the list./n");
    }
    p = head;
    n = head->next;
    tmp = n;
    while(n != NULL){
        if (p == head){
            p->next = n->next;
            n->next = p;
            head = n;
        }
        else{
            p->next = n->next;
            n->next = p;
            tmp->next = n;
        }
        tmp = p;
        p = p->next;
        if(p == NULL)
            break;
        n = p->next;
    }
}

//reverse the linked list(0: head is null)
int reverse(){
    Node *h = NULL;
    Node *p = head;
    Node *tmp;
    if(!head)
        return 0;
    while(p != NULL){
        tmp = p;
        p = p->next;
        tmp->next = h;
        h = tmp;
    }
    head = h;
    return 1;
}

//find whether there is a circle in the linked list
void addCircle(){
    Node *tmp = head;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = head;
}
int find_circle(){
    if(!head || !head->next)
        return 0;
    Node *fast, *slow;
    fast = head;
    slow = head;
    while (fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast)
            return 1;
    }
    return 2;
}

//find the middle node, if there are two, use the former
Node *findMiddle(){
    if (!head || !head->next)
        return head;
    Node *fast = head;
    Node *slow = head;
    while(fast){
        if(fast->next == NULL || fast->next->next == NULL)
            return slow;
        fast = fast->next->next;
        slow = slow->next;
    }
}

//2.1 remove the duplicates from an unsorted list
int delDuplicates(){
    if(!head || !head->next)
        return 0;
    Node *p, *q;
    p = head;
    q = head;
    while(p->next != NULL){
        q = p;
        while(q->next != NULL){
            if(strcmp(p->value, q->next->value)==0)
                q->next = q->next->next;
            else
                q = q->next;
        }
        p = p->next;
    }
    return 1;
}

//find the kth to last element of a singly linked list
int kthToLast(int k){

}

int main(int argc, char* argv[]) {
    int i;
    for(i = 0; i< 5; i++){
        append(input[i]);
    }
    print_list();

    //printf("\nAter deleting: ");
    //delNode(input[0]);
    //print_list();

    printf("\nAter swapping: ");
    swap();
    print_list();

    printf("\nAfter reversing: ");
    reverse();
    print_list();

    //addCircle();
    //printf("\nCircle: %d\n", find_circle());
    Node *middle = findMiddle();
    printf("\nThe value of the middle node is: %s\n", middle->value);

    printf("After removing the duplicates: ");
    delDuplicates();
    print_list();   
}