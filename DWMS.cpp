#include <iostream>
using namespace std;

void processTransaction(int from_user, int to_user, int amount, int balances[], int n) {
    if (balances[from_user - 1] >= amount) {
        balances[from_user - 1] -= amount;
        balances[to_user - 1] += amount;
        cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
    }
}

void bubbleSort(int user_ids[], int balances[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (balances[j] > balances[j + 1]) {

                int temp = balances[j];
                balances[j] = balances[j + 1];
                balances[j + 1] = temp;
                
                int tempId = user_ids[j];
                user_ids[j] = user_ids[j + 1];
                user_ids[j + 1] = tempId;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int user_ids[n], balances[n];
    for (int i = 0; i < n; i++) {
        cin >> user_ids[i] >> balances[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int from_user, to_user, amount;
        cin >> from_user >> to_user >> amount;
        processTransaction(from_user, to_user, amount, balances, n);
    }

    cout << endl;

    bubbleSort(user_ids, balances, N);
    for (int i = 0; i < n; i++) {
        cout << user_ids[i] << " " << balances[i] << endl;
    }
    return 0;
}
