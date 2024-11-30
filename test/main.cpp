#include "../src/utils/math.cpp"
#include <cassert>
#include <set>
#include <thread>
#include <vector>

void test_get_prime_factors() {
  std::vector<int> prime_factors = get_prime_factors(18200);
  std::vector<int> expected_factors = {2, 5, 7, 13};

  assert(prime_factors == expected_factors);

  return;
}

void test_difference() {
  // Overload 1: set
  {
    std::set<int> a = {1, 2, 3};
    std::set<int> b = {2, 3, 4, 5};
    std::set<int> expected_diff = {1};
    std::set<int> received_diff = set_difference(a, b);

    assert(expected_diff == received_diff);
  }

  // Overload 2: vector with sets
  {
    std::set<int> a = {1, 2, 3};
    std::set<int> b = {2, 3, 4, 5};
    std::vector<int> expected_diff = {1};
    std::vector<int> received_diff = vec_difference(a, b);

    assert(expected_diff == received_diff);
  }

  // Overload 3: vector
  {
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {2, 3, 4, 5};
    std::vector<int> expected_diff = {1};
    std::vector<int> received_diff = vec_difference(a, b);

    assert(expected_diff == received_diff);
  }

  return;
}

void test_mersenne_numbers() {
  std::vector<int> mersenne_a = get_mersenne_nums_from_interval(3, 2047);
  std::vector<int> expected_mersenne = {3,   7,   15,  31,   63,
                                        127, 255, 511, 1023, 2047};

  assert(mersenne_a == expected_mersenne);
}

void test_perfect_numbers() {
  std::vector<int> perfect_a = get_perfect_nums_from_interval(6, 8128);
  std::vector<int> expected_perfection = {6, 28, 496, 8128};

  assert(perfect_a == expected_perfection);
}

int main(int argc, char *argv[]) {
  std::vector<std::thread> threads;

  threads.push_back(std::thread([]() { test_get_prime_factors(); }));
  threads.push_back(std::thread([]() { test_difference(); }));
  threads.push_back(std::thread([]() { test_mersenne_numbers(); }));
  threads.push_back(std::thread([]() { test_perfect_numbers(); }));

  for (std::thread &t : threads) {
    t.join();
  }

  std::cout << "ALL TESTS PASSED!" << std::endl;

  return 0;
}
