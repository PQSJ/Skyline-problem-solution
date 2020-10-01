#include <bits/stdc++.h> 
using namespace std; 
  
// Function to create skyline 
vector<pair<int, int> > 
createSkyline(vector<vector<int> >& buildings) 
{ 
  
    // Get the number of buildings 
    int N = buildings.size(); 
  
    // To store the left and right 
    // wall position of the buildings 
    vector<pair<int, int> > wall; 
  
    // Triplet of building structure 
    // parameters 
    int left, height, right; 
    for (int i = 0; i < N; i++) { 
  
        // Get left point of building 
        left = buildings[i][0]; 
  
        // Get height of building 
        height = buildings[i][1]; 
  
        // Get right point of building 
        right = buildings[i][2]; 
  
        // Store left point and height 
        // of the left wall 
  
        // Negative value means left wall 
        // will be inserted to multiset first 
        // for the same abscissa(x) as right wall 
        wall.push_back({ left, -height }); 
  
        // Store right point and height 
        // of the right wall 
        wall.push_back( 
            make_pair(right, height)); 
    } 
  
    // Sort the walls in ascending order 
    sort(wall.begin(), wall.end()); 
  
    // To store skyline: output 
    vector<pair<int, int> > skyline; 
  
    // Initialize a multiset to 
    // keep left wall heights sorted 
    multiset<int> leftWallHeight = { 0 }; 
  
    // Current max height among 
    // leftWallHeights 
    int top = 0; 
  
    // Traverse through the sorted walls 
    for (auto w : wall) { 
  
        // If left wall is found 
        if (w.second < 0) { 
  
            // Insert the height 
            leftWallHeight.insert(-w.second); 
        } 
  
        // If right wall is found 
        else { 
  
            // Remove the height 
            leftWallHeight.erase( 
                leftWallHeight.find(w.second)); 
        } 
  
        // Mark a skyline point if top changes 
        // .rbegin(): reverse iterator 
        if (*leftWallHeight.rbegin() != top) { 
  
            top = *leftWallHeight.rbegin(); 
            skyline.push_back( 
                make_pair(w.first, top)); 
        } 
    } 
  
    // Return skyline to printSkyline 
    return skyline; 
} 
  
// Function to print the output skyline 
void printSkyline( 
    vector<vector<int> >& buildings) 
{ 
  
    // Function call for creating skyline 
    vector<pair<int, int> > skyline 
        = createSkyline(buildings); 
  
    cout << "Skyline for given"
         << " buildings:\n{"; 
  
    for (auto it : skyline) { 
  
        cout << "{" << it.first << ", "
             << it.second << "} "; 
    } 
    cout << "}"; 
} 
  
// Driver Code 
int main() 
{ 
    vector<vector<int> > buildings;blockquote 
  
    // Given left and right location 
    // and height of the wall 
    buildings = { { 1, 11, 5 }, { 2, 6, 7 },  
                  { 3, 13, 9 }, { 12, 7, 16 }, 
                  { 14, 3, 25 }, { 19, 18, 22 }, 
                  { 23, 13, 29 }, { 24, 4, 28 } }; 
  
    // Function Call 
    printSkyline(buildings); 
    return 0; 
} 
