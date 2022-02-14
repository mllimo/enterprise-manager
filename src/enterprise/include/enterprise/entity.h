#pragma once

#include <enterprise/entity_type.h>

namespace ent {

  class Entity {
  public:
    Entity();
    Entity(long id);

    virtual ~Entity();
    long Id() const;

    virtual EntityType Type() const;

  protected:
    long id_;
  };

} // namespace ent