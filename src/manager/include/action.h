#pragma once 

#include <memory>

#include <enterprise/entity.h>

#include "action.h"
class Action {
public:
  Action(const std::shared_ptr<ent::Entity>& entity);
  virtual ~Action();
  virtual void Execute(ent::EntityType type);

protected:
  std::shared_ptr<ent::Entity> entity_;
};