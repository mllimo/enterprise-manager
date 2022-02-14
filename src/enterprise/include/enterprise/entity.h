#pragma once

namespace ent {

  class Entity {
  public:
    Entity();
    Entity(long id);

    virtual ~Entity();
    long Id() const;

  protected:
    long id_;
  };

} // namespace ent