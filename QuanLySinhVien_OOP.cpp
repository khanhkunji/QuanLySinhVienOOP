/*
	QUAN LY SINH VIEN OOP
*/
#include<iostream>
#include<vector>
#include<string>
#include<fstream>// update neu ban muon dung file import

using namespace std;

class SinhVien {
private:
	string maSo;
	string ho, ten;
	string diaChi;
	int namSinh;
	string tenLop;
	double dtb;
public:
	SinhVien() {
		this->maSo = this->ho = this->ten = this->diaChi = this->tenLop = "";
		this->namSinh = 2002;
		this->dtb = 4.0;
	}

	//getter & setter
	void setHo(string h) {
		this->ho = h;
	}
	void setTen(string t) {
		this->ten = t;
	}
	void setNamSinh(int ns) {
		this->namSinh = ns;
	}
	void setDiaChi(string dc) {
		this->diaChi = dc;
	}
	void setTenLop(string tl) {
		this->tenLop = tl;
	}
	void setDtb(double d) {
		this->dtb = d;
	}
	string getHo() {
		return this->ho;
	}
	string getTen() {
		return this->ten;
	}
	string getMaSo() {
		return this->maSo;
	}
	int getNamSinh() {
		return this->namSinh;
	}
	string getDiaChi() {
		return this->diaChi;
	}
	double getDtb() {
		return this->dtb;
	}

	// Method 
	void nhapThongTin() {
		cout << "Nhap ma so :";
		getline(cin, this->maSo);
		cout << "Nhap ho :";
		getline(cin, this->ho);
		cout << "Nhap ten :";
		getline(cin, this->ten);
		cout << "Nhap nam sinh :";
		cin >> this->namSinh;
		cin.ignore();
		cout << "Nhap dia chi :";
		getline(cin, this->diaChi);
		cout << "Nhap ten lop :";
		getline(cin, this->tenLop);
		cout << "Nhap diem trung binh :";
		cin >> this->dtb;
		cin.ignore();
	}
	void xuatThongTin() {
		cout << "\n----THONG TIN SINH VIEN----"
			<< "\nMa sinh vien: " << this->maSo
			<< "\nHo va ten: " << this->ho.append(" " + this->ten) << "\nNam sinh: " << this->namSinh
			<< "\nDia chi noi o: " << this->diaChi << "\nTen lop: " << this->tenLop
			<< "\nDiem trung binh: " << this->dtb << endl;
	}
};

class QuanLySinhVien {
private:
	vector<SinhVien> dssv;
public:
	//setter & getter
	void setDssv(vector<SinhVien> ds) {
		this->dssv = ds;
	}
	vector<SinhVien> getDssv() {
		return this->dssv;
	}

	// Method
	void themSinhVien(SinhVien& sv) {
		this->dssv.push_back(sv);
	}
	void nhapDssv(int n) {
		for (int i = 0; i < n; i++) {
			cout << "\tNHAP THONG TIN SINH VIEN THU " << i + 1 << endl;
			SinhVien sv;
			sv.nhapThongTin();
			themSinhVien(sv);
		}
		
	}
	void inDssv() {
		cout << "\n\tDANH SACH SINH VIEN";
		for (int i = 0; i < this->getDssv().size(); i++) {
			dssv[i].xuatThongTin();
		}

	}
	void sapXepSinhVienTheoDiem() {
		//Sap xep tang dan
		for (int i = 0; i < this->getDssv().size(); i++) {
			for (int j = i + 1; j < this->getDssv().size(); j++) {
				if (dssv[i].getDtb() > dssv[j].getDtb()) {
					SinhVien sv = dssv[i];
					dssv[i] = dssv[j];
					dssv[j] = sv;
				}
			}
		}
	}
	int timKiemSinhVienTheoTen(string ten) {
		for (int i = 0; i < this->getDssv().size(); i++) {
			if (dssv[i].getTen() == ten) {
				return i;
			}
		}
		return -1;
	}
	int timKiemSinhVienTheoMaSo(string ms) {
		for (int i = 0; i < this->getDssv().size(); i++) {
			if (dssv[i].getMaSo() == ms) {
				return i;
			}
		}
		return -1;
	}
	void xoaSinhVienTheoTen(string ten) {
		int vi_tri = timKiemSinhVienTheoTen(ten);

		if (vi_tri != -1) {
			this->dssv.erase(dssv.begin() + (vi_tri));
			cout << "Xoa thanh cong!!!" << endl;
		}
		else {
			cout << "Khong co trong danh sach!!!";
		}
	}
	void xoaSinhVienTheoMaSo(string ms) {
		int vi_tri = timKiemSinhVienTheoMaSo(ms);

		if (vi_tri != -1) {
			this->dssv.erase(dssv.begin() + (vi_tri));
			cout << "Xoa thanh cong!!!" << endl;
		}
		else {
			cout << "Khong co trong danh sach!!!";
		}
	}

	//Một số chức năng cần update thêm
	/*
	- import bằng file
	- chuẩn hóa họ tên từng sinh viên ( viết hoa , xóa khoảng trắng thừa)
	- update form in thông tin clean hơn
	*/

};

//Global
//=================
int chon; 
bool act = false;
string t, ms;
QuanLySinhVien ds;
int sl;
//=================
static void menu() {
	cout << "\tQUAN LY SINH VIEN - OOP\n"
		<< "1.Khoi tao so luong sinh vien.\n"
		<< "2.In danh sach sinh vien.\n"
		<< "3.Sap xep sinh vien theo diem trung binh.\n"
		<< "4.Tim kiem sinh vien theo ten hoac ma so.\n"
		<< "5.Xoa sinh vien theo ten hoac ma so.\n"
		<< "6.Thoat chuong trinh.\n"
		<< "Chon thao tac:";
	cin >> chon;
	switch (chon) {
	case 1:
		cout << "Nhap so luong khoi tao (n > 2) :";
		cin >> sl;
		if (sl < 2) {
			cout << "Sai dau vao!!!Khoi tao lai." << endl;
		}
		else {
			cin.ignore();
			ds.nhapDssv(sl);
			act = true;
		}
		break;
	case 2:
		if (act) {
			ds.inDssv();
		}
		else {
			cout << "Chua khoi tao danh sach!!!" << endl;
		}
		break;
	case 3:
		if (act) {
			cout << "\tDANH SACH SAU KHI SAP XEP\n";
			ds.sapXepSinhVienTheoDiem();
		}
		else {
			cout << "Chua khoi tao danh sach!!!" << endl;
		}
		break;
	case 4:
		if (act) {
			cout << "1.Tim theo ten\n2.Tim theo ma so\n"
				<< "Chon :";
			cin >> chon;
			if (chon == 1) {
				cout << "Nhap ten can tim :";
				cin >> t;
				int kq1 = ds.timKiemSinhVienTheoTen(t);
				if (kq1 != -1) {
					cout << t<<" co trong danh sach!!!" << endl;
				}
				else {
					cout << t << " khong co trong danh sach!!!" << endl;
				}
			}else if (chon == 2) {
				cout << "Nhap ma so can tim :";
				cin >> ms;
				int kq2 = ds.timKiemSinhVienTheoMaSo(ms);
				if (kq2 != -1) {
					cout << ms << " co trong danh sach!!!" << endl;
				}
				else {
					cout << ms << " khong co trong danh sach!!!" << endl;
				}
			}
			else {
				cout << "Khong co thao tac nay!!!" << endl;
			}
		}
		else {
			cout << "Chua khoi tao danh sach!!!" << endl;
		}
		break;
	case 5:
		if (act) {
			cout << "1.Xoa theo ten\n2.Xoa theo ma so\n"
				<< "Chon :";
			cin >> chon;
			if (chon == 1) {
				cout << "Nhap ten can tim :";
				cin >> t;
				ds.xoaSinhVienTheoTen(t);
				
			}
			else if (chon == 2) {
				cout << "Nhap ma so can tim :";
				cin >> ms;
				ds.xoaSinhVienTheoMaSo(ms);
			}
			else {
				cout << "Khong co thao tac nay!!!" << endl;
			}
		}
		else {
			cout << "Chua khoi tao danh sach!!!" << endl;
		}
		break;
	default:
		cout << "\nHEN GAP LAI!!!" << endl;
		break;
	}
}

int main() {
	char c;
	do {
		system("cls");
		menu();
		cout << "\nBan co muon tiep tuc?\nNhan y de tiep tuc \nNhan n de thoat :";
		cin >> c;
	} while (c == 'y' || c == 'Y');
	return 0;
}


