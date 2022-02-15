#pragma once

#include <set>
#include <string>
#include <tuple>
#include <iterator>

#include <nlohmann/json.hpp>
#include <enterprise/entity.h>
#include <enterprise/regexs.h>

namespace ent {

  // Todo: Compare set with the id of the item

  struct CompareItem {
    bool operator()(const Item& lhs, const Item& rhs) const;
  };

  typedef std::tuple<long, std::string, double, long> Item;

  class Billiterator {
  public:
    using ValueType = Item;
    using ContPointer = const ValueType*;
    using ConstReference = const ValueType&;

    Billiterator(const std::set<ValueType, CompareItem>::iterator& it);
    Billiterator(const Billiterator& rhs);

    Billiterator& operator++();
    Billiterator operator++(int);

    bool operator==(const Billiterator& rhs);
    bool operator!=(const Billiterator& rhs);
    ConstReference operator*();
    ContPointer operator->();

  private:
    std::set<ValueType>::iterator it_;
  };

  class Bill : public Entity {
  public:
    using const_iterator = Billiterator;

    Bill();
    Bill(long id, const std::string& name, const std::string& email, const std::string& phone, const std::string& address);
    virtual ~Bill();

    const std::string& Name() const;
    const std::string& Email() const;
    const std::string& Phone() const;
    const std::string& Address() const;

    void Name(const std::string& name);
    void Email(const std::string& email);
    void Phone(const std::string& phone);
    void Address(const std::string& address);

    void AddItem(const Item& item);
    void AddItems(const std::set<Item>& items);

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
    std::string name_;
    std::string email_;
    std::string phone_;
    std::string address_;
    std::set <std::tuple<Item>, CompareItem> items_;
  };

} // namespace ent