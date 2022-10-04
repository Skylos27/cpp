#include <iostream>
using namespace std;

long long sqrt(long long n){
    long long i = 0;
    while(i * i < n)
        i++;
    return i; 
}

int main() {

    long long i, n;
    bool is_prime = true;

    while(cin >> n){
        bool is_prime = true;
	long long root = sqrt(n);
        if (n <= 1) {
            is_prime = false;
        }
	else if (n <= 3){
	    is_prime = true;
	}
        else{
            for (i = 2; i <= root; ++i) {
                if (n % i == 0) {
                    is_prime = false;
                }
            }
        }
        if (is_prime)
            cout << n << " is a prime: True\n";
        else
            cout << n << " is a prime: False\n";
    }
    return 0;
}
