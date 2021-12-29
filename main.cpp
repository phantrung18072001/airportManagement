#include <iostream>
#include <vector>
#include <fstream>
#include "Plane.h"
#include "Helicopter.h"
#include "Airport.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(Airport ap);
void updateAirport(Airport &ap);
void inforAirport(Airport ap);
void menuPlane(Airport &ap);
void addPlane(Airport &ap);
void updatePlane(Airport &ap);
void deletePlane(Airport &ap);
void infoPlane(Airport &ap);
void menuHelicopter(Airport &ap);
void addHelicopter(Airport &ap);
void updateHelicopter(Airport &ap);
void deleteHelicopter(Airport &ap);
void infoHelicopter(Airport &ap);
void ghiFile(Airport ap);


void infoHelicopter(Airport &ap) {
	string MTT;
	cout << "THONG TIN TRUC THANG\n";
	cout << "Nhap ma truc thang: ";
	cin >> MTT;
	for(int i =0; i < ap.helicopters.size(); i++) {
		if(ap.helicopters[i].MTT == MTT) {
			cout << "=====================";
			cout << "Ma truc thang: " << ap.helicopters[i].MTT << endl;
			cout << "Chieu dai: " <<ap.helicopters[i].length << endl;
			cout << "Chieu rong: "<<ap.helicopters[i].width << endl;
			cout << "Khoi luong: "<<ap.helicopters[i].weight << endl;
			cout << "Tai trong: " << ap.helicopters[i].mass << endl;
		}
	}
}

void deleteHelicopter(Airport &ap){
	string MTT;
	cout << "XOA TRUC THANG\n";
	cout << "Nhap ma truc thang: ";
	cin >> MTT;
	for(int i =0; i < ap.helicopters.size(); i++) {
		if(ap.helicopters[i].MTT == MTT) {
			ap.sumMass -= ap.helicopters[i].mass;
			ap.helicopters.erase(ap.helicopters.begin()+i);
		}
	}
}

void updateHelicopter(Airport &ap){
	string MTT;
	float length, width, weight, mass = -1;
	cout << "CAP NHAT TRUC THANG\n";
	cout << "Nhap ma truc thang: ";
	cin >> MTT;
	for(int i = 0; i < ap.helicopters.size(); i++) {
		if(ap.helicopters[i].MTT == MTT) {
			cout << "======================\n";
			cout << "Nhap ma truc thang moi: ";
			cin >> MTT;
			cout << "Nhap chieu dai: ";
			cin >> length;
			cout << "Nhap chieu rong: ";
			cin >> width;
			cout << "Nhap khoi luong may bay: ";
			cin >> weight;
			do {
				if (ap.sumMass + mass > ap.mass) {
					cout << "Tai trong cua truc thang phai nho hon(" << ap.mass - ap.sumMass << ")\n";
				}
				cout << "Nhap tai trong: ";
				cin >> mass;
			} while (ap.sumMass + mass > ap.mass);
			ap.sumMass -= ap.helicopters[i].mass + mass;
			ap.helicopters[i].updateHelicopter(MTT,length,width,weight,mass);
			return;
		}
	}
	cout << "Khong tim thay truc thang";
}

void addHelicopter(Airport &ap) {
	string MTT;
	float length, width, weight, mass = -1;
	cout << "THEM TRUC THANG\n";
	cout << "Nhap ma truc thang: ";
	cin >> MTT;
	cout << "Nhap chieu dai: ";
	cin >> length;
	cout << "Nhap chieu rong: ";
	cin >> length;
	cout << "Nhap khoi luong: ";
	cin >> weight;
	do {
		if (ap.sumMass + mass > ap.mass) {
			cout << "Tai trong cua truc thang phai nho hon(" << ap.mass - ap.sumMass << ")\n";
		}
		cout << "Nhap tai trong: ";
		cin >> mass;
	} while (ap.sumMass + mass > ap.mass);
	Helicopter h = Helicopter(MTT, length, width, weight, mass);
	ap.sumMass += mass;
	ap.addHelicopter(h);
}


void menuHelicopter(Airport &ap) {
	system("CLS");
	int key;
	cout << "Danh muc truc thang.\n";
	cout << "**  1. Them truc thang\n";
    cout << "**  2. Cap nhat truc thang\n";
    cout << "**  3. Xoa truc thang\n";
    cout << "**  4. Thong tin truc thang\n";
    cout << "**  0. Tro lai\n";
    cin >> key;
    switch(key){
        case 1:
        	if(ap.spaceOfHelicopter > ap.helicopters.size()) {
        		addHelicopter(ap);
			}
			else {
				system("CLS");
				cout << "San bay da het cho dau truc thang!";
			}
            break;
        case 2:
        	updateHelicopter(ap);
        	break;
        case 3:
        	deleteHelicopter(ap);
        	break;
        case 4:
        	infoHelicopter(ap);
        	break;
        case 0:
        	menu(ap);
        	break;
        default:
        	return;
        cout << "Nhan 0 de tro lai!!!";
		int key;
		cin>> key;
		if (key == 0) {
			menuHelicopter(ap);
		}
	}
}
// ---------------------


void infoPlane(Airport &ap) {
	string MMB;
	cout << "THONG TIN MAY BAY\n";
	cout << "Nhap ma may bay: ";
	cin >> MMB;
	for(int i =0; i < ap.planes.size(); i++) {
		if(ap.planes[i].MMB == MMB) {
			cout << "=====================\n";
			cout << "Ma may bay: " << ap.planes[i].MMB << endl;
			cout << "Suc chua: "<<ap.planes[i].capacity << endl;
			cout << "Chieu dai: " <<ap.planes[i].length << endl;
			cout << "Chieu rong: "<<ap.planes[i].width << endl;
			cout << "Khoi luong: "<<ap.planes[i].weight << endl;
			cout << "Chieu dai duong bang toi thieu: " << ap.planes[i].minLanding <<endl;
		}
	}
}

void deletePlane(Airport &ap){
	string MMB;
	cout << "XOA MAY BAY\n";
	cout << "Nhap ma may bay: ";
	cin >> MMB;
	for(int i =0; i < ap.planes.size(); i++) {
		if(ap.planes[i].MMB == MMB) {
			ap.planes.erase(ap.planes.begin()+i);
		}
	}
}

void updatePlane(Airport &ap){
	string MMB;
	int capacity;
	float length, width, weight, minLanding = -1;
	cout << "CAP NHAT MAY BAY\n";
	cout << "Nhap ma may bay: ";
	cin >> MMB;
	for(int i = 0; i < ap.planes.size(); i++) {
		if(ap.planes[i].MMB == MMB) {
			cout << "======================";
			cout << "Nhap ma may bay moi: ";
			cin >> MMB;
			cout << "Nhap suc chua: ";
			cin >> capacity;
			cout << "Nhap chieu dai may bay: ";
			cin >> length;
			cout << "Nhap chieu rong may bay: ";
			cin >> width;
			cout << "Nhap khoi luong may bay: ";
			cin >> weight;
			do {
				if (minLanding > ap.runwayLength) {
					cout << "Chieu dai toi thieu phai be hon chieu dai duong bang san bay(" << ap.runwayLength << ")\n";
				}
				cout << "Nhap khoang cach duong bang toi thieu: ";
				cin >> minLanding;
			} while (minLanding > ap.runwayLength);
			ap.planes[i].updatePlane(MMB,capacity,length,width,weight,minLanding);
			return;
		}
	}
	cout << "Khong tim thay may bay";
}

void addPlane(Airport &ap) {
	string MMB;
	int capacity;
	float length, width, weight, minLanding = -1;
	cout << "THEM MAY BAY\n";
	cout << "Nhap ma may bay: ";
	cin >> MMB;
	cout << "Nhap suc chua: ";
	cin >> capacity;
	cout << "Nhap chieu dai may bay: ";
	cin >> length;
	cout << "Nhap chieu rong may bay: ";
	cin >> width;
	cout << "Nhap khoi luong may bay: ";
	cin >> weight;
	do {
		if (minLanding < ap.runwayLength) {
			cout << "Chieu dai toi thieu phai be hon chieu dai duong bang san bay(" << ap.runwayLength << ")\n";
		}
		cout << "Nhap khoang cach duong bang toi thieu: ";
		cin >> minLanding;
	} while (minLanding > ap.runwayLength);
	Plane p = Plane(MMB, capacity, length, width, weight, minLanding);
	ap.addPlane(p);
}


void menuPlane(Airport &ap) {
	system("CLS");
	int key;
	int back;
	cout << "Danh muc san bay.\n";
	cout << "**  1. Them may bay\n";
    cout << "**  2. Cap nhat may bay\n";
    cout << "**  3. Xoa may bay\n";
    cout << "**  4. Thong tin may bay\n";
    cout << "**  0. Tro lai\n";
    cin >> key;
    switch(key){
        case 1:
        	if(ap.spaceOfPlane > ap.planes.size()) {
        		addPlane(ap);
			}
			else {
				system("CLS");
				cout << "San bay da het cho dau may bay!";
			}
			cout << "Nhan 0 de tro lai!!!";
			cin>> back;
			if (back == 0) {
				menuPlane(ap);
			}
            break;
        case 2:
        	updatePlane(ap);
        	cin>> back;
			if (back == 0) {
				menuPlane(ap);
			}
            break;
        case 3:
        	deletePlane(ap);
        	cin>> back;
			if (back == 0) {
				menuPlane(ap);
			}
            break;
        case 4:
        	infoPlane(ap);
        	cin>> back;
			if (back == 0) {
				menuPlane(ap);
			}
            break;
        case 0: 
        	menu(ap);
        	break;
        default:
        	return;
	}
}


void updateAirport(Airport &ap) {
	string MSB;
	float mass;
	float runwayLength;
	int spaceOfPlane;
	int spaceOfHelicopter;
	cout << "CAP NHAT SAN BAY\n";
	cout << "Nhap ma san bay: ";
	cin >> MSB;
	cout << "Nhap khoi luong chiu tai: ";
	cin >> mass;
	cout << "Nhap chieu dai duong bang: ";
	cin >> runwayLength;
	cout << "Nhap so cho dau may bay: ";
	cin >> spaceOfPlane;
	cout << "Nhap so cho dau truc thang: ";
	cin >> spaceOfHelicopter;
	ap.updateAirport(MSB,mass,runwayLength,spaceOfPlane,spaceOfHelicopter);
	menu(ap);
}

void infoAirport(Airport ap) {
	system("CLS");
	cout << "THONG TIN SAN BAY"<<endl;
	cout << "Ma san bay: " << ap.MSB << endl;
	cout << "Khoi luong chiu tai: "<<ap.mass << endl;
	cout << "Chieu dai duong bang: " <<ap.runwayLength << endl;
	cout << "So cho dau may bay: "<<ap.spaceOfPlane << endl;
	cout << "So cho dau truc thang: "<<ap.spaceOfHelicopter << endl;
	cout << "So luong may bay trong san bay: " << ap.planes.size() <<endl;
	cout << "Nhan 0 de tro lai!!!";
	int key;
	cin>> key;
	if (key == 0) {
		menu(ap);
	}
}

void menu(Airport ap) {
	system("CLS");
	int key;
	cout << "QUAN LY SAN BAY\n";
    cout << "**  1. Danh muc may bay\n";
    cout << "**  2. Danh muc truc than\n";
    cout << "**  3. Sua thong tin san bay\n"; // Chua xu ly xoa neu trong tai va duong bang thay doi
    cout << "**  4. Thong tin san bay\n"; 
    cout << "**  5. Ghi danh sach vao file.\n";
    cout << "**  0. Thoat\n";
    cout << "*******************************************************\n";
    cout << "Nhap tuy chon: ";
    cin >> key;
	switch(key){
        case 1:
            menuPlane(ap);
            break;
        case 2:
        	menuHelicopter(ap);
        	break; 
        case 3:
        	updateAirport(ap);
        	break;
        case 4:
        	infoAirport(ap);
        	break;
        case 5:
        	ghiFile(ap);
        default:
        	return;
	}
}

Airport airport() {
	string MSB;
	float mass;
	float runwayLength;
	int spaceOfPlane;
	int spaceOfHelicopter;
	cout << "Khoi tao san bay\n";
	cout << "Nhap ma san bay: ";
	cin >> MSB;
	cout << "Nhap khoi luong chiu tai: ";
	cin >> mass;
	cout << "Nhap chieu dai duong bang: ";
	cin >> runwayLength;
	cout << "Nhap so cho dau may bay: ";
	cin >> spaceOfPlane;
	cout << "Nhap so cho dau truc thang: ";
	cin >> spaceOfHelicopter;
	Airport ap = Airport(MSB,mass,runwayLength,spaceOfPlane,spaceOfHelicopter);
	return ap;
}

void ghiFile(Airport ap) {
    ofstream outfile; 
    outfile.open("save.txt",ios::out);
    outfile << "MA SAN BAY: " << ap.MSB << endl;
    outfile << "Chieu dai san bay: " << ap.runwayLength << endl;
    outfile << "Khoi luong chiu tai: " << ap.mass << endl;
    outfile << "So luong dau may bay: " << ap.spaceOfPlane << endl;
    outfile << "So luong dau truc thang: " << ap.spaceOfHelicopter << endl;
    outfile << "- May bay trong san bay" << endl;
    for(int i = 0; i < ap.planes.size(); i++) {
    	outfile << "May bay " << i+1 << endl;
    	outfile << "Ma may bay" << ap.planes[i].MMB;
	}
	outfile << "- Truc thang trong san bay" << endl;
	for(int i = 0; i < ap.helicopters.size(); i++) {
		outfile << "Truc thang " << i+1 << endl;
    	outfile << "Ma truc thang" << ap.planes[i].MTT;
	}
    outfile.close();
}

int main(int argc, char** argv) {
	Airport ap = airport();
	menu(ap);
	return 0;
}
