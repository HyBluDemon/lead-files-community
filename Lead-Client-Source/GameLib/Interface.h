#pragma once

// 2004.07.05.myevan. Solved the problem of getting stuck in the Gungsin Tanyeong map.
class IBackground : public CSingleton<IBackground>
{
	public:
		IBackground() {}
		virtual ~IBackground() {}

		virtual bool IsBlock(int x, int y) = 0;
};