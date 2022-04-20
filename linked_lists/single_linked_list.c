#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *next_node;


} node_t;
 
node_t *head = NULL;
node_t *tail = NULL;


void push_head(int);
void push_tail(int);

void print_list();
void get_by_value(node_t **, int);
void get_by_index (node_t **, int);

int main (void) {
    node_t *value = NULL;
    for (int i = 0; i < 30; ++i) {
        push_head(i);
    }
    print_list();
    get_by_index(&value, 30);
    
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

void get_by_value (node_t **ptr_value, int value) {
    node_t *buff_head = head;
    
    while (head->next_node != NULL) {
        if (head->data == value) {
            (*ptr_value) = head;
            break;
        }
        head = head->next_node;
    }
    
    if ((*ptr_value) == NULL) {
        printf("Value not in list!\n");
    }
    head = buff_head;
    
}

void get_by_index (node_t **ptr_value, int index) {
    node_t *ptr_head = head;
    
    for (int i = 0; i < index; ++i) {
        if (head->next_node == NULL) {
            printf("Index out of range\n");
            break;
        }
        head = head->next_node;
    }
    if (index < 0) {
        printf("Invalid index!\n");
    } else {
        (*ptr_value) = head;
    }
    head = ptr_head;
    
}