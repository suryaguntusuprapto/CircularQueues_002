#include <iostream>
using namespace std;

class Queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];

public:
	Queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter a number: ";
		cin >> num;
		cout << endl;

		//cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue overflow\n";
			return;
		}

		//cek apakah antrian kosong
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			//jika REAR berada di posisi terakhir array, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_array[REAR] = num;
	}

	void remove(){
		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queque undeflow\n";
			return;
		}
		cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

		//cek jika antrian hanya memiliki satu elemen
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			//jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}

	void display() {
		int FRONT_posisition = FRONT;
		int REAR_posisition = REAR;

		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue is empty\n";
			return;
		}

		cout << "\nElement in the queue are: \n";

		//jika FRONT_posisition <= REAR_posisition, iterasi dari FRONT hingga REAR
		if(FRONT_posisition <= REAR_posisition){
			while (FRONT_posisition <= REAR_posisition) {
				cout << queue_array[FRONT_posisition] << "   ";
				FRONT_posisition++;
			}
			cout << endl;
		}
		else {
			//jika FRONT_posisition > REAR_posisition, iterasi dari FRONT hingga akhir array
			while (FRONT_posisition <= max - 1) {
				cout << queue_array[FRONT_posisition] << "   ";
				FRONT_posisition++;
			}

			FRONT_posisition = 0;

			//Iterasi dari awal array hingga REAR
			while (FRONT_posisition <= REAR_posisition) {
				cout << queue_array[FRONT_posisition] << "   ";
				FRONT_posisition++;
			}
			cout << endl;
		}
	}
};

int main() {
	Queues q;
	char ch;

	while (true) {
		try {
			cout << "Menu" << endl;
			cout << "1. Implement Insert operation" << endl;
			cout << "2. Implement Delete operation" << endl; 
			cout << "3. Display value" << endl;
			cout << "4. Exit" << endl;
			cout << "Enter your choice (1-4): ";
			cin >> ch;
			cout << endl;

			switch (ch) {
			case '1': {
				q.insert();
				break;
			}
			case '2': {
				q.remove();
				break;
			}
			case '3': {
				q.display();
				break;
			}
			case '4': {
				return 0;

			}
			default: {
				cout << "Pilihan Tidak Ada dalam menu" << endl;
				break;
			}
			} 
		}
		catch (exception& e) {
			cout << "check for the values entered" << endl;
		}
	}
	return 0;
}