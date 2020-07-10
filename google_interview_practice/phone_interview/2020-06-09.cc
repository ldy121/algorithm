Please use this Google doc during your interview (your interviewer will see what you write here).
To free your hands for typing, we recommend using a headset or speakerphone.

Mohan: There is a race track with M tracks and N sensors per track.
Whenever a car crosses a sensor, It would call a function.
And there is a second function, when invoked, will provide an ordered list of cars based on their position in the track.

Function 1: Registers an event.
void Event(int car_id, int sensor_id);  //Can access a real time clock.

The Event function is called by ordered or not?

Car1 passed fast/ Car2 passed the track later.


Function 2: Used to rank cars based on their position.
std::vector<int> List(void);

Function 1
//vector<vector<int> > g_sensor;
unordered_map<int, int> g_car; // position of the car
unordered_map<int, int> g_sensor; // count - how many times car passed sensor
unrodered_map<int, int> g_count;

bool comp(int a, int b) {
	return g_sensor[a] > g_sensor[b]
}

void Event(int car_id, int sensor_id) {
	g_car[car_id] = sensor_id;
	int count = ++g_sensor[car_id];
	if (g_count[count] == g_cout.end()) {
		g_count = car_id;
	}
}

int getFirstCar(int sensor) {
	if (g_
}

std::vector<int> List(void) {
	vector<int> vec;		// car M
	vector<int> ret;
	for (int i = 0; i < g_car.size(); ++i) {
		vec.push_back(i);	//0 .. M
	}
	sort(vec.begin(), vec.end(), comp);	// 0 .. M => 1 0 5 M M-1
	
	return vec;
}

