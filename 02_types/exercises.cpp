#include <cstdio>

enum Operation{
  add,
  subtract,
  multiply,
  divide
};

struct Calculator{

  Calculator(Operation op){
    this->op = op;
  }

  int calculate(int a, int b){
    
    switch(op){
      case add:
        return a + b;
    case multiply:
      return a *b;
    case subtract:
      return a - b;
    case divide:
      if(b ==0) return 0;
      return a/b;
    default:
      return 0;
        
      }
  }
private:
  Operation op{add};
};

int main(){
  
   
  Calculator calc{subtract};
  int result = calc.calculate(10, 4);
  
  printf("result %d and long lon %d", sizeof(size_t), sizeof(long long));

}
