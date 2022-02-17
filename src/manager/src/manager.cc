#include "manager.h"

Manager::Manager(const std::string& cif) : company_(1, cif), is_exit_(false) {
  menu_actions_["1"] = []() {
    std::cout
      << "\n1) Manual\n"
      << "2) Json file\n"
      << "\nYour option: ";
  };

  menu_actions_["2"] = []() {
    std::cout
      << "\n1) Print to screen\n"
      << "2) Print to file\n"
      << "\nYour option: ";
  };

  actions_["11"] = [&]() {
    return std::make_shared<GetManual>(company_);
  };

  actions_["12"] = [&]() {
    return std::make_shared<GetFile>(company_);
  };

}

void Manager::Run() {
  while (!is_exit_) {
    UserInput();
    auto action = actions_[options_]();
    action->Execute(type);
  }
}

void Manager::Menu() {
  std::cout
    << "1) ADD\n"
    << "2) GET\n"
    << "3) DELETE\n"
    << "4) UPDATE\n"
    << "5) EXIT\n"
    << "\nYour option: ";
}

void Manager::UserInput() {
  char aux;

  Menu();
  std::cin >> options_;
  if (options_ == "5")  {
    is_exit_ = true;
    return;
  }

  menu_actions_[options_]();
  std::cin >> aux;
  options_ += aux;

  std::cout
    << "\n\nChoose the type of entity you want to add:\n"
    << "1) Client\n"
    << "2) Supplier\n"
    << "3) Bill\n"
    << "\nYour option: ";

  std::cin >> aux;
  switch (aux) {
  case '1':
    type = ent::EntityType::Client;
    break;
  case '2':
    type = ent::EntityType::Supplier;
    break;
  case '3':
    type = ent::EntityType::Bill;
    break;
  default:
    throw std::invalid_argument("Invalid option");
    return;
  }

}