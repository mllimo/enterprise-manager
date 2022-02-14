#include "gtest/gtest.h"
#include <enterprise/entity.h>

TEST(Entity, EntityDefaultConstructor) {
  ent::Entity e;
  EXPECT_EQ(-1, e.Id());
}

TEST(Entity, EntityIdConstructor) {
  long id = 10;
  ent::Entity e(id);
  EXPECT_EQ(10, e.Id());
}

TEST(Entity, EntityType) {
  ent::Entity e;
  EXPECT_EQ(ent::EntityType::Entity, e.Type());
}