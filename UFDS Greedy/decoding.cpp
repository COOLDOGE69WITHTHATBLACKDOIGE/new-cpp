#include <bits/stdc++.h>

using namespace std;

int main(){

    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int N, K;
        cin >> N >> K;
        char binstr[N];
        cin >> binstr;
        vector<int> diffvec(N);
        int diff = 0;

        for (int i = 0; i < N; i++){
            diff += 2 * (binstr[i] - '0') - 1;
            diffvec[i] = abs(diff);
        }

        char ans[N + 1];
        for (int i = 1; i < N; i++){
            ans[i] = '0';
        }

        ans[0] = '1';
        int final = diffvec[N - 1];
        int t = final - final % K;
        int j = N - 1;

        while (j > -1 && t > 0){
            if (diffvec[j] == t){
                ans[j + 1] = '1';
                t = t - K;
            }

            j--;

        }

        for (int i = 0; i < N; i++){
            cout << ans[i];
        }

        cout << '\n';
    }
}