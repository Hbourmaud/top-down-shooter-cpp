#pragma once

class GameManager
{
public:
	float windowWidth{ 800 }, windowHeight{ 600 };

	template <class T1, class T2>
	bool isIntersecting(T1& mA, T2& mB) 
	{
		return mA.right() >= mB.left() && mA.left() <= mB.right() &&
			mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
	};

private:

};