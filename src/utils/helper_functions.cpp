#include "./helper_functions.h"

void print_heading(const std::string &content) {
  std::string lines(content.size(), '-');
  std::cout << lines.c_str() << std::endl;
  std::cout << content << std::endl;
  std::cout << lines.c_str() << std::endl;
}

void print_heading(const char **content) {
  std::string lines(sizeof(content) / sizeof(char), '-');
  printf("%s\n%s\n%s", lines.c_str(), *content, lines.c_str());
}
