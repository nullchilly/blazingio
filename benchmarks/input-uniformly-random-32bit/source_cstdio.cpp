#include <cstdint>
#include <cstdio>

int main() {
    int32_t n;
    uint64_t sum = 0;
    while (scanf("%d", &n) > 0) {
        sum += n;
    }
    // Do not optimize out reading of n
    printf("%lu\n", sum);
    return 0;
}
