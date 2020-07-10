#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

void func(int a) {
  cout << a << endl;
}

int main(void) {
	thread t(func, 1);
	t.join();
	return 0;
}
