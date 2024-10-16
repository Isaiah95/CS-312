#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int, int> > SUM2_LinearSearch (int A1[], int A2[], int n1, int n2, int x)
{
   //use this variable to insert the results
   vector<pair<int, int> > pairs;   

   //YOUR CODE FOR SUM2 WITH LINEAR SEARCH GOES HERE
   for (int i = 0; i < n1; i++) {
       for (int j = 0; j < n2; j++) {
           if (A1[i] + A2[j] == x) {
               pairs.push_back(make_pair(A1[i], A2[j]));
           }
       }
   }
   return pairs;
}

vector< pair<int, int> > SUM2_BinarySearch (int A1[], int A2[], int n1, int n2, int x)
{
   //use this variable to insert the results
   vector<pair<int, int> > pairs;
   
   // Sort the second array for binary search
   sort(A2, A2 + n2);

   //YOUR CODE FOR SUM2 WITH BINARY SEARCH GOES HERE
   for (int i = 0; i < n1; i++) {
       int target = x - A1[i];
       if (binary_search(A2, A2 + n2, target)) {
           pairs.push_back(make_pair(A1[i], target));
       }
   }

   return pairs;
}

int main()
{
    //TEST THE FUNCTIONS WITH INPUTS FROM FIRST EXERCISE
    //Notice that array2 must be sorted for binary search to work
    int A1[] = {4,5,2,7,8,10};
    int A2[] = {1,9,-4,12,-7,-6};  
  
    vector< pair<int, int> > result = SUM2_LinearSearch(A1, A2, 6, 6, 3);
    cout << "\n===== TEST 1 with SUM2_LinearSearch =====\n";
    for(int i=0; i < result.size(); i++){
          cout << "(" << result[i].first << ", " << result[i].second << ")\n";
    }

    result = SUM2_BinarySearch(A1, A2, 6, 6, 3);
    cout << "\n===== TEST 1 with SUM2_BinarySearch =====\n";
    for(int i=0; i < result.size(); i++){
          cout << "(" << result[i].first << ", " << result[i].second << ")\n";
    }

    // Additional tests
 
  
    result = SUM2_LinearSearch(A1, A2, 6, 6, 0);
    cout << "\n===== TEST 2 with SUM2_LinearSearch =====\n";
    for(int i=0; i < result.size(); i++){
          cout << "(" << result[i].first << ", " << result[i].second << ")\n";
    }

    result = SUM2_BinarySearch(A1, A2, 6, 6, 0);
    cout << "\n===== TEST 2 with SUM2_BinarySearch =====\n";
    for(int i=0; i < result.size(); i++){
          cout << "(" << result[i].first << ", " << result[i].second << ")\n";
    }

    int A5[] = {4,5,2,7,8,10};
    int A6[] = {1,9,-4,12,-7,-6};  
  
    result = SUM2_LinearSearch(A1, A2, 6, 6, 7);
    cout << "\n===== TEST 3 with SUM2_LinearSearch =====\n";
    for(int i=0; i < result.size(); i++){
          cout << "(" << result[i].first << ", " << result[i].second << ")\n";
    }

    result = SUM2_BinarySearch(A1, A2, 6, 6, 7);
    cout << "\n===== TEST 3 with SUM2_BinarySearch =====\n";
    for(int i=0; i < result.size(); i++){
          cout << "(" << result[i].first << ", " << result[i].second << ")\n";
    }

    int A3[] = {5,2,7,-8,10,-20,13,64,0,-36,-10,-4,-44};
    int A4[] = {1,2,3,5,6,7,8,10,12,13,14,15,16,17,19,20,21,22,23,25,26,27,28,30,31,33,34,35,36,37,41,41,43,44,47,48,49,50,51,52,53,54,56,57,58,63,64,65,67,68,69,70,75,80};  
  
    result = SUM2_LinearSearch(A3, A4, 13, 64, 14);
    cout << "\n===== TEST 4 with SUM2_LinearSearch =====\n";
    for(int i=0; i < result.size(); i++){
          cout << "(" << result[i].first << ", " << result[i].second << ")\n";
    }

    result = SUM2_BinarySearch(A3, A4, 13, 64, 14);
    cout << "\n===== TEST 4 with SUM2_BinarySearch =====\n";
    for(int i=0; i < result.size(); i++){
          cout << "(" << result[i].first << ", " << result[i].second << ")\n";
    }
}