#include <iostream>
#include "../../node_list.cpp"

DoublyLinkedList* sortedInsert(DoublyLinkedList* list, int data) {
    Node* new_node = new Node(data);
    if(!list -> head) {
        list -> head = new_node;
        list -> tail = new_node;
        return list;
    }
    
    if(data <= list->head->value) {
        new_node -> next = list -> head;
        list -> head -> prev = new_node;
        list -> head = new_node;
        return list;
    }

    if(data >= list->tail->value) {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
        return list;
    }
    Node* current = list->head;
    while(current && current->value < data) {
        current = current->next;
    }
    new_node->next = current;
    new_node->prev = current->prev;
    current->prev->next = new_node;
    current->prev = new_node;
    return list;
}

int main() {
    DoublyLinkedList *list = new DoublyLinkedList();
    sortedInsert(list, 10);
    sortedInsert(list, 3);
    sortedInsert(list, 1);
    sortedInsert(list, -2);
    sortedInsert(list, 0);
    list->print_forward(); // -2 0 1 3 10
    return 0;
}