#include "get_manual.h"

GetManual::GetManual(ent::Entity& entity) : GetAction(entity) {}

GetManual::~GetManual() {}

void GetManual::Execute(ent::EntityType type) {
  std::cout << "Write in json format: " << std::endl;
  Read(std::cin, type);
}