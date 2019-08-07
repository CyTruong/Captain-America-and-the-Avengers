#pragma once
#include <list>
#include <vector>
#include "define.h"
#include "Direction.h"
template <class T>

class Rect {

public:
	T x;
	T y;
	T width;
	T height;
	T vx;
	T vy;

public:
	Rect() {};
	Rect(T x, T y, T width, T height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
	Rect(const Rect& rect) {
		try {
			this->x = rect.x;
			this->y = rect.y;
			this->height = rect.height;
			this->width = rect.width;
		}
		catch (exception e) {
			this->x = 0;
			this->y = 0;
			this->height = 1;
			this->width = 1;
		}
		
	}
	void Translate(T x, T y) {
		this->x += x;
		this->y += y;
	}
	// Swept AABB 
	bool isColliding(const Rect& object, const Rect& other)
	{


		float left = other.x - (object.x + object.width);
		float top = (other.y + other.height) - object.y;
		float right = (other.x + other.width) - object.x;
		float bottom = other.y - (object.y + object.height);

		// mình xét ngược lại cho nhanh hơn
		return !(left > 0 || right < 0 || top < 0 || bottom > 0);
	}
	// tạo rect từ trạng thái ban đầu và tiếp theo để kiểm tra xem sau đó có vacham k 
	Rect getSweptBroadphaseRect(const Rect object)
	{
		float x = object.vx > 0 ? object.x : object.x + object.vx;
		float y = object.vy > 0 ? object.y : object.y + object.vy;
		float w = object.width + abs(object.vx);
		float h = object.height + abs(object.vy);

		return Rect(x, y, w, h);
	}

	float sweptAABB(const Rect& object, const Rect& other, Direction & result)
	{   // khoảng cách để va chạm và kc để hết va cham
		float dxEntry, dxExit;
		float dyEntry, dyExit;

		// tìm khoảng cách các cạnh tương ứng
		if (object.vx > 0.0f)
		{
			dxEntry = other.x - (object.x + object.width);
			dxExit = (other.x + other.width) - object.x;
		}
		else
		{
			dxEntry = (other.x + other.width) - object.x;
			dxExit = other.x - (object.x + object.width);
		}

		if (object.vy > 0.0f)
		{
			dyEntry = other.y - (object.y + object.height);
			dyExit = (other.y + height) - object.y;
		}
		else
		{
			dyEntry = (other.y + other.height) - object.y;
			dyExit = other.y - (object.y + object.height);
		}

		// tính thời gian từ khoảng cách tính được và vận tốc của đối tượng
		// vận tốc này là trong 1 frame hình nha

		float txExit, txEntry;
		float tyExit, tyEntry;

		if (object.vx == 0.0f)
		{
			// đang đứng yên thì bằng vô cực (chia cho  0)
			txEntry = -std::numeric_limits<float>::infinity();
			txExit = std::numeric_limits<float>::infinity();
		}
		else
		{
			txEntry = dxEntry / object.vx;
			txExit = dxExit / object.vx;
		}

		if (object.vy == 0.0f)
		{
			tyEntry = -std::numeric_limits<float>::infinity();
			tyExit = std::numeric_limits<float>::infinity();
		}
		else
		{
			tyEntry = dyEntry / object.vy;
			tyExit = dyExit / object.vy;
		}

		// thời gian va chạm là thời gian lớn nhất của 2 trục (2 trục phải cùng tiếp xúc thì mới va chạm)
		float entryTime = max(txEntry, tyEntry);
		// thời gian hết va chạm là thời gian của 2 trục, (1 cái ra khỏi là object hết va chạm)
		float exitTime = min(txExit, tyExit);

		// kiểm tra xem có thể va chạm không, mình xét ngược lại cho nhanh
		if (entryTime > exitTime || (txEntry < 0.0f && tyEntry < 0.0f) || txEntry > 1.0f || tyEntry > 1.0f)
		{
			return 1.0f;
		}

		// lấy hướng va chạm
		if (txEntry > tyEntry)
		{
			if (dxEntry > 0.0f)
			{
				//result = eDirection::RIGHT;
			}
			else
			{
				//result = eDirection::LEFT;
			}
		}
		else
		{
			if (dyEntry > 0.0f)
			{
				//result = eDirection::UP;
			}
			else
			{
				//result = eDirection::DOWN;
			}
		}

		// có thì lấy thời gian
		return entryTime;
	}



	// gán this bằng phần giao của this vs 1 rect khác
	void Clip(Rect rect) {
		T sRight = this->x + this->width;
		T sBottom = this->y + this->height;
		T rRight = rect.x + rect.width;
		T rBottom = rect.y + rect.height;

		this->x = max(this->x, rect.x);
		this->y = max(this->y, rect.y);

		sRight = min(sRight, rRight);
		sBottom = min(sBottom, rBottom);
		width = sRight - this->x;
		height = sBottom - this->y;
	}

	bool operator == (const Rect< T > rect)
	{
		return (x == rect.x &&
			y == rect.y &&
			width == rect.width &&
			height == rect.height);
	}

	//kiểm tra xem 2 rect có va chạm nhau không
	bool checkCollision(Rect r2)
	{


		/*	if (this->x + this->width <= (T)r2.x)
				return false;
			if (this->x >= r2.x + (T)r2.width)
				return false;
			if (this->y + this->height <= (T)r2.y)
				return false;
			if (this->y >= r2.y + (T)r2.height)
				return false;
			return true;*/
			// new change 



		Rect other = r2;
		//

		Rect object = *this;
		object = getSweptBroadphaseRect(object);
		float left = other.x - (object.x + object.width);
		float top = (other.y + other.height) - object.y;
		float right = (other.x + other.width) - object.x;
		float bottom = other.y - (object.y + object.height);

		// mình xét ngược lại cho nhanh hơn
		return !(left > 0 || right < 0 || top < 0 || bottom > 0);

	}

	//kiểm tra xem rect có nằm trong this hay không ( chỉ xét trục X )
	bool checkEdgeCollsion(Rect r2)
	{

		if (this->checkCollision(r2))
		{
			if (this->x > (T)r2.x) return false;
			if (this->x + this->width < (T)r2.x + (T)r2.width) return false;
			return true;

		}

		else
			return false;
	}

	template < class T2 >
	//phép ép kiểu
	operator const Rect< T2 >()
	{
		return Rect< T2 >((T2)x, (T2)y, (T2)width, (T2)height);
	}
};

typedef Rect< float > RectF;
typedef std::list< Rect<float> > RectFList;
typedef Rect < int > RectI;


