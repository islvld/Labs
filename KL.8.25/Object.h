#pragma once
class Object
{
public:
	Object(void);
	virtual void output() = 0;
	virtual void input() = 0;
	virtual ~Object(void);
};

