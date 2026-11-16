#include <cassert>
#include <iostream>
#include <string>

class RecentlyPlayed {
private:
    std::string* data;
    size_t cap;
    size_t sz;
    size_t next_idx;

public:
    RecentlyPlayed(size_t capacity) : cap(capacity), sz(0), next_idx(0) {
        assert(capacity > 0);
        data = new std::string[cap];
    }

    ~RecentlyPlayed() {
        delete[] data;
    }

    
    RecentlyPlayed(const RecentlyPlayed& other)
        : cap(other.cap), sz(other.sz), next_idx(other.next_idx) {
        data = new std::string[cap];
        for (size_t i = 0; i < cap; ++i) {
            data[i] = other.data[i];
        }
    }

    void play(const std::string& title) {
        data[next_idx] = title;
        next_idx = (next_idx + 1) % cap;
        if (sz < cap) {
            ++sz;
        }
    }

    size_t size() const {
        return sz;
    }

    size_t capacity() const {
        return cap;
    }

    std::string get(size_t i) const {
        assert(i < sz);
        
        size_t idx = (next_idx + cap - 1 - i) % cap;
        return data[idx];
    }

    void print() const {
        for (size_t i = 0; i < sz; ++i) {
            std::cout << get(i);
            if (i + 1 < sz) {
                std::cout << ", ";
            }
        }
        std::cout << '\n';
    }
};

int main()
{
    RecentlyPlayed recent(3);
    recent.play("Heroes");
    recent.play("Literary Mind");
    std::cout << recent.size() << ' ' << recent.capacity() << '\n';
    recent.play("Sports");
    recent.print();
    recent.play("Henry Don't Got Love");
    recent.print();

    RecentlyPlayed copy = recent;
    recent.play("Guided by Angels");
    recent.print();
    copy.print();
    std::cout << copy.get(0) << '\n';
    return 0;
}
