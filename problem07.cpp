#include <iostream>
#include <vector>
using namespace std;

void find_min_height_planks(int n, int k, vector<int>& heights) {
    vector<int> prefix_sum(n + 1, 0);

    // Compute prefix sum
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + heights[i - 1];
    }

    for (int i = 0; i < prefix_sum.size(); ++i) {
        cout << prefix_sum[i] << " ";
    }

    cout << "\n";

    int min_sum = prefix_sum[k] - prefix_sum[0]; // it took the first sum in the chain of k
    int min_index = 0;

    // Find the minimum sum subarray of size k
    for (int i = 1; i <= n - k; ++i) {
        int current_sum = prefix_sum[i + k] - prefix_sum[i];
        if (current_sum < min_sum) {
            min_sum = current_sum;
            min_index = i;
        }
    }

    // Output 1-based index
    cout << min_index + 1 << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    find_min_height_planks(n, k, heights);
    return 0;
}
