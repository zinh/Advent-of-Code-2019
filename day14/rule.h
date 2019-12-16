struct Map {
  int count;
  char *name;
};

struct Rule {
  struct Map target;
  int n_rule;
  struct Map *rules;
};

struct Rule read_file(char *);
