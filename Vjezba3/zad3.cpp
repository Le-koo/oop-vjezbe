#include <iostream>
#include <array>

constexpr int DAYS = 7;

double total(const std::array<double, DAYS>& hours) {
    double sum =0.0;
    for (double h : hours) {
        sum += h;
    }
    return sum;
}

int best_day(const std::array<double, DAYS>& hours){
    int max_index = 0;
    for (int i = 1; i < DAYS; ++i){
        if (hours[i] > hours[max_index]){
            max_index = i;
        }
    }
    return max_index + 1;
}

int main() {

    std::array<double, DAYS> tjedan1;

    std::cout << "Unesite sate ucenja za " << DAYS << " dana prvog tjedna:\n";

    for (int i = 0; i < DAYS; ++i){
        std::cout << "Dan " << (i + 1) << ": ";
        std::cin >> tjedan1[i];
    }

    std::cout << "\nPrvi tjedan\n";
    std::cout << "Ukupno sati: " << total(tjedan1) << "\n";
    std::cout << "Dan s najvise ucenja: Dan " << best_day(tjedan1) << "\n";

    std::array<double, DAYS> tjedan2;
    tjedan2.fill(1.5);

    std::cout << "\nUsporedba\n";
    std::cout << "tjedan1 == tjedan2: " << (tjedan1 == tjedan2) << "\n";
    std::cout << "tjedan1 < tjedan2:  " << (tjedan1 < tjedan2) << "\n";

    tjedan1.swap(tjedan2);

    std::cout << "\nNakon swap-a\n";
    std::cout << "Novi broj sati za prvi tjedan:  " << total(tjedan1) <<"\n";
    std::cout << "Novi broj sati za drugi tjedan: " << total(tjedan2) <<"\n";

    return 0;
}