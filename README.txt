TASK:
ADT Sorted Multi Map - implementation on a hash table, collision resolution by separate chaining

PROBLEM STATEMENT:
You are put in charge of administrating an email database where each user owning an account can receive messages. 
You must make sure that all incoming messages reach their destination and that for any account all received messages are stored.

PROBLEM EXPLANATION:
The hash function will associate the emails ( pairs of email address and message – a string ) to the corresponding position in the database ( the hash table ).
Because an address can obviously receive more than one email, all emails received by an address will be stored in a linked list (separate chaining).

Additional information can be found inside the Project Documentation PDF file.