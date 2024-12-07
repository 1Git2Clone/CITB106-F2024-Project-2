#include "./utils/divisors.cpp"
#include "./utils/mersenne.cpp"

int main(int argc, char *argv[]) {
  print_first_n_amount_of_mersenne_prime_nums<unsigned long long>(5);
  print_divisors(141235);
  print_mersenne_nums_in_interval(0, 10999);
  print_prime_factors(6469693230);
  return 0;
}
