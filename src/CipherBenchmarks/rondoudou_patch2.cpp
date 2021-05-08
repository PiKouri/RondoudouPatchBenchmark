#include <stdio.h>
#include <stdarg.h>
#include <benchmark/benchmark.h>
#include "rondoudou_patch2.h"

int rondoudou_patch_call_level = 0;
uintptr_t rondoudou_patch_key = 0xffffffffffffffff;
uintptr_t rondoudou_patch_offset = 1;
uintptr_t *rondoudou_patch_return_addr_addr = 0;

int print_debug = 0;

int print_log(const char *format, ...) {
    if (print_debug) {
        va_list args;
        va_start(args, format);
        int ret = vprintf(format, args);
        va_end(args);
        return ret;
    }
    return 0;
}

int h(int a) {
    cipher;
    print_log("Dans h(%d)\n", a);
    if (a > 0) {
        int ret = h(a - 1);
        decipher;
        return ret;
    }
    change_key(15165314561313153217ul);

    decipher;
    return 5;
}

int mainCipher() {

    cipher;
    for (int i = 0; i < 1000; ++i) {
        h(25);
    }
    decipher;

    return 0;
}

int h2(int a) {
    print_log("Dans h(%d)\n", a);
    if (a > 0) {
        int ret = h2(a - 1);
        return ret;
    }
    return 5;
}

int mainNoCipher() {
    for (int i = 0; i < 1000; ++i) {
        h2(25);
    }

    return 0;
}
static void BM_Cipher(benchmark::State& state) {
    for (auto _ : state)
        mainCipher();
}
// Register the function as a benchmark
BENCHMARK(BM_Cipher);

// Define another benchmark
static void BM_No_Cipher(benchmark::State& state) {
    for (auto _ : state)
        mainNoCipher();
}
BENCHMARK(BM_No_Cipher);

BENCHMARK_MAIN();