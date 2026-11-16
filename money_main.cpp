// Vjezba 7, zadatak 2: napisite klasu Money i operatore iznad main.
// Datoteka racun.txt mora biti u mapi iz koje se program pokrece.

#include <fstream>
#include <iostream>
#include <string>

class Money {
	int iznos;
};

int main()
{
	Money a(1, 5);
	Money b(0, 95);
	std::cout << a << " + " << b << " = " << a + b << '\n';

	std::ifstream in("racun.txt");
	if (!in) {
		std::cout << "Datoteka racun.txt ne postoji\n";
		return 1;
	}

	std::string item;
	Money price;
	Money total;
	Money max_price;
	std::string max_item;
	int count = 0;
	while (in >> item >> price) {
		total += price;
		if (max_price < price) {
			max_price = price;
			max_item = item;
		}
		++count;
	}
	if (!in.eof())
		std::cout << "Neispravan zapis: " << item << '\n';

	std::cout << "Stavki: " << count << '\n';
	std::cout << "Ukupno: " << total << '\n';
	std::cout << "Najskuplje: " << max_item << ' ' << max_price << '\n';
	return 0;
}

/*
Ocekivani ispis:

	1.05 EUR + 0.95 EUR = 2.00 EUR
	Neispravan zapis: Sok
	Stavki: 5
	Ukupno: 17.23 EUR
	Najskuplje: Kava 7.99 EUR
*/
