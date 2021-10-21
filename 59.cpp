#include <vector>
#include <iostream>
using namespace std;
#define TO_RIGHT 0
#define TO_BOTTOM 1
#define TO_LEFT 2
#define TO_TOP 3
class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int top = 0, left = -1, bottom = n, right = n;
        int c = 1;
        int i = 0, j = 0;
        int state = TO_RIGHT;
        while (!(bottom-top==1&&right-left==1)) {
            res[j][i] = c++;
            switch (state) {
                case TO_RIGHT:
                    if (++i >= right) {
                        i--;
                        j++;
                        right--;
                        state = TO_BOTTOM;
                    }
                    break;
                case TO_BOTTOM:
                    if (++j >= bottom) {
                        j--;
                        i--;
                        bottom--;
                        state = TO_LEFT;
                    }
                    break;
                case TO_LEFT:
                    if (--i <= left) {
                        i++;
                        j--;
                        left++;
                        state = TO_TOP;
                    }
                    break;
                case TO_TOP:
                    if (--j <= top) {
                        j++;
                        i++;
                        top++;
                        state = TO_RIGHT;
                    }
                    break;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.generateMatrix(3);
    return 0;
}

