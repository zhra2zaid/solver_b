#include <iostream>
#include <complex>
#define EPS .0001
using namespace std;

namespace solver {

    class RealVariable {
    public:
        double _a ;
        double _b ;
        double _c;
    
    /**RealVariable(const double &a=0.0, const double &b=1.0, const double &c=0.0)
            :_a(a),_b(b),_c(c){}*/
    RealVariable()
    {
        _a=0;
        _b=1;
        _c=0;
    }


    RealVariable(const double a, const double b, const double c){
            this->_a = a;
            this->_b = b;
            this->_c = c;
        }
        //////geters//////
        const double & a() const    {return _a;}
        const double & b()  const  {return _b;}
        const double & c()  const  {return _c;}
           
        // + operator
    friend RealVariable operator+(const RealVariable& x, const RealVariable &y );
    friend RealVariable operator+(const RealVariable& x, const double y );
    friend RealVariable operator+(const double y, const RealVariable& x);

    // - operator
    friend RealVariable operator-(const RealVariable& x,const RealVariable& y );
    friend RealVariable operator-(const RealVariable& x, const double y);
    friend RealVariable operator-(const double y, const RealVariable& x);

    //* operator
    friend RealVariable operator*(const RealVariable& x, const RealVariable &y);
    friend RealVariable operator*(const RealVariable& x, const double y);
    friend RealVariable operator*(const double y, const RealVariable& x);

    // / operator
    friend RealVariable operator/(const RealVariable& x, const RealVariable &y);
    friend RealVariable operator/(const RealVariable& x, const double y);
    friend RealVariable operator/(const double y, const RealVariable& x);

    // ^ operator
    friend RealVariable operator^(const RealVariable &x, const double power);

    // == operator
    friend RealVariable operator==(const RealVariable& x, const RealVariable& y);
    friend RealVariable operator==(const RealVariable& x, const double y);
    friend RealVariable operator==(const double y, const RealVariable& x);
    };



    class ComplexVariable {
    
    private:

        complex <double> _a;
        complex <double> _b;
        complex <double> _c;
    public:  

    /**ComplexVariable(const std::complex<double> &a = 0.0, const std::complex<double> &b = 1.0,
                        const std::complex<double> &c = 0.0)
                : _a(a), _b(b), _c(c){}*/
     ComplexVariable()
    {
        _a=0;
        _b=complex(1,0);
        _c=0;
    }

    ComplexVariable(complex <double> a,complex <double> b,complex <double> c)
    {
        this->_a = complex<double>(a);
        this->_b = complex<double>(b);
        this->_c = complex<double>(c);
    }
     ////// geters/////
     const complex<double> &a() const
     {
         return _a;
     }  
     const complex<double> &b() const
     {
         return _b;
     }
     const complex<double> &c() const
     {
         return _c;
     }



    /////////Operators///////////////
      // + operator
        friend ComplexVariable operator+(const ComplexVariable& x,const ComplexVariable &y );
        friend ComplexVariable operator+(const ComplexVariable& x, const complex<double> y );
        friend ComplexVariable operator+(const complex<double> y,const ComplexVariable& x);
        // - operator
        friend ComplexVariable operator-(const ComplexVariable& x,const ComplexVariable &y );
        friend ComplexVariable operator-(const ComplexVariable& x,const complex<double> y);
        friend ComplexVariable operator-(const complex<double> y,const ComplexVariable& x);
        //* operator
        friend ComplexVariable operator*(const ComplexVariable& x, const ComplexVariable &y);
        friend ComplexVariable operator*(const ComplexVariable& x, const complex<double> y);
        friend ComplexVariable operator*(const complex<double> y,const ComplexVariable& x);
        //: operator
        friend ComplexVariable operator/(const ComplexVariable& x, const ComplexVariable &y);
        friend ComplexVariable operator/(const ComplexVariable& x, const complex<double> y);
        // friend ComplexVariable operator/(const complex<double> y,const ComplexVariable& x);check this
        // ^ operator
        friend ComplexVariable operator^(const ComplexVariable &x, const complex<double> power);
        // == operator
        friend ComplexVariable operator==(const ComplexVariable &x, const ComplexVariable &y);
        friend ComplexVariable operator==(const ComplexVariable &x, const complex<double> y);
        friend ComplexVariable operator==(const complex<double> y,const ComplexVariable &x);
    };
    


    double solve (const RealVariable& x);
    complex<double> solve (const ComplexVariable & x);

};