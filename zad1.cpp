#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void input_vector(vector<int>& v) {
	int x;
	cout << "Unesite broj: ";
	cin >> x;
	
	if (x != 0) {
		v.push_back(x);
		while (x != 0) {
			v.push_back(x);
			cout << endl;
			cout << "Unesite broj: ";
			cin >> x;
		}
	}

}

int main() {

	vector<int> v;

	input_vector(v);

	int k;
	cout << "Unesite k:" << endl;
	cin >> k;

	auto negativni = [](int n) {return n < 0; };
	auto cnt = count_if(v.begin(), v.end(), negativni);

	cout << "Negativnih: " << cnt << endl;

	auto djeljiv = [k](int n) {return n % k == 0; };
	auto visekratnik = find_if(v.begin(), v.end(), djeljiv);


	if (visekratnik != v.end()) {
		cout << "Prvi visekratnik broja " << k << " je na poziciji "<< visekratnik - v.begin() << endl;
	}

	auto max = max_element(v.begin(), v.end());
	auto min = min_element(v.begin(), v.end());

	cout << "Max (Pozicija " << max-v.begin() << "): " << *max << " Min(Pozicija " << min - v.begin() << "): " << *min << endl;

	auto makni = remove_if(v.begin(), v.end(), djeljiv);

	v.erase(makni, v.end());

	for (int broj : v) {
		cout << broj << " ";
	}


	return 0;
}