#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mulmod(ll a, ll b, ll mod){
    ll res = 0;
    a %= mod;
    while(b){
        if(b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}
ll pow(ll a, ll b, ll mod){
    ll res = 1;
    a %= mod;
    while(b){
        if(b & 1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}

bool millerRabin(ll n){
    if(n < 2) return false;
    if(n != 2 && n % 2 == 0) return false;
    ll d = n - 1;
    while(d % 2 == 0) d /= 2;
    for(ll i = 0; i < 5; i++){
        ll a = 2 + rand() % (n - 3);
        ll x = pow(a, d, n);
        if(x == 1 || x == n - 1) continue;
        for(ll j = 0; j < n - 1; j++){
            x = (x * x) % n;
            if(x == 1) return false;
            if(x == n - 1) break;
        }
        if(x != n - 1) return false;
    }
    return true;
}
bool isPrime(ll n){
    return n > 1 && (n == 2 || (n & 1 && millerRabin(n)));
}
int main(){
    ll n;
    cin >> n;
    
    if(isPrime(n)){
        cout << "Prime" << endl;
    }
    else{
        cout << "Not Prime" << endl;
    }

    return 0;
}

// Time Complexity: O(k * log^3(n))
// k = number of iterations
// k = 7 is enough for n < 10^16
// Space Complexity: O(1)