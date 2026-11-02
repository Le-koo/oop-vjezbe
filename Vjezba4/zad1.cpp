#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void input_vector(vector<int>& v) {
	int x;
	cout << "Unesite brojeve (0 za kraj): ";
	cin >> x;
	
	while (x != 0) {
        cout << "Unesite broj: ";
		v.push_back(x);
		cin >> x;
	}
}

int main() {

	vector<int> v;

	input_vector(v);

	int k;
	cout << "k: ";
	cin >> k;

	auto negativni = [](int n) { return n < 0; };
	auto cnt = count_if(v.begin(), v.end(), negativni);
	cout << "negativnih: " << cnt << endl;

	auto djeljiv = [k](int n) { return n % k == 0; };
	auto visekratnik = find_if(v.begin(), v.end(), djeljiv);

	if (visekratnik != v.end()) {
		cout << "prvi visekratnik od " << k << ": " << *visekratnik << " (pozicija " << visekratnik - v.begin() << ")" << endl;
	} else {
		cout << "Nema visekratnika broja " << k << endl;
	}

	if (!v.empty()) {
		auto max = max_element(v.begin(), v.end());
		auto min = min_element(v.begin(), v.end());

		cout << "min " << *min << " (pozicija " << min - v.begin() << "), " << "max " << *max << " (pozicija " << max - v.begin() << ")" << endl;
	}

	auto makni = remove_if(v.begin(), v.end(), djeljiv);
	v.erase(makni, v.end());

	cout << "bez visekratnika: ";
	for (int broj : v) {
		cout << broj << " ";
	}
	cout << endl;

	return 0;
}