//#include <iostream>
//
//template <typename T>
//void promjena(T niz[], int n, T(*operacija)(T)) {
//	for (int i = 0; i < n; i++) {
//		niz[i] = operacija(niz[i]);
//	}
//}
//template <typename T>
//T pomnozi(T broj) {
//	return broj * 3;
//}
//
//int main() {
//
//	int niz[] = { 3,5,7,4,2};
//	int n = sizeof(niz) / sizeof(niz[0]);
//
//	promjena(niz, n, pomnozi);
//	for (int i = 0; i < n; i++) {
//		std::cout << niz[i] << ' ';
//	}
//	
//
//
//}