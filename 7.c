#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    int coef, expo;
    struct node *next;
} node;

/* Insert in descending exponent order */
node* insert(node* head, int coef, int expo) {
    node *p = malloc(sizeof(node)), *q;
    p->coef = coef; 
    p->expo = expo;

    if (!head) { p->next = p; return p; }

    if (expo > head->expo) { 
        p->next = head->next; 
        head->next = p; 
        return p; 
    }

    if (expo == head->expo) { 
        head->coef += coef; 
        free(p); 
        return head; 
    }

    q = head;
    while (q->next != head && expo <= q->next->expo)
        q = q->next;

    if (q->expo == expo) { 
        q->coef += coef; 
        free(p); 
    } else {
        p->next = q->next;
        q->next = p;
    }

    return head;
}

/* Create polynomial */
node* create() {
    int n, c, e;
    node* head = NULL;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    while (n--) {
        scanf("%d %d", &c, &e);
        head = insert(head, c, e);
    }
    return head;
}

/* Add polynomials */
node* add(node* a, node* b) {
    node *res = NULL, *p;

    p = a;
    do { res = insert(res, p->coef, p->expo); p = p->next; } while (p != a);
    
    p = b;
    do { res = insert(res, p->coef, p->expo); p = p->next; } while (p != b);

    return res;
}

/* Evaluate polynomial */
int eval(node* head) {
    int x, sum = 0;
    node* p = head;

    printf("x = ");
    scanf("%d", &x);

    do {
        sum += p->coef * pow(x, p->expo);
        p = p->next;
    } while (p != head);

    return sum;
}

/* Display */
void display(node* head) {
    node* p = head;
    do {
        printf("%dx^%d", p->coef, p->expo);
        p = p->next;
        if (p != head) printf(" + ");
    } while (p != head);
    printf("\n");
}

/* Main */
int main() {
    int ch;
    node *p1, *p2, *p3;

    while (1) {
        printf("\n1.Add 2.Evaluate 3.Exit : ");
        scanf("%d", &ch);

        if (ch == 1) {
            p1 = create();
            p2 = create();
            p3 = add(p1, p2);
            printf("Result: ");
            display(p3);
        }
        else if (ch == 2) {
            p1 = create();
            display(p1);
            printf("Value = %d\n", eval(p1));
        }
        else break;
    }
}
