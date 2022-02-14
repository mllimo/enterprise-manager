#include <string>
#include <set>
#include <tuple>

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <enterprise/bill.h>

TEST(Bill, BillDefaultConstructor) {
  ent::Bill b;
  EXPECT_EQ(-1, b.Id());
  EXPECT_EQ(-1, b.ClientId());
  EXPECT_EQ(-1, b.SupplierId());
  EXPECT_EQ(0, b.Total());
  EXPECT_EQ(0, b.Date());
  EXPECT_EQ({}, b.Items());
}

TEST(Bill, BillParameterConstructor) {
  long id = 1;
  long client_id = 2;
  long supplier_id = 3;
  int total = 4;
  int date = 5;

  // id, description, price, quantity
  std::set<std::tuple<long, std::string, double, long>> items = {
    std::make_tuple(1, "item1", 1.0, 1),
    std::make_tuple(2, "item2", 2.0, 2),
    std::make_tuple(3, "item3", 3.0, 3)
  };

  ent::Bill b(id, client_id, supplier_id, total, date);
  b.AddItem({1, "item1", 1.0, 1});
  b.AddItem({2, "item2", 2.0, 2});
  b.AddItem({3, "item3", 3.0, 3});

  EXPECT_EQ(1, b.Id());
  EXPECT_EQ(2, b.ClientId());
  EXPECT_EQ(3, b.SupplierId());
  EXPECT_EQ(4, b.Total());
  EXPECT_EQ(5, b.Date());
  EXPECT_EQ(items, b.Items());
}

TEST(Bill, BillType) {
  ent::Bill b;
  EXPECT_EQ(ent::EntityType::Bill, b.Type());
}

TEST(Bill, AddItems) {
  ent::Bill b;
  std::set<std::tuple<long, std::string, double, long>> items = {
    std::make_tuple(1, "item1", 1.0, 1),
    std::make_tuple(2, "item2", 2.0, 2),
    std::make_tuple(3, "item3", 3.0, 3)
  };

  b.AddItems(items);
  EXPECT_EQ(items, b.Items());
}

TEST(Bill, OstreamIsteram) {
  ent::Bill b;
  std::ostringstream osjson;
  std::ostringstream osclient;

  nlohmann::json expected_json;
  expected_json["id"] = 1;
  expected_json["client_id"] = 2;
  expected_json["supplier_id"] = 3;
  expected_json["total"] = 4;
  expected_json["date"] = 5;
  expected_json["items"] = {
    {1, "item1", 1.0, 1},
    {2, "item2", 2.0, 2},
    {3, "item3", 3.0, 3}
  };

  osjson << expected_json;
  std::string expected_str = osjson.str();
  std::istringstream isjson(expected_str);

  isjson >> b;
  EXPECT_EQ(expected_json["id"], b.Id());
  EXPECT_EQ(expected_json["client_id"], b.ClientId());
  EXPECT_EQ(expected_json["supplier_id"], b.SupplierId());
  EXPECT_EQ(expected_json["total"], b.Total());
  EXPECT_EQ(expected_json["date"], b.Date());
  EXPECT_EQ(expected_json["items"], b.Items());
}
