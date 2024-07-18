#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

const int limit = 1e6 + 1; // Limit of the sieve
vector<int> primes(limit); // Vector to store the primes

void sieve() { // Function to generate the sieve

	fill(all(primes), 1); // Fill the vector with 1
	primes[0] = primes[1] = 0; // 0 and 1 are not prime

	// Loop to mark the multiples of the numbers as not prime
	for(int i = 2; i * i < limit; i++) {
		if(primes[i] == 1) { // If i is prime
			for(int j = i * i; j < limit; j += i) { // Mark the multiples of i as not prime
				primes[j] = 0;
			}
		}
	}
}

bool isPrime(int n) {
	// Returns 1 if prime, 0 if not prime
	return primes[n];
}
int main() {
	// Generate the sieve
	sieve();
	int n;
	cin >> n;
	// Check if a number is prime or not
	if(isPrime(n)) { // 1 if prime, 0 if not prime
		cout << "Prime" << endl;
	} else {
		cout << "Not Prime" << endl;
	}

	return 0;
}

/*
	time complexity: O(n log n)
	space complexity: O(n)
	Generates all the prime numbers upto a limit
	get the prime numbers in O(1) time

*/