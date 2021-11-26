#pragma once
#include "Character.h"
#include "RedCar.h"
#include <fstream>

class ListCars
{
public:
	/// <summary>
	/// Set làn cần vẽ
	/// </summary>
	/// <param name="lane"></param>
	virtual void setLane(int lane) = 0;

	/// <summary>
	/// Set Level
	/// </summary>
	/// <param name="level"></param>
	virtual void setLevel(int level) = 0;

	/// <summary>
	/// Vẽ tất cả các xe trên làn
	/// </summary>
	virtual void drawListCar() = 0;

	/// <summary>
	/// Cập nhật vị trí các xe trên làn
	/// </summary>
	virtual void updateListCar() = 0;

	/// <summary>
	/// Xóa các xe trên làn
	/// </summary>
	virtual void deleteListCar() = 0;

	/// <summary>
	/// Thay đổi màu đèn giao thông
	/// </summary>
	virtual void trafficColor() = 0;

	/// <summary>
	/// Kiểm tra xem có đụng độ với người hay không?
	/// </summary>
	/// <param name="character"></param>
	/// <returns></returns>
	virtual bool isCollision(Character* character) = 0;

};

