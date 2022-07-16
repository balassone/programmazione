#ifndef CITY_H
#define CITY_H
#include <vector>
#include "Date.h"
#include "Rilevatore.h"
#include "Rilevamento.h"

class City{
    private:
        std::vector<Rilevatore> ril;
    public:
        City() = default;
        City(const std::vector<Rilevatore>& v) :ril{v} {}
        City& addMeasurement(const int& id, const Date& dat, const int& pimi){
            for(Rilevatore& ra : ril){
                if(ra.getID()==id){
                    ra.add(dat,pimi);
                    break;
                }
            }
            return *this;
        }
        double meanCO2Zone(const Date& d1, const Date& d2, const int& x1, const int& y1, const int& x2, const int& y2){
            double media{0};
            int count;
            for (Rilevatore& r : ril){
                if(r.getX()>=x1 && r.getY()>=y1 && r.getX()<=x2 && r.getY()<=y2){
                    for(Rilevamento ra : r.getRel()){
                        if(d1<ra.getDate() && ra.getDate()<d2){
                            media+=ra.getPPM();
                            count++;
                        }
                    }
                }
            }
            return (media/count);
        }

};
#endif