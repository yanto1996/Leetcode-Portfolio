/**
 *Yan To
 *Perfect Squares
 *https://leetcode.com/problems/perfect-squares/description/
 */

// using the three squares theorm to calculate the # of perfect squares it takes to sum to value n
int numSquares(n){
    // if n is a perfect square, return 1
    int i = sqrt(n);
    if (i * i == n){
        return 1;
    }

    // using 3 squares theorm to calculate for n
    // if i^2 + j^2 = n, return 2
    for (int i = 0; i * i <= n; i++){
        int j = sqrt(n - i * i);
        if (i * i + j* j == n){
            return 2;
        }
    }

    // using 3 squares theorm to calculate for n
    // if i^2 + j^2 + k^2 = n, return 3
    for (int i = 0; i * i <= n; i++){
        for (int j = i; i*i + j*j <=n; j++){
            int k = sqrt(n - i*i - j*j);
            if (i*i + j*j + k*k == n){
                return 3;
            }
        }
    }

    // uses the 3 squares theorm to see if n can be calculated by 4 perfect squares
    // get rid of all factors of 4 of n
    while (n % 4 == 0){
        n = n / 4;
    }
    
    // if remaining value n can be expressed as n = 4^a(8b + 7), then n can be calculated by 4 perfect squares
    if (n % 8 == 7){
        return 4;
    }

    return -1;
}

