#include <sstream>

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include <enterprise/company.h>


TEST(Company, DefaultConstructor) {
  ent::Company c;
  EXPECT_EQ(-1, c.Id());
  EXPECT_EQ("", c.Cif());
  EXPECT_EQ(0, c.Clients().size());
  EXPECT_EQ(0, c.Suppliers().size());
  EXPECT_EQ(0, c.Bills().size());
}

TEST(Company, ParameterConstructor) {
  int id = 1;
  std::string cif = "cif";
  ent::Company c(id, cif);
  EXPECT_EQ(id, c.Id());
  EXPECT_EQ(cif, c.Cif());
  EXPECT_EQ(0, c.Clients().size());
  EXPECT_EQ(0, c.Suppliers().size());
  EXPECT_EQ(0, c.Bills().size());
}

TEST(Company, CompanyType) {
  ent::Company c;
  EXPECT_EQ(ent::EntityType::Company, c.Type());
}

// ADD
TEST(Company, AddClient) {
  ent::Company c;
  ent::Client client;
  c.AddClient(client);
  EXPECT_EQ(1, c.Clients().size());
}

TEST(Company, AddSupplier) {
  ent::Company c;
  ent::Supplier supplier;
  c.AddSupplier(supplier);
  EXPECT_EQ(1, c.Suppliers().size());
}

TEST(Company, AddBill) {
  ent::Company c;
  ent::Bill bill;
  c.AddBill(bill);
  EXPECT_EQ(1, c.Bills().size());
}

// GET
TEST(Company, GetClient) {
  ent::Company c;
  ent::Client client;
  c.AddClient(client);
  EXPECT_EQ(client, *c.GetClient(client.Id()));
}

TEST(Company, GetSupplier) {
  ent::Company c;
  ent::Supplier supplier;
  c.AddSupplier(supplier);
  EXPECT_EQ(supplier, *c.GetSupplier(supplier.Id()));
}

TEST(Company, GetBill) {
  ent::Company c;
  ent::Bill bill;
  c.AddBill(bill);
  EXPECT_EQ(bill, *c.GetBill(bill.Id()));
}

// UPDATE

TEST(Company, UpdateClient) {
  ent::Company c;
  ent::Client client;
  c.AddClient(client);
  ent::Client client2;
  client2.SetId(client.Id());
  c.UpdateClient(client2);
  EXPECT_EQ(client2, *c.GetClient(client.Id()));
}

TEST(Company, UpdateSupplier) {
  ent::Company c;
  ent::Supplier supplier;
  c.AddSupplier(supplier);
  ent::Supplier supplier2;
  supplier2.SetId(supplier.Id());
  c.UpdateSupplier(supplier2);
  EXPECT_EQ(supplier2, *c.GetSupplier(supplier.Id()));
}

TEST(Company, UpdateBill) {
  ent::Company c;
  ent::Bill bill;
  c.AddBill(bill);
  ent::Bill bill2;
  bill2.SetId(bill.Id());
  c.UpdateBill(bill2);
  EXPECT_EQ(bill2, *c.GetBill(bill.Id()));
}

// REMOVE

TEST(Company, UpdateClient) {
  ent::Company c;
  ent::Client client;
  c.AddClient(client);
  c.RemoveClient(client.Id());
  EXPECT_EQ(0, c.Clients().size());
}

TEST(Company, UpdateSupplier) {
  ent::Company c;
  ent::Supplier supplier;
  c.AddSupplier(supplier);
  c.RemoveSupplier(supplier.Id());
  EXPECT_EQ(0, c.Suppliers().size());
}

TEST(Company, UpdateBill) {
  ent::Company c;
  ent::Bill bill;
  c.AddBill(bill);
  c.RemoveBill(bill.Id());
  EXPECT_EQ(0, c.Bills().size());
}

////////


TEST(Compnay, CompanyIstreamOstream) {
  ent::Company c;
  std::ostringstream osjson;
  std::ostringstream oscompany;

  nlohmann::json expected_json;
  expected_json["id"] = 1;
  expected_json["cif"] = "cif";

  nlohmann::json client_1;
  client_1["id"] = 1;
  client_1["name"] = "ab";
  client_1["email"] = "aa@asd.es";

  nlohmann::json client_2;
  client_2["id"] = 2;
  client_2["name"] = "ab";
  client_2["email"] = "asdasd@ad.es";

  nlohmann::json supplier_1;
  supplier_1["id"] = 1;
  supplier_1["name"] = "ab";
  supplier_1["email"] = "ads@asd.es";
  supplier_2["phone"] = "123456789";
  supplier_2["address"] = "address";

  nlohmann::json bill_1;
  bill_1["id"] = 11;
  bill_1["client_id"] = 2;
  bill_1["supplier_id"] = 3;
  bill_1["date"] = "2019-01-01";

  nlohmann::json item1;
  item1["id"] = 1;
  item1["description"] = "item1";
  item1["price"] = 1.0;
  item1["quantity"] = 1;
  nlohmann::json item2;
  item2["id"] = 2;
  item2["description"] = "item2";
  item2["price"] = 2.0;
  item2["quantity"] = 2;
  nlohmann::json item3;
  item3["id"] = 3;
  item3["description"] = "item3";
  item3["price"] = 3.0;
  item3["quantity"] = 3;

  bill_1["items"] = { item1, item2, item3 };

  expected_json["clients"] = { client_1, client_2 };
  expected_json["suppliers"] = { supplier_1, supplier_2 };
  expected_json["bills"] = { bill_1 };

  osjson << expected_json;
  std::string expected_str = osjson.str();
  std::istringstream isjson(expected_str);

  isjson >> c;
  oscompany << c;

  std::string actual_str = oscompany.str();

  EXPECT_EQ(expected_str, actual_str);
}