#ifndef GERENCIATEMPO_H
#define GERENCIATEMPO_H
#include <time.h>

class GerenciaTempo
{
    private:
        time_t rawtime;
        struct tm * timeinfo;
    public:
        char* asctime(const struct tm *timeptr); //http://www.cplusplus.com/reference/ctime/asctime/
        void data_hora();

};

#endif // GERENCIATEMPO_H
