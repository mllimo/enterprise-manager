#pragma once 

#include <memory>

#include <enterprise/entity.h>

class Action {
public:
  Action(ent::Entity& entity);
  virtual ~Action();
  virtual void Execute(ent::EntityType type);

protected:
  ent::Entity& entity_;
};