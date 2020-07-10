class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
	list<string> words;
	vector<vector<string> > ret;

    sort(products.begin(), products.end());
	for (int i = 0; i < products.size(); ++i) {
		words.push_back(products[i]);
	}
	
	for (int i = 0; i < searchWord.length(); ++i) {
		vector<string> vec;
		for (list<string>::iterator iter = words.begin(); iter != words.end();) {
			if (iter->length() <= i || (*iter)[i] != searchWord[i]) {
				iter = words.erase(iter);
				continue;
			}
            if (vec.size() < 3) {
                vec.push_back(*iter);
            }
            ++iter;
		}
		ret.push_back(vec);
	}
	return ret;
  }

};
