// Vjezba 7, zadatak 1: napisite strukturu Vec2 i operatore iznad main.

#include <iostream>

struct Vec2 {
    int x{};
    int y{};

    Vec2& operator+=(const Vec2& drugi) {
        x += drugi.x;
        y += drugi.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& drugi) {
        x -= drugi.x;
        y -= drugi.y;
        return *this;
    }
};

inline Vec2 operator+(Vec2 lijevi, const Vec2& desni) {
    lijevi += desni;
    return lijevi;
}

inline Vec2 operator-(Vec2 lijevi, const Vec2& desni) {
    lijevi -= desni;
    return lijevi;
}

inline Vec2 operator*(Vec2 v, int faktor) {
    v.x *= faktor;
    v.y *= faktor;
    return v;
}

inline Vec2 operator*(int faktor, Vec2 v) {
    return v * faktor;
}

inline bool operator==(const Vec2& a, const Vec2& b) {
    return a.x == b.x && a.y == b.y;
}

inline bool operator!=(const Vec2& a, const Vec2& b) {
    return !(a == b);
}

inline std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    return os << '(' << v.x << ", " << v.y << ')';
}

int main()
{
    Vec2 player{2, 3};
    Vec2 right{1, 0};
    Vec2 down{0, 1};

    player += right;
    std::cout << player << '\n';
    player += 2 * down;
    std::cout << player << '\n';
    Vec2 target = player + right * 3 - down;
    std::cout << target << '\n';

    Vec2 enemy{6, 4};
    std::cout << (target == enemy) << ' ' << (player != enemy) << '\n';
    std::cout << player << " -> " << target << '\n';
    return 0;
}

/*
Ocekivani ispis:

    (3, 3)
    (3, 5)
    (6, 4)
    1 1
    (3, 5) -> (6, 4)
*/