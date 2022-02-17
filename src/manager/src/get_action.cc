#include "get_action.h"

GetAction::GetAction(ent::Entity& entity) : Action(entity) {}

GetAction::~GetAction() {}

void GetAction::Execute(ent::EntityType type) {}

void GetAction::Read(std::istream& is, ent::EntityType type) {
  std::shared_ptr<ent::Entity> entity;

  switch (type) {
  case ent::EntityType::Client:
    is >> *std::dynamic_pointer_cast<ent::Client>(entity);
    break;

  case ent::EntityType::Supplier:
    is >> *std::dynamic_pointer_cast<ent::Supplier>(entity);
    break;

  case ent::EntityType::Bill:
    is >> *std::dynamic_pointer_cast<ent::Bill>(entity);
    break;

  default:
    throw std::invalid_argument("Invalid entity type in Read");
    break;
  }

  dynamic_cast<ent::Company&>(entity_).Add(entity, type);
}