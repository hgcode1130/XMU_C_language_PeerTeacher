#include <stdio.h>
#include <string.h>
// 4, 2020, 10, 5
int main() {
  FILE *fp;
  char c = 50, s[10];
  int d = 20, e, f;
  long len;
  fp = fopen("a.tmp", "w");
  fprintf(fp, "%c0%d.1.10", c, d);//'2'
  fclose(fp);
  fp = fopen("a.tmp", "r");
  fscanf(fp, "%d", &e); //2020
  len = ftell(fp);
  printf("%ld, ", len);
  fgets(s, 4, fp);
  fscanf(fp, "%d", &f);
  printf("%d, %d, ", e, f);
  fseek(fp, 0L, 2); //SEEK_CUR;SEEK_END;SEEK_SET;
  printf("%ld", ftell(fp) - len);
  fclose(fp);
}