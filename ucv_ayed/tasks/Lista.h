//priviene la inclusion multiple del archivo de enzabezado
#ifdef LISTA_H
#define LISTA_H

namespace lista
{
    template <class T> 
    class Lista {
        public:
            Lista();
            Lista(T);
            ~Lista();
            bool isEmpty();
            const int getId();
            void setId(int);
            T *getHead();
            void setHead(T *);
            T *getTail();
            void setTail(T *);
            T get(int);
            void insert(int, T *);
            void Delete(int);
            void Delete();
            const int size();
            const void print();       

        private:
            unsigned int size;
            static unsigned int _id;
            T *head, *tail;
    };
};

#endif