#include <bits/stdc++.h>
using namespace std;

int toh(char from, char to, char aux, int n) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return 1;
    }
    int count = 0;
    count += toh(from, aux, to, n - 1);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    count += toh(aux, to, from, n - 1);
    return count;
}

int main() {
    char from = 'F';
    char to = 'T';
    char auxilary = 'A';
    int n;
    cin >> n;
    int ans = toh(from, to, auxilary, n);
    cout << "Total moves: " << ans << endl;
}
