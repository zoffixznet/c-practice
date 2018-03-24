#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>
#include <math.h>

#define GRISU_D_1_LOG2_10 0.30102999566398114  /*  1/lg(10)  */
#define GRISU_TEN7 10000000
#define UINT64_2PART_C(a, b) ((((uint64_t)(a) << 32) + (0x##b##u)))
static const uint64_t kSignMask = UINT64_2PART_C(0x80000000, 00000000);
static const uint64_t kExponentMask = UINT64_2PART_C(0x7FF00000, 00000000);
static const uint64_t kSignificandMask = UINT64_2PART_C(0x000FFFFF, FFFFFFFF);
static const uint64_t kHiddenBit = UINT64_2PART_C(0x00100000, 00000000);
static const int kPhysicalSignificandSize = 52;  // Excludes the hidden bit.
static const int kSignificandSize = 53;

typedef struct grisu_fp {
    uint64_t f;
    int e;
} grisu_fp;

grisu_fp minus(grisu_fp x, grisu_fp y) {
    assert(x.e == y.e && x.f >= y.f);
    grisu_fp r = {.f = x.f - y.f, .e = x.e};
    return r;
}

grisu_fp multiply(grisu_fp x, grisu_fp y) {
    uint64_t a, b, c, d,  ac, bc, ad, bd,  tmp;
    grisu_fp r;
    uint64_t M32 = 0xFFFFFFF;
    a = x.f >> 32; b = x.f & M32;
    c = y.f >> 32; d = y.f & M32;
    ac = a*c; bc = b*c; ad = a*d; bd = b*d;
    tmp = (bd >> 32) + (ad & M32) + (bc & M32);
    tmp += 1U << 31; // Round
    r.f = ac + (ad >> 32) + (bc >> 32) + (tmp >> 32);
    r.e = x.e + y.e + 64;
    return r;
}

int k_comp(int e, int alpha, int gamma) {
    /* 63 magic number is the Grisu's `q - 1` specialized for 64-bits */
    gamma++;
    return ceil((alpha - e + 63) * GRISU_D_1_LOG2_10);
}

void cut(grisu_fp D, uint32_t parts[3]) {
    uint64_t tmp;
    parts[2] = (D.f % (GRISU_TEN7 >> D.e)) << D.e;
    tmp      = D.f / (GRISU_TEN7 >> D.e);
    parts[1] = tmp % GRISU_TEN7;
    parts[0] = tmp / GRISU_TEN7;
}

grisu_fp double2grisu_fp(double v) {
    int e = 42;
    grisu_fp gfp = {.e = 42, .f = 42 };
    printf("Fuck %d %d %g\n", gfp.e, e, v);
    exit(1);
}
grisu_fp normalize_grisu_fp (grisu_fp v) {
    printf("Fuck %d\n", v.e);
    exit(1);
}
grisu_fp cached_power(int mk) {
    printf("Fuck %d\n", mk);
    exit(1);
}

void grisu(double v) {
    grisu_fp w;
    uint32_t ps[3];
    int q = 64, alpha = 0, gamma = 3;
    w = normalize_grisu_fp(double2grisu_fp(v));
    int mk = k_comp(w.e + q, alpha, gamma);
    grisu_fp c_mk = cached_power(mk);
    grisu_fp D = multiply(w, c_mk);
    cut(D, ps);
    printf("%u%07u%07ue%d", ps[0], ps[1], ps[2], -mk);
}

int main(void) {
    // grisu(1.42);
    printf("%" PRIx64 "\n", kSignificandMask);
    return 0;
}
