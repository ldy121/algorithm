class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		unordered_map<string, vector<string> > contentMap;
		vector<vector<string> > ret;
		vector<string> mapKey;

		for (int i = 0; i < paths.size(); ++i) {
			string str = paths[i];
			int idx = 0;
			while (str[++idx] != ' ');
			string dir = str.substr(0, idx);

			for (;idx < str.length(); ++idx) {
				int fileIdx = ++idx;
				while (str[++idx] != '(');
				string fileName = str.substr(fileIdx, idx - fileIdx);

				int contentIdx = ++idx;
				while (str[++idx] != ')');
				string content = str.substr(contentIdx, idx - contentIdx);

				if (contentMap.find(content) == contentMap.end()) {
					mapKey.push_back(content);
					contentMap[content] = vector<string>();
				}

				contentMap[content].push_back(dir + "/" + fileName);
			}
		}

		for (int i = 0; i < mapKey.size(); ++i) {
			if (contentMap[mapKey[i]].size() > 1) {
				ret.push_back(contentMap[mapKey[i]]);
			}
		}

		return ret;
	}
};
