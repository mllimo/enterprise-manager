#pragma once

#include "get_action.h"

class GetManual : public GetAction {
public:
  GetManual(ent::Entity& entity);
  virtual ~GetManual();
  virtual void Execute(ent::EntityType type) override;
};

