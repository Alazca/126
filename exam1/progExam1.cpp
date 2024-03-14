#include "box.h"
#include "imperialWeight.h"

using namespace std;

const int SIZE = 10;

int main() {
  imperialWeight b1(4, 12);
  imperialWeight b2(4, 13);
  imperialWeight books(25, 12);
  imperialWeight lTable(5, 4);
  imperialWeight rTable(10, 5);
  imperialWeight paintings(7, 1);
  string bString = "test";
  Box box1(bString, b1);
  Box room[SIZE] = { Box("Books", books), Box("Table Left", lTable),
                     Box("Table Right", rTable), Box("Paintings", paintings) };
  cout << box1.getName() << endl;
  cout << b1 << endl;
  cout << b2 << endl;
  cout << "Operator < check: " << (b2 < b1 ? "Yes" : "No") << endl;
  cout << "Operator <= check: " << (b2 <= b1 ? "Yes" : "No") << endl;
  cout << "Operator > check: " << (b2 > b1 ? "Yes" : "No") << endl;
  cout << "Operator >= check: " << (b2 >= b1 ? "Yes" : "No") << endl;
  imperialWeight b3 = b2 + b1;
  cout << b3;
  return 0;
}
