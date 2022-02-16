#pragma once

#include <functional>
#include <memory>
#include <map>

#include <enterprise/company.h>

class Manager {
public:
  Manager(const std::string& cif);
  void Run();

private:
  ent::Company company_;
  std::string options_;
  std::map<std::string, std::function<void()>> menu_actions_;
  std::map<std::string, std::function<std::shared_ptr<Action>(ent::Company&, std::shared_ptr<Strategy>)> add_actions_;

  void Menu();
  void UserInput();

};