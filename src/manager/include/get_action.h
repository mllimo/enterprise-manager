#pragma once

#include "action.h"

#include <enterprise/client.h>
#include <enterprise/supplier.h>
#include <enterprise/bill.h>
#include <enterprise/company.h>

class GetAction : public Action {
public:
  GetAction(ent::Entity& entity);
  virtual ~GetAction();
  virtual void Execute(ent::EntityType type) override;

protected:
  virtual void Read(std::istream& is, ent::EntityType type);
};
