#include "get_file.h"

GetFile::GetFile(const std::shared_ptr<ent::Entity>& entity)
  : GetAction(entity) {}

GetFile::~GetFile() {}

void GetFile::Execute(ent::EntityType type) {
  std::cout << "Type the path of the file/folder you want to use: " << std::endl;
  std::cin >> path;

  if (std::filesystem::is_directory(path)) {
    std::cout << "Loading folder: " << path << std::endl;
    for (auto& entry : std::filesystem::directory_iterator(path)) {
      if (!std::filesystem::is_directory(entry.path())) {
        std::cout << "Loading file: " << entry.path() << std::endl;
        std::ifstream file(entry.path());
        Read(file, type);
      }
    }
  }
  else {
    std::cout << "Loading file: " << entry.path() << std::endl;
    std::ifstream file(entry.path());
    Read(file, type);
  }
}