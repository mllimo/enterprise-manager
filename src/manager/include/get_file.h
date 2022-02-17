#pragma once

#include <filesystem>
#include <fstream>

#include "get_action.h"


class GetFile : public GetAction {
public:
  GetFile(ent::Entity& entity);
  virtual ~GetFile();
  virtual void Execute(ent::EntityType type) override;

private:
  std::filesystem::path path_;
};
