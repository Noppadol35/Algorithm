#include <iostream>
using namespace std;

// ---------- sort ----------
void sortArray(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

// ---------- concatenate & store digits ----------
int concatDigits(int a[], int n, int digits[]) {
    int dCount = 0;

    for (int i = 0; i < n; i++) {
        int x = a[i];
        int rev[10], rc = 0;

        while (x > 0) {
            rev[rc++] = x % 10;
            x /= 10;
        }

        for (int j = rc - 1; j >= 0; j--) {
            digits[dCount++] = rev[j];
            cout << rev[j];
        }
    }
    cout << endl;
    return dCount;
}

// ---------- find max consecutive ----------
int findMaxRepeat(int digits[], int dCount) {
    int maxCnt = 1, cnt = 1;

    for (int i = 1; i < dCount; i++) {
        if (digits[i] == digits[i - 1]) {
            cnt++;
            if (cnt > maxCnt) maxCnt = cnt;
        } else {
            cnt = 1;
        }
    }
    return maxCnt;
}

// ---------- print digits with max repeat ----------
void printMaxRepeatDigits(int digits[], int dCount, int maxCnt) {
    int cnt = 1;
    bool printed[10] = {false};

    for (int i = 1; i <= dCount; i++) {
        if (i < dCount && digits[i] == digits[i - 1]) {
            cnt++;
        } else {
            if (cnt == maxCnt && !printed[digits[i - 1]]) {
                cout << digits[i - 1] << " ";
                printed[digits[i - 1]] = true;
            }
            cnt = 1;
        }
    }
    cout << endl;
}

// ---------- reduce ----------
void reduceDigits(int digits[], int dCount) {
    cout << digits[0];
    for (int i = 1; i < dCount; i++) {
        if (digits[i] != digits[i - 1]) {
            cout << digits[i];
        }
    }
    cout << endl;
}

// ---------- main ----------
int main() {
    int n;
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sortArray(a, n);

    int digits[1000];
    int dCount = concatDigits(a, n, digits);

    int maxCnt = findMaxRepeat(digits, dCount);

    printMaxRepeatDigits(digits, dCount, maxCnt);

    reduceDigits(digits, dCount);

    return 0;
}
