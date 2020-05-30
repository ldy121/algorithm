class FooBar {
private:
	int n;
	int m_barCount;
	int m_fooCount;

public:
	FooBar(int n) {
		this->n = n;
		m_barCount = 0;
		m_fooCount = 0;
	}

	void foo(function<void()> printFoo) {
		for (int i = 0; i < n; i++) {
			while (m_fooCount != m_barCount);
			// printFoo() outputs "foo". Do not change or remove this line.
			printFoo();
			++m_fooCount;
		}
	}

	void bar(function<void()> printBar) {
		for (int i = 0; i < n; i++) {
			while (m_fooCount == m_barCount);
			// printBar() outputs "bar". Do not change or remove this line.
			printBar();
			++m_barCount;
		}
	}
};
