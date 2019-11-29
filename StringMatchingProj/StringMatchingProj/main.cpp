#include "Board.h"

int main() {
	Board p(5, 5);

	p.printCol(1);
	char* r = p.getCol(1);

	cout << "\n";
	for (int i = 0; i < 5; ++i)
		cout << int(r[i]) << " ";
	system("pause");
}