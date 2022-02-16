#pragma once

#include <set>
#include <string>
#include <memory>

#include <nlohmann/json.hpp>

#include <enterprise/client.h>
#include <enterprise/supplier.h>
#include <enterprise/bill.h>
#include <enterprise/status.h>
#include <enterprise/regexs.h>

namespace ent {

  class Company : public Entity {
  public:
    Company();
    Company(long id, const std::string& cif);
    virtual ~Company();

    EntityType Type() const override;

    const std::string& Cif() const;
    
    Status Add(std::shared_ptr<Entity> entity, EntityType type);
    Status Update(std::shared_ptr<Entity> entity, EntityType type);
    Status Remove(long id_entity, EntityType type);
    Status Get(long id_entity, EntityType type) const;

    friend std::istream& operator>>(std::istream& is, Company& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Company& rhs);

  protected:
    std::string cif_;
    std::set<Client> clients_;
    std::set<Supplier> suppliers_;
    std::set<Bill> bills_;
  };

} // namespace ent