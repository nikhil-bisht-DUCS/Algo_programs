#include<iostream>
using namespace std;

// Q11. Shaktimaan Program, By Nikhil Bisht MCA 3rd Sem Roll No.24

int getGroups(int N, int K) {
    
    // If the value of N falls below the minimum no. people K, then it is not a valid group
    if(N < K && N > 0)
    { return 0; }
    
    else if(N == 0)
    { return 1; }
    
    else
    { return getGroups(N - K, K) + getGroups(N, K + 1); }
    // Tries out every possibility for getting groups made out of N people where K is for minimum no. of people required.
}

int main() {
    
    int N, K;
    
    cout << "Enter Total No. of People (N): ";
    cin >> N;
    
    cout << "Enter Minimum No. of People to be present in a group(K): ";
    cin >> K;
    
    cout << endl;
    
    if(N > 0 && K > 0 && N >= K)
    { cout << "With " << N << " no. of people, The number of ways we can form groups where each group has atleast " << K << " members: " <<  getGroups(N, K); }
    
    else
    { cout << "Kindly Provide valid Inputs...."; }
    
    cout << endl << endl;
    
    return 0;
    
}
