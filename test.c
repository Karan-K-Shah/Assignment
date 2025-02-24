#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void twoSum(int targetSum, int array[], int nums, unordered_map<int, vector<int>>& indexMap) {
    // Populate the index map with element-value pairs
    for (int i = 0; i < nums; i++) {
        indexMap[array[i]].push_back(i);
    }

    // Check each element to find if its complement exists in the array
    for (int i = 0; i < nums; i++) {
        int current = array[i];
        int complement = targetSum - current;

        // Check if the complement exists and hasn't been used before with any other index
        if (indexMap.find(complement) != indexMap.end()) {
            for (int j : indexMap[complement]) {
                if (j != i) {
                    return make_pair(j, i);
                }
            }
        }
    }

    // If no pair found, return (-1, -1)
    return make_pair(-1, -1);
}

int main() {
    int targetSum = 10;
    int array[] = {3, 8, 7, 2};
    int nums = 4;
    unordered_map<int, vector<int>> indexMap;

    // Call the twoSum function
    auto result = twoSum(targetSum, array, nums, indexMap);

    if (result.first == -1 && result.second == -1) {
        cout << "No pair found" << endl;
    } else {
        cout << "Indices of two numbers: (" << result.first << ", " << result.second << ")" << endl;
    }

    // Example continuation for multiple pairs
    if (result.first != -1) {
        // Reset the index map to allow finding another pair
        auto resetResult = twoSum(targetSum, array, nums, indexMap);
        if (resetResult.first != -1 && resetResult.second != -1) {
            cout << "Another valid pair: (" << resetResult.first << ", " << resetResult.second << ")" << endl;
        } else {
            cout << "No more pairs found" << endl;
        }
    } else {
        cout << "Only one pair found or none" << endl;
    }

    return 0;
}