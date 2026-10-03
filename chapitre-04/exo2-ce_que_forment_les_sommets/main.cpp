#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    long long totalPoints = 0, totalSegments = 0, totalTriangles = 0;
    int refuses = 0;

    for (int i = 0; i < n; ++i) {
        std::string type;
        long long s;
        std::cin >> type >> s;
if (type == "POINTS") {
     std::cout << type << " " << s << " " << s << " POINTS 0\n";
            totalPoints += s;
        } else if (type == "LINES") {
    long long nb = s / 2;
    long long reste = s % 2;
    std::cout << type << " " << s << " " << nb << " SEGMENTS " << reste << "\n";
    totalSegments += nb;
        } else if (type == "LINE_STRIP") {
            long long nb, reste;
            if (s >= 2) { nb = s - 1; reste = 0; }
            else { nb = 0; reste = s; }
            std::cout << type << " " << s << " " << nb << " SEGMENTS " << reste << "\n";
            totalSegments += nb;
        } else if (type == "TRIANGLES") {
            long long nb = s / 3;
            long long reste = s % 3;
            std::cout << type << " " << s << " " << nb << " TRIANGLES " << reste << "\n";
            totalTriangles += nb;
        } else if (type == "TRIANGLE_STRIP" || type == "TRIANGLE_FAN") {
            long long nb, reste;
            if (s >= 3) { nb = s - 2; reste = 0; }
            else { nb = 0; reste = s; }
            std::cout << type << " " << s << " " << nb << " TRIANGLES " << reste << "\n";
            totalTriangles += nb;
        } else {
            std::cout << type << " " << s << " REFUSE\n";
            refuses++;
        }
    }

    std::cout << "POINTS " << totalPoints << "\n";
    std::cout << "SEGMENTS " << totalSegments << "\n";
    std::cout << "TRIANGLES " << totalTriangles << "\n";
    std::cout << "REFUSES " << refuses << "\n";

    return 0;
}
