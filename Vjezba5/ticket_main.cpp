#include <iostream>
#include <string>

class Ticket {
    std::string concert_name;
    int id;
    static int counter;

public:
    Ticket(const std::string& name) : concert_name(name) {
        id = ++counter;
    }

    int get_id() const {
        return id;
    }

    static int issued() {
        return counter;
    }
};

int Ticket::counter = 0;

int main()
{
    std::cout << Ticket::issued() << '\n';
    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");
    std::cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << '\n';
    std::cout << Ticket::issued() << '\n';
    return 0;
}