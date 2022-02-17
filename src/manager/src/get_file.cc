#include "get_file.h"

GetFile::GetFile(ent::Entity& entity)
  : GetAction(entity) {}

GetFile::~GetFile() {}

void GetFile::Execute(ent::EntityType type) {
  std::cout << "Type the path of the file/folder you want to use: ";
  std::cin >> path_;

  if (std::filesystem::is_directory(path_)) {
    std::cout << "Loading folder: " << path_ << std::endl;
    for (auto& entry : std::filesystem::directory_iterator(path_)) {
      if (!std::filesystem::is_directory(entry.path())) {
        std::cout << "Loading file: " << entry.path() << std::endl;
        std::ifstream file(entry.path());
        Read(file, type);
      }
    }
  }
  else {
    std::cout << "Loading file: " << path_ << std::endl;
    std::ifstream file(path_);
    Read(file, type);
  }
}