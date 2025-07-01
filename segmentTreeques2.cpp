/*C. Sereja and Brackets
time limit per test1 second
memory limit per test256 megabytes
Sereja has a bracket sequence s1, s2, ..., sn, or, in other words, a string s of length n, consisting of characters "(" and ")".

Sereja needs to answer m queries, each of them is described by two integers li, ri (1 ≤ li ≤ ri ≤ n). The answer to the i-th query is the length of the maximum correct bracket subsequence of sequence sli, sli + 1, ..., sri. Help Sereja answer all queries.

You can find the definitions for a subsequence and a correct bracket sequence in the notes.

Input
The first line contains a sequence of characters s1, s2, ..., sn (1 ≤ n ≤ 106) without any spaces. Each character is either a "(" or a ")". The second line contains integer m (1 ≤ m ≤ 105) — the number of queries. Each of the next m lines contains a pair of integers. The i-th line contains integers li, ri (1 ≤ li ≤ ri ≤ n) — the description of the i-th query.

Output
Print the answer to each question on a single line. Print the answers in the order they go in the input.

Examples
InputCopy
())(())(())(
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10
OutputCopy
0
0
2
10
4
6
6
question available at codeforces*/

/*we can use the same template from  the segment tree implementation but we need to add node here comes the addtion of nodes in the segment tree
which can contain the values of open ,close and full cnt of the brackets then we can return this node and finally return 2*full brackets cnt */
#include <iostream>
#include <vector>
using namespace std;

struct info {
    int open, close, full;
};

info merge(info a, info b) {
    int match = min(a.open, b.close);
    info ans;
    ans.full = a.full + b.full + match;
    ans.open = a.open + b.open - match;
    ans.close = a.close + b.close - match;
    return ans;
}

void build(int i, int l, int r, string &s, vector<info> &st) {
    if (l == r) {
        st[i].open = (s[l] == '(');
        st[i].close = (s[l] == ')');
        st[i].full = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i + 1, l, mid, s, st);
    build(2 * i + 2, mid + 1, r, s, st);
    st[i] = merge(st[2 * i + 1], st[2 * i + 2]);
}

info query(int i, int l, int r, int x, int y, vector<info> &st) {
    if (y < l || x > r) {
        return {0, 0, 0};
    }
    if (x <= l && r <= y) {
        return st[i];
    }
    int mid = (l + r) / 2;
    info a = query(2 * i + 1, l, mid, x, y, st);
    info b = query(2 * i + 2, mid + 1, r, x, y, st);
    return merge(a, b);
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<info> st(4 * n);
    build(0, 0, n - 1, s, st);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        info ans = query(0, 0, n - 1, l, r, st);
        cout << ans.full * 2 << '\n';
    }
    return 0;
}
