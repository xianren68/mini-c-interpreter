
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <fcntl.h>

const int POOL_SIZE = 256 * 1024;
int token; // 当前token
int line; // 行数
char *src, *old_src; // src指向每次读取字符后的位置，old_src指向初始位置

void next(){
  token = *src++; // -> token = *src; src++;
  return;
}

void expression(){
  // todo
}

void program() {
  next();
  while(token > 0){
    printf("token is %c\n",token);
    next();
  }
}

int eval() {
  // todo
  return 0;
}

int main(int argc, char** argv) {
  int i;
  FILE* fd;
  argc--;
  argv++;
  line = 1;

  // 打开源代码文件
  if(fopen_s(&fd,*argv,"r") != 0){
      printf("could not open(%s)\n",*argv);
      return -1;
  }

  // 开辟内存空间，用于存储源代码
  if((src = old_src = malloc(POOL_SIZE ))) {
    printf("could not malloc(%d) for source area\n",POOL_SIZE);
    return -1;
  }

  // 读取源代码
  if((i = fread(src,1,POOL_SIZE-1,fd)) <= 0) {
    printf("read() returned %d\n",i);
    return -1;
  }

  src[i] = 0; // 添加终止符号
  fclose(fd); // 关闭源代码文件

  program(); // 分析代码

  return eval(); // 执行代码
}
