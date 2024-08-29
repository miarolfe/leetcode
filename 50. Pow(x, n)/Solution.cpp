class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;

        long longN = n;
        if (n < 0)
        {
            x = 1 / x;
            longN = -longN;
        }

        double xToTheN = 1;
        double current = x;

        while (longN > 0)
        {
            if (longN % 2)
            {
                xToTheN *= current;
            }
            current *= current;
            longN /= 2;
        }

        return xToTheN;
    }
};
