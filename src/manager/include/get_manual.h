#include "get_action.h"

class GetManual : public GetAction {
public:
  GetManual(const std::shared_ptr<ent::Entity>& entity);
  virtual ~GetManual();
  virtual void Execute(std::shared_ptr<ent::Entity> entity, ent::EntityType type) override;
};

