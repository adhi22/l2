#include<iostream>
#include<algorithm>
using namespace std;

struct Job
{
   char jobID;
   int deadline;
   int profit;
};

// sorts jobs in decreasing order of profits
bool comparison(Job a, Job b)
{
     return (a.profit > b.profit);
}

void jobScheduling(Job arr[], int n)
{
    int profit = 0;
    sort(arr, arr+n, comparison);

    char resultSequence[n];
    bool slotAvailable[n];

    for(int i=0; i<n; i++){
        slotAvailable[i] = true;
        resultSequence[i] = '-';
    }

    for(int i=0; i<n; i++){
       for(int j=arr[i].deadline-1; j>=0; j--){
          if(slotAvailable[j] == true){
             resultSequence[j] = arr[i].jobID;
             slotAvailable[j] = false;

             profit += arr[i].profit;

             break;
          }
       }
    }

    for(int i=0; i<n; i++){
        if(resultSequence[i] != '-') cout << " " << resultSequence[i] << " ";
    }

    cout << "\n\n Maximum profit : " << profit << "\n\n";
}

int main()
{
    int jobs;
    char id;
    int dl, pr;
    cout << " Enter no. of jobs : ";
    cin >> jobs;

    Job arr[jobs];
    for(int i=0; i<jobs; i++){
        cout << "\n For job " << i+1 << " =>\n";
        cout << "\tJob ID : "; cin >> id;
        cout << "\tProfit : "; cin >> pr;
        cout << "\tDeadline : "; cin >> dl;

        arr[i] = {id, dl, pr};
    }

    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "\n\n Optimal Scheduling sequence : ";

    jobScheduling(arr, n);
    return 0;
}
