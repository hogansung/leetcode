#include <cstdio>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

int calFactorial(int v, vector<int>& rcdFactorial) {
    if (v == 0) {
        return 1;
    } else if (rcdFactorial[v] != -1) {
        return rcdFactorial[v];
    } else {
        return rcdFactorial[v] = v * calFactorial(v-1, rcdFactorial);
    }
}

int calDp(int d, int k, vector<vector<int>>& rcdDp, vector<int>& rcdFactorial) {
    /* d: number of elements, where the largest 
     * one is the right most element
     * k: number of elements can be seen
     */
    if (k == 1) {
        assert(d == 1);
        return 1;
    } else if (k == 2) {
        return calFactorial(d-2, rcdFactorial);
    } else if (rcdDp[d][k] != -1) {
        return rcdDp[d][k];   
    } else {
        int sum = 0;
        for (int i = 0; i <= d - k; i++) {
            sum += calFactorial(i, rcdFactorial) * calDp(d-1-i, k-1, rcdDp, rcdFactorial);
        }
        return rcdDp[d][k] = sum;
    }
}

int calTotal(int n, int x, int y) {
    /* n: number of people
     * x: people seen by guard A
     * y: people seen by guard B
     * 
     * Example:
     * A ..................... B
     */
    assert(x > 0 and y > 0);
    assert(x + y - 1 <= n);

    int maxD = max(n-x+1, x-y+1);
    int maxK = max(x, y);
    vector<vector<int>> rcdDp(maxD+1, vector<int>(maxK+1, -1));

    int maxV = maxD;
    vector<int> rcdFactorial(maxV, -1);

    int sum = 0;
    for (int i = x; i <= n-y+1; i++) {
        sum += calDp(i, x, rcdDp, rcdFactorial) * calDp(n-i+1, y, rcdDp, rcdFactorial);
    }
    return sum;
}

int main() {
    int val = calTotal(5, 1, 5);
    printf("%d\n", val);
}
