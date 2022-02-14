#pragma once

#include <string>

#include <enterprise/entity.h>
#include <enterprise/regexs.h>

namespace ent {

  class Client : public Entity {
  public:
    Client();
    Client(long id, const std::string& name, const std::string& email);
    virtual ~Client();

    const std::string& Name() const;
    const std::string& Email() const;

    void Name(const std::string& name);
    void Email(const std::string& email);

    virtual EntityType Type() const override;

  protected:
    std::string name_;
    std::string email_;
  };

} // namespace ent
