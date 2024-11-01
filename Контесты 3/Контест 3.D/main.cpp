#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

class Function {
private:
    int a, b, c, d;

public:
    Function(int ai, int bi, int ci, int di) : a(ai), b(bi), c(ci), d(di) {};

    long double Value(long double x) {
        return a * std::pow(x, 3) + b * std::pow(x, 2) + c * x + d;
    }
};

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    Function Equation(a, b, c, d);

    long double r = 1;

    while (!(Equation.Value(-r) * Equation.Value(r) < 0)) {
        r *= 2;
    }

    long double l = -r;
    long double eps = 1e-4;

    while (r - l > eps) {
        long double m = (l + r) / 2;
        if (Equation.Value(m) * Equation.Value(r) > 0) {
            r = m;
        }
        else {
            l = m;
        }
    }

    std::cout << std::fixed << std::setprecision(4) << (l + r) / 2;
}