class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            vector<int> result;
            multimap<int, int> mapNums;
            for (int idx = 0; idx < nums.size(); ++idx)
                mapNums.insert(pair<int,int>(nums[idx], idx + 1));

            multimap<int,int>::iterator it = mapNums.begin();
            for (; it != mapNums.end(); ++it)
            {
                multimap<int,int>::iterator itFind = mapNums.find(target - it->first);
                if (itFind != mapNums.end())
                {
                    if (itFind == it)
                        ++itFind;
                    result.push_back(min(it->second, itFind->second));
                    result.push_back(max(it->second, itFind->second));
                    break;
                }
            }
            return result;
        }
};
