#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 10000

typedef struct options {
  int e;  //
  int i;  //+
  int v;  //+
  int c;  //+
  int l;  //+
  int n;  //+
  int h;  //+
  int s;  //+
  int f;  //+
  int o;  //+
  char str[BUFFER];
  char str_regexec[BUFFER];
  char str_o[BUFFER];
  char filename[BUFFER];
} FLAGS;

int flags_reading(int argc, char *argv[], FLAGS *opt);
void output(int ci, int argc, char *argv[], FLAGS *opt);
void f_flag(FLAGS *opt);

int main(int argc, char *argv[]) {
  FLAGS opt = {0};
  // printf("fr\n");
  int ci = flags_reading(argc, argv, &opt);
  while (ci <= (argc - 1)) {
    output(ci, argc, argv, &opt);
    ci++;
  }
  // printf("o");
  return 0;
}

int flags_reading(int argc, char *argv[], FLAGS *opt) {
  char flag;
  while ((flag = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, 0)) != -1) {
    switch (flag) {
      case 'e':
        opt->e = 1;
        strcat(opt->str, optarg);
        strcat(opt->str, "|");
        break;
      case 'i':
        opt->i = 1;
        break;
      case 'v':
        opt->v = 1;
        break;
      case 'c':
        opt->c = 1;
        break;
      case 'l':
        opt->l = 1;
        break;
      case 'n':
        opt->n = 1;
        break;
      case 'h':
        opt->h = 1;
        break;
      case 's':
        opt->s = 1;
        break;
      case 'f':
        opt->f = 1;
        strcpy(opt->filename, optarg);
        f_flag(opt);
        break;
      case 'o':
        opt->o = 1;
        break;
      default:
        break;
    }
    if (opt->v && opt->o) {
      opt->o = 0;
    }
  }
  if (!opt->e && !opt->f) {
    if (argc > optind) {
      strcat(opt->str, argv[optind]);
    }
    optind++;
  }
  if (opt->e || opt->f) {
    opt->str[strlen(opt->str) - 1] = '\0';  // удаляем посл. пайп
                                            // printf("%s\n", A->str);
  }
  // printf("%s", (*opt).sample);
  // printf("%d", optind);
  return optind;
}

void output(int ci, int argc, char *argv[], FLAGS *opt) {
  FILE *file;
  regex_t reg;
  regmatch_t start;
  int match = 0;
  int counter = 0;
  int index = 0;
  int flag = 0;
  int flag_i = REG_EXTENDED;
  if (opt->i) {
    flag_i =
        REG_EXTENDED | REG_ICASE;  // | - последовательность, если выполнилось
                                   // REG_EXTENDED, то выполнится и REG_ICASE
  }
  regcomp(&reg, opt->str, flag_i);
  file = fopen(argv[ci], "r");
  if (file != NULL) {
    while (fgets(opt->str_regexec, BUFFER, file) != NULL) {
      index++;
      match = regexec(&reg, opt->str_regexec, 1, &start, 0);
      if (opt->v) {  // флаг v
        match = !match;
      }
      if (!match && (argc - optind) == 1) {  // если один файл на входе
        if (!match) {
          flag = 1;
        }
        if (opt->o) {
          strcpy(opt->str_o, opt->str_regexec);
        }
        if (!match && opt->o) {
          char *pointer = opt->str_o;
          while ((regexec(&reg, pointer, 1, &start, 0) == 0)) {
            // найти кол-во повторений аргументов с помощью функции (своей);
            printf("%.*s\n", (int)(start.rm_eo - start.rm_so),
                   pointer + start.rm_so);
            pointer += start.rm_eo;
          }
        }
        if (opt->c) {
          counter++;
        }
        if (!opt->c && !opt->o && !opt->l) {
          if (opt->n) {
            printf("%d:%s", index, opt->str_regexec);
            if (opt->str_regexec[strlen(opt->str_regexec) - 1] == '\n') {
            } else {
              printf("\n");
            }
          } else {
            opt->str_regexec[strlen(opt->str_regexec) - 1] == '\n'
                ? printf("%s", opt->str_regexec)
                : printf("%s\n", opt->str_regexec);
          }
        }
      }
      if ((argc - optind) > 1) {  // если больше одного файла на входе
        if (opt->o) {
          strcpy(opt->str_o, opt->str_regexec);
        }
        if (!match && opt->o) {
          char *pointer = opt->str_o;
          while ((regexec(&reg, pointer, 1, &start, 0) == 0)) {
            // найти кол-во повторений аргументов с помощью функции (своей);
            if (!opt->h) {
              printf("%s:%.*s\n", argv[ci], (int)(start.rm_eo - start.rm_so),
                     pointer + start.rm_so);
              pointer += start.rm_eo;
            } else {
              printf("%.*s\n", (int)(start.rm_eo - start.rm_so),
                     pointer + start.rm_so);
              pointer += start.rm_eo;
            }
          }
        }
        if (!match) {
          flag = 1;
        }
        if (!match && opt->c) {
          counter++;
        }
        if (!match && !opt->c && !opt->l && !opt->o) {
          if (!opt->h) {
            printf("%s:", argv[ci]);
          }
          if (!opt->c) {
            if (opt->n) {
              printf("%d:%s", index, opt->str_regexec);
              if (opt->str_regexec[strlen(opt->str_regexec) - 1] == '\n') {
              } else {
                printf("\n");
              }
            } else {
              opt->str_regexec[strlen(opt->str_regexec) - 1] == '\n'
                  ? printf("%s", opt->str_regexec)
                  : printf("%s\n", opt->str_regexec);
            }
          }
        }
      }
    }
    regfree(&reg);
    // if (opt->v && (argc - optind) == 1) {  // отработка переноса строки флага
    // v(когда файл 1)
    //   if(opt->str_regexec[strlen(opt->str_regexec) - 1] == '\n') {
    //   } else {
    //     printf("\n");
    //   }
    // }
    if (opt->c && (argc - optind) > 1) {
      printf("%s:%d\n", argv[ci], counter);
    }
    if (opt->f && (argc - optind) > 2) {
      printf("%s:", argv[ci]);
    }
    if (opt->c && (argc - optind) == 1) {
      printf("%d\n", counter);
    }
    if (opt->l && flag == 1) {
      printf("%s\n", argv[ci]);
    }
    // if (opt->c && !opt->l && opt->v) printf("%d\n", index - counter);
    fclose(file);
  } else {
    if (!opt->s) {
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[optind]);
    }
  }
}

void f_flag(FLAGS *opt) {
  FILE *f;
  f = fopen(opt->filename, "rb");
  if (f != NULL) {
    while (!feof(f)) {
      if (fgets(opt->str_regexec, 1000, f) != NULL) {
        if (opt->str_regexec[strlen(opt->str_regexec) - 1] == '\n' &&
            (strlen(opt->str_regexec) - 1) != 0)
          opt->str_regexec[strlen(opt->str_regexec) - 1] = '\0';
        strcat(opt->str, opt->str_regexec);
        strcat(opt->str, "|");
      }
    }
    fclose(f);
  }
}