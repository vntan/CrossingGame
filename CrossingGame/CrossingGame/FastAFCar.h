#include "CarStructure.h"

class FastAFCar : public CarStructure {
private:
	int width;
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