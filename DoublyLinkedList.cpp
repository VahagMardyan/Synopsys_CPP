#include <iostream>

class Node {
    public:
        int value;
        Node* next;
        Node* prev;
        Node(int val) : value(val), next(nullptr), prev(nullptr) {};
        Node() {}
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) {}

        void push_back(int data) {
            Node* new_node = new Node(data);
            if(!head) {
                head = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                new_node->prev = tail;
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
                head -> prev = new_node;
                head = new_node;
            }
        }

        void push_at(int pos, int data) {
            if(pos <= 0) {
                push_front(data);
                return;
            }
            Node *current = head;
            for(size_t i=0; current && i < pos - 1; i++) {
                current = current->next;
            }
            if(!current || !current->next) {
                push_back(data);
                return;
            }
            Node* new_node = new Node(data);
            new_node->next = current -> next;
            new_node -> prev = current;
            current->next->prev = new_node;
            current -> next = new_node;
        }

        void pop_front() {
            if(!head) return;
            Node* temp = head;
            head = head -> next;
            if(head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
        }

        void pop_back() {
            if(!tail) return;
            Node* temp = tail;
            tail = tail -> prev;
            if(tail) {
                tail -> next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
        }

        void pop_at(int pos) {
            if(!head || pos < 0) return;
            Node* current = head;
            for(int i=0; current && i < pos; i++) {
                current = current -> next;
            }
            if(!current) return;

            if(current == head) {
                pop_front();
                return;
            }
            if(current == tail) {
                pop_back();
                return;
            }
            current -> prev -> next = current -> next;
            current -> next -> prev = current -> prev;
            delete current;
        }

        void print_forward() {
            Node* current = head;
            while(current) {
                std::cout<<current->value<<" ";
                current = current -> next;
            }
            std::cout<<"\n";
        }

        void print_backward() {
            Node* current = tail;
            while(current) {
                std::cout<<current->value<<" ";
                current = current -> prev;
            }
            std::cout<<"\n";
        }

        int get_size() {
            int size = 0;
            Node *current = head;
            while(current != nullptr) {
                size++;
                current = current->next;
            }
            return size;
        }
};

// int main() {
//     DoublyLinkedList* list;
//     list.push_front(5);
//     list.push_front(4);
//     list.push_back(6);
//     list.push_back(7);
//     list.push_at(2,-77);
//     list.pop_at(2);
//     list.print_forward(); // 4 5 6 7
//     list.print_backward(); // 7 6 5 4
//     int l = list.get_size();
//     std::cout<<l<<std::endl;
//     return 0;
// }