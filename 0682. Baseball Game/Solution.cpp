class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        stack<int> scores;

        // long int strtol (const char* str, char** endptr, int base);

        for (const string& operation : operations)
        {
            int score = strtol(operation.c_str(), nullptr, 10);

            // Any zero score either represents:
            // - an operation, so we don't need to push it
            // - zero point, which has no effect
            if (score != 0) scores.push(score);
            else
            {
                if (strcmp(operation.c_str(), "+") == 0)
                {
                    // We can pop two safely because the constraints guarantee
                    // at least two previous scores on the record for "+"
                    int score1 = scores.top();
                    scores.pop();
                    int score2 = scores.top();
                    scores.pop();

                    int sumOfPreviousTwo = score1 + score2;
                    scores.push(score2);
                    scores.push(score1);
                    scores.push(sumOfPreviousTwo);
                }
                else if (strcmp(operation.c_str(), "D") == 0)
                {
                    // We can read one safely because the constraints guarantee
                    // at least one previous score on the record for "D"
                    int prevScore = scores.top();
                    scores.push(prevScore * 2);
                }
                else if (strcmp(operation.c_str(), "C") == 0)
                {
                    // We can pop one safely because the constraints guarantee
                    // at least one previous score on the record for "C"
                    scores.pop();
                }
            }
        }

        int sumOfScores = 0;
        while (!scores.empty())
        {
            sumOfScores += scores.top();
            scores.pop();
        }

        return sumOfScores;
    }
};