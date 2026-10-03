#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    int refuses = 0;

    for (int i = 0; i < n; ++i) {
        std::string nom;
        long long w, h, px, py, ox, oy, sx, sy, angle;
        std::cin >> nom >> w >> h >> px >> py >> ox >> oy >> sx >> sy >> angle;

        if (angle % 90 != 0) {
            std::cout << nom << " ANGLE REFUSE\n";
            refuses++;
            continue;
        }

        long long norm = ((angle % 360) + 360) % 360;
        long long c, s;
        if (norm == 0)        { c = 1;  s = 0; }
        else if (norm == 90)  { c = 0;  s = 1; }
        else if (norm == 180) { c = -1; s = 0; }
        else                  { c = 0;  s = -1; } // 270

        long long lx[4] = {0, w, w, 0};
        long long ly[4] = {0, 0, h, h};
        long long wx[4], wy[4];

        for (int k = 0; k < 4; ++k) {
            long long ax = (lx[k] - ox) * sx;
            long long ay = (ly[k] - oy) * sy;
            long long rx = ax * c - ay * s;
            long long ry = ax * s + ay * c;
            wx[k] = px + rx;
            wy[k] = py + ry;
        }

        std::cout << nom << " COINS "
                  << wx[0] << " " << wy[0] << " "
                  << wx[1] << " " << wy[1] << " "
                  << wx[2] << " " << wy[2] << " "
                  << wx[3] << " " << wy[3] << "\n";

        long long minx = *std::min_element(wx, wx + 4);
        long long maxx = *std::max_element(wx, wx + 4);
        long long miny = *std::min_element(wy, wy + 4);
        long long maxy = *std::max_element(wy, wy + 4);

        std::cout << nom << " BOITE " << minx << " " << miny << " " << maxx << " " << maxy << "\n";
    }

    std::cout << "REFUSES " << refuses << "\n";
    return 0;
}
