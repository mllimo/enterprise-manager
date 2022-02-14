#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <enterprise/supplier.h>

TEST(Supplier, SupplierDefaultConstructor) {
  ent::Supplier s;
  EXPECT_EQ(-1, s.Id());
  EXPECT_EQ("", s.Name());
  EXPECT_EQ("", s.Email());
  EXPECT_EQ("", s.Phone());
  EXPECT_EQ("", s.Address());
}

TEST(Supplier, SupplierParameterConstructor) {
  long id = 1;
  std::string name = "name";
  std::string email = "a@gmail.com"
    std::string phone = "123456789";
  std::string address = "address";
  ent::Supplier s(id, name, email, phone, address);
  EXPECT_EQ(1, s.Id());
  EXPECT_EQ(name, s.Name());
  EXPECT_EQ(email, s.Email());
  EXPECT_EQ(phone, s.Phone());
  EXPECT_EQ(address, s.Address());
}

TEST(Supplier, SupplierType) {
  ent::Supplier s;
  EXPECT_EQ(ent::EntityType::Supplier, s.Type());
}

TEST(Supplier, SupplierIstreamOstream) {
  ent::Supplier s;
  std::ostringstream osjson;
  std::ostringstream osclient;

  nlohmann::json expected_json;
  expected_json["id"] = 1;
  expected_json["name"] = "ab";
  expected_json["email"] = "a@a.es";
  expected_json["phone"] = "123456789";
  expected_json["address"] = "address";

  osjson << expected_json;
  std::string expected_str = osjson.str();
  std::istringstream isjson(expected_str);

  isjson >> s;
  EXPECT_EQ(expected_json["id"], s.Id());
  EXPECT_EQ(expected_json["name"], s.Name());
  EXPECT_EQ(expected_json["email"], s.Email());
  EXPECT_EQ(expected_json["phone"], s.Phone());
  EXPECT_EQ(expected_json["address"], s.Address());
}