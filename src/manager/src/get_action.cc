#include "get_action.h"

GetAction::GetAction(ent::Entity& entity) : Action(entity) {}

GetAction::~GetAction() {}

void GetAction::Execute(ent::EntityType type) {}

void GetAction::Read(std::istream& is, ent::EntityType type) {
  std::shared_ptr<ent::Entity> entity;

  switch (type) {
  case ent::EntityType::Client:
    entity = std::make_shared<ent::Client>();
    is >> *std::dynamic_pointer_cast<ent::Client>(entity);
    break;

  case ent::EntityType::Supplier:
    entity = std::make_shared<ent::Supplier>();
    is >> *std::dynamic_pointer_cast<ent::Supplier>(entity);
    break;

  case ent::EntityType::Bill:
    entity = std::make_shared<ent::Bill>();
    is >> *std::dynamic_pointer_cast<ent::Bill>(entity);
    break;

  default:
    throw std::invalid_argument("Invalid entity type in Read");
    break;
  }

  dynamic_cast<ent::Company&>(entity_).Add(entity, type);
}