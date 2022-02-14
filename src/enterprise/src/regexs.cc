#include <enterprise/regexs.h>

namespace ent {

    std::regex Regexs::email() {
      static std::regex email_regex("(\\w)+(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
      return email_regex;
    }
} // namespace ent