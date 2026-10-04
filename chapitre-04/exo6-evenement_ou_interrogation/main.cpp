#include <iostream>
#include <string>

int main() {
    long long v;
    int N;
    std::cin >> v >> N;

    long long xe = 0, xi = 0;
    long long sautsEv = 0, sautsInt = 0, manques = 0;
    bool spaceDown = false, leftDown = false, rightDown = false;

    for (int i = 1; i <= N; ++i) {
        int k;
        std::cin >> k;
        long long countSpacePress = 0;

        for (int j = 0; j < k; ++j) {
            std::string tok;
            std::cin >> tok;
            char sign = tok[0];
            std::string name = tok.substr(1);

            if (name == "SPACE") {
                if (sign == '+') { sautsEv++; countSpacePress++; spaceDown = true; }
                else { spaceDown = false; }
            } else if (name == "LEFT") {
                if (sign == '+') { xe -= v; leftDown = true; }
                else { leftDown = false; }
            } else if (name == "RIGHT") {
                if (sign == '+') { xe += v; rightDown = true; }
                else { rightDown = false; }
            }
            // tout autre nom : ignore
        }

        if (!spaceDown) manques += countSpacePress;

        if (spaceDown) sautsInt++;
        if (rightDown) xi += v;
        if (leftDown) xi -= v;

        std::cout << i << " " << xe << " " << xi << "\n";
    }

    std::cout << "SAUTS EVENEMENTS " << sautsEv << "\n";
    std::cout << "SAUTS INTERROGATION " << sautsInt << "\n";
    std::cout << "MANQUES " << manques << "\n";

    return 0;
}
