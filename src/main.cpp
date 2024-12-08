#include "./utils/divisors.hpp"
#include "./utils/mersenne.hpp"
#include "utils/helper_functions.hpp"
#include "utils/primes.hpp"
#include <format>
#include <limits>

int user_input_numbers() {
  int n_amount_of_mersenne_primes = get_integer_input_line(
      std::format("Enter number between {} and {} (In order to get the fisrt "
                  "<input> amount of mersenne primes): ",
                  1, 9),
      1, 9);

  std::cout << "First " << n_amount_of_mersenne_primes << " mersenne primes: ";
  print_first_n_amount_of_mersenne_prime_nums<unsigned long long>(
      n_amount_of_mersenne_primes);
  std::cout << std::flush;

  int to_get_divisors_from = get_integer_input_line(
      std::format("Enter number between {} and {} to get its divisors from: ",
                  0, std::numeric_limits<int>::max()),
      0, std::numeric_limits<int>::max());
  std::cout << "Divisors of " << to_get_divisors_from << ": ";
  print_divisors(to_get_divisors_from);
  std::cout << std::flush;

  int mersenne_number_interval_begin =
      get_integer_input_line<int>("Enter mersenne number interval begin: ");
  int mersenne_number_interval_end = get_integer_input_line(
      "Enter mersenne number interval end: ", mersenne_number_interval_begin);
  std::cout << "Mersenne numbers between " << mersenne_number_interval_begin
            << " and " << mersenne_number_interval_end << ": ";
  print_mersenne_nums_in_interval(mersenne_number_interval_begin,
                                  mersenne_number_interval_end);
  std::cout << std::flush;

  long prime_factors_n = get_integer_input_line<long>(
      "Enter a long int to get its prime factors from: ");
  std::cout << "Prime factors of " << prime_factors_n << ": ";
  print_prime_factors(prime_factors_n);
  std::cout << std::flush;

  return 0;
}

int main(int argc, char *argv[]) {
  user_input_numbers();
  return 0;
}
