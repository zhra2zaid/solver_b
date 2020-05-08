#include <iostream>
#include <math.h>
#include "solver.hpp"
#include <complex>


using namespace std;
namespace solver{



//Real variables

  // + operator
    RealVariable operator+(const RealVariable& x, const RealVariable &y )
    {
        return RealVariable(x.a()+y.a(), x.b()+y.b(), x.c()+y.c());
    }
    RealVariable operator+(const RealVariable& x, const double y )
    {
        return RealVariable(x.a(),x.b(),x.c()+y);
    }
    RealVariable operator+(const double y, const RealVariable& x)
    {
        return RealVariable(x.a(),x.b(),x.c()+y);
    }

    // - operator
    RealVariable operator-(const RealVariable& x,const RealVariable& y )
    {
        return RealVariable(x.a()-y.a(),x.b()-y.b(),x.c()-y.c());
    }
    RealVariable operator-(const RealVariable& x, const double y)
    {
        return RealVariable(x.a(),x.b(),x.c()-y);
    }
    RealVariable operator-(const double y, const RealVariable& x)
    {
        return RealVariable(x.a(),x.b(),x.c()-y);

    }

    //* operator
    RealVariable operator*(const RealVariable& x, const RealVariable &y)
    {
        if(x.a()!=0 && y.a()!=0)
                throw out_of_range("the power is greater than 2!");
            if(x.a()!=0 && y.b()!=0)
                throw out_of_range("the power is greater than 2!");
            if(x.b()!=0 && y.a()!=0)
                throw out_of_range("the power is greater than 2!");
                
            return RealVariable((x._a*y._c)+(x._b*y._b)+(x._c*y._a), (x._b*y._c)+(x._c*y._b), x._c*y._c);
    }
    RealVariable operator*(const RealVariable& x, const double y)
    {
        return RealVariable(x.a()*y,x.b()*y,x.c()*y);
    }
    RealVariable operator*(const double y, const RealVariable& x)
    {
        return RealVariable(x.a()*y,x.b()*y,x.c()*y);
    }

    // / operator
    RealVariable operator/(const RealVariable& x, const RealVariable &y)
    {
        return RealVariable(x.a()/y.a(),x.b()/y.b(),x.c()/y.c());
    }
    RealVariable operator/(const RealVariable& x, const double y)
    {
        if(y==0)
        {
            throw out_of_range("You can't divide by 0!");
        }
        return RealVariable(x.a()/y,x.b()/y,x.c()/y);
    }
    RealVariable operator/(const double y, const RealVariable& x)
    {
        if(x.a()==0 && x.b()==0 && x.c()==0)
            throw out_of_range("You can't divide by 0!");

        return RealVariable(x.a()/y,x.b()/y,x.c()/y);
    }




    // ^ operator
    RealVariable operator^(const RealVariable &x, const double power)
    {
        if(power==0) return RealVariable(0,0,1);
        if(power==1) return x;
        if(x.a()!=0 || power >2 || power <0)
           { throw out_of_range ("Can't accept this power!");}

        if(x.b()!=0 && x.c()!=0 && power==2) {return RealVariable(pow(x.b(),power),x.b()*x.c()*power,pow(x.c(),power));}
    
        if(x.b()!=0 && x.c()==0 && power==2) {return RealVariable(pow(x.b(),power),0,0);}

        if(x.b()==0 && x.c()!=0 && power>=2) {return RealVariable(0,0,pow(x.c(),power));}
    }

    // == operator
    RealVariable operator==(const RealVariable& x, const RealVariable& y)
    {
         return x-y;
    }
    RealVariable operator==(const RealVariable& x, const double y)
    {
         return x-y;
    }
    RealVariable operator==(const double y, const RealVariable& x)
    {
         return x-y;
    }






///////ComplexVariable//////



// + operator
        ComplexVariable operator+(const ComplexVariable& x,const ComplexVariable &y )
        {
            return ComplexVariable(x.a()+y.a(),x.b()+y.b(),x.c()+y.c());
        }
        ComplexVariable operator+(const ComplexVariable& x, const complex<double> y )
        {
            return ComplexVariable(x.a(),x.b(),x.c()+y);
        }
        ComplexVariable operator+(const complex<double> y,const ComplexVariable& x)
        {
            return ComplexVariable(x.a(),x.b(),x.c()+y);    
        }


        // - operator
        ComplexVariable operator-(const ComplexVariable& x,const ComplexVariable &y )
        {
            return ComplexVariable(x.a()-y.a(),x.b()-y.b(),x.c()-y.c());
        }
        ComplexVariable operator-(const ComplexVariable& x,const complex<double> y)
        {
            return ComplexVariable(x.a(),x.b(),x.c()-y);    
        }
        ComplexVariable operator-(const complex<double> y,const ComplexVariable& x)
        {
            return ComplexVariable(x.a(),x.b(),x.c()-y);    
        }



        //* operator
        ComplexVariable operator*(const ComplexVariable& x, const ComplexVariable &y){
            if(x.a()!=complex(0.0,0.0) && y.a()!=complex(0.0,0.0))
                throw out_of_range("the power is greater than 2!");
            if(x.a()!=complex(0.0,0.0) && y.b()!=complex(0.0,0.0))
                throw out_of_range("the power is greater than 2!");
            if(x.b()!=complex(0.0,0.0) && y.a()!=complex(0.0,0.0))
                throw out_of_range("the power is greater than 2!");
            
            return ComplexVariable((x.a()*y.c())+(x.b()*y.b())+(x.c()*y.a()), (x.b()*y.c())+(x.c()*y.b()), x.c()*y.c());
            
        }
        ComplexVariable operator*(const ComplexVariable& x, const complex<double> y)
        {
            return ComplexVariable(x.a()*y,x.b()*y,x.c()*y);
        }
        ComplexVariable operator*(const complex<double> y,const ComplexVariable& x)
        {
            return ComplexVariable(x.a()*y,x.b()*y,x.c()*y);
        }



        //: operator
        ComplexVariable operator/(const ComplexVariable& x, const ComplexVariable &y)
        {
            if (y.a() == complex<double >(0.0,0.0) && y.b() == complex<double >(0.0,0.0) && y.c() == complex<double>(0.0,0.0)) 
                throw out_of_range("division by zero is not possible !");
            ComplexVariable result = x-y;
        if(result.a() == complex(0.0,0.0) && result.b() == complex(0.0,0.0) && result.c() == complex(0.0,0.0))
        {
            return ComplexVariable(0, 0, 1);
        }
        if(x.a() != complex(0.0,0.0) && x.b() == complex(0.0,0.0) && x.c() == complex(0.0,0.0) 
        && y.a() != complex(0.0,0.0) && y.b() == complex(0.0,0.0) && y.c() == complex(0.0,0.0))
        { 
            return ComplexVariable(0,0,x.a()/y.a());
        }
        if(x.a() != complex(0.0,0.0) && x.b() == complex(0.0,0.0) && x.c() == complex(0.0,0.0) 
        && y.a() == complex(0.0,0.0) && y.b() != complex(0.0,0.0) && y.c() == complex(0.0,0.0))
        { 
            return ComplexVariable(0,x.a()/y.b(), 0);
        }
        if(x.a() == complex(0.0,0.0) && x.b() != complex(0.0,0.0) && x.c() == complex(0.0,0.0) 
        && y.a() == complex(0.0,0.0) && y.b() != complex(0.0,0.0) && y.c() == complex(0.0,0.0))
        { 
            return ComplexVariable(0,0,x.b()/y.b());
        }
        if(x.a() != complex(0.0,0.0) && x.b() != complex(0.0,0.0) && x.c() == complex(0.0,0.0)
         && y.a() == complex(0.0,0.0) && y.b() != complex(0.0,0.0) && y.c() == complex(0.0,0.0))
        { 
            return ComplexVariable(0, x.a()/y.c(), x.b()/y.c());
        }
        if(y.a() == complex(0.0,0.0) && y.b() == complex(0.0,0.0))
        { 
            return x/y.c();
        }
        throw runtime_error("cannot solve it!");
    
            
        }
        ComplexVariable operator/(const ComplexVariable& x, const complex<double> y)
        {
            if(y.real()==0 && y.imag()==0)
            {
                throw out_of_range("cannot div 0!");
            }
            return ComplexVariable(x.a()/y, x.b()/y, x.c()/y);
        }
        ComplexVariable operator/(const complex<double> y,const ComplexVariable& x)
        {
            if(x.a().real()!=0 && x.a().imag()!=0 && x.b().real()!=0 && x.b().imag()!=0 &&x.c().real()!=0 && x.c().imag()!=0)
            
                return ComplexVariable(y/x.a(), y/x.b(), y/x.c());
            throw out_of_range("cannot div whith 0!");
        }



        // ^ operator
        ComplexVariable operator^(const ComplexVariable &x, const complex<double> power)
        {
            if(power==complex<double>(0.0,0.0)) return ComplexVariable(0,0,1);

            if(power.imag() !=0) throw runtime_error("Invalid");

            if(power.real() ==1) return ComplexVariable(0, 0, 1);
            
         
        if(power.real() == 1)
        {
            return x;
        }
        if(x.a() != complex(0.0,0.0))
        {
            throw runtime_error("The power is greater than 2");
        }
        if(power.real() < 0)
        {
            throw runtime_error("The power is less than 0");
        }
        if(power.real() > 2)
        {
            if(x.b() != complex(0.0,0.0))
            {
                throw runtime_error("The power is greater than 2");
            }
            else
            {
               
                return ComplexVariable(0, 0, pow(x.c(), power));
            }
        }
            return x*x;
        }



        // == operator
        ComplexVariable operator==(const ComplexVariable &x, const ComplexVariable &y)
        {
            return x-y;
        }
        ComplexVariable operator==(const ComplexVariable &x, const complex<double> y)
        {
            return x-y;
        }
        ComplexVariable operator==(const complex<double> y,const ComplexVariable &x)
        {
            return y-x;
        }

//////////solve///////////
        double solve (const RealVariable& x)
        {
            double a=x.a();
            double b=x.b();
            double c=x.c();

            if(a==0)
            {
                if(b==0 && c!=0)
                    throw out_of_range("cannot solve this real variable!");
                else 
                    return c/-b;
            }
            double r=b*b-4*a*c;
            if(r>0)
            {
                return (-b+sqrt(r))/(a*2);
            }
            if(r==0)
                return (-b)/(a*2);
             
             throw out_of_range("There is no  solution!");

        }
        complex<double> solve (const ComplexVariable & x)
        {
            complex<double> a = x.a();
            complex<double> b = x.b();
            complex<double> c = x.c();

        if(a==complex<double>(0.0,0.0))
        {
             if(b==complex<double>(0.0,0.0) && c!=complex<double>(0.0,0.0))
                    throw out_of_range {" there is no result "};
            return -(c / b);
        }

        complex<double> r = b*b-complex(4.0,0.0)*a*c;
          
        /**if(r==complex(0.0,0.0,0.0))
                return (-b)/(a*complex(2.0,0.0));
*/
        return (-b+sqrt(r))/(complex(2.0,0.0)*a);
        
        }

};