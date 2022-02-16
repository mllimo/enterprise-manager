#pragma once

#include <regex>

namespace ent {

  class Regexs {
  public:
    static const std::regex& email();
    static const std::regex& phone();
    static const std::regex& cif();
  };

} // namespace ent