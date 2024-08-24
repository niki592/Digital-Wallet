#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Structure to hold user information
struct User {
    int userID;
    int balance;
};

// Function to sort users by balance, and by userID if balances are equal
bool compareUsers(const User &a, const User &b) {
    if (a.balance == b.balance)
        return a.userID < b.userID;
    return a.balance < b.balance;
}

int main() {
    int N;
    cin >> N;

    unordered_map<int, int> userBalances;
    vector<User> users(N);

    // Reading users and their balances
    for (int i = 0; i < N; ++i) {
        cin >> users[i].userID >> users[i].balance;
        userBalances[users[i].userID] = users[i].balance;
    }

    int T;
    cin >> T;

    // Processing transactions
    for (int i = 0; i < T; ++i) {
        int from_userID, to_userID, amount;
        cin >> from_userID >> to_userID >> amount;

        // Check if the transaction can be processed
        if (userBalances[from_userID] >= amount) {
            userBalances[from_userID] -= amount;
            userBalances[to_userID] += amount;
            cout << "Success" << endl;
        } else {
            cout << "Failure" << endl;
        }
       
    }
    cout<<endl;
    

    // Update the users' balances after all transactions
    for (int i = 0; i < N; ++i) {
        users[i].balance = userBalances[users[i].userID];
    }

    // Sorting users by balance (ascending order)
    sort(users.begin(), users.end(), compareUsers);

    // Output the users sorted by balance
    for (const auto &user : users) {
        cout << user.userID << " " << user.balance << endl;
    }

    return 0;
}
