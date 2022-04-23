#include <stdio.h> 
#include <stdlib.h> 

typedef struct node_t {
    int data;
    struct node_t *prev_node, *next_node;


}node_t;

node_t *head = NULL;
node_t *tail = NULL;

void print_list_forward();
void print_list_backwards();

void push_head (int);
void push_tail (int);

int main (void) {
    push_head(100);
    push_tail(200);
    push_tail(1000);
    
    printf("Forward: "); 
    print_list_forward();
    printf("Backwards: ");
    print_list_backwards();
    return 0;   
}


void push_head (int data) {
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next_node = head;

    if (head == NULL) {
        head = (node_t*) malloc(sizeof(node_t));
        tail = new_node;
    }

    
    head->prev_node = new_node;
    head = new_node;

}

void push_tail (int data) {
    node_t *new_node = (node_t*) malloc (sizeof(node_t));
    new_node->data = data;
    new_node->prev_node = tail;
    new_node->next_node = NULL;
    
    if (tail == NULL) {
        head = new_node;
    }else {
        tail->next_node = new_node;
    }
    tail = new_node;
}

void print_list_forward() {
    node_t *first_node = head;
    
    while (head != NULL) {
        printf("%d ", head->data); 
        head = head->next_node;
    }
    
    printf("\n");
    head = first_node;
}

void print_list_backwards() {
    node_t *last_node = tail;;

    while (tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev_node;
    }

    printf("\n");
    tail = last_node;
}
