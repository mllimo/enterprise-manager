#include <enterprise/company.h>

namespace ent {

  Company::Company() : Entity() {}

  Company::Company(long id, const std::string& cif) : Entity(id), cif_(cif) {
    if (!std::regex_match(cif_, Regexs::cif())) {
      throw std::invalid_argument("Invalid cif");
    }
  }

  Company::~Company() {}

  EntityType Company::Type() const {
    return EntityType::Company;
  }

  const std::string& Company::Cif() const {
    return cif_;
  }

  Status Company::Add(std::shared_ptr<Entity> entity, EntityType type) {
    bool added = false;
    switch (type) {
    case EntityType::Client:
      added = clients_.insert(std::dynamic_pointer_cast<Client>(entity)).second;
      break;
    case EntityType::Supplier:
      added = suppliers_.insert(std::dynamic_pointer_cast<Supplier>(entity)).second;
      break;
    case EntityType::Bill:
      added = bills_.insert(std::dynamic_pointer_cast<Bill>(entity)).second;
      break;
    default:
      added = false;
      break;
    }

    return Status{ (added ? StatusType::OK : StatusType::FAIL), (added ? entity : nullptr) };
  }

  Status Company::Update(std::shared_ptr<Entity> entity, EntityType type) {
    bool updated = false;
    switch (type) {
    case EntityType::Client:
      updated = clients_.erase(std::dynamic_pointer_cast<Client>(entity)) &&
        clients_.insert(std::dynamic_pointer_cast<Client>(entity)).second;
      break;
    case EntityType::Supplier:
      updated = suppliers_.erase(std::dynamic_pointer_cast<Supplier>(entity)) &&
        suppliers_.insert(std::dynamic_pointer_cast<Supplier>(entity)).second;
      break;
    case EntityType::Bill:
      updated = bills_.erase(std::dynamic_pointer_cast<Bill>(entity)) &&
        bills_.insert(std::dynamic_pointer_cast<Bill>(entity)).second;
      break;
    default:
      updated = false;
      break;
    }

    return Status{ (updated ? StatusType::OK : StatusType::FAIL), (added ? entity : nullptr) };
  }

  Status Company::Remove(long id_entity, EntityType type) {
    bool removed = false;
    switch (type) {
    case EntityType::Client:
      removed = clients_.erase(id_entity);
      break;
    case EntityType::Supplier:
      removed = suppliers_.erase(id_entity);
      break;
    case EntityType::Bill:
      removed = bills_.erase(id_entity);
      break;
    default:
      removed = false;
      break;
    }

    return Status{ (removed ? StatusType::OK : StatusType::FAIL), (removed ? entity : nullptr) };
  }

  Status Company::Get(long id_entity, EntityType type) const {
    std::shared_ptr<Entity> entity;
    switch (type) {
    case EntityType::Client:
      auto it = clients_.find(id_entity)->second;
      entity = std::make_shared<Client>(it != clients_.end() ? it->second : nullptr);
      break;
    case EntityType::Supplier:
      auto it = suppliers_.find(id_entity)->second;
      entity = std::make_shared<Supplier>(it != suppliers_.end() ? it->second : nullptr);
      break;
    case EntityType::Bill:
      auto it = bills_.find(id_entity)->second;
      entity = std::make_shared<Bill>(it != bills_.end() ? it->second : nullptr);
      break;
    default:
      entity = nullptr;
      break;
    }

    return Status{ (entity != nullptr ? StatusType::OK : StatusType::FAIL), entity };
  }

} // namespace ent