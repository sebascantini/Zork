#include "context.h"

void runContext(Context* context){
    while(context->isActive())
        context->next();
    delete(context);
}