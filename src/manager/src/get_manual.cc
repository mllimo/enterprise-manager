#include "get_manual.h"

GetManual::GetManual(const std::shared_ptr<ent::Entity>& entity) : GetAction(entity) {}

GetManual::~GetManual() {}

void GetManual::Execute(std::shared_ptr<ent::Entity> entity, ent::EntityType type) {
  std::cout << "Type the values in order and separated by spaces: " << std::endl;
  Read(std::cin, type);
}