#include <iostream>
#include <vector>
#include <cmath> // For the abs() function
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size(); // Size of the array
        vector<int> ans; // To store missing numbers

        // Step 1: Mark the presence of elements by negating the value at the corresponding index
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1; // Calculate index (convert value to 0-based index)
            if (nums[index] > 0) {
                nums[index] = -nums[index]; // Negate the value at the index to mark presence
            }
        }

        // Step 2: Collect indices with positive values, which correspond to missing numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1); // Missing number is (index + 1)
            }
        }

        return ans; // Return the result
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the vector: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    vector<int> missingNumbers = solution.findDisappearedNumbers(nums);

    cout << "The missing numbers are: ";
    for (int num : missingNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}