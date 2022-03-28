#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <limits.h>
#include <unordered_map>
#define ll long long
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define LOOP(i,k,n) for(ll i = k; i < n; i++)
#define ROOP(i,k,n) for(ll i = k; i >= n; i--)
using namespace std;


// speed of car from two points
int speed(int x1, int y1, int x2, int y2)
{
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

//velociry of car based on speed and time
int velocity(int speed, int time)
{
	return speed * time;
}

//distance between car and distination
int distance(int x1, int y1, int x2, int y2)
{
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

//time for car to reach distination
int time(int speed, int distance)
{
	return distance / speed;
}

//angle of destination from car


int main()
{
	int my_car_x; // my car current x coordinate
	int my_car_y; // my car current y coordinate
	int my_car_velocity_x; 	// my car velocity in x direction
	int my_car_velocity_y;	// my car velocity in y direction
	int enemy_car_x;	// enemy car current x coordinate
	int enemy_car_y;	// enemy car current y coordinate
	int enemy_car_velocity_x;	// enemy car velocity in x direction
	int enemy_car_velocity_y;	// enemy car velocity in y direction
	int checkpoint_x;	 	// checkpoint x coordinate
	int checkpoint_y;	 	// checkpoint y coordinate
	int angle_of_checkpoint_from_my_car; 	// angle of checkpoint from my car

	int next_dist_x;	// 
	int next_dist_y;
	int my_car_thrust; //thrust of my car from 0 to 100
	int turns;
	cin >> turns;

	while (turns--)
	{
		cin >> my_car_x >> my_car_y >> enemy_car_x >> enemy_car_y >> checkpoint_x >> checkpoint_y >> my_car_velocity_x >> my_car_velocity_y >> enemy_car_velocity_x >> enemy_car_velocity_y >> angle_of_checkpoint_from_my_car;

		
		
		cout << next_dist_x << " " << next_dist_y <<  " " << my_car_thrust <<endl;
	}

    return(0);
}