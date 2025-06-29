#include <cstdio>

// 5-1 Design an interface called AccountDatabase
// that can retrieve and se tamounts in bank accounts
// identified by a long id
struct Account
{
  long id;
  float initial_amount;
};

struct AccountDatabase
{
  virtual void add_new_account(long id, float initial_amount)=0;
  virtual void add_money(long id, float amount) = 0;
  virtual void remove_money(long id, float amount) =0; 
}


int main()
{

}
