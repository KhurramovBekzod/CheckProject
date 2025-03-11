#include <bits/stdc++.h>
#include <vector>
using namespace std;



void solve() {
    int t; cin >> t;


    for(int i = 0; i < t; i++) {
        int n, k, p; cin >> n >> k >> p;

        if(k < 0) {
            int negP = -1 * p;
            if(negP * n > k) {
                cout << -1 << "\n";
            }

        }else {

        }



    }


}





void fast_io()
{
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf; needs include <iomanip>
    std::cin.tie(nullptr); // turn off sync between cin and cout
}

int main()
{
    fast_io();
    solve();
    // flippingGame();
    
    return 0;

}