#pragma once // if included more than one same one, take that as same inclusion.

using namespace std;
class ArrayExamples {

protected:

private:

public:
	int findMaxValue(int a[], int len);

	int findMaxPixel(int a[][5], int h, int w);

};

int ArrayExamples::findMaxValue(int a[], int len) {
	int tmp = a[0];
	for (int i = 1; i<len; i++) { 	
		if (a[i] > tmp) {
			tmp = a[i];
		}
	}
	return tmp;
}

int ArrayExamples::findMaxPixel(int a[][5], int h, int w) {
	int maxVal = 0;
	for (int i = 0; i<h; i++)
		for (int j = 0; j<w; j++)
			if (maxVal < a[i][j])
				maxVal = a[i][j];
	return maxVal;
}
