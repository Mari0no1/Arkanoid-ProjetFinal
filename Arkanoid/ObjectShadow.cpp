/*====================================
// Filename : ObjectShadow.cpp
// Description : This file contains the implementation of the ObjectShadow class
//				 which contains the ball and player's shadows logic
// Author : Samy Larochelle
// Date : May 13th, 2024
====================================*/
#include "ObjectShadow.h"
using namespace sf;
using namespace std;

ObjectShadow::ObjectShadow()
{
	_type = "";
}

ObjectShadow::ObjectShadow(std::string objet)
{
	_type = objet;
	cout << "[ObjectShadow] Shadow with type " << objet << " has been created" << endl;
}

bool ObjectShadow::LoadTextures()
{
	if (_type == "Ball")
	{
		_shadow.scale(sizeMultiplier, sizeMultiplier);
		_shadow.setSize(Vector2f(_ballWidth, _ballHeight));		
		_rectSprite = IntRect(0, 0, _ballWidth, _ballHeight);
		_shadow.setOrigin(_ballWidth / 2, _ballHeight / 2);
		_shadow.setTextureRect(_rectSprite);
		if (!_texture.loadFromFile("ArkanoidUltra_Data/Sprites/Ball_S.png"))
			return false;
	}
	else if (_type == "Player")
	{
		_shadow.scale(sizeMultiplier, sizeMultiplier);
		_shadow.setSize(Vector2f(_playerWidth, _playerHeight));
		_rectSprite = IntRect(0, 0, _playerWidth, _playerHeight);
		_shadow.setOrigin(_playerWidth / 2, _playerHeight / 2);
		_shadow.setTextureRect(_rectSprite);
		if (!_texture.loadFromFile("ArkanoidUltra_Data/Sprites/Player_S.png"))
			return false;
	}

	_shadow.setTexture(&_texture);
}

void ObjectShadow::SetType(std::string type)
{
	_type = type;
	cout << "[ObjectShadow] Type has been changed to " << type << endl;
}

void ObjectShadow::draw(sf::RenderWindow& window)
{
	window.draw(_shadow);
}

void ObjectShadow::move(RectangleShape object)
{
	Vector2f position = object.getPosition();
	_time = _clock.getElapsedTime();
	if (_time.asMilliseconds() >= 10.0f) 
	{
		_shadow.setPosition(position.x + 4  * sizeMultiplier, position.y + 4 * sizeMultiplier);
		_clock.restart();
	}
}