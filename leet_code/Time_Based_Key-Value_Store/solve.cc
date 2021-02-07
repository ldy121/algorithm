class TimeMap {
private :
    unordered_map<string, map<int, string> > m_table;
public:
    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if (m_table.find(key) == m_table.end()) {
            m_table[key] = map<int, string>();
        }
        m_table[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (m_table.find(key) == m_table.end()) {
            return string();
        }
        map<int, string>::iterator iter = m_table[key].lower_bound(timestamp);
        --iter;
        
        for (map<int, string>::iterator prev = iter;
             (prev != m_table[key].end()) && (prev->first <= timestamp);
             ++prev) {
            iter = prev;
        }

        return ((iter == m_table[key].end()) || (iter->first > timestamp)) ? 
            string() : iter->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
