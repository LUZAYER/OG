#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(long n) {
    cout << "Checking " << n << "...\n";
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    long i = 5;
    while (i * i <= n) {
        cout << "Testing " << i << " and " << i+2 << "\n";
        if (n % i == 0 || n % (i+2) == 0) return false;
        i += 6;
    }
    return true;
}

vector<long> generatePrimes(long limit) {
    vector<long> primes;
    for(long i = 2; i <= limit; ++i)
        if (isPrime(i)) primes.push_back(i);
    return primes;
}

long nextPrime(long n) {
    long candidate = n + 1;
    while (!isPrime(candidate)) candidate++;
    return candidate;
}

vector<long> primeFactors(long n) {
    vector<long> factors;
    while (n % 2 == 0) { factors.push_back(2); n /= 2; }
    long i = 3;
    while (i*i <= n) {
        while (n % i == 0) { factors.push_back(i); n /= i; }
        i += 2;
    }
    if (n > 2) factors.push_back(n);
    return factors;
}

int main() {
    int choice;
    long n;
    while(true) {
        cout << "\n1.Check prime 2.Generate primes 3.Next prime 4.Prime factors 5.Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter number: "; cin >> n;
                cout << n << " is " << (isPrime(n) ? "" : "not ") << "prime\n";
                break;
            case 2: 
                cout << "Enter limit: "; cin >> n;
                for(auto p : generatePrimes(n)) cout << p << " ";
                cout << endl;
                break;
            case 3:
                cout << "Enter number: "; cin >> n;
                cout << "Next prime: " << nextPrime(n) << endl;
                break;
            case 4:
                cout << "Enter number: "; cin >> n;
                for(auto f : primeFactors(n)) cout << f << " ";
                cout << endl;
                break;
            case 5: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
