#pragma once

#include <enterprise/client.h>
#include <enterprise/supplier.h>
#include <enterprise/bill.h>

#include <set>
#include <string>
#include <memory>

namespace ent {

  class Company : public Entity {
  public:
    Company();

  protected:
    std::string cif_;

    std::set<Client> clients_;
    std::set<Supplier> suppliers_;
    std::set<Bill> bills_;
  };

} // namespace ent