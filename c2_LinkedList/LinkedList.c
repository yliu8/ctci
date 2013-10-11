#include    <stdio.h>
#include    <string.h>
#include    <ctype.h>
#include    <stdlib.h>


static char *input[] = {"5","2","9","3","1"}; 
#define STACKSIZE 100

typedef enum { false, true } bool;

typedef struct Node
{
    char *value;
    struct Node *next;
}Node;

typedef struct Node_int{
    int value;
    struct Node_int *next;
}Node_int;

//stack implementation
typedef struct {
    size_t size;
    char *items[STACKSIZE];
} STACK;
void push(STACK *ps, char *x)
{
    if (ps->size == STACKSIZE) {
        fputs("Error: stack overflow\n", stderr);
        abort();
    } else
        ps->items[ps->size++] = x;
}
char *pop(STACK *ps)
{
    if (ps->size == 0){
        fputs("Error: stack underflow\n", stderr);
        abort();
    } else
        return ps->items[--ps->size];
}

Node *head = NULL;

//append the node to the end
void append(char *value)
{
    Node *tail = (Node *) malloc (sizeof(Node *));
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

Node_int *createNum(int *value, int len){
    Node_int *num = NULL;
    int i;
    for(i = 0; i < len; i++){
        Node_int *tail = (Node_int *) malloc (sizeof(Node_int *));
        tail->value = value[i]; 
        tail->next = NULL;
        printf("\n%d \n", tail->value);
        if(num == NULL){
            num = tail;
        }
        else{
            if(num->next == NULL){
                num->next = tail;
            }
            else{
                Node_int *tmp = num;
                while(tmp->next != NULL){
                    tmp = tmp->next;
                }
                tmp->next = tail;
            }
        }
    }
    return num;
}

void print_list(Node *tmp){
    while(tmp != NULL){
        printf("%s ", tmp->value);
        tmp = tmp->next;
    }
}

void print_NumList(Node_int *tmp){
    while(tmp != NULL){
        printf("%d ", tmp->value);
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

//2.2 find the kth to last element of a singly linked list
//2.2 solution recursively
int nthToLast(Node *head, int k){
    if(head == NULL)
        return 0;
    int i = nthToLast(head->next, k) + 1;
    if(i==k)
        printf("\nThe %dth to last element is: %s\n", k, head->value);
    else return i;
}

//2.2 solution iteratively O(n) time O(1) space
Node *nthToLast1(Node *node, int k){
    if(k<=0)
        return NULL;
    Node *p1 = node;
    Node *p2 = node;
    int i;
    for(i = 0; i< k-1; i++){
        if(p2 == NULL)
            return NULL;
        p2 = p2->next;
    }
    if(p2 == NULL) return NULL;

    while(p2->next != NULL){
        p2 = p2->next;
        p1 = p1->next;
    }
    return p1;
}

//2.3 delete a node in the middle of a singly linked list, given only access to that node.
//solution: copy the value of the next node and then delete the next node
int delMid(Node *n){
    if(n == NULL || n->next ==NULL)
        return 0;
    else{
        Node *next = n->next;
        n->value = next->value;
        n->next = next->next;
        return 1;
    }
}

/*2.4 partitio a linked list arount a value x such that all nodes less than x come before all nodes greater than or equal to x
solution: 1, create two lists, one for nodes < x, one for nodes >= x
          2, merge these lists
below uses four pointers for tracking two linked lists. We can also use two: beforeStart and afterStart. Each time insert the node into start position. O(n) is the same, the second improve the efficiency and we get shorter codes.*/
Node *partitionList(Node *node, char *x){
    if(node == NULL)
        return NULL;
    Node *beforeStart = NULL;
    Node *beforeEnd = NULL;
    Node *afterStart = NULL;
    Node *afterEnd = NULL;
    while(node != NULL){
        Node *next = node->next;
        node->next = NULL;
        if(strcmp(node->value, x) < 0){
            if(beforeStart == NULL){
                beforeStart = node;
                beforeEnd = beforeStart;
            }
            else{
                beforeEnd->next = node;
                beforeEnd = node;
            }
        }
        else{
            if(afterStart == NULL){
                afterStart = node;
                afterEnd = afterStart;
            }
            else{
                afterEnd->next = node;
                afterEnd = node;
            }
        }
        node = next;
    }

    if(beforeStart == NULL)
        return afterStart;

    //Merge two lists
    beforeEnd->next = afterStart;
    return beforeStart;
}

/*2.5 You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order. Write a function that adds the two numbers and returns the sum as a linked list.
*/
Node_int *addNum(Node_int *num1, Node_int *num2, int carry){
    if(num1 == NULL && num2 == NULL)
        return NULL;
    Node_int *result = (Node_int *) malloc(sizeof(Node_int *));
    int value = carry;
    if(num1 != NULL)
        value += num1->value;
    if(num2 != NULL)
        value += num2->value;
    result->value = value % 10;
    Node_int *next = addNum(num1==NULL? NULL:num1->next, num2==NULL? NULL:num2->next, value > 10? 1:0);
    result->next = next;
    return result;
}

//2.5 follow up. digits are stored in forward order.
//reverse first and then use the function above
Node_int *addNum1(Node_int *num1, Node_int *num2, int carry){

}

/*2.6 given a circular linked list, implement an algorithm which returns the node at the beginning of the loop
Solution: Use FastRunner/SlowRunner. the CollisonSpot and LinkedListHead are both k nodes from the start of loop. 
After the first collision, move one pointer to the head while the other stay where it is, and then move both pointers at the same rate. They will collide at the start of the loop.
*/
Node *loopStart(Node *head){
    if(!head || !head->next)
        return NULL;
    Node *fast, *slow;
    fast = head;
    slow = head;
    while (fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }    
    }
    return NULL;
}

/*2.7 implement a function to check if a linked list is a palindrome
Solution1: reverse and compare
Solution2: Iterative approach. The first half is the reverse of the second half. 
           push  the first half in a stack. compare the node to the top of the stack. 
           If we know the size of the list, just push the first half in a stack. (size can be odd or even)
           If the size is not given, using the FastRunner/SlowRunner
Solution3: recursively
*/
int isPalindrome(){
    Node *fast = head;
    Node *slow = head;
    STACK *s = (STACK *) malloc(sizeof(STACK *));

    while(fast && fast->next){
        push(s, slow->value);
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast)
        slow = slow->next;
    while(slow){
        if(strcmp(pop(s), slow->value) != 0)
            return 0;
        slow = slow->next;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    int i;
    for(i = 0; i< 5; i++){
        append(input[i]);
    }
    print_list(head);

    //printf("\nAter deleting: ");
    //delNode(input[0]);
    //print_list(head);

    printf("\nAter swapping: ");
    swap();
    print_list(head);

    printf("\nAfter reversing: ");
    reverse();
    print_list(head);

    //addCircle();
    //printf("\nCircle: %d\n", find_circle());
    Node *middle = findMiddle();
    printf("\nThe value of the middle node is: %s\n", middle->value);

    //2.1
    printf("After removing the duplicates: ");
    delDuplicates();
    print_list(head); 

    //2.2
    nthToLast(head, 3);
    printf("The 3th to last element is: %s\n", nthToLast1(head, 3)->value);

    //2.4
    char *partiton = "4";
    printf("After partitioning the list by %s: ", partiton);
    print_list(partitionList(head, partiton));

    //2.5
    int number1[3] = {7, 1, 6};
    int number2[3] = {5, 9, 2};
    Node_int *num1 = createNum(number1,3);
    Node_int *num2 = createNum(number2,2);
    //print_NumList(num1);
    //print_NumList(num2);
    printf("\nThe result of 2.5 problem is: ");
    print_NumList(addNum(num1, num2, 0));

    //2.6
    //addCircle();
    Node *loop = loopStart(head);
    if(!loop) 
        printf("\nThere is no loop in this linked list!\n");
    else
        printf("\nThe start node of the loop is: %s\n", loop->value);

    //2.7
    if(isPalindrome() == 1)
        printf("\nThis linked list is a palindrome.\n");
    else
        printf("This linked list is not a palindrome.\n");


}