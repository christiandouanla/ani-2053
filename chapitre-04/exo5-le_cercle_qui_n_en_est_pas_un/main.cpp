#include <iostream>
#include <cmath>
#include <string>

int main() {
    const double pi = 3.141592653589793;
    int n;
    std::cin >> n;
    long long visibles = 0, refuses = 0;

    for (int i = 0; i < n; ++i) {
        long long r, segs;
        std::cin >> r >> segs;

        if (segs < 3) {
            std::cout << r << " " << segs << " REFUSE\n";
            refuses++;
            continue;
        }

        double g = (double)r * (1.0 - std::cos(pi / (double)segs));
        long long ecart = (long long)std::floor(g * 1000.0);

        if (g == 0.0) {
            std::cout << r << " " << segs << " " << ecart << " JAMAIS\n";
            continue;
        }

        long long zoom = (long long)std::ceil(100.0 / g);
        std::string verdict = (zoom <= 100) ? "VISIBLE" : "INVISIBLE";
        if (verdict == "VISIBLE") visibles++;

        std::cout << r << " " << segs << " " << ecart << " " << zoom << " " << verdict << "\n";
    }

    std::cout << "VISIBLES " << visibles << "\n";
    std::cout << "REFUSES " << refuses << "\n";
    return 0;
}
