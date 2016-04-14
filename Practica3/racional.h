#include <iostream>

using namespace std;
typedef int d_racional;

template<class d_racional>
class racional
{
private:
	d_racional numerador;
	d_racional denominador;
public:
	racional();
	racional(d_racional num_,d_racional den_);
	~racional();
	d_racional get_numerador(void);
	d_racional get_denominador(void);
	void set_numerador(d_racional num_);
	void set_denominador(d_racional dem_);
	d_racional denominador_comun(d_racional a,d_racional b);

	//operadores
	racional& operator+(const racional &rac_);
	racional& operator-(const racional &rac_);
	racional& operator*(const racional &rac_);
	racional& operator/(const racional &rac_);
	bool operator==(const racional &rac_);
	bool operator<(const racional &rac_);
	bool operator>(const racional &rac_);
};

template<class d_racional>
racional<d_racional>::racional()
{
	numerador=0;
	denominador=1;
}

template<class d_racional>
racional<d_racional>::racional(d_racional num_,d_racional den_)
{
	numerador = num_;
	if(den_!=0)
		denominador = den_;
}

template<class d_racional>
racional<d_racional>::~racional()
{
	numerador = 0;
	denominador = 0;
}

template<class d_racional>
d_racional racional<d_racional>::get_numerador(void)
{
	return numerador;
}

template<class d_racional>
d_racional racional<d_racional>::get_denominador(void)
{
	return denominador;
}

template<class d_racional>
void racional<d_racional>::set_numerador(d_racional num_)
{
	numerador = num_;
}

template<class d_racional>
void racional<d_racional>::set_denominador(d_racional den_)
{
	if(den_!=0)
		denominador = den_;
}

template<class d_racional>
d_racional racional<d_racional>::denominador_comun(d_racional a,d_racional b)
{
	if((a % b) == 0)
		return a;
	if((b % a) == 0)
		return b;
	if(((a % b) != 0) && ((b % a)!=0))
	{
		return a*b;
	}

}

template<class d_racional>
racional<d_racional>& racional<d_racional>::operator+(const racional &rac_)
{
	d_racional num_;
	d_racional den_;
	den_=denominador_comun(rac_.denominador,denominador);

	return *(new racional<d_racional>((den_/rac_.denominador)*rac_.numerador + (den_/denominador)*numerador,den_));
}

template<class d_racional>
racional<d_racional>& racional<d_racional>::operator-(const racional &rac_)
{
	d_racional num_;
	d_racional den_;
	den_=denominador_comun(rac_.denominador,denominador);
	return *(new racional<d_racional>((den_/denominador)*numerador - (den_/rac_.denominador)*rac_.numerador,den_));
}

template<class d_racional>
racional<d_racional>& racional<d_racional>::operator*(const racional &rac_)
{
	return *(new racional<d_racional>(numerador * rac_.numerador,denominador * rac_.denominador));
}


template<class d_racional>
racional<d_racional>& racional<d_racional>::operator/(const racional &rac_)
{
	return *(new racional<d_racional>(numerador * rac_.denominador,denominador * rac_.numerador));
}

template<class d_racional>
bool racional<d_racional>::operator==(const racional &rac_)
{
	if((rac_.numerador == numerador) && (rac_.denominador == denominador))
		return true;
	else
	{
		return false;
	}
}

template<class d_racional>
bool racional<d_racional>::operator<(const racional &rac_)
{

	bool comprobar = false;
	bool comprobar1= false;
	if(numerador > denominador)
	{
		comprobar = true;
	}
	if(rac_.numerador > rac_.denominador)
	{
		comprobar1 = true;
	}
	if(((comprobar == true)&&(comprobar1 == true))||((comprobar == false)&&(comprobar1==false)))
	{
			if(denominador == rac_.denominador)
			{

				if(numerador < rac_.numerador)
					return true;
				else
					return false;
			}
			else
			{
				d_racional den_;
				den_=denominador_comun(denominador,rac_.denominador);
				if(((den_ / denominador) * numerador) < ((den_ / rac_.denominador) * rac_.numerador))
					return true;
				else
					return false;
			}

	}
	else
	{
		if(comprobar == true && comprobar1 == false)
			return false;
		if(comprobar == false && comprobar1 == true)
			return true;
	}
}

template<class d_racional>
bool racional<d_racional>::operator>(const racional &rac_)
{
	bool comprobar = false;
	bool comprobar1= false;
	if(numerador > denominador)
		comprobar = true;
	if(rac_.numerador > rac_.denominador)
		comprobar1 = true;
	if(((comprobar == true)&&(comprobar1 == true))||((comprobar == false)&&(comprobar1==false)))
	{
			
			if(denominador == rac_.denominador)
			{
				if(numerador > rac_.numerador)
					return true;
				else
				{

					return false;
				}
			}
			else
			{
				d_racional den_;
				den_=denominador_comun(denominador,rac_.denominador);
				if(((den_ / denominador) * numerador) > ((den_ / rac_.denominador) * rac_.numerador))
					return true;
				else
					return false;
			}
	}
	else
	{
		if(comprobar == true && comprobar1 == false)
			return true;
		if(comprobar == false && comprobar1 == true)
			return false;
	}	
}