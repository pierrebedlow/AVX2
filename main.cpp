#include <iostream>
#include <immintrin.h>
 
int main() {
 
    float fin1[8] = { 1.1, 0.2, 0.3, 0.4, 1.6, 1.3, 1.3, 101.1 };
    float fin2[8] = { 1.1, 10.2, 0.3, 10.4, 1.6, 11.3, 1.3, 1.1 };
    float fout[8];
 
    __m256 result;
    __m256 a1;
    __m256 a2;
    a1 = _mm256_loadu_ps(fin1);
    a2 = _mm256_loadu_ps(fin2);
    result = _mm256_add_ps(a1, a2);
    _mm256_store_ps(fout, result);
 
    for (auto& i : fout) {
        std::cout << i << std::endl;
    }
 
    float ratio = 0.2;
    __int32 iin[8] = { 10, 20, 30, 40, 50, 60, 70, 80 };
    __int32 iout[8];
 
    __m256 a_r;
    a_r = _mm256_set1_ps(ratio);
    __m256i a_ini;
    a_ini = _mm256_loadu_si256((const __m256i*)iin);
    __m256 a_inf;
    a_inf = _mm256_cvtepi32_ps(a_ini);
 
    __m256 a_outf;
    a_outf = _mm256_mul_ps(a_r, a_inf);
 
    __m256i a_outi;
    a_outi = _mm256_cvttps_epi32(a_outf);
 
    _mm256_storeu_si256((__m256i*)iout, a_outi);
 
    for (auto& i : iout) {
        std::cout << i << std::endl;
    }
 
}
