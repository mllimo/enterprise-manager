#include "action.h"

Action::Action(ent::Entity& entity) : entity_(entity) {}

Action::~Action() {}

void Action::Execute(ent::EntityType type) {}