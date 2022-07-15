// DollarAmount.h
// DollarAmount class stores dollar amounts as a whole numbers of cents

#include <string>
#include <cmath>

class DollarAmount{
    public:
    // initialize amount from an int64_t value
        // explict means it cannot be used for implicit conversions/copy-initialization
    //The explicit specifier may be used with a constant expression.
    // The function is explicit if and only if that constant expression evaluates to true.
    //explicit DollarAmount (int64_t value) : amount{value} {  }
    // constructor with separate values for dollar and cents
    DollarAmount (int64_t dollar, int64_t cents) {
        //amount = dollar*100 + cents;
        this ->dollar = dollar;
        this ->cents = cents;
    }
    DollarAmount (DollarAmount &money) {
        //amount = dollar*100 + cents;
        dollar = money.getDollar();
        cents = money.getCents();
    }
    void controlCents(){
        if(cents >99){
            dollar += cents/100;
            cents %=100;
        }
        else if (cents < 0){
            dollar--;
            cents+=100;
        }
    }
    // add right's amount to this object's amount 
      void add (DollarAmount right) {
        // can access private data of other objects of the same class
        //amount += right.amount;
        dollar += right.dollar;
        cents += right.cents;
        controlCents();
    }
    

    // substract right's amount from this object's amount
    void subtract (DollarAmount right) {
        // can access private data of other objects of the same class
        //amount -= right.amount;
        dollar += right.dollar;
        cents += right.cents;

    }

    int64_t getDollar(){return dollar;}
    int64_t getCents(){return cents;}
    void setDollar(int64_t d){dollar = d;}
    void setCents(int64_t c){dollar = c;}

    void divide (int divisor){
        // dividing the amount in input by using the half-up rounding
        //amount = (amount + divisor/2) / divisor ;
        dollar = (dollar + divisor/2) / divisor ;
        cents = (cents + divisor/2) / divisor ;
        controlCents();

    }

    // uses integer arithmetic to calculate interest amount,
    // then calls add with the interest amount
    void addInterest(int rate, int divisor) {
        // create DollarAmount representing the interest
        DollarAmount interest {
            //(amount * rate + divisor / 2) / divisor
            (dollar * rate + divisor/2) / divisor ,
            (cents * rate + divisor/2) / divisor 
        };

        add(interest); // add interest to this object's amount
    }

    // return a string representation of a DollarAmount object
    std::string toString() const {
         /*std::string dollars{std::to_string(amount / 100)};
        std::string cents {std::to_string(std::abs(amount % 100))};
        return dollars + "." + (cents.size() == 1 ? "0" : "") + cents; */
        return std::to_string(dollar) + "." + std::to_string(cents);
    }
    private:
    //int64_t amount{0}; // dolar amount in pennies

    int64_t dollar{0};
    int64_t cents{0};
};
