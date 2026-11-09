// Vjezba 6, zadatak 1: napisite klasu IntStack iznad main.

#include <iostream>

class IntStack {
private:
		int* data;
		size_t sz;
		size_t cap;

public:
	IntStack(size_t pocetni_cap = 2) : data(new int[pocetni_cap]), sz(0), cap(pocetni_cap){}
	
	~IntStack(){
		delete[] data;
	}

	IntStack(const IntStack& other) : data(new int[other.cap]), sz(other.sz), cap(other.cap) {
		for (size_t i = 0; i < sz; i++) {
			data[i] = other.data[i];
		}
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
	IntStack s;
	for (int i = 1; i <= 5; ++i)
		s.push(i * 10);
	std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
	IntStack c = s;      // copy konstruktor; isto kao IntStack c(s);
	c.pop();
	c.push(99);
	std::cout << s.top() << ' ' << c.top() << '\n';
	while (!s.empty()) { std::cout << s.top() << ' '; s.pop(); }
	std::cout << '\n';
	return 0;
}

/*
Ocekivani ispis:

	5 8 50
	50 99
	50 40 30 20 10
*/
