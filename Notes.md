Redis operates as a single-threaded server. 
(Note: While Redis introduced multi-threading in version 6.0 specifically for handling non-blocking network I/O operations like parsing requests and flushing data, 
the core command execution engine remains single-threaded).
