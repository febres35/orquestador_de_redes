
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

#include "Lista.h"
using namespace lista;

int Lista::_id = 0;



Lista::Lista(){
    /**
     * @brief constructor.
    */
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
    this->_id++;        
};