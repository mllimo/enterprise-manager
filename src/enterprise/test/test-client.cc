#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include <sstream>

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
  ent::Client c(id, name, email);

  EXPECT_EQ(id, c.Id());
  EXPECT_EQ(name, c.Name());
  EXPECT_EQ(email, c.Email());
}

TEST(Client, ClientWithInvalidEmail) {
  int id = 1;
  std::string name = "name";
  std::string email = "email";
  try {
    ent::Client(id, name, email);
    FAIL();
  }
  catch (std::invalid_argument& err) {
    EXPECT_TRUE(true);
  }
}

TEST(Client, ClientType) {
  ent::Client c;
  EXPECT_EQ(ent::EntityType::Client, c.Type());
}

TEST(Client, ClientIstreamOstream) {
  ent::Client c;
  std::ostringstream osjson;
  std::ostringstream osclient;

  nlohmann::json expected_json;
  expected_json["id"] = 1;
  expected_json["name"] = "ab";
  expected_json["email"] = "a@gmail.com";

  osjson << expected_json;
  std::string expected_str = osjson.str();
  std::istringstream isjson(expected_str);

  isjson >> c;
  osclient << c;

  std::string actual_str = osclient.str();

  EXPECT_EQ(expected_str, actual_str);
}