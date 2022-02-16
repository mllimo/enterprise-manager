#include <enterprise/bill.h>


namespace ent {

  bool CompareItem::operator()(const Item& lhs, const Item& rhs) const {
    return std::get<0>(lhs) < std::get<0>(rhs);
  }

  Billiterator::Billiterator(const std::set<ValueType, CompareItem>::iterator& it)
    : it_(it) {}

  Billiterator::Billiterator(const Billiterator& rhs) : it_(rhs.it_) {}

  Billiterator& Billiterator::operator++() {
    ++it_;
    return *this;
  }

  Billiterator Billiterator::operator++(int) {
    Billiterator tmp(*this);
    ++it_;
    return tmp;
  }

  bool Billiterator::operator==(const Billiterator& rhs) {
    return it_ == rhs.it_;
  }

  bool Billiterator::operator!=(const Billiterator& rhs) {
    return it_ != rhs.it_;
  }

  Billiterator::ConstReference Billiterator::operator*() {
    return *it_;
  }

  Billiterator::ContPointer Billiterator::operator->() {
    return &*it_;
  }

  Bill::Bill() : Entity() {}

  Bill::Bill(long id, const std::string& name, const std::string& email, const std::string& phone, const std::string& address)
    : Entity(id), name_(name), email_(email), phone_(phone), address_(address) {}

  Bill::~Bill() {}

  const std::string& Bill::Name() const {
    return name_;
  }

  const std::string& Bill::Email() const {
    return email_;
  }

  const std::string& Bill::Phone() const {
    return phone_;
  }

  const std::string& Bill::Address() const {
    return address_;
  }

  void Bill::Name(const std::string& name) {
    name_ = name;
  }

  void Bill::Email(const std::string& email) {
    email_ = email;
  }

  void Bill::Phone(const std::string& phone) {
    phone_ = phone;
  }

  void Bill::Address(const std::string& address) {
    address_ = address;
  }

  void Bill::AddItem(const Item& item) {
    items_.insert(item);
  }

  void Bill::AddItems(const std::set<Item>& items) {
    items_.insert(items.begin(), items.end());
  }

  // TODO: Remove, Update, GetItems
  Bill::const_iterator Bill::UpdateItem(long id, const nlohmann::json& item) {
    Item aux_item;
    std::get<0>(aux_item) = id;
    auto it = items_.find(aux_item);

    if (it != items_.end()) {
      aux_item = *it;
      items_.erase(it);
      if (item.contains("name")) {
        std::get<1>(aux_item) = item["name"];
      }
      if (item.contains("price")) {
        std::get<2>(aux_item) = item["price"];
      }
      if (item.contains("quantity")) {
        std::get<3>(aux_item) = item["quantity"];
      }
      auto pair_it = items_.insert(aux_item);
      return Billiterator(pair_it.first);
    }

    return cend();
  }

  bool Bill::RemoveItem(long id) {
    bool ret = false;
    Item aux_item;
    std::get<0>(aux_item) = id;
    auto it = items_.find(aux_item);
    if (it != items_.end()) {
      items_.erase(it);
      ret = true;
    }
    return ret;
  }

  Bill::const_iterator Bill::GetItems(long id) {
    Item aux_item;
    std::get<0>(aux_item) = id;
    auto it = items_.find(aux_item);
    if (it != items_.end()) {
      return Billiterator(it);
    }
    return cend();
  }

  Bill::const_iterator Bill::cbegin() {
    return Billiterator(items_.cbegin());
  }

  Bill::const_iterator Bill::cend() {
    return Billiterator(items_.cend());
  }


  EntityType Bill::Type() const {
    return EntityType::Bill;
  }

  std::istream& operator>>(std::istream& is, Bill& rhs) {
    nlohmann::json json;
    is >> json;
    rhs.id_ = json["id"];
    rhs.name_ = json["name"];
    rhs.email_ = json["email"];
    rhs.phone_ = json["phone"];
    rhs.address_ = json["address"];

    for (auto& item : json["items"]) {
      Item aux_item;
      std::get<0>(aux_item) = item["id"];
      std::get<1>(aux_item) = item["name"];
      std::get<2>(aux_item) = item["price"];
      std::get<3>(aux_item) = item["quantity"];
      rhs.items_.insert(aux_item);
    }

    return is;
  }

  std::ostream& operator<<(std::ostream& os, const Bill& rhs) {
    nlohmann::json json;
    json["id"] = rhs.id_;
    json["name"] = rhs.name_;
    json["email"] = rhs.email_;
    json["phone"] = rhs.phone_;
    json["address"] = rhs.address_;

    for (auto& item : rhs.items_) {
      nlohmann::json aux_item;
      aux_item["id"] = std::get<0>(item);
      aux_item["name"] = std::get<1>(item);
      aux_item["price"] = std::get<2>(item);
      aux_item["quantity"] = std::get<3>(item);
      json["items"].push_back(aux_item);
    }

    os << json;
    return os;
  }

}