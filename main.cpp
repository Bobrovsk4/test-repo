#include <vector>
#include <functional>
#include <iostream>
#include "candle.h"
#include "tests.h"

static std::vector<std::function<bool()>> tests;

void initTests()
{
    tests.push_back(test1_body_contains_boundary_values);
    tests.push_back(test1_body_contains_external_values);
    tests.push_back(test1_body_contains_internal_values);

    tests.push_back(test2_contains_boundary_values);
    tests.push_back(test2_contains_external_values);
    tests.push_back(test2_contains_internal_values);

    tests.push_back(test3_full_size_integer_values);
    tests.push_back(test3_full_size_zeroes);
    tests.push_back(test3_full_size_double_values);

    tests.push_back(test4_body_size_integer_values);
    tests.push_back(test4_body_size_zeroes);
    tests.push_back(test4_body_size_double_values);

    tests.push_back(test5_is_red_integer_values);
    tests.push_back(test5_is_red_zeroes);
    tests.push_back(test5_is_red_double_values);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}
