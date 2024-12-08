#include "./user_input.h"

#include "./utils/divisors.hpp"
#include "./utils/mersenne.hpp"
#include "utils/helper_functions.hpp"
#include "utils/primes.hpp"
#include <limits>
#include <sstream>
#include <string>

void UserInput::n_mersenne_primes() {
  int min = 1;
  int max = 9;
  std::ostringstream msg;
  msg << "Enter number between " << min << " and " << max
      << "(In order to get the fisrt "
      << "<input> amount of mersenne primes): ";
  int n_amount_of_mersenne_primes = get_integer_input_line(msg.str(), min, max);

  std::cout << "First " << n_amount_of_mersenne_primes << " mersenne primes: ";
  print_first_n_amount_of_mersenne_prime_nums<unsigned long long>(
      n_amount_of_mersenne_primes);
  std::cout << std::flush;

  return;
}

void UserInput::divisors() {
  int min = 1;
  int max = std::numeric_limits<int>::max();
  std::ostringstream msg;
  msg << "Enter number between " << min << " and " << max
      << " to get its divisors from: ";
  int to_get_divisors_from = get_integer_input_line(msg.str(), min, max);
  std::cout << "Divisors of " << to_get_divisors_from << ": ";
  print_divisors(to_get_divisors_from);
  std::cout << std::flush;

  return;
}

void UserInput::mersennes_in_interval() {
  int mersenne_number_interval_begin =
      get_integer_input_line<int>("Enter mersenne number interval begin: ");
  int mersenne_number_interval_end = get_integer_input_line(
      "Enter mersenne number interval end: ", mersenne_number_interval_begin);

  std::cout << "Mersenne numbers between " << mersenne_number_interval_begin
            << " and " << mersenne_number_interval_end << ": ";
  print_mersenne_nums_in_interval(mersenne_number_interval_begin,
                                  mersenne_number_interval_end);
  std::cout << std::flush;

  return;
}

void UserInput::prime_factors() {
  long prime_factors_n = get_integer_input_line<long>(
      "Enter a long int to get its prime factors from: ");
  std::cout << "Prime factors of " << prime_factors_n << ": ";
  print_prime_factors(prime_factors_n);
  std::cout << std::flush;

  return;
}
