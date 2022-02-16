#pragma once

#include <memory>

#include <enterprise/entity.h>


namespace ent {

  enum class StatusType {
    OK,
    FAIL
  };

  struct Status {
    StatusType type;
    std::shared_ptr<const Entity> data;
  };

} // namespace ent

