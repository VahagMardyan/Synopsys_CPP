#include <iostream>

class Node {
    public:
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {}
        Node() {}
};

class SingleLinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        SingleLinkedList() : head(nullptr), tail(nullptr) {}
        ~SingleLinkedList() {
            Node* current = head;
            while(current) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }

        void push_back(int data) {
            Node* new_node = new Node(data);
            if(!head) {
                head = new_node;
                tail = new_node;
            } else {
                tail -> next = new_node;
                tail = new_node;
            }
        }

        void push_front(int data) {
            Node* new_node = new Node(data);
            if(!head) {
                head = new_node;
                tail = new_node;
            } else {
                new_node -> next = head;
                head = new_node;
            }
        }

        void push_at(int pos, int data) { 
            if (pos <= 0) {
                push_front(data);
                return;
            }
            Node* current = head;
            for (int i = 0; current && i < pos - 1; ++i) {
                    current = current->next;
            }
            if (!current) {
                push_back(data);
                return;
            }
            Node* new_node = new Node(data);
            new_node->next = current->next;
            current->next = new_node;
            if (new_node->next == nullptr) {
                    tail = new_node;
                }
        }

        void print_forward() {
            Node* current = head;
            while(current) {
                std::cout<<current->value<<" ";
                current = current->next;
            }
            std::cout<<"\n";
        }
};

int main() {
    SingleLinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_at(2, 15);
    list.push_at(3,554);
    list.print_forward();
    return 0;
}