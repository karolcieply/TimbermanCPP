#pragma once
class Timberman
{
public:
	Timberman();
	enum positionEnum {left,right};
	void ChangePosition(enum positionEnum);
	positionEnum playerPosition;
private:
};

