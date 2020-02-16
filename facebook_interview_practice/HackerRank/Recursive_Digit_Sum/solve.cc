// Complete the superDigit function below.
int get_answer(long long input)
{
    long long arg = 0;
    for (long long val = input; val > 0; val /= 10) {
        arg += (val % 10);
    }

    if (arg == input) {
        return input;
    } else {
        return get_answer(arg);
    }
}

int superDigit(string n, int k) {
    long long val = 0;

    for (int i = 0; i < n.length(); ++i) {
        val += ((n[i] - '0') * k);
    }
    return get_answer(val);
}
