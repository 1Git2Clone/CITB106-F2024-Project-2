#include "../src/utils/math.cpp"
#include <cassert>
#include <set>
#include <thread>
#include <vector>

const char *SAME_VEC = "Check if the received vector == expected_vector";
const char *SAME_SET = "Check if the received set == expected_set";
const char *PRINT_SUCCESS = "YES";

void test_get_prime_factors() {
  print_heading("Test prime factors");
  int of = 18200;
  std::vector<int> prime_factors = get_prime_factors(of);
  std::vector<int> expected_factors = {2, 5, 7, 13};

  std::cout << "Testing the prime factors of" << of << std::endl;
  assert(prime_factors == expected_factors);
  std::cout << PRINT_SUCCESS << std::endl;

  return;
}

void test_difference() {
  print_heading("Test set/vec difference (A \\ B in set theory).");
  {
    std::cout << "OVERLOAD 1: Set" << std::endl;
    std::set<int> a = {1, 2, 3};
    std::set<int> b = {2, 3, 4, 5};
    std::set<int> expected_diff = {1};
    std::set<int> received_diff = set_difference(a, b);

    std::cout << SAME_SET << std::endl;
    assert(expected_diff == received_diff);
  }

  {
    std::cout << "OVERLOAD 2: Vec with sets" << std::endl;
    std::set<int> a = {1, 2, 3};
    std::set<int> b = {2, 3, 4, 5};
    std::vector<int> expected_diff = {1};
    std::vector<int> received_diff = vec_difference(a, b);

    std::cout << SAME_VEC << std::endl;
    assert(expected_diff == received_diff);
    std::cout << PRINT_SUCCESS << std::endl;
  }

  {
    std::cout << "OVERLOAD 3: Vec" << std::endl;
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {2, 3, 4, 5};
    std::vector<int> expected_diff = {1};
    std::vector<int> received_diff = vec_difference(a, b);

    std::cout << SAME_VEC << std::endl;
    assert(expected_diff == received_diff);
    std::cout << PRINT_SUCCESS << std::endl;
  }

  return;
}

void test_mersenne_numbers() {
  print_heading("Test mersenne numbers");

  std::cout << SAME_VEC << std::endl;
  std::vector<int> mersenne_a = get_mersenne_nums_in_interval(3, 2047);
  std::vector<int> expected_mersenne = {2,   3,   7,   15,   31,  63,
                                        127, 255, 511, 1023, 2047};

  assert(mersenne_a == expected_mersenne);
  std::cout << PRINT_SUCCESS << std::endl;

  std::cout << SAME_VEC << std::endl;
  std::cout << "NOTE: This is for the first 9 mersenne primes so it's slow."
            << std::endl;
  std::vector<unsigned long long> first_nine_mersenne_primes =
      get_first_n_amount_of_mersenne_prime_nums<unsigned long long>(9ull);

  std::vector<unsigned long long> expected_first_nine_mersenne_primes = {
      3,
      7,
      31,
      127,
      8'191,
      131'071,
      524'287,
      2'147'483'647,
      2'305'843'009'213'693'951};

  assert(first_nine_mersenne_primes == expected_first_nine_mersenne_primes);
  std::cout << PRINT_SUCCESS << std::endl;
}

void test_perfect_numbers() {
  print_heading("Test perfect numbers");
  std::vector<int> perfect_nums = get_perfect_nums_from_interval(6, 8128);
  std::vector<int> expected_perfect_nums = {6, 28, 496, 8128};

  std::cout << SAME_VEC << std::endl;
  assert(perfect_nums == expected_perfect_nums);
  std::cout << PRINT_SUCCESS << std::endl;

  std::cout << "Check if all numbers are perfect" << std::endl;
  for (const int &num : perfect_nums) {
    assert(is_perfect(num));
  }
  std::cout << PRINT_SUCCESS << std::endl;
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
