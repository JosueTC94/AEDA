#pragma once
using namespace std;

template<class TClave>
class Celda
{
    private:
        TClave *pv;
        int nBloques; // Numero de bloques disponibles en la celda
        int nClaves; //Numero de elementos insertados  en la celda
    public:

        Celda(int num_bloques)
        {
            nClaves = 0; //Número de elementos insertados
            nBloques = num_bloques; //Numero de bloques disponibles en la celda
            if(num_bloques > 0) //Try catch
            {
                pv = new TClave[num_bloques];
            }
        }

        ~Celda()
        {
            if(pv != NULL)
            {
                delete [] pv;
                pv = NULL;
            }
        }

        int get_nBloques(void)
        {
            return nBloques;
        }

        TClave get_bloque(int pos)
        {
            return pv[pos];
        }

        bool buscar(TClave h)
        {
            bool encontrado = false;
            int contador = 0;
            while(contador < nClaves && encontrado == false)
            {
                if(pv[contador] == h)
                {
                    encontrado = true;
                }
                else
                {
                    encontrado = false;
                    contador++;
                }
            }

            return encontrado;
        }

        bool insertar(const TClave &h)
        {
            bool insertado = false;
            cout << "Muestro el bloque:\t";
            for(int i=0;i<nBloques;i++)
            {
                cout << pv[i] << ",";
            }
            cout << endl;
            if(estallena() == false)
            {
                int contador = 0;
                while(contador < nBloques && insertado == false)
                {
                    if(pv[contador] != '\0')
                    {
                        cout << "cnweiocnweicnoweo" << endl;
                        insertado = false;
                        contador++;
                    }
                    else
                    {
                        cout << "Bloque: " << contador << endl;
                        pv[contador] = h;
                        insertado = true;
                        nClaves++;
                    }
                }
            }
            else
            {
                insertado = false;
            }
            return insertado;
        }

        bool estallena()
        {
            if(nClaves == nBloques)
                return true;
            else
                return false;
        }

        void imprimir_bloque(void)
        {
            for(int i=0;i<nBloques;i++)
            {
                cout << pv[i] << ",";
            }
            cout << endl;
        }
};
