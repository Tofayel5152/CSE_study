#include <bits/stdc++.h>

using namespace std;


struct Activity {
    int start, end, weight, value;
};

struct knapsackItem {
    int weight, value;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int main() {
    int n, capacity;
    cout << "Enter number of activities and capacity: ";
    cin >> n >> capacity;

    vector<Activity> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].start >> items[i].end >> items[i].weight >> items[i].value;
    }

    sort(items.begin(), items.end(), compare);

    vector<knapsackItem> A;

    int take = 1;
    int lastEnd = items[0].end;

    for (int i = 1; i < n; i++) {
        if (items[i].start >= lastEnd) {
            take++;
            A.push_back({items[i].weight, items[i].value});

            lastEnd = items[i].end;
        }
    }
    
    cout << "Selected items (weight, value): " << endl;
    for (int i = 0; i < A.size(); i++) {
        cout << A[i].weight << " " << A[i].value << endl;
    }

    /*
    kecal accurate:

    #include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, end, weight, value;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int main() {
    int n, capacity;
    cout << "Enter number of activities and capacity: ";
    if (!(cin >> n >> capacity)) return 0;

    vector<Activity> items(n);
    cout << "Enter start, end, weight, value for each:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].start >> items[i].end >> items[i].weight >> items[i].value;
    }

    // 1. Activity Selection (Greedy)
    sort(items.begin(), items.end(), compare);

    vector<Activity> validActivities;
    if (n > 0) {
        validActivities.push_back(items[0]); // Add the first activity
        int lastEnd = items[0].end;

        for (int i = 1; i < n; i++) {
            if (items[i].start >= lastEnd) {
                validActivities.push_back(items[i]);
                lastEnd = items[i].end;
            }
        }
    }

    // 2. 0/1 Knapsack DP on the selected activities
    int m = validActivities.size();
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < m; i++) {
        for (int w = capacity; w >= validActivities[i].weight; w--) {
            dp[w] = max(dp[w], dp[w - validActivities[i].weight] + validActivities[i].value);
        }
    }

    cout << "--- Result ---" << endl;
    cout << "Non-overlapping activities found: " << m << endl;
    cout << "Maximum value within capacity " << capacity << " is: " << dp[capacity] << endl;

    return 0;
}
    
    
    */


    return 0;
}