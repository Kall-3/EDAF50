# CPP Project

## building with cmake

This project is built using cmake. To build the server and client, run the following from the console in the project root path `username/project/`:

```
mkdir build
cd build
cmake ..
cmake --build .
```

The binaries `primeServer, diskServer and client` are placed in `project/build/bin/`.

## running the files

To run the client and server, open two terminal windows.

In the first one, start the server with `server <name> <port>`, e.g.,

```
./diskServer news 7777
./primeServer news 7777
```

In the other one, start the client with `myclient <name> <server> <port>`, e.g.,

```
./client client1 localhost 7777
```

You can run multiple instances of client to each server. To guarantee the port is open, only use ports over 1024. Ports under 1024 are root privileged on linux distributions.

## running the tests

The tests can be run from the console with `java -jar [TestServer1.jar | TestServer2.jar] <server> <port>`, e.g.

```
java -jar TestServer1.jar primeServer 7777
java -jar TestServer2.jar diskServer 7777
```

The tests are located in `project/tests/`.