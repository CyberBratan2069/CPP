# 1 "main_10.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 366 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "main_10.c" 2





int line(int x){
  return x * 7 + -3;
}

int main(){
  int y = 0;
  int x = 0;
  while (x<20){
    y = line(x);

    x++;
  }
  return 0;
}
