int fibonacci(int n) {
    // Complete the function.
    if (n <= 1) return n;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}
