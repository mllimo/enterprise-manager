#pragma once

#include <functional>
#include <memory>
#include <map>

#include <enterprise/company.h>

#include "get_file.h"
#include "get_manual.h"

class Manager {
public:
  Manager(const std::string& cif);
  void Run();

private:
  ent::Company company_;
  std::string options_;
  bool is_exit_;
  ent::EntityType type;

  std::map<std::string, std::function<void()>> menu_actions_;
  std::map<std::string, std::function<std::shared_ptr<Action>()>> actions_;

  void Menu();
  void UserInput();

};