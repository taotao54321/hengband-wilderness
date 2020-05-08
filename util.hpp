#pragma once

#include <cassert>

inline constexpr int div_ceil(int a, int b) {
    int q = a / b;
    int r = a % b;
    if((b>0 && r>0) || (b<0 && r<0))
        ++q;
    return q;
}

inline int modulo(int a, int b) {
    assert(b > 0);
    int r = a % b;
    if(r < 0) r += b;
    return r;
}

inline int CLZ(int x) {
    if(x == 0) return 8*sizeof(int);
    return __builtin_clz(x);
}

inline int log2_ceil(int x) {
    assert(x > 0);
    return 8*int(sizeof(int)) - CLZ(x-1);
}

inline int pow2_ceil(int x) {
    return 1 << log2_ceil(x);
}
