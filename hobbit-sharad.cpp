#include <iostream>

using namespace std;
bool canBuy(int *, int, int);

int main() {
    // the real code is the function. this is only the test main program
    int coinBag[10] = {-2, 45, 9, 10, 11, 2, 56, 3, -1, 5};
    cout << canBuy(coinBag, 10, 21);
    return 0;
}

bool canBuy(int *coinBag, int numCoins, int K) {
    for(int i=0; i<numCoins; ++i) {
        int compliment = K - coinBag[i];
        for (int j=i+1; j<numCoins; ++j) {
            if (coinBag[j] == compliment) {
                return true;
            }
        }
    }
    return false;
}
