class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
    	vector<string> vec;
        string ret;
        int start = 0;
        
        sort(dict.begin(), dict.end());
        
        for (int i = 0; i < sentence.length(); ++i) {
	        if (sentence[i] == ' ') {
		        vec.push_back(sentence.substr(start, i - start));
		        start = i + 1;
	        }
        }
        if (start < sentence.length()) {
	        vec.push_back(sentence.substr(start, sentence.length() - start));
        }
        
        for (int i = 0; i < vec.size(); ++i) {
	        int j = 0;
	        for (j = 0; j < dict.size(); ++j) {
		        if (vec[i].find(dict[j]) == 0) {
			        break;
		        }
	        }

	        if (j == dict.size()) ret += vec[i];
	        else ret += dict[j];

	        if (i < (vec.size() - 1)) {
		        ret += " ";
	        }
        }

        return ret;
    }
};


