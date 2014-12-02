#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int who_wins(int p1, int p2, string m1, string m2);
int main()
{
    int n, k;
    cin >> n;
    while (n != 0)
    {
        cin >> k;
        if (n != 1) {
            int *wins = new int[n] ();
            int *loss = new int[n] ();
            
            int total_games = (k * n * (n - 1)) / 2;
            
            for (int i = 0; i < total_games; ++i) {
                int player1, player2;
                string move1, move2;
                cin >> player1 >> move1 >> player2 >> move2;
                
                int winner = who_wins(player1, player2, move1, move2);
                
                if (winner != 0) {
                    if (winner == player1) {
                        wins[player1 - 1]++;
                        loss[player2 - 1]++;
                    } else {
                        wins[player2 - 1]++;
                        loss[player1 - 1]++;
                    }
                }
            }
            
            for (int i = 0; i < n; ++i) {
                int w = wins[i];
                int l = loss[i];
                if (w == 0 && l == 0) {
                    cout << "-" << endl;
                } else {
                    // cout << "Player" << i + 1 << ": wins: " << w << " loss: " << l << endl;
                    cout << fixed << showpoint << setprecision(3);
                    cout << w / ((double)(w + l)) << endl;
                }
            }
            delete []wins;
            delete []loss;
        }
        cout << endl;
        cin >> n;
    }
    return 0;
}

int who_wins(int p1, int p2, string m1, string m2)
{
    if (m1 == m2 || p1 == p2) {
        return 0;
    } else if (m1 == "rock") {
        if (m2 == "paper"){
            return p2;
        } else {
            return p1; // m2 == scissors
        }
    } else if (m1 == "paper"){
        if (m2 == "rock") {
            return p1;
        } else {
            return p2; // m2 == scissors
        }
    } else {
        if (m2 == "rock") {
            return p2;
        } else {
            return p1;
        }
    }
}
