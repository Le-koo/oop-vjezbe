#include <iostream>
#include <cmath>

int& find_max(int arr[], int n) {
    int max_index = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[max_index]){
            max_index = i;
        }
    }
    return arr[max_index];
}

int main(){
    int brojevi[] = {4, -7, 12, 0, 9, -3};
    int n = sizeof(brojevi)/sizeof(brojevi[0]);

    for (int& broj : brojevi) {
        if (broj < 0) {
            broj = std::abs(broj);
        }
    }

    std::cout << "Niz nakon apsolutnih vrijednosti: ";
    for (int broj : brojevi) {
        std::cout << broj << " ";
    }

    std::cout << "\n";

    find_max(brojevi, n) = 0;

    std::cout << "Niz nakon promjene najveceg: ";
    for (int broj : brojevi) {
        std::cout << broj << " ";
    }
    std::cout << "\n";

    return 0;
}