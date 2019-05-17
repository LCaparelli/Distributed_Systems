#include <pthread.h>
#include <vector>
#include "model/AccountModel.h"

#ifndef EPDSID2_SERVERENDPOINT_H
#define EPDSID2_SERVERENDPOINT_H

#endif //EPDSID2_SERVERENDPOINT_H

extern pthread_mutex_t account_mutex;

extern std::vector<Account> accounts;

extern long global_id;
