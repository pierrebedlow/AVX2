#include <iostream>
#include <immintrin.h>
#include <random>
#include "Timer.h"

int main() {

    {
        Timer t1("float intrinsics");
        
        for (size_t i = 0; i < 100000; i++)
        {
            float fin1[8] = { 1.1f, 0.2f, 0.3f, 0.4f, 1.6f, 1.3f, 1.3f, 101.1f };
            fin1[0] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float fin2[8] = { 1.1f, 10.2f, 0.3f, 10.4f, 1.6f, 11.3f, 1.3f, 1.1f };
            float fout[8];
            __m256 result;
            __m256 a1;
            __m256 a2;
            a1 = _mm256_loadu_ps(fin1);
            a2 = _mm256_loadu_ps(fin2);
            result = _mm256_add_ps(a1, a2);
            _mm256_store_ps(fout, result);
        }
    }

    {
        Timer t2("float classic");

        for (size_t i = 0; i < 100000; i++)
        {
            float fin1[8] = { 1.1f, 0.2f, 0.3f, 0.4f, 1.6f, 1.3f, 1.3f, 101.1f };
            fin1[0] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float fin2[8] = { 1.1f, 10.2f, 0.3f, 10.4f, 1.6f, 11.3f, 1.3f, 1.1f };
            float fout[8];

            for (size_t i = 0; i < 8; i++)
            {
                fout[i] = fin1[i] + fin2[i];
            }
        }
    }

    {
        Timer t3("integer intrinsics");
        
        __int32 iin[8] = { 10, 20, 30, 45, 50, 60, 70, 80 };
        __int32 iout[8];

        __m256i a_ini;
        a_ini = _mm256_loadu_si256((const __m256i*)iin);
        __m256 a_outf;
        __m256i a_outi;
        __m256 a_inf;
        __m256 a_r;

        for (size_t i = 0; i < 100000; i++)
        {

            float ratio = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            a_r = _mm256_set1_ps(ratio);
            a_inf = _mm256_cvtepi32_ps(a_ini);
            a_outf = _mm256_mul_ps(a_r, a_inf);
            a_outi = _mm256_cvttps_epi32(a_outf);
            _mm256_storeu_si256((__m256i*)iout, a_outi);

        }
    }

    {
        Timer t4("integer classics");

        __int32 iin[8] = { 10, 20, 30, 45, 50, 60, 70, 80 };
        __int32 iout[8];

        for (size_t i = 0; i < 100000; i++)
        {

            float ratio = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

            for (size_t i = 0; i < 8; i++)
            {
                iout[i] = static_cast<int>(static_cast<float>(iin[i]) * ratio);
            }

        }
    }

}
