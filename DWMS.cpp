#include <iostream>
using namespace std;

void processTransaction(int from_user, int to_user, int amount, int balances[], int N) {
    if (balances[from_user - 1] >= amount) {
        balances[from_user - 1] -= amount;
        balances[to_user - 1] += amount;
        cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
    }
}

void bubbleSort(int user_ids[], int balances[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
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
    int N;
    cin >> N;
    int user_ids[N], balances[N];
    for (int i = 0; i < N; i++) {
        cin >> user_ids[i] >> balances[i];
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int from_user, to_user, amount;
        cin >> from_user >> to_user >> amount;
        processTransaction(from_user, to_user, amount, balances, N);
    }

    cout << endl;

    bubbleSort(user_ids, balances, N);
    for (int i = 0; i < N; i++) {
        cout << user_ids[i] << " " << balances[i] << endl;
    }
    return 0;
}