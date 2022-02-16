#include <enterprise/supplier.h>

namespace ent {
  Supplier::Supplier() : Entity() {}

  Supplier::Supplier(long id, const std::string& name, const std::string& email, const std::string& phone, const std::string& address)
    : Entity(id), name_(name), email_(email), phone_(phone), address_(address) {
    if (!std::regex_match(email_, Regexs::email())) {
      throw std::invalid_argument("Invalid email");
    }

    if (!std::regex_match(phone_, Regexs::phone())) {
      throw std::invalid_argument("Invalid phone");
    }
  }

  Supplier::~Supplier() {}

  const std::string& Supplier::Name() const {
    return name_;
  }

  const std::string& Supplier::Email() const {
    return email_;
  }

  const std::string& Supplier::Phone() const {
    return phone_;
  }

  const std::string& Supplier::Address() const {
    return address_;
  }

  void Supplier::Name(const std::string& name) {
    name_ = name;
  }

  void Supplier::Email(const std::string& email) {
    email_ = email;
  }

  void Supplier::Phone(const std::string& phone) {
    phone_ = phone;
  }

  void Supplier::Address(const std::string& address) {
    address_ = address;
  }

  EntityType Supplier::Type() const {
    return EntityType::Supplier;
  }

  std::istream& operator>>(std::istream& is, Supplier& rhs) {
    nlohmann::json json;
    is >> json;

    rhs.id_ = json["id"];
    rhs.name_ = json["name"];
    rhs.email_ = json["email"];
    rhs.phone_ = json["phone"];
    rhs.address_ = json["address"];

    return is;
  }

  std::ostream& operator<<(std::ostream& os, const Supplier& rhs) {
    nlohmann::json json;
    to_json(json, rhs);
    os << json;
    return os;
  }

  bool operator==(const Supplier& lhs, const Supplier& rhs) {
    return lhs.Id() == rhs.Id() &&
      lhs.name_ == rhs.name_ &&
      lhs.email_ == rhs.email_ &&
      lhs.phone_ == rhs.phone_ &&
      lhs.address_ == rhs.address_;
  }

  bool operator!=(const Supplier& lhs, const Supplier& rhs) {
    return !(lhs == rhs);
  }

  bool operator<(const Supplier& lhs, const Supplier& rhs) {
    return lhs.Id() < rhs.Id();
  }

  bool operator>(const Supplier& lhs, const Supplier& rhs) {
    return rhs < lhs;
  }

  bool operator<=(const Supplier& lhs, const Supplier& rhs) {
    return !(rhs < lhs);
  }

  bool operator>=(const Supplier& lhs, const Supplier& rhs) {
    return !(lhs < rhs);
  }

  void to_json(nlohmann::json& j, const Supplier& rhs) {
    j = nlohmann::json{
      {"id", rhs.Id()},
      {"name", rhs.Name()},
      {"email", rhs.Email()},
      {"phone", rhs.Phone()},
      {"address", rhs.Address()}
    };
  }

}