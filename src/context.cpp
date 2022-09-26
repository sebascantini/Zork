#include "context.h"

void runContext(Context* context_to_run){
    while(context_to_run->isActive())
        context_to_run->next();
    delete(context_to_run);
}