#include <iostream>

class Coin {
    int value;
    static int count;

public:
    Coin(int v) : value(v) {
        ++count;
    }

    ~Coin() {
        --count;
    }

    static int remaining() {
        return count;
    }
};

int Coin::count = 0;

void bonus(){
    Coin c1(5);
    Coin c2(5);
    Coin c3(10);
    std::cout << Coin::remaining() << '\n';
}

int main()
{
    std::cout << Coin::remaining() << '\n';
    Coin gold(50);
    {
        Coin a(1);
        Coin b(1);
        std::cout << Coin::remaining() << '\n';
    }
    std::cout << Coin::remaining() << '\n';
    bonus();
    std::cout << Coin::remaining() << '\n';
    return 0;
}