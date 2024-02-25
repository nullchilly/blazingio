#include <cstdint>
#include <cstdio>
#include <cstring>
#include <inttypes.h>

int main() {
    char s[2048];
    uint64_t sum = 0;
    while (fgets(s, 2048, stdin)) {
        sum += strcmp(s, "YES") == 0;
    }
    // Do not optimize out reading of s
    printf("%" PRIu64 "\n", sum);
    return 0;
}
