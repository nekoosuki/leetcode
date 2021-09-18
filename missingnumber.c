#include <stdio.h>
int missingNumber(int* nums, int numsSize) {
    if (nums[0] == 1) return 0;
    if (nums[numsSize - 1] != numsSize + nums[0]) return numsSize;
    int p, q;
    p = (numsSize - 1) / 2;
    q = p + 1;
    if (nums[q] - nums[p] != 1) {
        return (nums[q] + nums[p]) / 2;
    } else {
        int expnum = (nums[0] + nums[numsSize - 1]) / 2;
        if (nums[p] == expnum && numsSize % 2 == 1) {
            //缺后面
            return missingNumber(nums + numsSize / 2, numsSize / 2 + 1);
        } else if (nums[p] != expnum && numsSize % 2 == 1) {
            //缺前面
            return missingNumber(nums, numsSize / 2 + 1);
        } else if (nums[p] == expnum && numsSize % 2 == 0) {
            //缺前面
            return missingNumber(nums, numsSize / 2 + 1);
        } else {
            //缺后面
            return missingNumber(nums + numsSize / 2, numsSize / 2);//todo
        }
    }
}

int main() {
    int a[] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
               15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
               30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
               45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
               60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74,
               75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 89, 90,
               91, 92, 93, 94, 95, 96, 97, 98, 99};
    int m = missingNumber(a, 99);
    printf("%d\n", m);
}