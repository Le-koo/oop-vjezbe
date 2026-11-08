#include <cassert>
#include <iostream>
using namespace std;

class Volume {
    int glasnoca;
    int prije = 50;

    bool valid() const {
        return glasnoca >= 0 && glasnoca <= 100;
    }

public:
    static int granica(int l) {
        if (l > 100) {
            return 100;
        }
        else if (l < 0) {
            return 0;
        }
        return l;
    }

    Volume(int l) {
        glasnoca = granica(l);
        assert(valid());
    }

    Volume() : Volume(50) {}

    int get() const {
        return glasnoca;
    }

    void up(int step = 10) {
        glasnoca = granica(glasnoca + step);
        assert(valid());
    }

    void down(int step = 10) {
        glasnoca = granica(glasnoca - step);
        assert(valid());
    }

    void mute() {
        prije = glasnoca;
        glasnoca = 0;
        assert(valid());
    }

    void unmute() {
        glasnoca = prije;
        assert(valid());
    }
};

int main()
{
    Volume v;
    std::cout << v.get() << '\n';
    v.up();
    v.up(60);
    std::cout << v.get() << '\n';
    v.mute();
    std::cout << v.get() << '\n';
    v.unmute();
    std::cout << v.get() << '\n';
    Volume w(-20);
    w.down();
    std::cout << w.get() << '\n';
    return 0;
}


/*
Ocekivani ispis:

    50
    100
    0
    100
    0
*/
