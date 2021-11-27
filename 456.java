import java.util.*;
class Solution {
    public boolean find132pattern(int[] nums) {
        Stack<Integer> s = new Stack<Integer>();
        int p2 = Integer.MIN_VALUE;
        for(int i=nums.length-1;i>=0;i--){
            if(nums[i] < p2)return true;
            while(!s.empty()&&nums[i]>s.peek()){
                p2 = s.peek();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
}