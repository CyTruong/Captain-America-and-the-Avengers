#pragma once
#include <queue>
#include <stack>
//Lớp lưu trữ các trạng thái của 1 Key, khi dc thêm vào hàng đợi

using namespace std;


class KeyEvent 
{
public:
	enum KeyType
	{
		PRESS,
		RELEASE,
		NULLKEY
	};
public:
	KeyType type;
	int keycode;

public:
	KeyEvent(KeyType, int keycode);
	int getCode();
	bool isPressed();
	bool isReleased();

	

};
struct LessThanByType
{
	bool operator()(const KeyEvent& lhs, const KeyEvent& rhs) const
	{
		return lhs.type  < rhs.type ;
	}
};

//Lớp lưu trữ thông tin các key dc bấm , trình tự và trạng thái các key
class KeyBoard
{

private:

	static KeyBoard* Instance;

private:
	bool keyState[256];
	/*queue < KeyEvent > keyEventQueue;*/ // hàng đợi lưu trữ các event

	priority_queue < KeyEvent, std::vector<KeyEvent>, LessThanByType > keyEventQueue;

private:
	KeyBoard();

public:

	static KeyBoard* GetInstance();
	void onKeyPressed(int code);
	void onKeyReleased(int code);

	KeyEvent Read_Key(); //đọc sự kiện phím 
	KeyEvent ReadPop_Key(); //đọc và pop

	bool isPressed(int key);
	void Clean();
	bool isEmpty();
	
};

