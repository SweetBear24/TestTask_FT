#include <iostream>
using namespace std;

int main() {
    int entrance;
	int floors;
	int apartment;
    int apartments = 4;
    int number_apartments = 1;
    int count_entrance = 1;

    cout << "Enter number of entrance: ";
    cin >> entrance;
    cout << "Enter number of floors: ";
    cin >> floors;
    cout << "Enter number of apartment: ";
    cin >> apartment;
    cout << endl;
	    
    int house[floors][apartments] = {0};
	bool apartmentFound = false;
	while(count_entrance <= entrance){
	    
		cout << "Entrance - " << count_entrance;
	    cout << endl;
	    
		// Заполнение дома квартирами
	    for (int i = 0; i < floors; i++) {
	        for (int j = 0; j < apartments; j++) {
	            house[i][j] = number_apartments++;
	            cout << house[i][j] << " ";
	            if(house[i][j] == apartment){
	            	apartmentFound = true;
	            }
	        }
	        cout << endl;
	    } 
		cout << endl;
	    count_entrance++;
	}

    if (apartmentFound) {
	    // Общее количество квартир в подъезде
	    int totalApartmentsPerEntrance = floors * apartments;
	    // Определение подъезда
	    entrance = ((apartment - 1) / totalApartmentsPerEntrance) + 1;
	    // Номер квартиры в пределах подъезда
	    int apartmentNumberInEntrance = apartment - (entrance - 1) * totalApartmentsPerEntrance;
	    // Определение этажа
	    int floor = ((apartmentNumberInEntrance - 1) / apartments) + 1;
	    // Вывод результата
	    cout << "Entrance: " << entrance << endl;
	    cout << "Floor: " << floor << endl; 
	    
		int apartmentNumber = (apartment - 1) % apartments + 1;
		
		switch (apartmentNumber) {
        case 1:
            cout << "Closest to the left" << endl;
            break;
        case 2:
            cout << "Far left" << endl;
            break;
        case 3:
            cout << "Closest to the right" << endl;
            break;
        case 4:
            cout << "Far right" << endl;
            break;
    	}	
    }else{
	    cout << "Apartment " << apartment << " not found in the house." << endl;
    }
	return 0;
}