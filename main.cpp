#include <iostream>

#include <string>
class classeLegal {
public:
  char *memberPublicPointerChar;
  long double memberPublicLongDouble2;
  long long memberPublicLongLong;
  long memberPublicLong;
  double memberPublicDouble2222222;
  float memberPublicFloat = 0;
  bool memberPublicBool = false;
  int memberIntPublic{};
};

std::string hello(std::string name) {
  using namespace std::string_literals;
  return "Hello "s + name + "!\n"s;
}

int main() { std::cout << hello("World"); }
