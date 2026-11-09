#include <iostream>

class IntStack {
private:
    int* data;
    std::size_t sz;
    std::size_t cap;

public:
    
    explicit IntStack(std::size_t initial_cap = 2) 
        : data(new int[initial_cap]), sz(0), cap(initial_cap) {}

    
    ~IntStack() {
        delete[] data;
    }

    

    IntStack(const IntStack& other) 
        : data(new int[other.cap]), sz(other.sz), cap(other.cap) {
        for (std::size_t i = 0; i < sz; ++i) {
            data[i] = other.data[i];
        }
    }

    
    void push(int x) {
        if (sz == cap) {
            std::size_t new_cap = cap * 2;
            int* new_data = new int[new_cap];
            for (std::size_t i = 0; i < sz; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            cap = new_cap;
        }
        data[sz++] = x;
    }

    
    void pop() {
        if (sz > 0) {
            --sz;
        }
    }

    // Dohvat elementa na vrhu stoga
    int top() const {
        return data[sz - 1];
    }

    // Provjera je li stog prazan
    bool empty() const {
        return sz == 0;
    }

    // Vraća trenutni broj elemenata
    std::size_t size() const {
        return sz;
    }

    // Vraća trenutni kapacitet niza
    std::size_t capacity() const {
        return cap;
    }
};

int main()
{
    IntStack s;
    for (int i = 1; i <= 5; ++i)
        s.push(i * 10);
    std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
    IntStack c = s;      // copy konstruktor; isto kao IntStack c(s);
    c.pop();
    c.push(99);
    std::cout << s.top() << ' ' << c.top() << '\n';
    while (!s.empty()) { std::cout << s.top() << ' '; s.pop(); }
    std::cout << '\n';
    return 0;
}
