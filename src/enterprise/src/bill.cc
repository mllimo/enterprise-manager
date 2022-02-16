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

  bool operator==(const Billiterator& lhs, const Billiterator& rhs) {
    return lhs.it_ == rhs.it_;
  }

  bool operator!=(const Billiterator& lhs, const Billiterator& rhs) {
    return lhs.it_ != rhs.it_;
  }

  Billiterator::ConstReference Billiterator::operator*() {
    return *it_;
  }

  Billiterator::ContPointer Billiterator::operator->() {
    return &*it_;
  }

  Bill::Bill() : Entity(), client_id_(-1), supplier_id_(-1) {}

  Bill::Bill(long id, long client_id, long supplier_id, const std::string& date)
    : Entity(id), client_id_(client_id), supplier_id_(supplier_id), date_(date) {}

  Bill::~Bill() {}

  const std::set<Item, CompareItem>& Bill::Items() const {
    return items_;
  }

  long Bill::ClientId() const {
    return client_id_;
  }

  long Bill::SupplierId() const {
    return supplier_id_;
  }

  const std::string& Bill::Date() const {
    return date_;
  }

  double Bill::Total() const {
    double total = 0.f;
    for (const auto& item : items_) {
      total += std::get<2>(item) * std::get<3>(item);
    }
    return total;
  }

  void Bill::ClientId(long id) {
    client_id_ = id;
  }

  void Bill::SupplierId(long id) {
    supplier_id_ = id;
  }

  void Bill::Date(const std::string& date) {
    date_ = date;
  }

  void Bill::AddItem(const Item& item) {
    items_.insert(item);
  }

  void Bill::AddItems(const std::set<ent::Item, ent::CompareItem>& items) {
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
    rhs.client_id_ = json["client_id"];
    rhs.supplier_id_ = json["supplier_id"];
    rhs.date_ = json["date"];

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
    json["client_id"] = rhs.client_id_;
    json["supplier_id"] = rhs.supplier_id_;
    json["date"] = rhs.date_;

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