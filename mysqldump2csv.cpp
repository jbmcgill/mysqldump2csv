#include <fstream>
#include <vector>
#include <cstring>

std::string readfile(std::string fileName)
{
  std::ifstream ifs(fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

  std::ifstream::pos_type fileSize = ifs.tellg();
  ifs.seekg(0, std::ios::beg);

  std::vector<char> bytes(fileSize);
  ifs.read(&bytes[0], fileSize);

  return std::string(&bytes[0], fileSize);
}

void parse_dump(std::string s){
  char *next;
  char *curr = (char*)s.c_str();
  char buff[2048];
  while ((next = strchr(curr, '(')) != NULL) {
      curr = next + 1;
      next = strchr(curr, ')');
      strncpy(buff,curr,next-curr);
      buff[next-curr] = '\0';
      printf("%s\n", buff);
      curr = next+1;
    }
  return;
}

int main(int argc, char** argv){
  if( argc < 2 ){
    printf("must provide mysql dump file as argument");
    exit(0);
  }
  std::string activityfilename = argv[1];
  std::string raw[3], dates[3];
  raw[0] = readfile(activityfilename);
  parse_dump(raw[0]);
  return 0;
}

