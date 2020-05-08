#pragma once

inline constexpr int div_ceil(int a, int b) {
    int q = a / b;
    int r = a % b;
    if((b>0 && r>0) || (b<0 && r<0))
        ++q;
    return q;
}
