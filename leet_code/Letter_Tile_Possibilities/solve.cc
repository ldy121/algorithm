class Solution {
public:
	int get_answer(string& tile, vector<int>& histogram, unordered_map<string, int>& hash) {
		int ret = 0;

		if (hash.find(tile) == hash.end()) {
			ret = 1;
			hash[tile] = 1;

			for (int i = 0; i < histogram.size(); ++i) {
				if (histogram[i] > 0) {
					string s = tile;
					s.push_back('A' + i);

					--histogram[i];
					ret += get_answer(s, histogram, hash);
					++histogram[i];
				}  
			}
		}

		return ret;
	}

	int numTilePossibilities(string tiles) {
		unordered_map<string, int> hash;
		vector<int> histogram(26, 0);
		int ret = 0;

		for (int i = 0; i < tiles.length(); ++i) {
			++histogram[tiles[i] - 'A'];
		}

		for (int i = 0; i < tiles.length(); ++i) {
			string s;
			s += tiles[i];
			--histogram[tiles[i] - 'A'];
			ret += get_answer(s, histogram, hash);
			++histogram[tiles[i] - 'A'];
		}

		return ret;
	}
};
