#include<iostream>
#include<bits/stdc++.h>
using namespace std;



void display()
{
    system("Color 0B");
    system("cls");
    cout<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                    --MESS MANAGER--                                       "<<endl;
    cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"__________________________________________________________________________________________"<<endl;
    cout<<"----------------------------------CREATED BY SHAFIN117-----------------------------------"<<endl;
    cout<<"__________________________________________________________________________________________"<<endl;
}

void menu(pair<string,double> memdpo[],int m,double mb,int x);


void deposite(pair<string,double>memdpo[],int m,double mb)
{
    system("cls");
    display();
    cout<<endl;
    cout<<"___________DEPOSITE___________"<<endl;
    cout<<endl;
    cout<<"Mess members : "<<endl;
    cout<<"--------------"<<endl;

    for(int i=0;i<m;i++)
    {
        cout<<memdpo[i].first<<endl;
    }
    cout<<endl;
    cout<<"Who want to deposite ? : ";
    string s;
    cin>>s;
    cout<<endl;
    cout<<"Amount of deposite : ";
    int x;
    cin>>x;
    for(int i=0;i<m;i++)
    {
        if(s==memdpo[i].first)
        {
            memdpo[i].second += x;
            mb += x;
            cout<<endl;
            cout<<"...Successfully added deposite..."<<endl;
            break;
        }
    }
    cout<<endl;
    cout<<"Go back to menu (y/n) : ";
    char c;
    cin>>c;
    if(c=='y'|| c=='Y')
    {
        menu(memdpo,m,mb,0);
    }
}


void cost(pair<string,double> memdpo[],int m,double mb,int x)
{
    system("cls");
    display();
    cout<<endl;
    cout<<"________COST_________"<<endl;
    cout<<endl;
    cout<<"Add cost : ";
    cin>>x;
    mb -=x;

    cout<<endl;
    cout<<"Go back to the menu(y/n) : ";
    char c;
    cin>>c;
    if(c=='y'||c=='Y')
    {
        menu(memdpo,m,mb,x);

    }

}



void meal(pair<string,double>memdpo[],int m,double mb,int x)
{
    system("cls");
    display();
    cout<<endl;
    cout<<endl;
    cout<<"______________MEAL_____________"<<endl;
    double ml[m];
    cout<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<"Number of meal "<<memdpo[i].first<<" took : ";
        cin>>ml[i];
        cout<<endl;
    }

    double sum;

    for(int i=0;i<m;i++)
    {
        sum +=ml[i];
    }
    double mealrate;
    mealrate = x/sum;

    for(int i=0;i<m;i++)
    {
        memdpo[i].second -= mealrate * ml[i];
    }

    cout<<endl;
    cout<<"Go back to menu (y/n) : ";
    char c;
    cin>>c;
    if(c=='y'|| c=='Y')
    {
        menu(memdpo,m,mb,x);
    }

}


void menu(pair<string,double> memdpo[],int m,double mb,int x)
{

    system("cls");
    display();

    cout<<endl;
    cout<<"Current Mass Balance : "<<mb<<" Taka "<<"           Cost : "<<x;
    cout<<endl;
    cout<<endl;

    for(int i=0;i<m;i++)
    {
        cout<<"Current Balance of "<<memdpo[i].first<<" : "<<memdpo[i].second<<endl;
    }
    cout<<endl;
    cout<<endl;


    cout<<"_____OPTIONS_____"<<endl;
    cout<<"1.Add Deposit "<<endl;
    cout<<"2.Add Cost"<<endl;
    cout<<"3.Add Meal"<<endl;
    cout<<endl;

    cout<<"Chose option : ";
    int n;
    cin>>n;
    if(n == 1)
    {
        deposite(memdpo,m,mb);
    }
    else if(n==2)
    {
        cost(memdpo,m,mb,0);
    }
    else if(n==3)
    {
        meal(memdpo,m,mb,x);
    }


}



void mass_balance(pair<string,double> memdpo[],int m)
{
    system("cls");
    display();
    double mb;

    for(int i=0;i<m;i++)
    {
        mb += memdpo[i].second;
    }


    menu(memdpo,m,mb,0);

}





void mass(pair<string,double> memdpo[] ,int m)
{
    system("cls");
    display();

    cout<<endl;
    cout<<endl;

    for(int i=0;i<m;i++)
    {
        cout<<"Enter name of member "<<i+1<<" : ";

        cin>>memdpo[i].first;
        cout<<endl;

    }
     system("cls");
     display();
    for(int i=0;i<m;i++)
    {

        cout<<"Enter deposit of "<<memdpo[i].first<<" : ";
        cin>>memdpo[i].second;
        cout<<endl;
    }
    mass_balance(memdpo,m);
}


int main()
{
    display();
    int mem;
    cout<<endl;
    cout<<endl;
    cout<<"Enter number of mess member : ";
    cin>>mem;
    pair<string,double>memdpo[mem];

    if(mem>0)
    {
        mass(memdpo,mem);
    }
}
