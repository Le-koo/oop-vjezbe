// Vjezba 7, zadatak 3: kopirajte klasu IntStack iz vjezbe 6 iznad main i dopunite je.

#include <iostream>
#include <utility>

class IntStack {
private:
	int* data;
	size_t sz;
	size_t cap;

public:
	IntStack(size_t pocetni_cap = 2) : data(new int[pocetni_cap]), sz(0), cap(pocetni_cap) {}

	~IntStack() {
		delete[] data;
	}

	IntStack(const IntStack& drugi) : data(new int[drugi.cap]), sz(drugi.sz), cap(drugi.cap) {
		std::cout << "copy konstruktor\n";
		for (size_t i = 0; i < sz; i++) {
			data[i] = drugi.data[i];
		}
	}

	IntStack& operator=(const IntStack& drugi) {
		std::cout << "copy assignment\n";
		if (this == &drugi) {
			return *this;
		}

		int* novi_data = new int[drugi.cap];
		for (size_t i = 0; i < drugi.sz; i++) {
			novi_data[i] = drugi.data[i];
		}

		delete[] data;
		data = novi_data;
		sz = drugi.sz;
		cap = drugi.cap;
		return *this;
	}

	IntStack(IntStack&& drugi) noexcept : data(drugi.data), sz(drugi.sz), cap(drugi.cap) {
		std::cout << "move konstruktor\n";
		drugi.data = nullptr;
		drugi.sz = 0;
		drugi.cap = 0;
	}

	IntStack& operator=(IntStack&& drugi) noexcept {
		std::cout << "move assignment\n";
		if (this == &drugi) {
			return *this;
		}

		delete[] data;
		data = drugi.data;
		sz = drugi.sz;
		cap = drugi.cap;

		drugi.data = nullptr;
		drugi.sz = 0;
		drugi.cap = 0;
		return *this;
	}

	void push(int x) {
		if (sz == cap) {
			size_t novi_cap = cap * 2;
			int* novi_data = new int[novi_cap];
			for (size_t i = 0; i < cap; i++) {
				novi_data[i] = data[i];
			}

			delete[] data;
			data = novi_data;
			cap = novi_cap;
		}

		data[sz++] = x;
	}

	void pop() {
		if (sz > 0) {
			--sz;
		}
	}

	int top() {
		return data[sz - 1];
	}

	bool empty() {
		return sz == 0;
	}

	int size() {
		return sz;
	}

	int capacity() {
		return cap;
	}
};

int main()
{
    IntStack a;
    a.push(10);
    a.push(20);
    a.push(30);

    IntStack b = a;              // ispis: copy konstruktor
    b = a;                       // ispis: copy assignment
    IntStack c = std::move(a);   // ispis: move konstruktor
    b = std::move(c);            // ispis: move assignment

    std::cout << a.size() << ' ' << c.size() << ' ' << b.size() << ' ' << b.top() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    copy konstruktor
    copy assignment
    move konstruktor
    move assignment
    0 0 3 30
*/