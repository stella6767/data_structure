int power(int a, int n) { //지수함수 
    int result = 1;
    for (int i = 0; i < n; i++)
        result *= a;
    return result;
}

int power(int a, int n) { //지수함수의 재귀적 방법
    if (n == 0) return 1;
    return a * power(a, n - 1);
}

int fact(int n) {  //계승함수 팩토리얼 함수
    int result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int fact(int n) { //팩토리얼 재귀적 방법
    if (n == 1) return 1;
    return n * fact(n - 1);
}

int fibo(int n) { //파보나치 수열
    int* f = new int[n + 1];
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i < n + 1; i++)
        f[i] = f[i - 1] + f[i - 2];
    return f[n];
}

int fibo(int n) { //파보나치 재귀
    if (n == 1 || n == 2) return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int gcd(int a, int b) { //최대공약수
    for (int i = a; i > 0; i--)
        if (a % i == 0 && b % i == 0)
            return i;
}

int gcd(int a, int b) { //최대공약수 재귀
    if (b == 0) return a;
    return gcd(b, a % b);
}

int power3(int n) { //3의 지수함수
    if (n == 0) return 1;
    return 3 * power(n - 1);
}

int fact(int n) {
    if (n == 1) return 1;
    return n * power(n - 1);
}







