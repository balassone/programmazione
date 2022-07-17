#include <string>
#include <sstream>
#ifndef PIANO_H
#define PIANO_H
class Piano{
    public:
        Piano();
        Piano(const int&, const std::string&, const std::string&, const float&);
        void setColor(const int&);
        const int& getColor() const;
        void setWood(const std::string&);
        const std::string& getWood() const;
        void setSupplier(const std::string&);
        const std::string& getSupplier() const;
        void setPricing(const float&);
        const float& getPricing() const;
        virtual float getArea() const = 0;
        bool operator<(const Piano& p);
        bool operator==(const Piano& p){
            if(this==&p) return true;
            else if(color==p.color && woodtype==p.woodtype && supplier==p.supplier && pricingsqm==p.pricingsqm) return true;
            return false;
        }
        virtual std::string toString() const;
    private:
        int color;
        std::string woodtype;
        std::string supplier;
        float pricingsqm;
};

class Rotondo: public Piano{
    public:
        Rotondo();
        Rotondo(const int&, const std::string&, const std::string&, const float&, const float&);
        void setRadius(const float&);
        const float& getRadius() const;
        virtual float getArea() const;
        std::string toString() const;
    private:
        float radius;
};
class Rettangolare: public Piano{
public:
    Rettangolare();
    Rettangolare(const int&, const std::string&, const std::string&, const float&, const float&, const float&);
    void setBase(const float&);
    const float& getBase() const;
    void setHeight(const float&);
    const float& getHeight() const;
    virtual float getArea() const;
    std::string toString() const;
private:
    float base;
    float height;
};

class Triangolare: public Piano{
    public:
        Triangolare();
        Triangolare(const int&, const std::string&, const std::string&, const float&, const float&, const float&);
        void setBase(const float&);
        const float& getBase() const;
        void setHeight(const float&);
        const float& getHeight() const;
        virtual float getArea() const;
        std::string toString() const;
    private:
        float base;
        float height;
};
#endif