class Solution 
{
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> answer;

        for (int i = 1; i <= n; i++)
        {
            bool divisibleBy3 = (i % 3 == 0);
            bool divisibleBy5 = (i % 5 == 0);

            if (divisibleBy3 && divisibleBy5) answer.push_back("FizzBuzz");
            else if (divisibleBy3) answer.push_back("Fizz");
            else if (divisibleBy5) answer.push_back("Buzz");
            else answer.push_back(to_string(i));
        }

        return answer;        
    }
};