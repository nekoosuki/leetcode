import java.util.*;
class Solution496 {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> s = new Stack<Integer>();
        HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();

        int[] res = new int[nums1.length];

        for(int e:nums2){
            while(!s.empty()&&s.peek()<e){
                m.put(s.pop(),e);
            }
            s.push(e);
        }
        
        for(int i=0;i<nums1.length;i++){
            res[i] = m.getOrDefault(nums1[i], -1);
        }
        return res;
    }
}