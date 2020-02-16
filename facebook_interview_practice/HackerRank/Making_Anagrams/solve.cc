const int characters = 26;

int makeAnagram(string a, string b) {
 	vector<int> delete_a(characters, 0);
	vector<int> delete_b(characters, 0);
	int ret = 0;

	for (int i = 0; i < a.length(); ++i) delete_a[a[i] - 'a']++;
	for (int i = 0; i < b.length(); ++i) delete_b[b[i] - 'a']++;
	for (int i = 0; i < characters; ++i) {
		 ret += ((delete_a[i] > delete_b[i]) ? 
			(delete_a[i] - delete_b[i]) : (delete_b[i] - delete_a[i]));
	}
	return ret;
}
