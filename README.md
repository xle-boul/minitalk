# minitalk
Projet minitalk de 42.

A short introduction to signals and how to make processes listen to eachother's signals and interpret them.

In this version: Both server and client are listening for incoming signals. My system works as a "handshake", the client sends a signal and waits for the server to send one back before continuing.
Eventually, the client sends a terminator signal to the server which then sends back a signal to the client to terminate its process.

I didn't use:

- any global variable

- memory allocation

- usleep


Bonus included.
