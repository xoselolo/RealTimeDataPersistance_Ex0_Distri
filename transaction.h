
#ifndef _TRANSACTION_H
#define _TRANSACTION_H

#include "tools.h"
#include "types.h"
#include "frame.h"
#include "binary_tree.h"

#include "semaphore_v2.h"

int TRANSACTION_sendConnect(Server *server);
int TRANSACTION_connectPassive(int fd_client, Server *server);

int TRANSACTION_readPassive(Server *server, int fd_client, int id_server, int id_trans);

int TRANSACTION_generateId(Node* root);

int TRANSACTION_readActive(Server server);
int TRANSACTION_readResponsePassive(int fd_client, Server *server);
int TRANSACTION_replyReadLastUpdated(int client_fd, int id_server, Server *server);
int TRANSACTION_replyReadCommon(int client_fd, int id_server, int id_trans, Server *server);


#endif //_TRANSACTION_H
