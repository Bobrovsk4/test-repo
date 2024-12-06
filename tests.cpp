#include "tests.h"

bool test1_body_contains_boundary_values()
{
	Price open = 10;
	Price high = 50;
	Price low = 0;
	Price close = 30;
	Candle candle(open, high, low, close);
	return candle.body_contains(10) && candle.body_contains(30);
}
bool test1_body_contains_external_values()
{
	Price open = 10;
	Price high = 50;
	Price low = 0;
	Price close = 30;
	Candle candle(open, high, low, close);
	return !candle.body_contains(9.9) && !candle.body_contains(30.1);
}
bool test1_body_contains_internal_values()
{
	Price open = 10;
	Price high = 50;
	Price low = 0;
	Price close = 30;
	Candle candle(open, high, low, close);
	return candle.body_contains(10.1) && candle.body_contains(29.9);
}

bool test2_contains_boundary_values()
{
	Price open = 10;
	Price high = 50;
	Price low = 0;
	Price close = 30;
	Candle candle(open, high, low, close);
	return candle.contains(0) && candle.contains(50);
}
bool test2_contains_external_values()
{
	Price open = 10;
	Price high = 50;
	Price low = 0;
	Price close = 30;
	Candle candle(open, high, low, close);
	return !candle.contains(-.1) && !candle.contains(50.1);
}
bool test2_contains_internal_values()
{
	Price open = 10;
	Price high = 50;
	Price low = 0;
	Price close = 30;
	Candle candle(open, high, low, close);
	return candle.contains(0.1) && candle.contains(49.9);
}