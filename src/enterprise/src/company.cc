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
      added = clients_.insert(*std::dynamic_pointer_cast<Client>(entity)).second;
      break;
    case EntityType::Supplier:
      added = suppliers_.insert(*std::dynamic_pointer_cast<Supplier>(entity)).second;
      break;
    case EntityType::Bill:
      added = bills_.insert(*std::dynamic_pointer_cast<Bill>(entity)).second;
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
      updated = clients_.erase(*std::dynamic_pointer_cast<Client>(entity)) &&
        clients_.insert(*std::dynamic_pointer_cast<Client>(entity)).second;
      break;
    case EntityType::Supplier:
      updated = suppliers_.erase(*std::dynamic_pointer_cast<Supplier>(entity)) &&
        suppliers_.insert(*std::dynamic_pointer_cast<Supplier>(entity)).second;
      break;
    case EntityType::Bill:
      updated = bills_.erase(*std::dynamic_pointer_cast<Bill>(entity)) &&
        bills_.insert(*std::dynamic_pointer_cast<Bill>(entity)).second;
      break;
    default:
      updated = false;
      break;
    }

    return Status{ (updated ? StatusType::OK : StatusType::FAIL), (updated ? entity : nullptr) };
  }

  Status Company::Remove(long id_entity, EntityType type) {
    bool removed = false;
    switch (type) {
    case EntityType::Client:
      removed = clients_.erase({ id_entity, "", "" });
      break;
    case EntityType::Supplier:
      removed = suppliers_.erase({ id_entity, "", "", "", "" });
      break;
    case EntityType::Bill:
      removed = bills_.erase({ id_entity, 0, 0, "" });
      break;
    default:
      removed = false;
      break;
    }

    return Status{ (removed ? StatusType::OK : StatusType::FAIL), nullptr };
  }

  Status Company::Get(long id_entity, EntityType type) const {
    std::shared_ptr<const Entity> entity;
    switch (type) {
    case EntityType::Client: {
      auto it = clients_.find({ id_entity, "", "" });
      entity = std::shared_ptr<const Entity>(it != clients_.end() ? &(*it) : nullptr);
    }break;
    case EntityType::Supplier: {
      auto it = suppliers_.find({ id_entity, "", "", "", "" });
      entity = std::shared_ptr<const Entity>(it != suppliers_.end() ? &(*it) : nullptr);
    }break;
    case EntityType::Bill: {
      auto it = bills_.find({ id_entity, 0, 0, "" });
      entity = std::shared_ptr<const Entity>(it != bills_.end() ? &(*it) : nullptr);
    }break;
    default:
      entity = nullptr;
      break;
    }

    return Status{ (entity != nullptr ? StatusType::OK : StatusType::FAIL), entity };
  }

  std::istream& operator>>(std::istream& is, Company& rhs) {
    nlohmann::json obj;
    is >> obj;
    rhs.id_ = obj["id"];
    rhs.cif_ = obj["cif"];

    auto clients = obj["clients"];
    auto suppliers = obj["suppliers"];
    auto bills = obj["bills"];

    for (auto& client : clients) {
      std::istringstream iss(client.dump());
      Client c;
      iss >> c;
      rhs.clients_.insert(c);
    }

    for (auto& supplier : suppliers) {
      std::istringstream iss(supplier.dump());
      Supplier s;
      iss >> s;
      rhs.suppliers_.insert(s);
    }

    for (auto& bill : bills) {
      std::istringstream iss(bill.dump());
      Bill b;
      iss >> b;
      rhs.bills_.insert(b);
    }

    return is;
  }

  std::ostream& operator<<(std::ostream& os, const Company& rhs) {
    nlohmann::json obj;
    obj["id"] = rhs.id_;
    obj["cif"] = rhs.cif_;

    auto clients = rhs.clients_;
    auto suppliers = rhs.suppliers_;
    auto bills = rhs.bills_;

    for (auto& client : clients) {
      obj["clients"].push_back(client);
    }

    for (auto& supplier : suppliers) {
      obj["suppliers"].push_back(supplier);
    }

    for (auto& bill : bills) {
      obj["bills"].push_back(bill);
    }

    os << obj;
    return os;
  }

} // namespace ent