#include "gtest/gtest.h"
#include "enterprise/client.h"

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

TEST(Client, ClientWithValidEmail) {
  int id = 1;
  std::string name = "name";
  std::string email = "email";
  EXPECT_TO_THROW(ent::Client(1, name, email), std::invalid_argument);
}