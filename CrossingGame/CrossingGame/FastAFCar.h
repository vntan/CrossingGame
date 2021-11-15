#include "CarStructure.h"

class FastAFCar : public CarStructure {
private:
	int width;
	int minX = 3;
	int minY = 6;
	int maxX = 95;
	int maxY = 30;
public:
	FastAFCar();
	void setCarWidth(int width);
	void drawCar(int x, int y);
	void deleteCar(int x, int y);
	void drawCar(int x, int y, int count);
	void drawCarReverse(int x, int y, int count);
	void deleteCar(int x, int y, int count);
	void deleteCarReverse(int x, int y, int count);
};