#include <iostream>
using namespace std;

int main() {

    int i, n;
    bool is_prime = true;

    while(cin >> n){
        bool is_prime = true;
        if (n == 0 || n == 1) {
            is_prime = false;
        }
        else{
            for (i = 2; i <= n/2; ++i) {
                if (n % i == 0) {
                    is_prime = false;
                }
            }
        }
        if (is_prime)
            cout << n << " is a prime : True\n";
        else
            cout << n << " is not a prime : False\n";
    }
    return 0;
}