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

    Ticket(const Ticket&) = delete;
    Ticket& operator=(const Ticket&) = delete;

    int get_id() const {
        return id;
    }

    std::string get_concert_name() const {
        return concert_name;
    }

    static int issued() {
        return counter;
    }
};

int Ticket::counter = 0;

void print(const Ticket& t) {
    std::cout << "Ulaznica #" << t.get_id() << " za koncert: " << t.get_concert_name() << '\n';
}

int main()
{
    std::cout << Ticket::issued() << '\n';
    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");
    std::cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << '\n';
    std::cout << Ticket::issued() << '\n';
    print(t1);
    return 0;
}
