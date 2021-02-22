class Solution {
private :
    vector<int> m_sequence;
    void getSequence(int low, int high, int val) {
        if (((val % 10) == 0) || (high < val)) {
            return;
        } else {
            if (low <= val) {
                m_sequence.push_back(val);
            }
            getSequence(low, high, val * 10 + (val % 10 + 1));            
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        for (int i = 1; i <= 9; ++i) {
            getSequence(low, high, i);
        }
        sort(m_sequence.begin(), m_sequence.end());
        return m_sequence;
    }
};
