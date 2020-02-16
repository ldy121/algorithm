// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int> hash;
    int i;
    for (i = 0; i < magazine.size(); ++i) {
        if (hash.find(magazine[i]) == hash.end()) {
            hash[magazine[i]] = 1;
        } else {
            ++hash[magazine[i]];
        }
    }

    for (i = 0; i < note.size(); ++i) {
        if ((hash.find(note[i]) == hash.end()) || (hash[note[i]] == 0)) {
            break;
        } else {
            --hash[note[i]];
        }
    }

    if (i == note.size()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
