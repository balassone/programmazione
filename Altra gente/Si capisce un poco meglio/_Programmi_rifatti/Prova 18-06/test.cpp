//test.cpp
#include"DLinkedList.h"
#include"Borrow.h"
#include"Book.h"
#include"QuickSort.h"
#include<iostream>
#include<vector>
using std::vector;
using std::cout; using std::endl;

void borrow(DLinkedList<Borrow>&,const Book&, const Date&);
double valueExpired(const Date&, const DLinkedList<Borrow>&);
int returnBook(const Date&,const Book&, DLinkedList<Borrow>&); 


int main() {
    Book b1;
    b1.setAuthors({"Spitch S.", "Clork J."});
    b1.setBookID("4879");
    b1.setPosition("378907");
    b1.setValue(15.50);
    b1.setYear(2018);
    b1.setTitle("L'arte della sincerita'");
    //cout<<"\nBook b1: "<<b1.toString()<<endl;
    Book b2 ("1927", {"Bront A.", "Scronch B."}, "Silence please", 1978, "187976", 18.76);
    //cout<<"\nBook b2: "<<b2.toString()<<endl;
    Book b3 = {"4537", {"Prest A.", "Best B."}, "Peace and love", 1989, "349832", 9.99};
    //cout<<"\nBook b3: "<<b3.toString()<<endl;
    Book b4 = {"2342", {"Scholes. C.", "Bisley D."}, "What?", 1998, "137526", 15.99};
    //cout<<"\nBook b4: "<<b4.toString()<<endl;
    Book b5 = {"7653", {"Scholes. C.", "Bisley D."}, "Beutiful wind", 1898, "434227", 7.99};
    //cout<<"\nBook b5: "<<b5.toString()<<endl;
    vector<Book> v{b1, b2, b3, b4, b5};
    quickSort(v, 0, v.size()-1);
    cout<<"\nPrint ordered vector of books (in order of 'authors' (in case of being equal than 'year')): ";
    for (int i=0; i< v.size(); i++){
        cout<<v[i].toString()<<endl;
    }
    Date d1 {1, 4, 2002};
    Date d2 {3, 5, 2001};
    Date d3 = {23,3,1989};
    Borrow borrow1(b1, d1);
    Borrow borrow2(b2, d2);
    cout<<"\nBorrows\n";
    cout<<"\nBorrow1 :"<<
    borrow1.toString();
    cout<<"\nBorrow2 :"<<
    borrow2.toString();
    DLinkedList<Borrow> borrowList;
    borrowList.addInOrder(borrow1);
    borrowList.addInOrder(borrow2);
    cout<<"\nAdd a book, b3, to list of borrows";
    borrow(borrowList, b3, d3);
    cout<<"\nList of borrows in order of restitution date: \n"<<borrowList.toString()<<endl;
    cout<<"Total value of books expired in list of borrows: "<<valueExpired({12,7,2020},borrowList)<<endl;
    
    Book b6{"1927", {"Bront A.", "Scronch B."}, "Silence please", 1978, "187976", 18.76};
    int multa{0};
    multa = returnBook({12,11,2021}, b6, borrowList);
    cout<<"\nMulta per il libro '"<<b6.getTitle()<<"' : "<<multa<<"$\n\n";
    cout<<"Lista aggiornata:"<<endl<<borrowList.toString()<<endl;
}

void borrow(DLinkedList<Borrow>& list,const Book& libro, const Date& dataPrestito){
    Borrow b{libro, dataPrestito};
    list.addInOrder(b);
}

double valueExpired(const Date& d, const DLinkedList<Borrow>& l){
    double sum{0};
    for (int i=0; i<l.size(); i++){
        if (l[i].getRestitutionDate() < d){
            sum += l[i].getBook().getValue();
        }
    }
    return sum;
}

int returnBook(const Date& d,const Book& b, DLinkedList<Borrow>& l) {
    int fine{0}; //multa
    for (int i=0; i<l.size(); i++){
        if (b.getBookID() == l[i].getBook().getBookID()){
            Date temp = l[i].getRestitutionDate();
            while (temp != d){
                ++temp;
                ++fine;
            }
            l.removeElement(l[i]);
            return fine;
        }
    }
    return fine;
}