#include <unordered_map>

int findFrequency(vector<int> v, int x){
 	unordered_map<int, int> hash;
	for (int i = 0; i < v.size(); ++i) {
		if (hash.find(v[i]) == hash.end()) {
			hash[v[i]] = 0;
		}
		++hash[v[i]];
	}
 	return (hash.find(x) == hash.end()) ? 0 : hash[x];
}


