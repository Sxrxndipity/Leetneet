/* this is like a reverse fibonacci seqeunce where f(n) = f(n-1) + f(n-2)*/
int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    return climbStairs(n-1) + climbStairs(n-2);
}
