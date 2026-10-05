#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

struct ObjInfo {
    long long x, y, angle, scale, depth;
};

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<std::string, ObjInfo> objets;
    long long maxDepth = 0;

    for (int i = 0; i < n; ++i) {
        std::string nom, parent;
        long long tx, ty, angle, echelle;
        std::cin >> nom >> parent >> tx >> ty >> angle >> echelle;

        ObjInfo info;

        if (parent == "-") {
            info.x = tx;
            info.y = ty;
            info.angle = ((angle % 360) + 360) % 360;
            info.scale = echelle;
            info.depth = 1;
        } else {
            ObjInfo &p = objets[parent];

            long long ax = tx * p.scale;
            long long ay = ty * p.scale;

            long long normP = p.angle;
            long long c, s;
            if (normP == 0)        { c = 1;  s = 0; }
            else if (normP == 90)  { c = 0;  s = 1; }
            else if (normP == 180) { c = -1; s = 0; }
            else                    { c = 0;  s = -1; } // 270

            long long rx = ax * c - ay * s;
            long long ry = ax * s + ay * c;

            info.x = p.x + rx;
            info.y = p.y + ry;
            info.angle = ((p.angle + angle) % 360 + 360) % 360;
            info.scale = p.scale * echelle;
            info.depth = p.depth + 1;
        }

        objets[nom] = info;
        maxDepth = std::max(maxDepth, info.depth);

        std::cout << nom << " " << info.x << " " << info.y << " " << info.angle << " " << info.scale << "\n";
    }

    std::cout << "PROFONDEUR " << maxDepth << "\n";
    return 0;
}
