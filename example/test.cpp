#include "kalman_filter.h"
#include <unistd.h>
#include <vector>
#include <array>
#include <iostream>
#include <string>			//string lib
#include <cmath>

using namespace std;

int main()
{
	kalman_filter kf(0.001, 0.1);
	
	double data_before[10] = {0, 1, 20, 24, 19, 50, 19, 24, 21, 18};
	double data_after;
	
	for (int i=0; i<10; i++)
	{
		kf.kalman_filter_1d(data_before[i], data_after);
		cout << i << ": " << data_before[i] << ", " << data_after << endl;
	}
	
	return 0;
}
