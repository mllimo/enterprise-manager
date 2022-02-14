#include "gtest/gtest.h"
#include <enterprise/client.h>

TEST(Client, ClientDefaultConstructor) {
  ent::Client c;
  EXPECT_EQ(-1, c.Id());
  EXPECT_EQ("", c.Name());
  EXPECT_EQ("", c.Email());
}

TEST(Client, ClientParameterConstructor) {
  int id = 1;
  std::string name = "name";
  std::string email = "email@a.es";
  ent::Client c(1, name, email);

  EXPECT_EQ(1, c.Id());
  EXPECT_EQ(name, c.Name());
  EXPECT_EQ(email, c.Email());
}

TEST(Client, ClientWithInvalidEmail) {
  int id = 1;
  std::string name = "name";
  std::string email = "email";
  try {
    ent::Client(1, name, email);
    FAIL();
  }
  catch (std::invalid_argument& err) {
    EXPECT_TRUE(true);
  }
}