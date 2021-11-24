import java.util.*;
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        //对数组排序
        //不放在下面方法里排序是为了减少不必要的性能消耗，不必在每次递归时都进行一次O(NlogN)的排序
        Arrays.sort(nums);
        return nSum(nums, 4, 0, target);
    }

    //设计一个n数之和的API
    public List<List<Integer>> nSum(int[] nums, int n, int start, int target) {
        int size = nums.length;
        List<List<Integer>> result = new ArrayList<>();

        //至少是2数之和并且数组长度至少要等于目标元素的个数
        if (n < 2 || size < n) {
            return result;
        }
        if (n == 2) {  //求2数之和，采用双指针法
            int left = start;
            int right = size - 1;
            while (left < right) {
                int leftElem = nums[left];
                int rightElem = nums[right];
                int sum = leftElem + rightElem;
                if (sum < target) {
                    //左指针右移+去重
                    while (left < right && nums[left] == leftElem) left++;
                } else if (sum > target) {
                    //右指针左移+去重
                    while (left < right && nums[right] == rightElem) right--;
                } else {
                    //加入一组元素
                    result.add(Arrays.asList(leftElem, rightElem));
                    //去重
                    while (left < right && nums[left] == leftElem) left++;
                    while (left < right && nums[right] == rightElem) right--;
                }
            } 
        } else {
            //大于2个数之和，采用递归计算
            for (int i = start; i < size; i++) {
                List<List<Integer>>  subResult= nSum(nums, n - 1, i + 1, 
                    target - nums[i]);
                //加入当前元素
                for (List<Integer> list : subResult) {
                    ArrayList<Integer> arrayList = new ArrayList<>();
                    arrayList.add(nums[i]);
                    arrayList.addAll(list);
                    result.add(arrayList);
                }
                //去重
                while (i < size - 1 && nums[i + 1] == nums[i]) {
                    i++;
                }
            }
        }
        return result;
    }
}