#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

void move_by(Point* p, double dx, double dy) {
    p->x += dx;
    p->y += dy;
}

double dist(const Point* a, const Point* b) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    return std::sqrt(dx * dx + dy * dy);
}

void move_by(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double dist(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    Point t1{1.0, 2.0};
    Point t2{4.0, 6.0};

    move_by(&t1, 1.0, 1.0);
    std::cout << "Nakon pomaka pointerom, t1: (" << t1.x << ", " << t1.y << ")\n";

    double udaljenost = dist(&t1, &t2);
    std::cout << "Udaljenost (pointeri): " << udaljenost << "\n";

    move_by(t1, -1.0, -1.0);
    std::cout << "Nakon pomaka referencom, t1: (" << t1.x << ", " << t1.y << ")\n";

    double udaljenost_ref = dist(t1, t2);
    std::cout << "Udaljenost (reference): " << udaljenost_ref << "\n";

    Point tocke[5] = {
        {5.0, 5.0},
        {1.5, 2.0},
        {10.0, -8.0},
        {0.5, 0.5},
        {3.0, 4.0}
    };

    Point ishodište{0.0, 0.0};

    int najbliza_index = 0;
    
    double min_dist = dist(tocke[0], ishodište);

    for (int i = 1; i < 5; ++i) {
        double d = dist(tocke[i], ishodište);
        if (d < min_dist) {
            min_dist = d;
            najbliza_index = i;
        }
    }

    std::cout << "Točka najbliža ishodištu je na koordinatama: (" 
              << tocke[najbliza_index].x << ", " << tocke[najbliza_index].y 
              << ") s udaljenošću " << min_dist << "\n";

    return 0;
}