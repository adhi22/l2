#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> input;
    int n;
    cout << "ENter n : "; cin >> n;

    for(int i=0; i<n; i++) {
        int deadline, profit;
        cout << "Job " << i+1 << " : "; cin >> deadline >> profit;
        input.push_back({profit, i+1, deadline});
    }

    int slots[n];
    for(int i=0; i<n; i++) {
        slots[i] = -1;
    }

    sort(input.begin(), input.end());
    reverse(input.begin(), input.end());

    int profit = 0;
    for(int i=0; i<input.size(); i++) {
        for(int j=input[i][2]-1; j>=0; j--) {
            if(slots[input[i][2]] == -1) {
                slots[input[i][2]] == input[i][1];
                profit += input[i][0];
                break;
            }
        }
        // if(slots[input[i][2]-1] == -1) {
        //     slots[input[i][2]-1] == input[i][1];
        //     profit += input[i][0];
        // }
    }

    for(int i=0; i<n; i++) {
        cout << slots[i] << " ";
    }
    cout << "\nProfit : " << profit << endl;



    return 0;
}