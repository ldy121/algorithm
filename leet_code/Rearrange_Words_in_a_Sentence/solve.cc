class Solution {
private :
    static vector<string> m_answer;
    void split(string &text) {
        string str;

        m_answer.clear();
        
        for (int i = 0; i < text.length(); ++i) {
            if (text[i] == ' ') {
                m_answer.push_back(str);
                str = "";
            } else {
                char ch = (text[i] >= 'A' && text[i] <= 'Z') ?
                    (text[i] - 'A' + 'a') : text[i];
                str += ch;
            }
        }
        m_answer.push_back(str);
    }
    
    static bool comp(int a, int b) {
        return (m_answer[a].length() < m_answer[b].length()) || 
            (m_answer[a].length() == m_answer[b].length() && a < b);
    }

public:
    string arrangeWords(string text) {
        vector<int> vec;
        string ret;

        split(text);
        
        for (int i = 0; i < m_answer.size(); ++i) {
            vec.push_back(i);
        }

        sort(vec.begin(), vec.end(), Solution::comp);

        ret += m_answer[vec[0]];
        for (int i = 1; i < vec.size(); ++i) {
            ret += ' ';
            ret += m_answer[vec[i]];
        }
        ret[0] = ret[0] - 'a' + 'A';
        return ret;
    }
};
vector<string> Solution::m_answer;
