#include<iostream>
#include<ctime>
#include<stack>

// Q9. Triathlon Program, By Nikhil Bisht MCA 3rd Sem Roll No.24

using namespace std;

#define APPLICANTS Contestant::contestant_count
#define TOTAL_SWIM Contestant::total_swimTime

struct StartOrder {
    
    int bikeRunTime; // (Bike + Running) time of each participant
    int sno;        // Unique serial no. of each participant
};

class Contestant {
    
    int swim_time;      // Projected Swimming time
    int bike_time;      // Projected Bike time
    int run_time;       // Projected Running time
    
public:
    
    static int contestant_count; // Total No. of participating contestants
    static int total_swimTime; // Total sum of Swimming Time of all the participating contestants
    
  
    Contestant(int swim_time, int bike_time, int run_time)
    { this->swim_time = swim_time;
      this->bike_time = bike_time;
      this->run_time = run_time;
        
      contestant_count++;               // Increments for each new participant
      total_swimTime += swim_time;
    }
    
    int getSwimTime()
    { return swim_time; }

    int getBikeTime()
    { return bike_time; }
    
    int getRunTime()
    { return run_time; }
    
};

int Contestant::contestant_count = 0;
int Contestant::total_swimTime = 0;


int quickSort_partition(StartOrder arr[], int start, int end) {
    
    StartOrder pivot = arr[end];
    int part_index = start;
    
    for(int i = start; i < end; i++)
    {
        if(arr[i].bikeRunTime > pivot.bikeRunTime)
        {
            StartOrder temp = arr[i];
            arr[i] = arr[part_index];
            arr[part_index] = temp;
            
            part_index++;
        }
    }
    
    StartOrder temp = arr[end];
    arr[end] = arr[part_index];
    arr[part_index] = temp;
    
    return part_index;
}


//Randomly picks an index value for pivot to be used in the partition function
int randomizePartition(StartOrder arr[], int start, int end)
{
    int random = start + rand() % (end - start);
    
    StartOrder temp = arr[random];
    arr[random] = arr[end];
    arr[end] = temp;
    
    return quickSort_partition(arr, start, end);
}


// Randomized Iterative Quicksort for sorting the Starting Order of Participants in Decreasing order of their (Bike + Running) time.
void quick_sort(StartOrder arr[], int start, int end) {
    
    stack<int> S;
    
    S.push(start);
    S.push(end);
    
    while(!S.empty())
    {
        end = S.top();
        S.pop();
        
        start = S.top();
        S.pop();
        
        int mid = randomizePartition(arr, start, end);
        
        if(mid - 1 > start)
        {
            S.push(start);
            S.push(mid - 1);
        }
        
        if(mid + 1 < end)
        {
            S.push(mid + 1);
            S.push(end);
        }
    }
}



int main() {
    
    srand(static_cast<unsigned int>(time(NULL)));
    
    
    //Participating Contestants --- Swim, Bike, Run time, respectively.
    Contestant contest_1(20, 25, 20);
    Contestant contest_2(15, 10, 15);
    Contestant contest_3(40, 20, 30);
    Contestant contest_4(25, 30, 25);
    
    Contestant participant[] = {contest_1, contest_2, contest_3, contest_4};
    
    StartOrder bikeRunOrder[APPLICANTS];  // The order in which Contestants will begin based on their (Bike + Running) Time
    
    for(int i = 0; i < APPLICANTS; i++)
    { bikeRunOrder[i].bikeRunTime = participant[i].getBikeTime() +  participant[i].getRunTime();
      bikeRunOrder[i].sno = i+1; }
    
    quick_sort(bikeRunOrder, 0, APPLICANTS - 1); // Sorting Participants in decreasing value of their (Bike + Running) Time
    
    int total_EventTime = 0;
    
    total_EventTime = TOTAL_SWIM + bikeRunOrder[APPLICANTS - 1].bikeRunTime;
    int prev_swimTime = 0;
    
    
    //The main loop which checks for every possible longest time for completing the event via Greedy Approach
    for(int i = APPLICANTS - 2; i >= 0; i--)
    {
      prev_swimTime += participant[bikeRunOrder[i+1].sno - 1].getSwimTime();
            
       if(bikeRunOrder[i].bikeRunTime + TOTAL_SWIM - prev_swimTime > total_EventTime)
       { total_EventTime = bikeRunOrder[i].bikeRunTime + TOTAL_SWIM - prev_swimTime; }
    }
    
    
    cout << "The Order in which the Constestants will go:-" << endl << endl;
    
    for(int i = 0; i < APPLICANTS; i++)
    { cout << "Participant #" << bikeRunOrder[i].sno << "\t\t"; }
    
    cout << endl << endl << endl;
    
    cout << "Total Time to finish the Triathlon(in Minutes): " << total_EventTime << " min.";
    
    cout << endl << endl;
    
    return 0;
    
}
