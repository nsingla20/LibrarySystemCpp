#include "Student.h"
#include <ctime>
#include "../Books/Book.h"
#include <boost/ptr_container/ptr_vector.hpp>

int Student::Calc_fine(){
    int fine=0;
    time_t t;
    for(auto book:books){
        t=book.show_dueDate();
        if(time(0)>t){
            t=difftime(time(0),t);
            fine+=(t/86400)*fine_day();
        }
    }
    return fine;
}
void Student::clear_fine(){
    for(auto book:books){
        book.unissue();
    }
    books.clear();
}