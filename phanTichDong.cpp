#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  std::string input = "1,gao,kg,50.5";
  std::stringstream ss(input);
 
  std::string m,t,d,s;
 
  std::getline(ss, m, ',');//lay so 1 dua vao m
  std::getline(ss, t, ',');//tiep theo lay gao dua vao t, cu nhu vay
  std::getline(ss, d, ',');
  std::getline(ss, s, ',');
  
  cout<<stoi(m)+1<<endl;
  cout<<t<<endl;
  cout<<d<<endl;
  cout<<stod(s)+1<<endl;
  return 0;
}

