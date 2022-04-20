#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *next_node;


} node_t;
 
node_t *head = NULL;
node_t *tail = NULL;


void push_head(int );
void push_tail(int);

void print_list();

int main (void) {

    for (int i = 0; i < 20; ++i) {
        push_head(i);
        print_list();
    }

    return 0;
}

void push_head(int data) {
   node_t *new_node = (node_t*) malloc(sizeof(node_t)); 
   
   new_node->data = data;
   new_node->next_node = head;
   head = new_node;

   if(tail == NULL) tail = head;
   
}

void push_tail(int data) {
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = data;
    
    if (head == NULL) {    
        
        head = new_node;
        tail = head;
    
    }else {
        
        tail->next_node = new_node;
        tail = new_node;
    }
   

}

void print_list() {
    node_t *first_node = head;

    while (head != NULL) {
        printf("%d  ", head->data);
        head = head->next_node;
    
    }printf("\n");
    
    head = first_node;


}
