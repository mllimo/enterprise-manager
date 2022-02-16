#include "action.h"

class GetAction : public Action {
public:
  GetAction(const std::shared_ptr<ent::Entity>& entity);
  virtual ~GetAction();
  virtual void Execute(std::shared_ptr<ent::Entity> entity, ent::EntityType type) override;

protected:
  virtual void Read(std::istream& is, ent::EntityType type);
};
