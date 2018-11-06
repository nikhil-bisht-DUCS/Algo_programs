#include<iostream>
#include<cstdlib>

using namespace std;


//Knapsack Billboard, By Nikhil Bisht MCA 3rd Sem Roll No.24


int *final_bBoard ;


int maxBillBoard(int *x ,int s, int temp){
    
    int max = 0;
    int index = 0;
    
    for (int i = 0; i < s; ++i)            //        function used to find max bill board                                            //        on the basis of its revenue
    {                                    //        ( based on knapsack problem )
        if(max < x[i])                    //
        {
            max = x[i];
            index = i;
        }
    }
    
    if(temp == 0)
    { return max;}
    
    else
    { return index; }
    
}


int calculateRevenue(int *bill_board, int *revenue,int n,int t,int m){
    
    int max_revenue = 0;                            //
    int selected_bill_board = 0;                    //        function used to find and calculate
    
    int present_bill_board;                            //        possible and optimal revenue for the
    
    for (int i = 0; i < n; ++i)                        //        given problem
    {                                                //
        int *possible_bill_board,*possible_revenue;
        
        possible_revenue = new int [n-(i+1)];
        possible_bill_board = new int [n-(i+1)];
    
        
        present_bill_board = i;
        possible_bill_board[0] = bill_board[i];
        
        possible_revenue[0] = revenue[i];
        
        final_bBoard = new int [n-(i+1)];
        
        int k = 1;
        
        for (int j = i+1; j < n; ++j)
        {
            // checking the distane contraints with every pair or bill boards
            if( ( bill_board[i] -  bill_board[j] > t ) || ( bill_board[j] -  bill_board[i] > t ) )
            {
                possible_bill_board[k] = bill_board[j];
                possible_revenue[k] = revenue[j];
                k++;
            }
            
        }
        
        int r = 0;
        
        while(selected_bill_board + possible_bill_board[maxBillBoard(possible_revenue,n-(i+1),1)] <= m){
            
            int index = maxBillBoard(possible_revenue,n-(i+1),1);
            
            selected_bill_board = selected_bill_board+possible_bill_board[index];
            
            final_bBoard[r] = possible_bill_board[index];
            
            max_revenue  = max_revenue + possible_revenue[index];
            
            possible_bill_board[index] = 0;
            
            possible_revenue[index] = 0;
            
            r++;
        }
        
        cout << endl;
    }
    
    return max_revenue;
}


int main() {
    
    int N,M;
    
    int *bill_board, *revenue;
    
    cout << "Enter length of highway : ";
    cin >> M;
    
    cout << endl << "Assuming minimum distance between bill board is 5";
    int t = 5;
    
    cout << "\nEnter no. of bill boards : ";
    cin >> N;
    
    bill_board = new int[N];
    revenue = new int[N];
    
    cout<<"Enter details : ";
    
    cout<<"\nS.no     Bill Board             Revenue \n";
    
    for (int i = 0; i < N; ++i)
    {
        cout << i+1 << "        ";
        cin >> bill_board[i];
        
        cout << "              ";
        cin >> revenue[i];
        
        cout << endl;
    }
    int temp = calculateRevenue(bill_board,revenue,N,t,M);
  
    cout<<"\nMax Revenue : " << temp <<"\n";
    
    return 0;
}
/*
 
 Time Complexity:-
 
 In this process, we are computing values in the array .
 But for each element of array, array is again iterated for possible bill boards
 Therefore, T(n) = O(n^2)
 
 */

