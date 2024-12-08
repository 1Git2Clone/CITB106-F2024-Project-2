#include "./user_input.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  UserInput::n_mersenne_primes();
  UserInput::divisors();
  UserInput::mersennes_in_interval();
  UserInput::prime_factors();
  return 0;
}
