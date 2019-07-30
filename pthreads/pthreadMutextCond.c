/*
 * Illustration of pthread_cond_wait(pthread_cond_t*, pthread_mutex_t*) and
 * pthread_mutex.
 * Order threads in order using the above.
 * https://leetcode.com/problems/print-in-order/
 */
typedef struct {
    
    // User defined data may be declared here.
    pthread_mutex_t mlock;
    pthread_cond_t first;
    pthread_cond_t second;
    pthread_cond_t third;
    int f;
    int s;
    int t;
    
} Foo;

Foo* fooCreate() {
    
    Foo* obj = (Foo*) malloc(sizeof(Foo));

    // Initialize user defined data here.
    pthread_mutex_init(&obj->mlock, NULL);
    pthread_cond_init(&obj->first, NULL); 
    pthread_cond_init(&obj->second, NULL);
    pthread_cond_init(&obj->third, NULL);
    obj->f = 0;
    obj->s = 0;
    obj->t = 0;
    
    return obj;
}

void first(Foo* obj) {
    
    pthread_mutex_lock(&obj->mlock);
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    obj->f = 1;
    pthread_cond_signal(&obj->first);
    pthread_mutex_unlock(&obj->mlock);
}

void second(Foo* obj) {
    
    pthread_mutex_lock(&obj->mlock);
    
    while (!obj->f)
        pthread_cond_wait(&obj->first, &obj->mlock);
    
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    obj->s = 1;
    pthread_cond_signal(&obj->second);
    pthread_mutex_unlock(&obj->mlock);
}

void third(Foo* obj) {
    
    pthread_mutex_lock(&obj->mlock);
    
    while (!obj->s)
        pthread_cond_wait(&obj->second, &obj->mlock);
        
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    obj->t = 1;
    pthread_cond_signal(&obj->third);
    pthread_mutex_unlock(&obj->mlock);
}

void fooFree(Foo* obj) {

	// User defined data may be cleaned up here.
    pthread_mutex_lock(&obj->mlock);
    
    while(!obj->t)
        pthread_cond_wait(&obj->third, &obj->mlock);
    
    pthread_mutex_unlock(&obj->mlock);
    free(obj);
}
