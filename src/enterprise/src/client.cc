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

}