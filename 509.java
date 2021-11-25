class Solution509 {
    public int fib(int n) {
        if(n<2)return n;
        int i=0,j=1,k=1;
        for(int m=2;m<=n;m++){
            k=i+j;
            i=j;
            j=k;
        }
        return k;
    }
};