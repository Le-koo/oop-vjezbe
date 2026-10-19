#include <iostream>
#include <vector>
using namespace std;

void input_vector(vector<int>& v) {
	int x;
	cout << "Unesite broj: ";
	cin >> x;
	cout << endl;
	if(x!=0){
		while (x != 0) {
			v.push_back(x);
			cout << endl;
			cout << "Size: " << v.size() << "\nCapacity: " << v.capacity() << endl;
			cout << "Unesite broj: ";
			cin >> x;
		}
	}
	
}
void print_vector(const vector<int>& v) {
	for (const auto& broj : v) cout << broj << " ";
}

int main() {

	vector<int> v;
	vector<int> vr;
	vr.reserve(100);

	input_vector(v);
	print_vector(v);
	cout << endl;


	for (auto it = v.rbegin(); it != v.rend(); ++it) {
		cout << *it << " ";
	}

	input_vector(vr);
	print_vector(vr);
	vr.shrink_to_fit();
	cout << endl;


}