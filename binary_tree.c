
#include "binary_tree.h"

int TRANSACTION_BINARY_TREE_exists(Node* node, int id_transaction){
    if(node == NULL || node->id_transaction == -1){
        return 0;
    }else{
        //printf("ID server: %d \nID transaction: %d\n", node->id_server, node->id_transaction);
        if(id_transaction == node->id_transaction){
            return 1;
        }else{
            if(id_transaction < node->id_transaction){
                // Explore the smaller son
                return TRANSACTION_BINARY_TREE_exists(node->smaller, id_transaction);
            }else{
                // Explore the bigger son
                return TRANSACTION_BINARY_TREE_exists(node->bigger, id_transaction);
            }
        }
    }
}


void TRANSACTION_BINARY_TREE_add(Node** node, int id_transaction, int id_server){


    if(*node == NULL){
        *node = (Node*)malloc(sizeof(Node));
        (*node)->id_transaction = id_transaction;
        (*node)->id_server = id_server;
        (*node)->smaller = NULL;
        (*node)->bigger = NULL;
    }else{
        if((*node)->id_transaction == -1){
            // is root (empty)
            (*node)->id_transaction = id_transaction;
            //(*node)->id_server = id_server;
        }else{
            // If the number exists, we don't add it again
            if(id_transaction < (*node)->id_transaction){
                // Explore the smaller son
                TRANSACTION_BINARY_TREE_add(&((*node)->smaller), id_transaction, id_server);
            }else if(id_transaction > (*node)->id_transaction){
                // Explore the bigger son
                TRANSACTION_BINARY_TREE_add(&((*node)->bigger), id_transaction, id_server);
            }
        }
    }
}

void TRANSACTION_BINARY_TREE_destroy(Node** node){
    if((*node)->smaller == NULL && (*node)->bigger == NULL){
        // We have no children, delete myself
        free(*node);
        *node = NULL;
    }else{
        if((*node)->smaller != NULL){
            TRANSACTION_BINARY_TREE_destroy(&((*node)->smaller));
        }
        if((*node)->bigger != NULL){
            TRANSACTION_BINARY_TREE_destroy(&((*node)->bigger));
        }
        free(*node);
        *node = NULL;
    }
}

int TRANSACTION_BINARY_TREE_findRoot(Node** trees, int id_server, int total_servers){
    for (int i = 0; i < total_servers; i++) {
        if(trees[i]->id_server == id_server){
            return i;
        }
    }
    return -1;
}