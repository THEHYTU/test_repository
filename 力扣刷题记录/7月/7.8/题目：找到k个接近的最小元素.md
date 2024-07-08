## 题目：找到k个接近的最小元素

![image-20240708111702835](C:\Users\27811\AppData\Roaming\Typora\typora-user-images\image-20240708111702835.png)

### 解题思路一：

​		对结果进行模拟，对于x在数组内的情况，左边用栈右边用队列（保持相对顺序不变），对于x不在数组的情况，如果x小于nums[0],从0开始计数，如果x>nums[len-1],从len-1开始计数，由于是逐一比较，需要考虑左侧右侧是否达到边界，如果到了边界还没有获取到对应的值，break

```c++
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        stack<int> left;
        queue<int> right;
        vector<int> ans(k);
        int len = arr.size();
        //折半查找
        int Index = findX(arr, x, 0, len);
        //特殊情况特殊处理
        if (Index == -1)
        {
            for (int i = 0; i < k; i++)
                ans[i] = arr[i];
            return ans;
        }
        else if (Index == len)
        {
            int j = 0;
            for (int i = len - 1; j < k; j++, i--)
            {
                ans[j] = arr[i];
            }
            return ans;
        }
        //对于x周围数字开始检测
        int L = 1;
        int R = 1;
        right.push(x);
        k = k - 1;
        while (k)
        {
            
            //差值最小
            if ((Index - L) >= 0 && (Index + R) <= len - 1)
            {
                int Lv = arr[Index - L];
                int Rv = arr[Index + R];
                //谁小取谁
                abs(Lv - x) <= abs(Rv - x) ? left.push(Lv) : right.push(Rv);
                abs(Lv - x) <= abs(Rv - x) ? L++ : R++;
                k--;
               
            }
            else if ((Index + R) > len - 1)
            {
                if ((Index - L) >= 0)
                {
                    left.push(arr[Index - L]);
                    L++;
                    k--;
                }
                else
                    break;
            }
            else
            {
                if ((Index+R) <= len-1)
                {
                    right.push(arr[Index +R]);
                    R++;
                    k--;
                }
                else
                    break;
            }
        }
        int flag = 0;
        while (!left.empty())
        {
            ans[flag] = left.top();
            left.pop();
            flag++;
        }
        while (!right.empty())
        {
            ans[flag] = right.front();
            right.pop();
            flag++;
        }
      
        return ans;
    }
private:
    int findX(vector<int>& arr, int x,int start,int end)
    {
        int mid = (end - start) / 2 + start;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            return findX(arr, x, mid + 1, end);
        else if (arr[mid] > x)
            return findX(arr, x, start, mid - 1);
        else if (start == end && arr[mid] != x)
        {
            if (x < arr[0])
                return -1;
            return arr.size();
        }
    }
};
int main()
{
    vector<int> test = { 1,2,3,4,5 };
    Solution sol;
    vector<int>ans = sol.findClosestElements(test, 4, 3);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
```

### 解题思路二：

​	在二分中递归，对解题思路一进行优化，考虑左值右值问题，当数组长度小于k时，直接返回整个数组即可，对于数组大于k的情况，由于需要返回K个数，那么最后返回的Index一定满足右值减左值=k-1，这个作为循环条件，对左右两边进行讨论即可，如果左边大，左边++,如果右边大，右边--

```c++
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1;
        
        // 使用二分查找确定初始窗口位置
        while (right - left >= k) {
            if (abs(arr[left] - x) > abs(arr[right] - x)) {
                left++;
            } else {
                right--;
            }
        }
        
        // 将结果添加到 vector 中
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

```

### 解题思路三：

​	双指针。依然是建立在解题思路一的优化上，我们找到第一个不小于x的元素index，如果都小于，直接从0开始遍历数组到K个，或者说小于时遍历整个数组，如果大于x的元素存在，如果左边的元素个数为0，直接++到k,除此之外，比较x和左右值，左值大则右值++,右值大则左值--，由于右值++可能会等于size大小，这时候说明右边走完了，左边继续减减即可

```c++
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        // 找到第一个不小于 x 的元素的位置
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;
        
        // 使用双指针找到最接近的 k 个元素
        while (k--) {
            if (left < 0) {
                right++;
            } else if (right >= n) {
                left--;
            } else if (x - arr[left] <= arr[right] - x) {
                left--;
            } else {
                right++;
            }
        }
        
        // 将结果添加到 vector 中
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};

```

