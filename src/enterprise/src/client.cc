#include <nlohmann/json.hpp>

#include <enterprise/client.h>

namespace ent {
  Client::Client() : Entity() {}

  Client::Client(long id, const std::string& name, const std::string& email) : Entity(id), name_(name), email_(email) {
    if (!std::regex_match(email_, Regexs::email())) {
      throw std::invalid_argument("Invalid email");
    }
  }

  Client::~Client() {}

  EntityType Client::Type() const {
    return EntityType::Client;
  }

  const std::string& Client::Name() const {
    return name_;
  }

  const std::string& Client::Email() const {
    return email_;
  }

  void Client::Name(const std::string& name) {
    name_ = name;
  }

  void Client::Email(const std::string& email) {
    email_ = email;
  }

  std::istream& operator>>(std::istream& is, ent::Client& rhs) {
    nlohmann::json json;
    is >> json;

    rhs.id_ = json["id"];
    rhs.name_ = json["name"];
    rhs.email_ = json["email"];

    return is;
  }

  std::ostream& operator<<(std::ostream& os, const ent::Client& rhs) {
    nlohmann::json json;
    to_json(json, rhs);
    os << json;
    return os;
  }

  bool operator==(const Client& lhs, const Client& rhs) {
    return lhs.Id() == rhs.Id() && lhs.name_ == rhs.name_ && lhs.email_ == rhs.email_;
  }

  bool operator!=(const Client& lhs, const Client& rhs) {
    return !(lhs == rhs);
  }

  bool operator<(const Client& lhs, const Client& rhs) {
    return lhs.Id() < rhs.Id();
  }

  bool operator>(const Client& lhs, const Client& rhs) {
    return lhs.Id() > rhs.Id();
  }

  bool operator<=(const Client& lhs, const Client& rhs) {
    return lhs.Id() <= rhs.Id();
  }

  bool operator>=(const Client& lhs, const Client& rhs) {
    return lhs.Id() >= rhs.Id();
  }

  void to_json(nlohmann::json& j, const Client& rhs) {
    j = nlohmann::json{
      {"id", rhs.Id()},
      {"name", rhs.Name()},
      {"email", rhs.Email()}
    };
  }
} // namespace ent