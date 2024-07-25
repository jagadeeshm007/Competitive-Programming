#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mulmod(ll a, ll b, ll c) {
    ll x = 0, y = a % c;
    while (b > 0) {
        if (b % 2) x = (x + y) % c;
        y = (y * 2) % c;
        b /= 2;
    }
    return x % c;
}

ll modulo(ll a, ll b, ll c) {
    ll x = 1, y = a % c;
    while (b > 0) {
        if (b % 2) x = mulmod(x, y, c);
        y = mulmod(y, y, c);
        b /= 2;
    }
    return x % c;
}

bool miller_rabin(ll p, ll iteration) {
    if (p < 2) return false;
    if (p % 2 == 0 && p != 2) return false;

    ll s = p - 1;
    while (s % 2 == 0) s /= 2;

    for (ll i = 1; i <= iteration; i++) {
        ll a = rand() % (p - 1) + 1, temp = s;

        ll mod = modulo(a, temp, p);
        while (mod != 1 && mod != p - 1 && temp != p - 1) {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (temp % 2 == 0 && mod != p - 1) return false;
    }
    return true;
}
void solve() {
    ll n;
    cin >> n;
    const int limit = 50; // limit of iteration for miller rabin primality test algorithm upto 1<=n<=10^18 
    if (miller_rabin(n, limit)) cout << "YES\n";
    else cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));

    /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
   
    int Test;
    cin >> Test;
    while (Test--) {
        solve();
    }
    return 0;
}
