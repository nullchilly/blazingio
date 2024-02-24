#include <cstdint>
#include <cstdio>
#include <random>

int main() {
    std::minstd_rand gen;
    for (size_t i = 0; i < 5000000; i++) {
        uint32_t rng = gen();
        int sign = rng & 1;
        rng >>= 1;
        int exp = rng & 15;
        rng >>= 4;
        int16_t x = rng & ((1 << exp) - 1);
        if (sign) {
            x = -x;
        }
        printf("%hd\n", x);
    }
    return 0;
}
