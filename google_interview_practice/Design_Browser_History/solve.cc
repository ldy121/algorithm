class BrowserHistory {
private :
	list<string> m_history;
	list<string>::iterator m_iter;
public:
    BrowserHistory(string homepage) {
	    m_history.push_back(homepage);
	    m_iter = m_history.begin();
    }
    
    void visit(string url) {
        list<string>::iterator iter = m_iter;

        if (++iter != m_history.end()) {
            m_history.erase(iter, m_history.end());
        }
        m_history.push_back(url);
        ++m_iter;
    }
    
    string back(int steps) {
        for(int i = 0; i < steps; ++i) {
		    if (m_iter == m_history.begin()) {
    			break;
	    	}
    		--m_iter;
    	}
	    return *m_iter;
    }
    
    string forward(int steps) {
	    for (list<string>::iterator iter = m_iter; steps > 0; --steps) {
            ++iter;
            if (iter != m_history.end()) {
                m_iter = iter;
            } else {
                break;
            }
	    }
	    return *m_iter;
    }

};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
