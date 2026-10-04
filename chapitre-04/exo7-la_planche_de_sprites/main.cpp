#include <iostream>

int main() {
    long long C, R, W, H, F, D, P;
    std::cin >> C >> R >> W >> H >> F >> D >> P;

    int N;
    std::cin >> N;

    long long currentCase = 0;
    long long accumulated = 0;
    long long avances = 0, plafonnes = 0;

    for (int i = 0; i < N; ++i) {
        long long dt;
        std::cin >> dt;

        if (dt > P) { dt = P; plafonnes++; }
        accumulated += dt;

        while (accumulated >= D) {
            accumulated -= D;
            currentCase = (currentCase + 1) % F;
            avances++;
        }

        long long x = (currentCase % C) * W;
        long long y = (currentCase / C) * H;

        std::cout << currentCase << " " << x << " " << y << " " << W << " " << H << "\n";
    }

    std::cout << "AVANCES " << avances << "\n";
    std::cout << "PLAFONNES " << plafonnes << "\n";

    return 0;
}
