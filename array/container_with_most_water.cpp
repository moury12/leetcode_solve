#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/// container needs left right boundary so when left boundary at index 2 right boundary index need to more
/// than 2 . so water will be hold to short bondary , and width will be distance between left and right boundary so all posible
/// container and check by max function max num of water quantity
int maxAreaBruteForce(vector<int> &height)
{
    int ans = 0;
    int maxWater = 0;
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int heightWater = min(height[i], height[j]);
            int width = j - i;
            int ans = heightWater * width;
            maxWater = max(maxWater, ans);
        }
    }
    return maxWater;
}

int maxAreaTwoPointer(vector<int> &height)
{
    int ans = 0;
    int maxWater = 0;
   
        int leftHeight = 0;
        int rightHeight = height.size() - 1;
        while (leftHeight < rightHeight)
        {
            int heightWater = min(height[leftHeight], height[rightHeight]);
            int widthWate = rightHeight - leftHeight;
            int ans = heightWater * widthWate;
            maxWater = max(maxWater, ans);
            if (height[leftHeight] < height[rightHeight])
            {
                leftHeight++;
            }
            else
            {
                rightHeight--;
            }
        }
         return maxWater;
    }
   

int main()
{
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxAreaTwoPointer(heights);
}