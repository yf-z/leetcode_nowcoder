class Solution {
public:
    double Power(double base, int exponent) {
       if (exponent >= 0)
           return PowerSub(base,exponent);
        
        return PowerSub(1/base, exponent);
    }
    
    double PowerSub(double base, int exponent) {
         if (base == 0)
            return 0;
        
        if (exponent == 0)
            return 1;
        
        if (exponent == 2)
            return base*base;
        
        if (exponent%2 == 0) {
            return PowerSub(base*base, exponent/2);
        }
        
        return PowerSub(base*base, exponent/2)*base;
    }
};