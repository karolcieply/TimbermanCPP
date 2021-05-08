#pragma once 
class Branch;
class Timberman
{
public:
	Timberman();
	enum positionEnum {left,right};
	void ChangePosition(enum positionEnum);
	positionEnum playerPosition;
private:
};
class Branch{
public:
	Timberman::positionEnum branchPosition;
	Branch();
};

