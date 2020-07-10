class Station {
public :
	Station() : m_totalTime(0), m_totalPeople(0) {};
	void addTimeTaken(int time) {
		m_totalTime += time;
		++m_totalPeople;
	}
	double getAverageTime() {
		double time = (double)m_totalTime;
		double people = (double)m_totalPeople;
		return time / people;
	}
	int m_totalTime;
	int m_totalPeople;
};

class Passenger {
public :
    Passenger() {};
	Passenger(string &station, int time) : m_station(station), m_time(time) {};
	string m_station;
    int m_time;	
};

class UndergroundSystem {
private:
	unordered_map<string, unordered_map<string, Station> > map;
	unordered_map<int, Passenger> passenger;
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
	    if (map.find(stationName) == map.end()) {
		    map[stationName] = unordered_map<string, Station>();
	    }
        passenger[id] = Passenger (stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
	    string src = passenger[id].m_station;
	    int startTime = passenger[id].m_time;
	    if (map[src].find(stationName) == map[src].end()) {
    		map[src][stationName] = Station();
	    }
	    map[src][stationName].addTimeTaken(t - startTime);
    }
    
    double getAverageTime(string startStation, string endStation) {
	    return map[startStation][endStation].getAverageTime();
    }
};



