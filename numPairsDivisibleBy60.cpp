/*
1010. 总持续时间可被 60 整除的歌曲
在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。
返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望下标数字 i 和 j 满足  i < j 且有 (time[i] + time[j]) % 60 == 0。
*/

/*
输入：time = [30,20,150,100,40]
输出：3
解释：这三对的总持续时间可被 60 整除：
(time[0] = 30, time[2] = 150): 总持续时间 180
(time[1] = 20, time[3] = 100): 总持续时间 120
(time[1] = 20, time[4] = 40): 总持续时间 60

注意：
1 <= time.length <= 6 * 104
1 <= time[i] <= 500
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public: 
    int numPairsDivisibleBy60(vector<int> &time) {
        int ans = 0, cnt[60] = { 0 };
        for (int t : time) {
            ans += cnt[(60 - t % 60) % 60];
            cnt[t % 60]++;
        }
        return ans;
    }
};

int main()
{
    vector<int> time;
    time.push_back(30);
    time.push_back(20);
    time.push_back(150);
    time.push_back(100);
    time.push_back(40);
    Solution s;
    int res = s.numPairsDivisibleBy60(time);
    cout << "The result is:" << res << endl;
    return 0;
}