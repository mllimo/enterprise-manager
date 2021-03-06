#include "enterprise/entity.h"

namespace ent {
  Entity::Entity() : id_(-1){}

  Entity::Entity(long id) : id_(id) {}

  Entity::~Entity() {}

  long Entity::Id() const {
    return id_;
  }

  ent::EntityType Entity::Type() const {
    return ent::EntityType::Entity;
  }
}