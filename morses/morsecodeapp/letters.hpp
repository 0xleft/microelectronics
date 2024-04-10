struct Letter {
  const char* sequence;
  char representation;
};

Letter TRANSLATION_LIST[] = {
  {"._", 'a'},
  {"_...", 'b'},
  {"_._.", 'c'},
  {"_..", 'd'},
  {".", 'e'},
  {".._.", 'f'},
  {"__.", 'g'},
  {"....", 'h'},
  {"..", 'i'},
  {".___", 'j'},
  {"_._", 'k'},
  {"._..", 'l'},
  {"__", 'm'},
  {"_.", 'n'},
  {"___", 'o'},
  {".__.", 'p'},
  {"__._", 'q'},
  {"._.", 'r'},
  {"...", 's'},
  {"_", 't'},
  {".._", 'u'},
  {"..._", 'v'},
  {".__", 'w'},
  {"_.._", 'x'},
  {"_.__", 'y'},
  {"__..", 'z'}
};

Letter findLetter(const char* sequence) {
  for (Letter letter : TRANSLATION_LIST) {
    if (strcmp(letter.sequence, sequence) == 0) {
      return letter;
    }
  }

  return Letter{" ", ' '};
}