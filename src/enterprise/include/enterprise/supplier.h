#pragma once

#include <string>

#include <nlohmann/json.hpp>
#include <enterprise/entity.h>
#include <enterprise/regexs.h>

namespace ent {

  class Supplier : public Entity {
  public:
    Supplier();
    Supplier(long id, const std::string& name, const std::string& email, const std::string& phone, const std::string& address);
    virtual ~Supplier();

    const std::string& Name() const;
    const std::string& Email() const;
    const std::string& Phone() const;
    const std::string& Address() const;

    void Name(const std::string& name);
    void Email(const std::string& email);
    void Phone(const std::string& phone);
    void Address(const std::string& address);

    virtual EntityType Type() const override;

    friend std::istream& operator>>(std::istream& is, Supplier& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Supplier& rhs);
    friend bool operator==(const Supplier& lhs, const Supplier& rhs);
    friend bool operator!=(const Supplier& lhs, const Supplier& rhs);
    friend bool operator<(const Supplier& lhs, const Supplier& rhs);
    friend bool operator>(const Supplier& lhs, const Supplier& rhs);
    friend bool operator<=(const Supplier& lhs, const Supplier& rhs);
    friend bool operator>=(const Supplier& lhs, const Supplier& rhs);

    friend void to_json(nlohmann::json& j, const Supplier& rhs);

  protected:
    std::string name_;
    std::string email_;
    std::string phone_;
    std::string address_;
  };

} // namespace ent