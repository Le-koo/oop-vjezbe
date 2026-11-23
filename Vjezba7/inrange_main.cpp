// Vjezba 7, zadatak 5: kopirajte Vec2 iz zadatka 1 i napisite klasu InRange.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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

struct Enemy {
    std::string name;
    Vec2 pos;
};

class InRange {
private:
    Vec2 centar;
    int domet;

public:
    InRange(Vec2 centar, int domet) : centar(centar), domet(domet) {}

    bool operator()(const Enemy& neprijatelj) const {
        int dx = neprijatelj.pos.x - centar.x;
        int dy = neprijatelj.pos.y - centar.y;
        return dx * dx + dy * dy <= domet * domet;
    }
};

int main()
{
    std::vector<Enemy> enemies = {
        {"Goblin", {2, 2}}, {"Troll", {6, 1}}, {"Bat", {3, 5}},
        {"Ghost", {0, 0}}, {"Slime", {7, 7}}
    };
    Vec2 player{3, 3};

    InRange near(player, 2);                                           // konstruktor, 2 je domet
    std::cout << near(enemies[0]) << ' ' << near(enemies[1]) << '\n';  // operator()

    int broj_obj = std::count_if(enemies.begin(), enemies.end(), near);
    std::cout << broj_obj << '\n';

    int range = 2;
    int broj_lambda = std::count_if(enemies.begin(), enemies.end(),
        [player, range](const Enemy& neprijatelj) {
            int dx = neprijatelj.pos.x - player.x;
            int dy = neprijatelj.pos.y - player.y;
            return dx * dx + dy * dy <= range * range;
        });
    std::cout << broj_lambda << '\n';

    return 0;
}

/*
Ocekivani ispis:

    1 0
    2
    2
*/