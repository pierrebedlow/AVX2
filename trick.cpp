#include <iostream>
#include <immintrin.h>
#include <random>
#include "Timer.h"

int main() {

	{
		Timer t("AVX");

		const int n = 1024;
		float a[n], b[n];
		float c = 3.0f;

		for (size_t i = 0; i < n; i++)
		{
			a[i] = 1.0f;
		}

		__m256 C = _mm256_broadcast_ss(&c);
		for (int i = 0; i < n; i+=8)
		{
			__m256 A = _mm256_load_ps(&a[i]);
			__m256 B = _mm256_mul_ps(A, C);
			_mm256_store_ps(&b[i], B);
		}


	}


	{
		Timer t("None AVX");

		const int n = 1024;
		float a[n], b[n];
		float c = 3.0f;

		for (size_t i = 0; i < n; i++)
		{
			a[i] = 1.0f;
		}

		for (int i = 0; i < n; i++)
		{
			b[i] = a[i] * c;
		}


	}
}
