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

bool test3_full_size_integer_values()
{
	Price open = 10;
	Price high = 50;
	Price low = -1;
	Price close = 30;
	Candle candle(open, high, low, close);
	return candle.full_size() == 51;
}
bool test3_full_size_zeroes()
{
	Price open = 0;
	Price high = 0;
	Price low = 0;
	Price close = 0;
	Candle candle(open, high, low, close);
	return candle.full_size() == 0;
}
bool test3_full_size_double_values()
{
	Price open = 10.1;
	Price high = 50.1;
	Price low = -1.1;
	Price close = 29.1;
	Candle candle(open, high, low, close);
	return candle.full_size() == 51.2;
}

bool test4_body_size_integer_values()
{
	Price open = 10;
	Price high = 50;
	Price low = -1;
	Price close = 30;
	Candle candle(open, high, low, close);
	return candle.body_size() == 20;
}
bool test4_body_size_zeroes()
{
	Price open = 0;
	Price high = 0;
	Price low = 0;
	Price close = 0;
	Candle candle(open, high, low, close);
	return candle.body_size() == 0;
}
bool test4_body_size_double_values()
{
	Price open = 10.1;
	Price high = 50.1;
	Price low = -1.1;
	Price close = 29.1;
	Candle candle(open, high, low, close);
	return candle.body_size() == 19.0;
}