#include<iostream>
#include<vector>
#include<string>
using namespace std;

class CDocGia {
protected:	
			string name;
			string ngaylapthe;
			int sothanghieuluc;
			bool ktra;
public:     
            CDocGia();
            CDocGia(string a, string b, int c);
            CDocGia(const string &a, const int &b);
            ~CDocGia();
			virtual void input();
			virtual void output();
            virtual int Tinh_Tien_Lam_The() = 0;
            void set_KT(bool kt);
            bool get_KT();
            string get_name();
};
class CDocGiaTreEm : public CDocGia {
	private:
		string representative;
	public:
        CDocGiaTreEm();
        CDocGiaTreEm(string a);
        CDocGiaTreEm(const string &a);
        ~CDocGiaTreEm();
		void input();
		void output();
		int Tinh_Tien_Lam_The();		
};
class CDocGiaNguoiLon : public CDocGia {
	private:
		string CMND;
	public:
        CDocGiaNguoiLon();
        CDocGiaNguoiLon(string a);
        CDocGiaNguoiLon(const string &a);
        ~CDocGiaNguoiLon();
		void input();
		void output();
		int Tinh_Tien_Lam_The();		
};
 class CThuVien {
    private:
        vector<CDocGia *> list_CDocGia;
 	public:
 		void input();
 		void output();
 		int Tinh_Tong_tien_Lam_The();
        void TimKiem();
        void SapXep();
        void Xoa();		
 };
CDocGia::CDocGia(){
     name = "ten chua xac dinh";
    ngaylapthe = "0";
    sothanghieuluc = 0;
 }
 CDocGia::CDocGia(string a, string b, int c){
     name = "a";
     ngaylapthe = "b";
     sothanghieuluc = c;
 }
 CDocGia::CDocGia(const string &a, const int &b){
     name = ngaylapthe = "a";
     sothanghieuluc = b;
 }
 CDocGia::~CDocGia(){}
 CDocGiaTreEm::CDocGiaTreEm(){
     representative = "ko xac dinh";
 } 
 CDocGiaTreEm::CDocGiaTreEm(string a){
     representative = "a";
 }  
 CDocGiaTreEm::CDocGiaTreEm(const string &a){
     representative = "a";
 }   
 CDocGiaTreEm::~CDocGiaTreEm(){}
 CDocGiaNguoiLon::CDocGiaNguoiLon(){
     CMND = "ko xac dinh";
 }
  CDocGiaNguoiLon::CDocGiaNguoiLon(string a){
     CMND = " a";
 }
  CDocGiaNguoiLon::CDocGiaNguoiLon(const string &a){
     CMND = "a";
 }
  CDocGiaNguoiLon::~CDocGiaNguoiLon(){
     
 }
string CDocGia::get_name(){
    return name;
}
 void CThuVien::TimKiem(){
     string m;
     cout<<"Nhap Ten cua doc gia can tim: ";
     cin.ignore();
     getline(cin,m);
     for(int i=0; i< list_CDocGia.size();i++){
         if(list_CDocGia[i]->get_name()==m){
             list_CDocGia[i]->output();
         }
     }
 }
 void CThuVien::SapXep(){
     for(int i=0; i< list_CDocGia.size();i++){
         for(int j=i+1; j< list_CDocGia.size();j++){
         if(list_CDocGia[i]->get_name() > list_CDocGia[j]->get_name()){
             CDocGia *m = list_CDocGia[i];
             list_CDocGia[i] = list_CDocGia[j];
             list_CDocGia[j] = m;
         }}
     }
 }
  void CThuVien::Xoa(){
     string m;
     cout<<"\nNhap Ten cua doc gia can xoa : ";
     cin.ignore();
     getline(cin,m);
     for(int i=0; i< list_CDocGia.size();i++){
         if(m==list_CDocGia[i]->get_name()){
             list_CDocGia.erase(list_CDocGia.begin()+i);
         }
     }
 }
 void CDocGia::input(){
 	cout<<"Nhap name: ";
 	getline(cin,name);
 	cout<<"Nhap ngaylapthe: ";
 	getline(cin,ngaylapthe);
 	cout<<"Nhap so thang hieu luc: ";
 	cin>>sothanghieuluc;
 	cin.ignore();
	  }
void CDocGia::output(){
	cout<<"name:"<< name << " ngaylapthe:"<< ngaylapthe << "  sothanghieuluc:"<<sothanghieuluc;
}
void CDocGiaTreEm::input(){
	cout<<"\n";
    cin.ignore();
	CDocGia::input();
	cout<<"Nhap representative: ";
	getline(cin,representative);
}
void CDocGiaTreEm::output(){
	CDocGia::output();
	cout<<" Representative: "<<representative;	
}
void CDocGiaNguoiLon::input(){
	cout<<endl;
    cin.ignore();
	CDocGia::input();
	cout<<"Nhap CMND: ";
	cin>>CMND;
	
}
void CDocGiaNguoiLon::output(){
	cout<<endl;
	CDocGia::output();
	cout<<" CMND:"<<CMND;
}
int CDocGiaTreEm::Tinh_Tien_Lam_The(){
	return sothanghieuluc*5000;
}
int CDocGiaNguoiLon::Tinh_Tien_Lam_The( ){

	return sothanghieuluc*10000;
}
void CDocGia::set_KT(bool kt){
	ktra = kt;
}
bool CDocGia::get_KT(){
	return ktra;
}
void CThuVien::input(){
    while(true){
        system("cls"); 
        cout<<"\n\n\t\t ========THU VIEN========";
        cout<<"\n\t 1.Doc gia tre em";
        cout<<"\n\t 2.Doc gia nguoi lon";
        cout<<"\n\t 3.Thoat ";
        cout<<"\n\n\t\t ========  END   ========";
        int luachon;   
        cout<<"\n\n Nhap su lua chon cua ban: ";
        cin>>luachon;
        CDocGia *x;
        if(luachon==1){
            x = new CDocGiaTreEm;
            cout<<"Enter information of reader:  "<<endl;
            x->set_KT(true);
            x->input();
            list_CDocGia.push_back(x);     
        }
        else if(luachon == 2){
           x = new CDocGiaNguoiLon;
            cout<<"Enter information of reader:  "<<endl;
            x->set_KT(false);
            x->input();
           list_CDocGia.push_back(x);
        }
        else if(luachon == 3){
            break;
        }
        else {
            cout<<"lua chon ko hop le! Xin vui long chon lai:(-_-) "<<endl;
            system("pause");        
        }
    }
}
void CThuVien::output(){
    int i=1;
    int n;
    while (i)
    {	system("cls"); 
        cout<<"\n\n\t\t\t==============Danh Sach=============="<<endl;
        cout<<"\t\t1. Xuat Danh Sach Tat Ca Doc Gia Tre EM."<<endl;
        cout<<"\t\t2. Xuat Danh Sach Tat Ca Doc Gia Nguoi Lon."<<endl;
        cout<<"\t\t3. Xuat Danh Sach Tat Ca Doc Gia."<<endl;
        cout<<"\t\t4. Thoat. "<<endl;
        cout<<"\t\t\t==============~End~=============="<<endl;
        cout<<"\n Nhap Lua Chon: ";
        cin>>n;
        switch (n)
        {
        case 1:
           {int dem1 = 0;
            cout<<"\n List Reader Childs:"<<endl;
            for(int i=0; i< list_CDocGia.size(); i++) 
            {   if(list_CDocGia[i]->get_KT()==true){
    	            dem1++;
    	            cout<<"\n Reader childs thu "<<dem1<<endl;
                    list_CDocGia[i]->output(); }
             }
             	system("pause");
                break;
           }
        case 2:
        {   int dem2=0;
            cout<<"\n List Reader Adults:"<<endl;
            for(int i=0; i< list_CDocGia.size(); i++) 
        {   if(list_CDocGia[i]->get_KT()==false){
    	        dem2++;
                cout<<"\nReader Adults thu "<<dem2<<endl;
                list_CDocGia[i]->output();
		    }
        } 	system("pause");
            break;
        }
        case 3:{
            cout<<"\n\n List Readers : "<<endl;
            for(int i=0; i< list_CDocGia.size(); i++) 
        {    
                 cout<<"\n  Reader  thu "<<i+1<<endl;    
                 list_CDocGia[i]->output();
        }	system("pause");
            break;
        }
        case 4:{
            i=0;
            break;
        }
        default:
            cout<<"Lua chon khong phu hop. Xin vui long nhap lai!!!"<<endl;
            system("pause");
            break;
        }
    }  
}
int CThuVien::Tinh_Tong_tien_Lam_The(){
    int i=1;
    int m;
    while (i)
    {	system("cls"); 
        cout<<"\n\n\t\t\t==============Danh Sach=============="<<endl;
        cout<<"\t\t1. Tinh Tong Tien Lam The Cua Tat Ca Doc Gia Tre EM."<<endl;
        cout<<"\t\t2. Tinh Tong Tien Lam The Cua Tat Ca Doc Gia Gia Nguoi Lon."<<endl;
        cout<<"\t\t3. Tinh Tong Tien Lam The Cua Tat Ca Doc Gia."<<endl;
        cout<<"\t\t4. Thoat. "<<endl;
        cout<<"\t\t\t==============~End~=============="<<endl;
        cout<<"\n Nhap Lua Chon: ";
        cin>>m;
        switch (m)
        {
        case 1:
        {   int sum1=0;
            for(int i=0; i< list_CDocGia.size(); i++) 
            {   if(list_CDocGia[i]->get_KT()==true){
    	            sum1+= list_CDocGia[i]->Tinh_Tien_Lam_The();
                 }
             }
            cout<<"Tong Tien Lam The Cua Tat Ca Doc Gia Tre EM: "<<sum1<<endl;
            system("pause");
            break;
           }
        case 2:
        {   int sum2=0;
            for(int i=0; i< list_CDocGia.size(); i++) 
        {   if(list_CDocGia[i]->get_KT()==false){
                sum2+= list_CDocGia[i]->Tinh_Tien_Lam_The();
		    }
        }   cout<<"Tong Tien Lam The Cua Tat Ca Doc Gia Nguoi Lon: "<<sum2<<endl;
        	system("pause");
            break;
        }
        case 3:
		{   int sum=0;
            for(int i=0; i< list_CDocGia.size(); i++) 
        {    
                sum+= list_CDocGia[i]->Tinh_Tien_Lam_The();   
        }   cout<<"Tong Tien Lam The Cua Tat Ca Doc: "<<sum<<endl;
        	system("pause");
            break;         
        }
        case 4:{
            i=0;
            break;
        }
        default:
            cout<<"Lua chon khong phu hop. Xin vui long nhap lai!!!"<<endl;
            system("pause");
            break;
        }
    }
}
void Menu(){
    int choose;
    CThuVien *library = new CThuVien;
    while(true){
    	system("cls"); 
        cout<<"\n\n================Menu================"<<endl;
        cout<<"1. Nhap danh sach doc gia."<<endl;
        cout<<"2. Xuat danh sach doc gia. "<<endl;
        cout<<"3. Tong tien lam the. "<<endl;
        cout<<"4. Sap xep danh sach theo ten."<<endl;
        cout<<"5. Tim kiem mot doc gia theo ten."<<endl;
        cout<<"6. Xoa mot doc gia theo ten"<<endl;
        cout<<"7. Thoat."<<endl;
        cout<<"================End================"<<endl;
        cout<<"\nLua chon cua ban la: ";
        cin>>choose;
        
        switch (choose)
        {
        case 1:
            library->input();
            break;
        case 2:
            library->output();
            system("pause");
            break;
        case 3:
            cout<<library->Tinh_Tong_tien_Lam_The();
            system("pause");
            break;
        case 4:
        {
            library->SapXep();
            system("pause");
            break;}
        case 5: {
			library->TimKiem();
			system("pause");
            break;
        }
        case 6: 
            library->Xoa();
            break;
        case 7:
        	cout<<"Have a good day "<<endl;
        	exit(0);
            break;
        default:
            cout<<"Lua chon khong phu hop. Xin vui long nhap lai!!!"<<endl;
            system("pause");
            break;
        }
    }
}
int main(){
	Menu();
    return 0;
}

