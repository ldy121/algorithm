class Solution {
private :
    vector<vector<int> > m_answer;
    int m_n;
    int m_k;

    void getAnswer(vector<int> vec, int idx) {
        vec.push_back(idx);

        if (vec.size() < m_k) {
            for (int i = idx + 1; i <= m_n; ++i) {
                getAnswer(vec, i);
            }
        } else {
            m_answer.push_back(vec);            
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        m_n = n;
        m_k = k;
        for (int i = 1; i <= n; ++i) {
            getAnswer(vector<int>(), i);
        }
        return m_answer;
    }
};
