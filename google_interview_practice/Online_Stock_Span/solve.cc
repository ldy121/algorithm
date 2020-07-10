class StockSpanner {
private :
	stack<int> m_sp;
	vector<int> m_prices;
public:
    StockSpanner() {
    }
    
    int next(int price) {
    	int ret;
	    while (!m_sp.empty() && m_prices[m_sp.top()] <= price) {
    		m_sp.pop();
	    }

	    ret = (!m_sp.empty()) ? (m_prices.size() - m_sp.top()) : (m_prices.size() + 1);
	    m_sp.push(m_prices.size());
	    m_prices.push_back(price);

	    return ret;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
