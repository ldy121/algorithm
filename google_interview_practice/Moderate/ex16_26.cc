#include <list>
#include <string>
#include <iostream>

using namespace std;

const char invalid = -1;

class parameter {
public :
	parameter(char op, double val = 0.0f) : m_op(op), m_val(val) {};
	double m_val;
	char m_op;
};


double calculator(string str) {
	list<parameter> params;

	for (int i = 0; i < str.length();) {
	  if ( '0' <= str[i] && str[i] <= '9') {
			int j, k = 0;
			for (j = i; j < str.length(); ++j) {
				if (str[j] < '0' || str[j] > '9') {
					break;
				} else {
					k = k * 10 + (str[j] - '0');
				}
			}
			params.push_back(parameter(invalid, (double)k));
			i = j;
		} else {
			params.push_back(str[i]);
			++i;
		}
	}

	for (list<parameter>::iterator iter = params.begin(); iter != params.end(); ++iter) {
		if (iter->m_op == '*' || iter->m_op == '/') {
			list<parameter>::iterator prev = iter;
			list<parameter>::iterator next = iter;
			--prev;
			++next;
			next->m_val = (iter->m_op == '*') ? prev->m_val * next->m_val : prev->m_val / next->m_val;
			params.erase(prev);
			params.erase(iter);
			iter = next;
		}
	}
	
	for (list<parameter>::iterator iter = params.begin(); iter != params.end(); ++iter) {
		if (iter->m_op == '+' || iter->m_op == '-') {
			list<parameter>::iterator prev = iter;
			list<parameter>::iterator next = iter;
			--prev;
			++next;
			next->m_val = (iter->m_op == '+') ? prev->m_val + next->m_val : prev->m_val - next->m_val;
			params.erase(prev);
			params.erase(iter);
			iter = next;
		}
	}

	return params.begin()->m_val;
}

int main(void) {
	cout << calculator(string("2*3+5/6*3+15")) << endl;
}

