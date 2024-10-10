class RandomizedSet 
{
/*
This would be a lot faster with a vector-backed implementation. Might come back to this one.
*/

private:
    unordered_set<int> m_set;

public:
    RandomizedSet() 
    {
        
    }
    
    bool insert(int val) 
    {
        if (m_set.count(val) == 0)
        {
            m_set.insert(val);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool remove(int val) 
    {
        if (m_set.count(val) != 0)
        {
            m_set.erase(val);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int getRandom() 
    {
        int i = 0;
        int j = rand() % m_set.size();

        for (int x : m_set)
        {
            if (i == j) return x;
            i++;
        }

        return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */