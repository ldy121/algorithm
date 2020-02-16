// Complete the jumpingOnClouds function below.
int get_minimum_jump(vector<int>& answer, vector<int>& c, int idx)
{
	if (answer[idx] == -1) {
		if ((idx + 1) == c.size()) {
			answer[idx] = 1;
		} else if (c[idx + 1] == 1) {
			answer[idx] = get_minimum_jump(answer, c, idx + 2) + 1;
		} else {
			int ret1 = get_minimum_jump(answer, c, idx + 1) + 1;
			if (((idx + 2) < c.size()) && (c[idx + 2] == 0)) {
				int ret2 = get_minimum_jump(answer, c, idx + 2) + 1;
				answer[idx] = (ret1 < ret2) ? (ret1) : (ret2);
			} else {
				answer[idx] = ret1;
			}
		}
	 }
	return answer[idx];
}


int jumpingOnClouds(vector<int> c) {
	vector<int> answer(c.size(), -1);
	get_minimum_jump(answer, c, 0);
	return answer[0] - 1;
}
