#pragma once

#include <set>
#include <string>
#include <tuple>
#include <iterator>

#include <nlohmann/json.hpp>
#include <enterprise/entity.h>
#include <enterprise/regexs.h>

namespace ent {

  typedef std::tuple<long, std::string, double, long> Item;

  struct CompareItem {
    bool operator()(const Item& lhs, const Item& rhs) const;
  };

  class Billiterator {
  public:
    using ValueType = Item;
    using ContPointer = const ValueType*;
    using ConstReference = const ValueType&;

    Billiterator(const std::set<ValueType, CompareItem>::iterator& it);
    Billiterator(const Billiterator& rhs);

    Billiterator& operator++();
    Billiterator operator++(int);

    friend bool operator==(const Billiterator& lhs, const Billiterator& rhs);
    friend bool operator!=(const Billiterator& lhs, const Billiterator& rhs);
    ConstReference operator*();
    ContPointer operator->();

  private:
    std::set<ValueType, CompareItem>::iterator it_;
  };

  class Bill : public Entity {
  public:
    using const_iterator = Billiterator;

    Bill();
    Bill(long id, long client_id, long supplier_id, const std::string& date);
    virtual ~Bill();

    const std::set<Item, CompareItem>& Items() const;
    const std::string& Date() const;
    long SupplierId() const;
    long ClientId() const;
    double Total() const;


    void ClientId(long id);
    void SupplierId(long id);
    void Date(const std::string& date);


    void AddItem(const Item& item);
    void AddItems(const std::set<ent::Item, ent::CompareItem>& items);

    // TODO: Remove, Update, GetItems
    const_iterator UpdateItem(long id, const nlohmann::json& item);
    const_iterator GetItems(long id);
    bool RemoveItem(long id);

    const_iterator cbegin();
    const_iterator cend();

    virtual EntityType Type() const override;

    friend std::istream& operator>>(std::istream& is, Bill& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Bill& rhs);

  protected:
    long client_id_;
    long supplier_id_;
    std::string date_;
    std::set <Item, CompareItem> items_;
  };

} // namespace ent