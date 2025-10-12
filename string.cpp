#include <iostream>

class String {
    private:
        char* data;
        size_t size;
        size_t capacity;

        void resize(size_t new_capacity) {
            char* new_data = new char[new_capacity];
            for(size_t i=0;i<size;i++) {
                new_data[i] = data[i];
            }
            new_data[size] = '\0';
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    
    public:
        String() : data(new char[1]), size(0), capacity(1) {
            data[0] = '\0';
        }
        String(const char* s) {
            size_t len = 0;
            while(s[len]!='\0') {
                len++;
            }
            size = len;
            data = new char[size+1];
            for(size_t i=0;i<size;i++) {
                data[i] = s[i];
            }
            data[size] = '\0';

            capacity = size + 1;
        }
        ~String() {
            delete[] data;
        }
        size_t length() {
            size_t l = 0;
            while(data[l]!='\0') {
                l++;
            }
            return l;
        }
        String& operator=(const String& s) {
            if(this == &s) return *this;
            delete[] data;

            size = s.size;
            capacity = s.capacity;
            data = new char[capacity];
            for(size_t i=0;i<size;i++) {
                data[i] = s.data[i];
            }
            data[size] = '\0';
            return *this;
        }
        String operator+(const String& s) {
            String result;
            result.size = this->size + s.size;
            result.capacity = result.size + 1;
            result.data = new char[result.capacity];
            for(size_t i=0;i<this->size;i++) {
                result.data[i] = this->data[i];
            }
            for(size_t i=0; i<s.size;i++) {
                result.data[this->size + i] = s.data[i];
            }
            result.data[result.size] = '\0';
            return result;
        }

        bool operator==(const String& s) const {
            if(size!=s.size) {
                return false;
            }
            for(size_t i=0;i<size;i++) {
                if(data[i] != s.data[i]) {
                    return false;
                }
            }
            return true;
        }

        char& operator[](size_t index) {
            return data[index];   
        }

        const char& operator[](size_t index) const {
            return data[index];
        }

        String& operator+=(const String& s) {
            append(s);
            return *this;
        }

        String& operator+=(char c) {
            append(c);
            return *this;
        }

        char at(size_t index) {
            if (index >= size) {
                throw std::out_of_range("Index out of range");
            } else {
                return data[index];
            }
        }

        int find(char c) {
            for(size_t i=0;i<size;i++) {
                if(data[i] == c) {
                    return i;
                }
            }
            return -1;
        }

        int find(const String& val) {
            if(val.size == 0) {
                return 0;
            }
            for(size_t i=0; i <= this->size - val.size; i++) {
                bool match = true;
                for(size_t j=0; j<val.size; j++) {
                    if(data[i+j] != val.data[j]) {
                        match = false;
                        break;
                    }
                }
                if(match) {
                    return i;
                }
            }
            return -1;
        }

        void append(const String& s) {
            size_t total_size = this->size + s.size;
            if(total_size >= capacity) {
                resize(total_size + 1);
            }
            for(size_t i=0;i<s.size;i++) {
                data[size+i] = s.data[i];
            }
            size = total_size;
            data[size] = '\0';
        }

        void append(char c) {
            if(size + 1 >= capacity) {
                resize(size + 2);
            }
            data[size] = c;
            size++;
            data[size] = '\0';
        }

        void clear() {
            delete[] data;
            size = 0;
            capacity = 1;
            data = new char[capacity];
            data[0] = '\0';
        }

        void insert(const String& s, size_t index) {
            if(index > size) {
                index = size;
            }
            size_t total_size = this->size + s.size;
            if(total_size >= capacity) {
                resize(total_size + 1);
            }
            for(int i=size;i>index; i--) {
                data[i + s.size - 1] = data[i - 1];
            }
            for(size_t i=0;i<s.size;i++) {
                data[index + i] = s.data[i];
            }
            size = total_size;
            data[size] = '\0';
        }

        void erase(size_t start, size_t end) {
            if(start >= size || start > end) return;
            if(end >= size) end = size - 1;
            size_t count = end - start + 1;
            for(size_t i = start; i + count < size; i++) {
                data[i] = data[i + count];
            }
            size -= count;
            data[size] = '\0'; 
        }

        void print() {
            for(size_t i=0;i<size;i++) {
                std::cout<<data[i];
            }
            std::cout<<'\n';
        }
        void reverse() {
            for(size_t i=0;i<size/2;i++) {
                char temp = data[i];
                data[i] = data[size - 1 - i];
                data[size - 1 - i] = temp;
            }
            data[size] = '\0';
        }
};

int main() {
    String s = "Hello";
    String x = " World";
    String n = s+x;
    // n.insert("ABC",2);
    // n.erase(2,5);
    n.reverse();
    n.print();
    return 0;
}