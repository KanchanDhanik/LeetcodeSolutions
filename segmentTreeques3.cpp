/*
INVCNT - Inversion Count
#number-theory #sorting

Let A[0 ... n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. Given n and an array A your task is to find the number of inversions of A.

Input
The first line contains t, the number of testcases followed by a blank space. Each of the t tests start with a number n (n ≤ 200000). Then n + 1 lines follow. In the ith line a number A[i - 1] is given (A[i - 1] ≤ 107). The (n + 1)th line is a blank space.

Output
For every test output one line giving the number of inversions of A.

Example
Input:
2

3
3
1
2

5
2
3
8
6
1


Output:
2

5
*/
#include<iostream>
#include<vector>
using namespace std;

class ST {
public:
    vector<int> st;
    ST(int n) {
        st.resize(4 * n + 1, 0);
    }

    void build(int i, int low, int high, vector<int>& nums, vector<int>& st) {
        if (low == high) {
            st[i] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * i + 1, low, mid, nums, st);
        build(2 * i + 2, mid + 1, high, nums, st);
        st[i] = st[2 * i + 1] + st[2 * i + 2];
    }

    void update(int i, int low, int high, int pos, int val, vector<int>& st) {
        if (low == high) {
            st[i] += val;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid)
            update(2 * i + 1, low, mid, pos, val, st);
        else
            update(2 * i + 2, mid + 1, high, pos, val, st);
        st[i] = st[2 * i + 1] + st[2 * i + 2];
    }

    int query(int i, int low, int high, int l, int r, vector<int>& st) {
        if (r < low || high < l) return 0;
        if (l <= low && high <= r) return st[i];
        int mid = (low + high) / 2;
        int a = query(2 * i + 1, low, mid, l, r, st);
        int b = query(2 * i + 2, mid + 1, high, l, r, st);
        return a + b;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string line;
        getline(cin, line); // consume the newline after t or blank line
        while (line.empty()) getline(cin, line); // skip empty lines

        int n = stoi(line);
        vector<int> arr(n);
        int mx = -1;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mx = max(mx, arr[i]);
        }
        getline(cin, line); // skip the blank line after input

        mx += 1;
        vector<int> freq(mx, 0);
        for (auto i : arr) freq[i]++;
        ST st(mx);
        st.build(0, 0, mx - 1, freq, st.st);

        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            freq[arr[i]]--;
            st.update(0, 0, mx - 1, arr[i], -1, st.st);
            cnt += st.query(0, 0, mx - 1, 1, arr[i] - 1, st.st);
        }
        cout << cnt << endl;
    }
    return 0;
}
