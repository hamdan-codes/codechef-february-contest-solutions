#include <vector>

#include<cstdio>

using namespace std;

#define int long long

const int MaxN = 1 << 19, M = 998244353;

int mod = 998244353;

int ws[MaxN];

int inverse_factorial[500005];

int vectarr[500005];

int factorial[500005];

int arrr1[1 << 19], arrr2[1 << 19];



// Fast Fourier Transform help has been taken from CP algorithms and drdobbs
// Refer : https://cp-algorithms.com/algebra/fft.html
// and   : https://www.drdobbs.com/cpp/a-simple-and-efficient-fft-implementatio/199500857

// From Geeksforgeeks ...
// REFER : https://www.geeksforgeeks.org/fast-fourier-transformation-poynomial-multiplication/

// Helper Functions made anonymously by someone and I took it for my Coding help Thank you

// Thank you : https://github.com/Pokelover166/FFT-polynomial-multiplication/blob/master/main.cpp

// ************************** Below are the functions ************************************








long long binpow(long long a, long long b = mod - 2, long long m = mod) {

    a %= m;

    long long res = 1;

    while (b > 0) {

        if (b & 1)

            res = res * a % m;

        a = a * a % m;

        b >>= 1;

    }

    return res;

}

void fourier(int *a, int n, int f = 0) {

    int i, j, k, m, u, v, w, wm;

    for (i = n >> 1, j = 1, k; j < n - 1; j++) {

        if (i > j)swap(a[i], a[j]);

        for (k = n >> 1; k <= i; k >>= 1)i ^= k; i ^= k;

    }

    for (m = 2; m <= n; m <<= 1)

        for (i = 0, wm = binpow(3, f == 1 ? (M - 1) / m : (M - 1) / m * (m - 1), M); i < n; i += m)

            for (j = i, w = 1; j < i + (m >> 1); j++) {

                u = a[j], v = 1ll * w * a[j + (m >> 1)] % M;

                if ((a[j] = u + v) >= M)a[j] -= M;

                if ((a[j + (m >> 1)] = u - v) < 0)a[j + (m >> 1)] += M;

                w = 1ll * w * wm % M;

            }

    if (f == 1)for (w = binpow(n, M - 2, M), i = 0; i < n; i++)a[i] = 1ll * a[i] * w % M;

}


vector<int> mul(vector<int> arr, vector<int> brr) {

    int n_a = arr.size() - 1;

    int n_b = brr.size() - 1;

    int n_final = 1;

    while (n_final <= n_a + n_b)n_final *= 2;

    int i = 0;

    while (i < n_final) {

        arrr1[i] = i <= n_a ? arr[i] : 0;

        i++;

    }

    i = 0;

    while (i < n_final) {

        arrr2[i] = i <= n_b ? brr[i] : 0;

        i++;

    }

    fourier(arrr2, n_final);

    fourier(arrr1, n_final);

    i = 0;

    while (i < n_final) {

        arrr1[i] = arrr1[i] * arrr2[i] % M;

        i++;

    }

    fourier(arrr1, n_final, 1);

    vector<int> c;

    i = 0;

    while (i <= (n_a + n_b)) {

        c.push_back(arrr1[i]);

        i++;

    }

    return c;

}

int nCr(int n, int r) {

    if (r > n)return 0;

    return (((inverse_factorial[r] * inverse_factorial[n - r]) % mod) * factorial[n]) % mod;

}

// ****************** My own code below created on 12 feb 2021 *********************


void precompute() {

    inverse_factorial[1] = inverse_factorial[0] = 1;

    vectarr[1] = vectarr[0] = 1;

    factorial[1] = factorial[0] = 1;

    for (int i = 2; i < 200005; i++) {

        vectarr[i] = vectarr[mod % i] * (mod - mod / i) % mod;

    }

    for (int i = 2; i < 200005; i++) {

        factorial[i] = (factorial[i - 1] * i) % mod;

    }

    for (int i = 2; i < 200005; i++) {

        inverse_factorial[i] = (vectarr[i] * inverse_factorial[i - 1]) % mod;

    }

}

signed main() {

    precompute();

    int n;

    scanf("%lld", &n);

    vector<int> arr(n);

    vector<int> vectarr(30);

    for (int i = 0; i < n; i++) {

        scanf("%lld", &arr[i]);

    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < 30; j++) {

            if (arr[i] & (1 << j)) {

                vectarr[j]++;

            }

        }

    }

    vector<int> sol(n + 1);

    for (int ii = 0; ii < 30; ii++) {

        vector<int> eno = {0};

        vector<int> orez = {1};

        for (int i = 1; i <= vectarr[ii]; i += 2) {

            eno.push_back(nCr(vectarr[ii], i));

            eno.push_back(0);

        }

        int i = 1;

        while (i <= (n - vectarr[ii])) {

            orez.push_back(nCr(n - vectarr[ii], i));;

            i++;

        }

        auto gotit = mul(eno, orez);

        i = 0;

        while (i <= n) {

            sol[i] = (sol[i] + ((1 << ii) * gotit[i])) % mod;;

            i++;

        }

    }

    int i = 1;

    while (i <= n) {

        sol[i] += sol[i - 1];

        sol[i] %= mod;

        i++;

    }

    int q;

    scanf("%lld", &q);

    while (q--) {
        int qq;
        scanf("%lld", &qq);
        printf("%lld\n", sol[qq]);
    }

}


// ************************ Author Chaudhary Hamdan *******************************
// ch.hamdan.edu@gmail.com
// Thank you

//*********************************************************************************
//*********************************************************************************

