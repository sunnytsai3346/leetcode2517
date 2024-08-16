#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    bool canPickCandies(std::vector<int>& price, int k, int min_diff) {
        int count = 1;  // We always pick the first candy
        int last_price = price[0];
        std::cout <<"min_diff:" << min_diff<< "\n";
        
        for (int i = 1; i < price.size(); ++i) {
            if (price[i] - last_price >= min_diff) {
                count++;
                std::cout << count-1 << " :"<<price[i] <<","<<last_price<<"\n";
                last_price = price[i];
            }
            if (count == k) return true;
        }
        return false;
    }

    int maximumTastiness(std::vector<int>& price, int k) {
        std::sort(price.begin(), price.end());
        for (auto& it : price)
        {
            std::cout <<it << " ";
        }
        int left = 0;
        int right = price.back() - price.front();
         std::cout <<"price.back()" << price.back() << " ,price.front()" << price.front() <<"\n" ;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canPickCandies(price, k, mid)) {
                result = mid;
                left = mid + 1;  // Try for a bigger minimum difference
            } else {
                right = mid - 1;  // Try for a smaller minimum difference
            }
        }
        return result;
    }
};    
    int main()
    {
        Solution s;
        std::vector<int> price = {13,5,1,8,21,2};
        int k=3;
        int result=0 ;
        result = s.maximumTastiness(price,k);
        std::cout << result <<" ";
        return 0;
    }
