#include <iostream>

void my_transform(int arr[], int n, int (*f)(int)) {
    for (int i = 0; i < n; i++) {
        arr[i] = f(arr[i]);
    }
}

int twice(int x) {
    return x * 2;
}

void printarr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Pocetni niz: ";
    printarr(arr, n);

    my_transform(arr, n, twice);
    std::cout << "Nakon twice: ";
    printarr(arr, n);

    my_transform(arr, n, [](int x) {
        if (x % 2 == 0) {
            return x / 2;
        } else {
            return x* 2;
        }
    });

    std::cout << "Nakon lambde: ";
    printarr(arr, n);

    std::cout << std::endl;

    int arr2[] = {2, 10, 4, 12, 3};
    int n2 =sizeof(arr2) / sizeof(arr2[0]);

    int suma = 0;
    int produkt = 1;
    
    auto sum_prod = [&](int x) {
        suma += x;
        produkt *= x;
    };

    for(int i = 0; i < n2; i++) {
        sum_prod(arr2[i]);
    }

    std::cout << "Suma elemenata: " << suma << std::endl;
    std::cout << "Produkt elemenata: " << produkt << std::endl;

    int prag = 5;
    int s = 0;

    auto zbrojprag = [prag, &s](int x) {
        if (x >prag) {
            s += x;
        }
    };

    for(int i = 0; i < n2; i++) {
        zbrojprag(arr2[i]);
    }
    std::cout << "Suma elemenata vecih od " << prag << ": " << s << std::endl;


}