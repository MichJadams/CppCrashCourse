#include <cstdio>
#include <concepts>
//6-6 Implement an Account class and instantiate a Bank<Account>.
// Implement functions to Account to keep track of balances!


struct Account
{
  Account(float amount): amount{amount}{}
  void add_money(float amount_in)
  {
    amount += amount_in;

  }
  float get_balance()
  {
    return amount;
  }
  bool remove_money(float amount_out)
  {
    if(amount - amount_out <= 0)
      {
	return false;
      }
    else
      {
	amount -= amount_out;
	return true;
      }
  }
  
private:
  long id;
  float amount =0;
};
  
struct Bank
{
  template<typename T, typename I>
  void move_money(T* source, I* target, float amount)
  {
    if(source->remove_money(amount))
      {
	target->add_money(amount);
      }
  }
};

int main()
{
  Account a{100};
  Account b{ 50};
  printf("starting balances a:%f b:%f \n", a.get_balance(), b.get_balance());
  Bank bank;
  bank.move_money<Account, Account>(&a, &b, 50);
  printf("ending balances a:%f b:%f \n", a.get_balance(), b.get_balance()); 
}
