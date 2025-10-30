#include <iostream>

class String {
    private:
        static const int string_size = 23; // for stack

        union {
            char s[string_size]; // stack-memory (small strings)
            char *heap; // heap-memory (large strings)
        };
        
        size_t size;
        size_t capacity;
        bool inHeap;

        size_t len(const char* str) {
            size_t len = 0;
            while(str[len] != '\0') {
                len++;
            }
            return len;
        }

        void copy(char* dest, const char* src) {
            size_t i=0;
            while((dest[i]=src[i]) != '\0') {
                i++;
            }
        }
    
    public:
        String(const char* str) {
            size = len(str);
            if(size < string_size) {
                inHeap = false;
                capacity = string_size - 1;
                copy(s,str);
            } else {
                inHeap = true;
                capacity = size;
                heap = new char[capacity + 1];
                copy(heap, str);
            }
        }

        String() {}

        ~String() {
            if(inHeap) {
                delete[] heap;
            }
        }

        // // copy constructor
        String(const String& other_str) {
            size = other_str.size;
            capacity = other_str.capacity;
            inHeap = other_str.inHeap;
            if(inHeap) {
                heap = new char[capacity + 1];
                copy(heap, other_str.heap);
            } else {
                copy(s, other_str.s);
            }
        }

        String& operator=(const String& other) {
            if(this == &other) {
                return *this;
            }
            if(inHeap) {
                delete[] heap;
            }
            size = other.size;
            capacity = other.capacity;
            inHeap = other.inHeap;
            if(inHeap) {
                heap = new char[capacity + 1];
                copy(heap, other.heap);
            } else {
                copy(s,other.s);
            }
            return *this;
        }
        char& operator[](size_t i) {
            return inHeap ? heap[i] : s[i];
            // return inHeap ? *(heap + i) : *(s + i);
        }
        const char* c_str() const {
            return inHeap ? heap : s;
        }
        size_t length() const {
            return size;
        }
        String operator + (const String& other) const {
            String result;
            size_t new_size = size + other.size;
            if(new_size < string_size) {
                result.inHeap = false;
                result.capacity = string_size - 1;
                result.size = new_size;

                size_t i = 0, j = 0;
                while(i < size) {
                    result.s[i] = inHeap ? heap[i] : s[i];
                    i++;
                }
                while(j < other.size) {
                    result.s[i] = other.inHeap ? other.heap[j] : other.s[j];
                    j++;
                    i++;
                }
                result.s[i] = '\0';
            } else {
                result.inHeap = true;
                result.capacity = new_size;
                result.size = new_size;
                result.heap = new char[new_size + 1];
                size_t i = 0, j = 0;
                while(i < size) {
                    result.heap[i] = inHeap ? heap[i] : s[i];
                    i++;
                }
                while(j < other.size) {
                    result.heap[i] = other.inHeap ? other.heap[j] : other.s[j];
                    j++;
                    i++;
                }
                result.heap[i] = '\0';
            }
            return result;
        }
};

int main() {
    String a = "Hello";
    String b = "World";
    String d = "abcdefghijklmnopqrstuvwxyz";
    String c = a + " "  + b + "!!!";
    std::cout<<d[2]<<std::endl;
    // std::cout<<d.c_str()<<std::endl;
    // std::cout<<c.length()<<std::endl;
    return 0;
}