class Solution {
private :
    const int windowSize = 3;
    const char invalid = -1;

public:
    bool isValid(string S) {
        string& in = S;
        for (bool isChange = true; isChange;) { 
            string data;
            for (int i = 0; i < in.length(); ++i) {
                if (in[i] != invalid) {
                    data += in[i];
                }
            }
            
            isChange = false;
            for (string::size_type idx = data.find("abc", 0); 
                    idx != string::npos;
                    idx = data.find("abc", idx)) {
                data[idx] = data[idx + 1] = data[idx + 2] = invalid;
                isChange = true;
            }
            in = data;
        }
        
        return (in.length() == 0);
    }
};
