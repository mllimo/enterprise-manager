#include <filesystem>

#include "get_action.h"


class GetFile : public GetAction {
public:
  GetFile(const std::shared_ptr<ent::Entity>& entity);
  virtual ~GetFile();
  virtual void Execute(std::shared_ptr<ent::Entity> entity, ent::EntityType type) override;

private:
  std::filesystem::path path_;
};
