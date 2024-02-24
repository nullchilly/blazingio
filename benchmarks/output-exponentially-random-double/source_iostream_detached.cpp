#include <iomanip>
#include <iostream>
#include <random>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cout << std::setprecision(12);
    std::minstd_rand gen;
    for (size_t i = 0; i < 500000; i++) {
        int32_t rng = gen();
        double x = exp10(rng / 7158278.);
        if (rng & 1) {
            x = -x;
        }
        std::cout << x << '\n';
    }
    return 0;
}
