class Solution {
private :
   string intToString(int val) {
	stack<char> sp;
	string ret;
	while (val > 0) {
        char ch = (val % 10) + '0';
		sp.push(ch);
		val /= 10;
	}
	while (!sp.empty()) {
		ret.append(1, sp.top());
		sp.pop();
	}
	return ret;
   }
    static bool comp(string a, string b) {
        if (a.length() < b.length()) {
            return true;
        } else if (a.length() > b.length()) {
            return false;
        } else {
            return a < b;
        }
    }
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_map<string, unordered_map<string, int> > table;
        unordered_map<string, bool> existFood;
        vector<string> keyTable;
        vector<string> keyFood;
        vector<string> header;
        vector<vector<string> > ret;
        
        for (int i = 0; i < orders.size(); ++i) {
            string tableNumber = orders[i][1];
            string foodName = orders[i][2];
            if (table.find(tableNumber) == table.end()) {
                keyTable.push_back(tableNumber);
                table[tableNumber] = unordered_map<string, int>();
            }
            if (table[tableNumber].find(foodName) == table[tableNumber].end()) {
                table[tableNumber][foodName] = 0;
            }
            if (existFood.find(foodName) == existFood.end()) {
                existFood[foodName] = true;
                keyFood.push_back(foodName);
            }
            ++table[tableNumber][foodName];
        }
	    sort(keyTable.begin(), keyTable.end(), Solution::comp);
	    sort(keyFood.begin(), keyFood.end());

	    header.push_back("Table");
	    for (int i = 0; i < keyFood.size(); ++i) {
    		header.push_back(keyFood[i]);
    	}
    	ret.push_back(header);

    	for (int i = 0; i < keyTable.size(); ++i) {
	    	string tableNumber = keyTable[i];
    		vector<string> content;
	    	content.push_back(tableNumber);
    		for (int j = 0; j < keyFood.size(); ++j) {
	    		string foodName = keyFood[j];
		    	content.push_back(
			      (table[tableNumber].find(foodName) != table[tableNumber].end()) ?
				    intToString(table[tableNumber][foodName]) : "0");
		    }
		    ret.push_back(content);
	    }
	
	    return ret;
    }

};
