class Solution {
public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		queue<int> q;
		vector<int> order;
		vector<int> ret(deck.size());

		for (int i = 0; i < deck.size(); ++i) {
			q.push(i);
		}

		while (!q.empty()) {
			int idx = q.front();
			order.push_back(idx);
			q.pop();

			if (!q.empty()) {
				idx = q.front();
				q.pop();
				q.push(idx);
			}
		}

		sort(deck.begin(), deck.end());

		for (int i = 0; i < order.size(); ++i) {
			ret[order[i]] = deck[i];
		}

		return ret;
	}
};
