#include <vector>
#include <algorithm>
using namespace std;

// 最简便版本
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = i + 1; j < nums.size(); j++)
      {
        if (nums[i] + nums[j] == target)
        {
          result.push_back(i);
          result.push_back(j);
        }
      }
    }
    return result;
  }
};

// 排序
class Solution2
{
public:
  struct KV
  {
    int val;
    int index;
  };
  vector<int> twoSum(vector<int> &nums, int target)
  {
    vector<int> result;

    auto comp = [](KV x, KV y) -> bool
    { return (x.val < y.val); };

    vector<KV> data(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
      data[i].index = i;
      data[i].val = nums[i];
    }

    sort(data.begin(), data.end(), comp);
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
      while (i < j && data[i].val + data[j].val < target)
      {
        i++;
      }
      while (i < j && data[i].val + data[j].val > target)
      {
        j--;
      }
      if (data[i].val + data[j].val == target)
      {
        result.push_back(data[i].index);
        result.push_back(data[j].index);
        break;
      }
    }
    return result;
  }
};