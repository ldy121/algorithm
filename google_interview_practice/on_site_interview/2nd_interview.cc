Please use this Google doc during your interview (your interviewer will see what you write here).
To free your hands for typing, we recommend using a headset or speakerphone.

Hi, it’s Leo :)

bool getAnswer(vector<int> &vec) {
	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i - 1] > vec[i]) {
			return false;
		}
	}
	return true;
}

bool getAnswer(vector<int>::iterator begin, vector<int>::iterator end) {
	if (begin == end) {
// this will return false if begin == end, while the fist |getAnswer| returns |true| if |vec| is empty.
		return false; 
	}

	vector<int>::iterator prev = begin;
	vector<int>::iterator current = ++begin;
	for (; current != end; ++current) {
		if (*prev > *current) {
			return false;
		}
		prev = current;
	}
	return true;
}

// 5 1 2 3 4
bool isSorted(vector<int> &vec, int skipIdx) {
	int j, i;	// j = prev
	if (skipIdx == 0) {
		j = 1;
		i = 2;
	} else {
		j = 0;
		i = 1;
	}

	for (; i < vec.size(); ++i) {
		if (i == skipIdx) {
			continue;
		}
		if (vec[j] > vec[i]) {
			return false;
		}
		j = i;
	}
	return true;
}

bool getAnswer(vector<int> &vec) {
	for (int i = 0; i < vec.size(); ++i) {
		if(isSorted(vec, i)) {
			return true;
		}
	}
	return false;
}


// 5 1 2 3 4
bool getAnswer(vector<int> &vec) {
	int count = 0;

	for (int i = 0; i < vec.size(); ++i) {
		for (int j = i + 1; j < vec.size(); ++j) {
			if (vec[i] > vec[j]) {
				++count;
			}
		}
		if (count > 1) {
			break;
		}
	}
	return (count <= 1);
}

