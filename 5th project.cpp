#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
       int profit, weight;
};
bool cmp(Item a, Item b) {
     double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
     return r1 > r2;
}
double fractionalKnapsack(int W, Item arr[], int n) {
                  sort(arr, arr+n, cmp);
            double totalProfit = 0.0;
             for (int i = 0; i < n; i++) {
             if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalProfit += arr[i].profit;
           } else {
            totalProfit +=arr[i].profit * ((double)W / arr[i].weight);
             break;
    }
    }
    return totalProfit;
}
int main() {

Item items[] = {{60,10}, {100,20}, {120,30}, {50,5}};
     int W = 20;
     int n = sizeof(items)/sizeof(items[0]);
    cout << "Maximum Profit (Fractional Knapsack, capacity " << W << ") = "
         << fractionalKnapsack(W, items, n) << endl << endl;
return 0;
}
