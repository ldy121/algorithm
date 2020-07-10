#include <iostream>
#include <vector>

using namespace std;

class keyboard {
public :
	keyboard(int screen, int buffer) : m_screen(screen), m_buffer(buffer){};
	int m_screen;
	int m_buffer;
};

int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		vector<keyboard> screen, buffer;
		int N;
		cin >> N;
		for (int i = 0; i <= (N + 2); ++i) {
			screen.push_back(keyboard(i, 0));
      buffer.push_back(keyboard(i, 0));
		}

		for (int i = 0; i <= N; ++i) {
			int s, b;

			screen[i + 1].m_screen = screen[i].m_screen + 1;
			screen[i + 1].m_buffer = screen[i].m_buffer;

			if ((screen[i].m_screen + screen[i].m_buffer) > (buffer[i].m_screen + buffer[i].m_buffer)) {
			    s = screen[i].m_screen + screen[i].m_buffer;
			    b = screen[i].m_buffer;
			} else if ((screen[i].m_screen + screen[i].m_buffer) < (buffer[i].m_screen + buffer[i].m_buffer)) {
			    s = buffer[i].m_screen + buffer[i].m_buffer;
			    b = buffer[i].m_buffer;
			} else {
			    s = buffer[i].m_screen + buffer[i].m_buffer;
			    b = (buffer[i].m_buffer > screen[i].m_buffer) ? buffer[i].m_buffer : screen[i].m_buffer;
			}

			if (screen[i + 1].m_screen < s) {
			  screen[i + 1].m_screen = s;
			  screen[i + 1].m_buffer = b;
			} else if (screen[i + 1].m_screen == s) {
				if (screen[i + 1].m_buffer < b) {
				  screen[i + 1].m_buffer = b;
				}
			}
			
			buffer[i + 2].m_screen = screen[i].m_screen;
      buffer[i + 2].m_buffer = screen[i].m_screen;
		}

		cout << screen[N].m_screen << endl;
	}
	return 0;
}


