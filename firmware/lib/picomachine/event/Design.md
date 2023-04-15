

## Notes 

### Using `queue_init` versus `queue_init_with_spinlock` from `pico_utils`

Regarding the queue_init_with_spinlock function, it can be useful in scenarios where you expect 
high contention and concurrent read/write operations. A spinlock is a synchronization primitive 
that allows a thread to spin in a loop (busy-wait) until a resource becomes available. This can 
be more efficient than blocking in some cases, especially when the wait time for the resource is 
expected to be short.

However, the base queue.h implementation is already designed to be thread-safe and lock-free, 
which should be sufficient for most use cases. If you find that the base implementation does not 
provide the desired level of performance, you can consider using the queue_init_with_spinlock 
function to optimize for higher concurrency.
