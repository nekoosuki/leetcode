import java.util.*;
class Solution402 {
    public String removeKdigits(String num, int k) {
        int l = num.length();
        Deque<Character> stack = new ArrayDeque<Character>();
        int count = l-k;
        if(count == 0)return "0";
        StringBuilder res = new StringBuilder();
        for(int i=0;i<num.length();i++){
            while(!stack.isEmpty()&&stack.peekLast()>num.charAt(i)&&stack.size()+num.length()-i-1>=count){
                stack.removeLast();
            }
            if(stack.size()<count)
            stack.addLast(num.charAt(i));
        }
        while(!stack.isEmpty()){
            char c = stack.removeFirst();
            if(res.length()==0&&c=='0')continue;
            res.append(c);
        }
        if(res.length()==0)return "0";
        return res.toString();
    }
}
