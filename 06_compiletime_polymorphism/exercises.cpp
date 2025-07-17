#include <cstdio>
#include <concepts>
//6-6 Implement an Account class and instantiate a Bank<Account>.
// Implement functions to Account to keep track of balances!


struct Account
{
  Account(float amount_in): amount{amount_in}{}
  
  virtual void add_money(float amount_in)
  {
    amount += amount_in;
  }
  
  virtual void print_balance() = 0;
  
  virtual bool remove_money(float amount_out)
  {
    if(amount - amount_out < 0)
      {
	return false;
      }
    else
      {
	amount -= amount_out;
	return true;
      }
  }
  long id;
  float amount =0;
};

struct SavingsAccount : Account
{
  SavingsAccount(float amount_in): Account{amount_in}{}
  void print_balance()  override
  {
    printf(" from the savings account! %f\n", amount);
  }

};

struct CheckingAccount : Account
{
  CheckingAccount(float amount_in): Account{amount_in}{}
  void print_balance()  override
  {
    printf("from the checking accounts!! %f \n", amount);
  }

};

struct Bank
{
  void move_money(Account* source, Account* target, float amount)
  {
    if(source->remove_money(amount))
      {
	target->add_money(amount);
      }
  }
};

int main()
{
  CheckingAccount a{100};
  SavingsAccount b{ 50};
  a.print_balance();
  b.print_balance();
  
    
  Bank bank;
  bank.move_money(&a, &b, 50);
  printf("ending balances \n");
  a.print_balance();
  b.print_balance();
}
