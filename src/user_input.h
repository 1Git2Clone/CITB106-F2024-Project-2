#ifndef USER_INPUT_H
#define USER_INPUT_H

/**
 * Mainly used to test the behaviour of the printing functions as well as the
 * user_input ones.
 */
class UserInput {
public:
  UserInput();

  static void n_mersenne_primes();
  static void divisors();
  static void mersennes_in_interval();
  static void prime_factors();
};

#endif // !USER_INPUT_H
