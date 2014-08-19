#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main()
{
    void *dl_so = NULL;
    int (*call_func_add)(int ,int );
    void (*call_func_hey)();

    if((dl_so = dlopen("./libtest.so",RTLD_NOW)) == NULL)
    {
        printf("dlopen %s\n",dlerror());
        exit(1);
    }
    else
    {
        if((call_func_add = dlsym(dl_so,"add")) == NULL)
        {
            printf("dlopen %s\n",dlerror());
            exit(1);
        }
        else
        {
            printf("add 1+9 = %d\n",call_func_add(1,9));

        }

        if((call_func_hey = dlsym(dl_so,"printf_hey")) == NULL)
        {
            printf("dlopen %s\n",dlerror());
            exit(1);
        }
        else
        {
            //printf("add 1+9 = %d",call_func_add(1,9));
            call_func_hey();

        }
        
        dlclose(dl_so);
        printf("dlclose %s\n",dlerror());
    }
    
    return 0;
}
