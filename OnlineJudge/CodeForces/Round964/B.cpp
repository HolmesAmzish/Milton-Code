/**
 * @problem: Card Game
 * @author: Nulla
 * @date: 2024-08-06
 */

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        
        int suneet_wins = 0;

        // All possible game scenarios
        int scenarios[4][4] = {
            {a1, a2, b1, b2},
            {a1, a2, b2, b1},
            {a2, a1, b1, b2},
            {a2, a1, b2, b1}
        };

        // Evaluate each scenario
        for (int i = 0; i < 4; ++i) {
            int suneet_rounds = 0, slavic_rounds = 0;

            if (scenarios[i][0] > scenarios[i][2]) ++suneet_rounds;
            if (scenarios[i][1] > scenarios[i][3]) ++suneet_rounds;
            if (scenarios[i][2] > scenarios[i][0]) ++slavic_rounds;
            if (scenarios[i][3] > scenarios[i][1]) ++slavic_rounds;

            if (suneet_rounds > slavic_rounds) ++suneet_wins;
        }

        cout << suneet_wins << endl;
    }
    return 0;
}
