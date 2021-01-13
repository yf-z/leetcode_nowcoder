class Solution {
public:
    long mask[2] = {0x00000000, 0xFFFFFFFF};
    int Sum_Solution(int n) {
        unsigned int middle = ((n+1)>>1)&mask[n&1];
        return multi(n+1, n >> 1)+middle;
    }
    
    int multi(int a, int b) {
        int result = 0;
        bool stop = (b != 0) && (result = (a & mask[b&1]) + multi(a << 1, b >> 1));
        return result;
    }
};