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
  virtual void print_balances() =0;
};

struct InMemoryAccountDatabase : AccountDatabase
{
  InMemoryAccountDatabase(size_t max_size): max_size{max_size}
  {
    accounts = new Account*[max_size];
    length = 0; 

  }

  
  void add_new_account(long id, float initial_amount)
  {
    if(sizeof(accounts) < max_size)
      {
	accounts[length++] = new Account{id, initial_amount};
      }
    
  }

  void add_money(long id, float amount)
  {
    for(int i{}; i < length; i ++)
      {
	if(accounts[i]->id == id)
	  {
	    accounts[i]->initial_amount += amount;
          }
      }
  }

  void remove_money(long id, float amount)
  {
    for(int i{}; i < length; i ++)
      {
	if(accounts[i]->id == id)
	  {
	    accounts[i]->initial_amount -= amount;
          }
      }
  }

  void print_balances()
  {
    for(int i = 0; i< length; i ++)
      {
	Account* acc = accounts[i];
	printf("Account Id %ld: Account Balance: %f\n", acc->id, acc->initial_amount);
      }
  }
  
private:
  size_t max_size;
  size_t length;
  Account** accounts; // do not understand double **
};

struct Bank
{
  Bank(AccountDatabase& database): database{database}{};
  void new_customer(float amount)
  {
    // I kinda forget why this is a dot operator
    // and not an arrow operator ... because database is a reference? not a pointer?
    
    database.add_new_account(100, amount);
  }
  void are_we_rich()
  {
    database.print_balances();
  }
private:
  AccountDatabase& database; 
};

int main()
{
  InMemoryAccountDatabase base{10};
  Bank bank{base};
  bank.new_customer(100000);
  bank.are_we_rich(); 
}
