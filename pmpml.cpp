#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;

class bus
{
    private:
        string b_no,from,to,via;
        int b_seats;
    public:
        void menu1();
        void menu2();
        void new_bus();
        void single_bus_view();
        void all_bus_view();
        void del_bus();
        void ticket_booking();
        void seat_details();
        void del_seat();
};

    void bus::menu1()
    {
        a:
        system("cls");
        int choice;
        system("cls");
        cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
        cout<<"\n\n\n\t\t\t\t\t  * Main Menu * ";
        cout<<"\n\n\n\t\t 1. Add Bus Details";
        cout<<"\n\n\t\t 2. Delete Bus Details";
        cout<<"\n\n\t\t 3. Exit";
        cout<<"\n\n\t\t\tEnter your Choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            new_bus();
            break;
        case 2:
            del_bus();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"\n\n\n Invalid Choice...Try Again...";
            getch();
            goto a;
        }
    }

    void bus::menu2()
    {
        b:
        int choice;
        system("cls");
        cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
        cout<<"\n\n\n\t\t\t\t\t  * Main Menu * ";
        cout<<"\n\n\n\t\t 1.View all Bus details";
        cout<<"\n\t\t 2.Serach Bus";
        cout<<"\n\t\t 3.Book Ticket Now";
        cout<<"\n\t\t 4.Search booking Record";
        cout<<"\n\t\t 5.Delete Booking Record";
        cout<<"\n\t\t 6.Exit";
        cout<<"\n\n\n\t\t\t Enter your Choice : ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                all_bus_view();
                break;
            case 2:
                single_bus_view();
                break;
            case 3: 
                ticket_booking();
                break;
            case 4:
                seat_details();
                break;
            case 5:
                del_seat();
                break;
            case 6:
                cout<<"\n\n\t\t\t\t ---Thank you for visiting---";
                exit(0);
            default:
                cout<<"\n\n Invalid Choice...Try Again...";
                getch();
                goto b;
        }      
    }

    void bus::new_bus()
    { 
        c:
        system("cls");
        fstream file;
        string t_no,t_from,t_to,t_via;
        int t_seat,found=0;
        cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
        cout<<"\n\n\n\t\t Bus No : ";
        cin>> b_no;
        cout<<"\n\t\t Total Seats : ";
        cin>>b_seats;
        cout<<"\n\t\t From : ";
        cin>>from;
        cout<<"\n\t\t To : ";
        cin>>to;
        cout<<"\n\t\t Via : ";
        cin>>via;

        file.open("bus.txt",ios::in);
        if(!file)
        {
            file.open("bus.txt",ios::app|ios::out);
            file<<b_no<<" "<< b_seats<<" "<<from<<" "<<to<<" "<<via<<"\n";
            file.close();
            cout<<"\n\n Bus Added Successfully...";
        }
        else
        {
            file>>t_no>>t_seat>>t_from>>t_to>>t_via;
            while(!file.eof())
            {
                if(b_no==t_no)
                {
                    found++;
                }
                file>>t_no>>t_seat>>t_from>>t_to>>t_via;
                file>>t_no>>t_seat>>t_from>>t_to>>t_via;
            }
            file.close();
            if(found==0)
            {
                file.open("bus.txt",ios::app|ios::out);
                file<<b_no<<" "<< b_seats<<" "<<from<<" "<<to<<" "<<via<<"\n";
                file.close();
                cout<<"\n\n Bus Added Successfully...";
            }
            else
            {
                cout<<"\n\n Duplicate Record Found... ";
                getch();
                goto c;
            }
        }
        cout<<"\n\n Press enter to return Main Menu";
        getch();
        menu1();
    }

    void bus::single_bus_view()
    {
        d:
        system("cls");
        string t_from,t_to;
        fstream file;
        int found=0;
        cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
        file.open("bus.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File opening error...";
        }
        else
        {
            cout<<"\n\n\n\t\t\t From : ";
            cin>>t_from;
            cout<<"\n\t\t\t To : ";
            cin>>t_to;
            file>>b_no>>b_seats>>from>>to>>via;
            while(!file.eof())
            {
                if((t_from==from && t_to==to) || (t_from==to && t_to==from))
                {
                    cout<<"\n\n Bus no : "<<b_no<<"\t\t Total seats : "<<b_seats<<"\t\tRoute : "<<from<<"\t to\t"<<to<<"\t\t via : "<<via<<"\n\t\t\t\t\t\t\t\t"<<to<<"\t to\t"<<from<<"\t\t via : "<<via<<"\n";
                    file>>b_no>>b_seats>>from>>to>>via;
                    found++;
                }
                file>>b_no>>b_seats>>from>>to>>via;
            }
            file.close();
            if(found==0)
            {
                cout<<"\n\n Sorry!!! No Bus found on the Route... ";
                getch();
                goto d;
            }
        }
        cout<<"\n\n Press enter to return Main Menu...";
        getch();
        menu2();
    }

    void bus::all_bus_view()
    {
        system("cls");
        fstream file;
        cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
        file.open("bus.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File opening error...";
        }
        else
        {
            file>>b_no>>b_seats>>from>>to>>via;
            while(!file.eof())
            {
                cout<<"\n\n Bus no : "<<b_no<<"\t\t Total seats : "<<b_seats<<"\t\tRoute : "<<from<<"\t to\t"<<to<<"\t\t via : "<<via<<"\n\t\t\t\t\t\t\t\t"<<to<<"\t to\t"<<from<<"\t\t via : "<<via<<"\n";
                file>>b_no>>b_seats>>from>>to>>via;
            }
            file.close();
        }
        cout<<"\n\n\t Press Enter to return Main Mainu...";
        getch();
        menu2();
    }

    void bus::del_bus()
    {
        system("cls");
        fstream file,file1;
        string t_no;
        int found=0,n;
        cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
        system("cls");
        file.open("bus.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File opening error...";
        }

        else
        {
            cout<<"\n\n Bus No : ";
            cin>>t_no;
            file1.open("bus3.txt",ios::app|ios::out);
            file>>b_no>>b_seats>>from>>to>>via;
            while(!file.eof())
            {
                if(t_no==b_no)
                {
                    cout<<"\n\n\n Bus record deleted succesfully";
                    cout<<"\n\n Press enter to return main menu";
                    found++;
                }
                else
                {
                    file1<<b_no<<" "<<b_seats<<" "<<from<<" "<<to<<" "<<via<<"\n";
                }
                file>>b_no>>b_seats>>from>>to>>via;
            }
            file.close();
            file1.close();
            remove("bus.txt");
            rename("bus3.txt","bus.txt");
            if(found==0)
            {
                cout<<"\n\n Please enter valid Bus Number...";
            }
        }
        getch();
        menu1();
    }

    void bus::seat_details()
    {
        system("cls");
        fstream file2,file;
        string t_no,s_no,s_b_no;
        int count=0,found=0;
        cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
        file.open("bus.txt",ios::in);
        file2.open("seat.txt",ios::in);
        if(!file2 || !file)
        {
            cout<<"\n\n\t\t File opening Error!!!";
            cout<<"\n\n \t\t\t Press enter to Main Menu...";
        }
        else
        {
            cout<<"\n\n\n\t\t Bus no. : ";
            cin>>t_no;
            file2>>s_b_no>>s_no;
            while(!file2.eof())
            {
                if(t_no == s_b_no)
                {
                    count++;
                }
                file2>>s_b_no>>s_no;
            }
            file2.close();
            file>>b_no>>b_seats>>from>>to>>via;

            while(!file.eof())
            {
                if(t_no == b_no)
                {
                    system("cls");
                    cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
                    cout<<"\n\n\n\t\t Total seats : " << b_seats;
                    cout<<"\n\n\t\t Reserved seats :" << count;
                    cout<<"\n\n\t\t Empty Seats :" << b_seats-count;
                    cout<<"\n\n\n\t Press Enter to return Main Menu...";
                    found++;
                }
                file>>b_no>>b_seats>>from>>to>>via;
            }
            
            file.close();
            if(found==0)
            {
                cout<<"\n\nNo Bus Found!!! ";
            } 
        }
        getch();
        menu2();

    }

    void bus::ticket_booking()
    {
        p:
        system("cls");
        fstream file2,file;
        string t_no,s_b_no,cust_name1,cust_name2,aadhar_no;
        int found=0,seats=36,count=0,s_s_no,s_no,i=0,x;
        cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
        file.open("bus.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File opening error...";
        }
        else
        {
            cout<<"\n\n\n\t\t Bus no : ";
            cin>>t_no;
            file.close();
            file2.open("seat.txt",ios::in);
            if(file2)
            {
                file2>>s_b_no>>s_s_no;
                while(!file2.eof())
                {
                    if(t_no == s_b_no)
                    {
                        count++;
                    }
                    file2>>s_b_no>>s_s_no;
                }
                file2.close();
            }
            file.open("bus.txt",ios::in);
            file>>b_no>>b_seats>>from>>to>>via;
            while(!file.eof())
            {
                if(t_no ==b_no)
                {
                    seats = b_seats;
                    found++;
                }
                file>>b_no>>b_seats>>from>>to>>via;
            }
            file.close();
            if(seats-count==0)
            {
                cout<<"\n\n\n\t\t\t All seats are reserved...";
            }
            else if(found == 1)
            {
                do
                {
                    a:
                    cout<<"\n\n\t\t Seat no : ";
                    cin>>s_no;
                    if(s_no > seats || s_no < 1)
                    {
                        cout<<"\n\n Plese Enter valid Seat Number...";
                        goto a;
                    }
                    file2.open("seat.txt",ios::in);
                    if(!file2)
                    {
                        file2.open("seat.txt",ios::app|ios::out);
                        file2<<t_no<<" "<<s_no<<"\n";
                        file2.close();
                    }
                    else
                    {
                        file2>>s_b_no>>s_s_no;
                        while(!file2.eof())
                        {
                            if(t_no == s_b_no && s_no == s_s_no)
                            {
                                cout<<"\n\n\t\t\t Seat is already reserved...";
                                goto a;
                            }
                            file2>>s_b_no>>s_s_no;
                        }
                        file2.close();
                        file2.open("seat.txt",ios::app|ios::out);
                        file2<<t_no<<" "<<s_no<<"\n";
                        file2.close();
                    }
                    cout<<"\n\n\t\t\t Your seat has been booked...";
                    cout<<"\n\n\t\t Customer First name : ";
                    cin>>cust_name1;
                    cout<<"\n\n\t\t Customer Second name : ";
                    cin>>cust_name2;
                    cout<<"\n\n\t\t Aadhar no (last 4 digit) : ";
                    cin>>aadhar_no;
                    file.open("customer.txt",ios::app|ios::in);
                    file<<cust_name1<<" "<<cust_name2<<" "<<t_no<<" "<<s_no<<" "<<aadhar_no<<"\n";
                    file.close();
                    cout<<"\n\n\t\t\t Your seat has been booked";
                    cout<<"\n\n\t\t Your booking details are in progress, please wait";
                    cout<<"\n\n\n\t\t\t\t\t Loading...";
                    Sleep(1000);
                    system("cls");
                    cout<<"\n\t\t   ------- Welcome to PMPML Bus Reservation -------";
                    cout<<"\n\n\n\t\t   ********************************************************";
                    cout<<"\n\n\t\t\t ------------- Booking Details -------------";
                    cout<<"\n\n\t\t   ********************************************************";
                    cout<<"\n\n\t\t   Name    : "<<cust_name1<<" "<<cust_name2;
                    cout<<"\n\t\t   Bus no  : "<<t_no;
                    cout<<"\n\t\t   Seat id : "<<aadhar_no<<"_"<<s_no;
                    cout<<"\n\n\t\t   ********************************************************";
                    cout<<"\n\n\t\t   ********************************************************";
                    cout<<"\n\n\n\t\t # Do you want to book book another seat \n\n\t\t\t Yes=1 \t no=2 \n\n\t\t Enter your choice : ";
                    cin>>x;
                }while(x == 1);
                system("cls");
                menu2();
                
            }
            else
            {
                cout<<"\n\n Please Enter valid Bus Number...";
            }
            getch();
            goto p;
        }
    }

    void bus::del_seat()
    {
        system("cls");
        fstream file2,file1;
        string t_no,s_t_no,s_b_no,s_s_no;
        int found=0;
        cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
        file2.open("seat.txt",ios::in);
        if(!file2)
        {
            cout<<"\n\n File opening error...";
        }

        else
        {
            cout<<"\n\n\t\t Bus No : ";
            cin>>t_no;
            cout<<"\n\n\t\t Seat no : ";
            cin>>s_t_no;
            file1.open("seat2.txt",ios::app|ios::out);
            file2>>s_b_no>>s_s_no;
            while(!file2.eof())
            {
                if(t_no==s_b_no && s_t_no==s_s_no)
                {
                    cout<<"\n\n\n Seat record deleted succesfully";
                    cout<<"\n\n Press enter to return Main Menu...";
                    found++;
                }
                else
                {
                    file1<<s_b_no<<" "<<s_s_no<<"\n";
                }
                file2>>s_b_no>>s_s_no;
            }
            file2.close();
            file1.close();
            remove("seat.txt");
            rename("seat2.txt","seat.txt");
            if(found==0)
            {
                cout<<"\n\n Bus or seat no is invalid...";
            }
        }
        getch();
        menu2();
    }

int main()
{
    bus b;
    int n;
    string pass,user_id,ch;
    p:
    system("cls");
    cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
    cout<<"\n\n\n\t\t\t\t Employee = 1 \t\t costomer = 2";
    cout<<"\n\n\n\t\t\tEnter your Choice : ";
    cin>>n;
    if (n==1)
    {
        q:
        system("cls");   
        cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
        cout<<"\n\n\n\t\t\t\t\t >>> Sign in <<<";
        cout<<"\n\n\t\t User Id : ";
        cin>>user_id;
        cout<<"\n\n\t\t Password : ";
        for(int i=1;i<10;i++)
        {
            ch = getch();
            pass += ch;
            cout<<"*";
        }

        if((user_id=="shelaraditya490@gmail.com" && pass=="aditya490") || (user_id=="atharv22110317@viit.ac.in" && pass=="atharv317"))
        {
            system("cls");
            cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
            cout<<"\n\n\n\t\t\t\t\t Loading...";
            Sleep(750);
            b.menu1();
        }

        else
        {
            cout<<"\n Invalid User Id or password";
            getch();
            goto q;
        }
    }

    else
    {
        system("cls");
        cout<<"\n\t\t\t ------- Welcome to PMPML Bus Reservation -------";
        cout<<"\n\n\n\t\t\t\t\t Loading...";
        Sleep(750);
        b.menu2();
    }
    return 0;
}