#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
class Admin
{
    public:
    int Addtaxidata();
    int showtaxibookings();
    string carnameadd,bookingpriceadd;
    int k=0;
    string line;
    string find;
    ofstream myfile;
};
class Taxi
{
public:
    int loginOrSignup();
    int menu();
    int BookTaxi();
    int Pay();
    int PaymentReceipt();
    int Rate();
    int random();            //for generaring otp and taxi id

    int people,bookingprice,baccno,cvv,taxiId,otp,star;
    char from[30],to[30],cardhname[20];
    char date[20],times[20],carname[20],amount,payn;
    string fname,lname;
};
int Taxi::menu()
{
    Taxi T;
    int ch;
    do{
    cout<<"\n****************************************MAIN MENU***************************************"<<endl;
    cout<<"Press 1: LOGIN OR SIGNUP"<<endl;
    cout<<"Press 2: BOOK TAXI"<<endl;
    cout<<"Press 3: GENERATE PAYMENT RECEIPT"<<endl;
    cout<<"Press 4: RATE US"<<endl;
    cout<<"Press 5: EXIT"<<endl;
    cout<<"Enter your choice:";
    cin>>ch;
    switch(ch)
    {
    case 1: T.loginOrSignup();break;
    case 2: T.BookTaxi();break;
    case 3: T.PaymentReceipt(); break;
    case 4: T.Rate(); break;
    case 5: cout<<"THANKS FOR VISITING!!";break;
    }}while((ch>0)&&(ch<4));

}
int Taxi::PaymentReceipt()
{
    cout<<"Enter your Taxi Identification Number:";
    cin>>taxiId;
    cout<<"Enter your FIRST name:";
    cin>>fname;
    cout<<"Enter your last name:";
    cin>>lname;
    cout<<"THIS IS YOUR PAYMENT RECEIPT:"<<endl;
    cout<<"*****************************************************************************************************"<<endl;
    cout<<"                                        PAYMENT RECEIPT                                              "<<endl;
    cout<<"*****************************************************************************************************"<<endl;
    cout<<"_____________________________________________________________________________________________________"<<endl;
    cout<<"NAME:"<<fname<<" "<<lname<<"    "<<"TAXI ID:"<<taxiId<<"    "<<endl;
    cout<<"                                                                                                     "<<endl;
    cout<<"FROM:"<<from<<"    "<<"TO:"<<to<<"    "<<"DATE:"<<date<<"    "<<"TIME:"<<times<<endl;
    cout<<"_____________________________________________________________________________________________________"<<endl;

}
int Taxi::loginOrSignup()
{
    Taxi T;
    char ls,username[20];
    string psw,cpsw,npsw;
    cout<<"LOGIN(L) or SIGNUP(S)";
    cin>>ls;
    if(ls=='S')
    {
        cout<<"Create username:";
        cin>>username;
        cout<<"Create Password:";
        cin>>psw;
        cout<<"Confirm Password:";
        cin>>cpsw;
        if(cpsw==psw)
        cout<<"Sign up successful!";
        else
            cout<<"Enter password again!"<<endl;
    }
    if(ls=='L')
    {
        cout<<"Enter username:";
        cin>>username;
        cout<<"Enter password(Type F if you have forgot password):";
        cin>>psw;
        if(psw=="F")
        {
            cout<<"Your New Password:";
            cout<<T.random();
            cout<<"Enter password:"<<endl;
            cin>>npsw;
            cout<<"Login succesful!"<<endl;
        }
        else
        cout<<"Login succesful!"<<endl;
    }
}
int Taxi::Pay()
{
    Taxi T;
    cout<<"Enter Account number:";
    cin>>baccno ;
    cout<<"Enter CVV:";
    cin>>cvv;
    cout<<"THIS IS YOUR OTP:";
    cout<<T.random();
    cout<<"Enter OTP:";
    cin>>otp;
    cout<<"PAYMENT SUCCESSFULL"<<endl;
    cout<<"TAXI BOOKED!!!";
    cout<<"\nTHIS IS YOUR TAXI IDENTIFICATION NUMBER:";
    cout<<T.random();
    cout<<"You can check your payment receipt."<<endl;

}
int Taxi::BookTaxi()
{
    Taxi T;
    fstream fout;
    fout.open("hello.txt", ios::app);
    if (!fout) {
        cout<<" Error while creating the file ";
    }
    else {

        cout<<"From:(Enter city)";
        cin>>from;
        cout<<"To:(Enter city)";
        cin>>to;
        cout<<"Enter Number of people(Max 4):";
        cin>>people;
        cout<<"Enter Date(DD/MM/YYYY):";
        cin>>date;
        cout<<"Enter Time (00:00AM/PM):";
        cin>>times;
        fout<<"FROM:"<<from<<"    "<<"TO:"<<to<<"    "<<"DATE:"<<date<<"    "<<"TIME:"<<times<<endl;
        fout.close();
        cout<<"\nSHOWING AVAIABLE TAXIS FOR"<<endl;
        cout<<"FROM:"<<from<<"    "<<"TO:"<<to<<"    "<<"DATE:"<<date<<"    "<<"TIME:"<<times<<endl;
        ifstream in("taxiDetails.txt");
        if(!in) {
        cout << "Cannot open input file.\n";
        return 1;
        }

        char str[1000];

        while(in) {
        in.getline(str, 1000);
        if(in) cout << str << endl;
        }
        cout<<"Enter car name of your choice:";
        cin>>carname;
        cout<<"Enter booking price:";
        cin>>bookingprice;
        cout<<"PAY NOW:(Y/N)";
        cin>>payn;
        char Y,N;
        switch(payn){
        case 'Y':T.Pay();break;
        case 'N':cout<<"PAYMENT INTERRUPTED";break;
    }}
}
int Taxi::random()
{
    int b=0;
    srand(time(0));
    while(b<1){
        cout<<rand()<<endl;
    cout<<endl;
    return 0;
    }
}
int Taxi::Rate()
{
    cout<<"Please Rate your experience!"<<endl;
    cout<<"Give points from 1 to 5."<<endl;
    cin>>star;
    switch (star)
    {
        case 1:cout<<"THANK YOU FOR RATING US. WE WILL TRY TO IMPROVE.";break;
        case 2:cout<<"THANK YOU FOR RATING US. WE WILL TRY TO MAKE IT BETTER.";break;
        case 3:cout<<"THANK YOU FOR RATING US. WE WILL TRY TO MAKE IT BETTER.";break;
        case 4:cout<<"THANK YOU FOR RATING US. WE ARE HAPPY THAT YOU LIKED IT.";break;
        case 5:cout<<"THANK YOU FOR RATING US. WE ARE HAPPY THAT YOU LOVED IT.";break;
    }
}
 int Admin::Addtaxidata()
{

    myfile.open("taxidetails.txt",ios::app);

    while(k!=2){

        cout<<"press 1 for adding Taxi"<<endl;
        cin>>k;

        if(k==1)
        {
            cout<<"enter car name:"<<endl;
            cin>>carnameadd;

            cout<<"enter Booking price"<<endl;
            cin>>bookingpriceadd;
          myfile<<"CAR NAME:"<<carnameadd<<"      "<<"BOOKING PRICE:"<<"     "<<bookingpriceadd<<endl;
        }
        break;
}
}
int Admin::showtaxibookings()
{
    cout<<"SHOWING BOOKIGS TILL NOW"<<endl;
ifstream in("taxiDetails.txt");
        if(!in) {
        cout << "Cannot open input file.\n";
        return 1;
        }

        char str[1000];

        while(in) {
        in.getline(str, 1000);
        if(in) cout << str << endl;
        }
}
int main()
{

    char au;
    int ch,cha;
    Admin A;
    Taxi T;
    string p,u;
    cout<<"Admin or user(A/U):";
    cin>>au;
    if(au=='A')
    {
        cout<<"Enter username:";
        cin>>u;
        cout<<"Enter password:";
        cin>>p;
        if(p=="1234")
        {
            cout<<"Welcome Admin!!";
            do{
            cout<<"\n****************************************MAIN MENU***************************************"<<endl;
            cout<<"Press 1: ADD TAXI DATA"<<endl;
            cout<<"Press 2: SHOW TAXI BOOKINGS"<<endl;
            cout<<"Press 3: EXIT"<<endl;
            cin>>cha;
            switch(cha)
            {
                case 1: A.Addtaxidata();break;
                case 2:A.showtaxibookings();break;
                case 3:break;
            }}while((cha>0)&&(cha<3));
        }
    }
    if(au=='U')
      {
        cout<<"Welcome user";
        cout<<"\n*******************************************WELCOME*******************************************"<<endl;
        cout<<"_____________________________________TAXI BOOKING SYSTEM________________________________________"<<endl;
        T.menu();
      }
return 0;
}

