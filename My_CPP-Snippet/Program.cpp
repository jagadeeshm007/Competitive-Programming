#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(), c.end()

unsigned long long mul(unsigned long long a, unsigned long long b, unsigned long long m) {
    unsigned long long ans = 0;
    while(b) {
        if(b&1) {
            ans = (ans + a) % m;
        }
        a = (a + a) % m;
        b >>= 1;
    }
    return ans;
}

unsigned long long pow(unsigned long long a, unsigned long long b, unsigned long long m) {
    unsigned long long ans = 1;
    while(b) {
        if(b&1) {
            ans = mul(ans, a, m);
        }
        a = mul(a, a, m);
        b >>= 1;
    }
    return ans;
}

bool millerRabin(unsigned long long n){
    unsigned long long a, d, s;
    d = n-1;
    s = 0;
    while(!(d&1)) {
        d >>= 1;
        s++;
    }
    const int limit = 5; // 5 is enough for 64 bit integer
    for(int i=0; i<limit; i++) {
        a = 2 + rand() % (n-3);
        unsigned long long x = pow(a, d, n);
        if(x==1 || x==n-1) {
            continue;
        }
        bool flag = false;
        for(unsigned long long j=0; j<s; j++) {
            x = mul(x, x, n);
            if(x==1) {
                return false;
            }
            if(x==n-1) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            return false;
        }

    }
    return true;

}
bool isPrime(unsigned long long n) {
    return n>1 && (n==2 || (n&1) && millerRabin(n) );
}
void Program() {
    unsigned long long n;
    cin >> n;
    if(isPrime(n)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test;
    cin >> test;
    while (test--) Program();
    return 0;
}

