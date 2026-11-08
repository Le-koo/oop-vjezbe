#include <iostream>
#include <string>

class Clip {
    int start;
    int end;
    int length;
    std::string name;
    const int max_length;

public:
    Clip(const std::string& name, int s, int e)
        : start(s), end(e), length(end - start), name(name), max_length(600)
    {
    }

    void print() const {
        std::cout << name << ": " << length << " s\n";
    }
};

int main() {
    Clip c("Concrete (Shame)", 10, 190);
    c.print();
    return 0;
}