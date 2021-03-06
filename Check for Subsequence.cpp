#include<iostream>
using namespace std;


/*Function to check whether a given sequence denoted by sub_seq[] is a subsequence
 of the given Primary Sequnce denoted by seq[] */
bool is_SubSequence(string sub_seq[], string seq[], int sub_size, int seq_size) {
    
    int j = 0;
    
    for(int i = 0; i < seq_size; i++)
    {
        if(j == sub_size)
        { break; }
        
        if(sub_seq[j] == seq[i])
        { j++; }
    }
    
    if(j != 0 && j == sub_size)
    { return true; }
    
    return false;
}

/* The time complexity of the program is denoted by the size of the primary sequence; which is the worst-case time
 if the given subsequence is of the same size as the Primary Sequence. Therefore, the worst-case time is given by O(n) where
 n is the seq_size */

int main() {
    
    string visited[] = {"buy Yahoo", "buy eBay", "buy Yahoo", "buy Oracle"};
    string sites[] = {"buy Amazon", "buy Yahoo", "buy eBay", "buy Yahoo", "buy Yahoo", "buy Oracle"};
    
    int visited_size = sizeof(visited) / sizeof(string);
    int sites_size = sizeof(sites) / sizeof(string);
    
    if(is_SubSequence(visited, sites, visited_size, sites_size))
    { cout << "Subsequence" << endl; }
    
    else
    { cout << "Not a Subsequence" << endl; }
    
    return 0;
}
