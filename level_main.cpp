#include <iostream>
#include <string>
#include <vector>

class Enemy {
private:
    std::string name;
    int x;
    int y;
    int health;

public:
    Enemy(std::string name, int x, int y) : name(name), x(x), y(y), health(100) {}

    std::string get_name() const { return name; }
    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_health() const { return health; }

    bool is_alive() const {
        return health > 0;
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void take_damage(int d) {
        health -= d;
        if (health < 0) {
            health = 0;
        }
    }
};

class Level {
private:
    int rows;
    int cols;
    std::vector<Enemy> enemies;

public:
    Level(int r, int c) : rows(r), cols(c) {}

    bool add(Enemy e) {
        if (e.get_x() >= 0 && e.get_x() < cols && e.get_y() >= 0 && e.get_y() < rows) {
            enemies.push_back(e);
            return true;
        }
        return false;
    }

    void step(int dx, int dy) {
        for (auto& e : enemies) {
            int nx = e.get_x() + dx;
            int ny = e.get_y() + dy;
            if (nx >= 0 && nx < cols && ny >= 0 && ny < rows) {
                e.move(dx, dy);
            }
        }
    }

    void print() const {
        for (const auto& e : enemies) {
            std::cout << e.get_name() << " (" << e.get_x() << ", " << e.get_y() << ") " << e.get_health() << '\n';
        }
    }
};

int main()
{
    Level cave(5, 10);
    cave.add(Enemy("Gnome", 1, 1));
    std::cout << cave.add(Enemy("Troll", 8, 3))
              << cave.add(Enemy("Bat", 12, 2)) << '\n';
    cave.step(1, 1);
    cave.print();
    cave.step(1, 1);
    cave.print();
    return 0;
}
