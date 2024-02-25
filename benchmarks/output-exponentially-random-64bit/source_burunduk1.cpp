#include <cstdint>
#include <cstdio>
#include <random>

static const int buf_size = 4096;

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;

int main() {
    std::minstd_rand gen;
    for (size_t i = 0; i < 5000000; i++) {
        uint32_t rng = gen();
        int sign = rng & 1;
        rng >>= 1;
        int exp = rng & 63;
        int32_t x = (((uint64_t)gen() << 32) | gen()) & ((1ULL << exp) - 1);
        if (sign) {
            x = -x;
        }
        writeInt(x, '\n');
    }
    return 0;
}