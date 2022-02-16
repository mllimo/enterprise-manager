#include "manager.h"

Manager::Manager(const std::string& cif) : company_(1, cif) {
  menu_actions_["a"] = []() {
    std::cout
      << "1) Manual\n"
      << "2) Json file\n"
      << "\nYour option: ";
  };

  menu_actions_["b"] = []() {
    std::cout
      << "1) Print to screen\n"
      << "2) Print to file\n"
      << "\nYour option: ";
  };
}

void Manager::Run() {
  UserInput();
}

void Manager::Menu() {
  std::cout
    << "a) ADD\n"
    << "b) GET\n"
    << "c) DELETE\n"
    << "d) UPDATE\n"
    << "\nYour option: ";
}

void Manager::UserInput() {
  char aux;
  Menu();
  std::cin >> options_;
  menu_actions_[options_]();
  std::cin >> aux;
  options_ += aux; 
}