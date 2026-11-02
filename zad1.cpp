#include <cassert>
#include <iostream>
using namespace std;

class Volume {
	int glasnoca;

public:
	Volume(int l) {
		if (glasnoca > 100) {
			glasnoca = 100;
		}
		else if (glasnoca < 0) {
			glasnoca = 0;
		}
	}
	Volume(int l) : Volume() { glasnoca = 50; };
	Volume() = default;

	static int granica(int glasnoca) {
		if (glasnoca > 100) {
			glasnoca = 100;
		}
		else if (glasnoca < 0) {
			glasnoca = 0;
		}
	}

	void up(int step = 10) {
		glasnoca += step;
		granica(glasnoca);
	}

	void down(int step = 10) {
		glasnoca -= step;
		granica(glasnoca);
	}

	void mute() {
		int prije = glasnoca;
		glasnoca = 0;
	}

	void unmute(int prije) {
		glasnoca = prije;
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
