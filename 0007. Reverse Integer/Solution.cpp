class Solution 
{
public:
    int reverse(int x) 
    {
        bool isNegative = false;
        if (x < 0) 
        {
            isNegative = true;
            x = abs(x);
        }

        string xAsStr = to_string(x);
        ::reverse(xAsStr.begin(), xAsStr.end());

        long long reversedX = 0;
        int exponent = 0;

        for (int i = xAsStr.size() - 1; i >= 0; i--)
        {
            int digit = xAsStr[i] - '0';
            reversedX += digit * pow(10, exponent++);

            // This doesn't really handle the problem in spirit...
            if (reversedX > INT_MAX || reversedX < INT_MIN) return 0;
        }

        if (isNegative) reversedX = -reversedX;
        return reversedX;
    }
};