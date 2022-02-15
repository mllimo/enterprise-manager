#include <enterprise/regexs.h>

namespace ent {

  const std::regex& Regexs::email() {
    static std::regex email_regex("(\\w)+(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return email_regex;
  }

  const std::regex& Regexs::phone() {
    static std::regex phone_regex("\\d+");
    return phone_regex;
  }
} // namespace ent