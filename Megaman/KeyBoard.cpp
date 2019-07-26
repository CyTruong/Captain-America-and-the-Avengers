#include "KeyBoard.h"


#pragma region KeyEvent

KeyEvent::KeyEvent(KeyEvent::KeyType type, int code) {
	this->type = type;
	this->keycode = code;
}

int KeyEvent::getCode() {
	return keycode;
}

bool KeyEvent::isPressed() {
	return type == KeyEvent::PRESS;
}

bool KeyEvent::isReleased() {
	return type == KeyEvent::RELEASE;


}

#pragma endregion

#pragma region Keyboard

KeyBoard* KeyBoard::Instance = nullptr;

KeyBoard* KeyBoard::GetInstance()
{
	if (Instance == nullptr) {
		Instance = new KeyBoard();
	}
	return Instance;
}

KeyBoard::KeyBoard() {
	for (int i = 0; i < 256; i++) {
		keyState[i] = false;
	}
}

void KeyBoard::onKeyPressed(int keycode) {
	if (!keyState[keycode]) {
		keyState[keycode] = true;
		keyEventQueue.push(KeyEvent(KeyEvent::PRESS,keycode));
	}
}

void KeyBoard::onKeyReleased(int keycode) {
	if (keyState[keycode]) {
		keyState[keycode] = false;
		keyEventQueue.push(KeyEvent(KeyEvent::RELEASE, keycode));
	}
}

KeyEvent KeyBoard::Read_Key()
{
	if (keyEventQueue.size() > 0) {
		return keyEventQueue.top();
	}
	else
	{
		return KeyEvent(KeyEvent::NULLKEY, 0);
	}
}

KeyEvent KeyBoard::ReadPop_Key()
{
	if (keyEventQueue.size() > 0) {
		KeyEvent temp = keyEventQueue.top();
		keyEventQueue.pop();
		return temp;
	}
	else
	{
		return KeyEvent(KeyEvent::NULLKEY, 0);
	}
}

bool KeyBoard::isPressed(int key)
{
	return keyState[key];
}

void KeyBoard::Clean()
{
	while (!keyEventQueue.empty())
	{
		keyEventQueue.pop();
	}
}

bool KeyBoard::isEmpty()
{
	return keyEventQueue.empty();
}


#pragma endregion

