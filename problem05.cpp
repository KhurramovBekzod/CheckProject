#include <bits/stdc++.h>




void solve() {
    using namespace std;


    int n; cin >> n;

    vector<int> vec(n + 1, 0);

    int total_cnt = 0;

    for(int i = 1; i <= n; i++) {
        cin >> vec[i];
        if (vec[i] == 1) {
            total_cnt++;
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {

            // swap everything on (i, j)
            int cnt0 = 0, cnt1 = 0;

            for(int k = i; k <= j; ++k) {
                if(vec[k] == 1) ++cnt1;
                else ++cnt0;
            }

            int next_cnt = total_cnt - cnt1 + cnt0;
        }
        cout << total_cnt << "\n";
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
    return 0;
}