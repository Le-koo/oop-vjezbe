#include <iostream>

class Board {
private:
    int r;
    int c;
    char border;
    char* grid;

public:
    Board(int rows, int cols, char border_char) : r(rows), c(cols), border(border_char) {
        grid = new char[r * c];
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                    grid[i * c + j] = border;
                } else {
                    grid[i * c + j] = ' ';
                }
            }
        }
    }

    ~Board() {
        delete[] grid;
    }

    Board(const Board& other) : r(other.r), c(other.c), border(other.border) {
        grid = new char[r * c];
        for (int i = 0; i < r * c; ++i) {
            grid[i] = other.grid[i];
        }
    }

    void set(int i, int j, char ch) {
        if (i > 0 && i < r - 1 && j > 0 && j < c - 1) {
            grid[i * c + j] = ch;
        }
    }

    char get(int i, int j) const {
        return grid[i * c + j];
    }

    int rows() const { return r; }
    int cols() const { return c; }

    void print() const {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                std::cout << grid[i * c + j];
            }
            std::cout << '\n';
        }
    }
};

int main()
{
    Board b(4, 8, '#');
    b.set(1, 2, '@');
    Board copy = b;
    copy.set(2, 5, '*');
    copy.set(0, 0, '!');
    b.print();
    copy.print();
    std::cout << copy.rows() << ' ' << copy.cols() << ' '
              << copy.get(2, 5) << '\n';
    return 0;
}
