class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        bool carry = true;
        int currentDigitIndex = digits.size() - 1;

        while (currentDigitIndex >= 0 && carry)
        {
            int digit = digits[currentDigitIndex];
            if (digit < 9)
            {
                digits[currentDigitIndex]++;
                carry = false;
            }
            else
            {
                digits[currentDigitIndex] = 0;
            }


            currentDigitIndex--;
        }

        if (currentDigitIndex < 0 && carry)
        {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};