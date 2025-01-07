### README for Minitalk 🚀

---

## 🖍 **Project Overview**  
Minitalk is a 42 project designed to explore interprocess communication (IPC) using UNIX signals. The project consists of a **server** and a **client**, which communicate via `SIGUSR1` and `SIGUSR2` signals to send and receive messages.

---

## 🖂 **Files and Structure**

- **Makefile**  
  Automates the build process. It compiles the server and client with the specified flags (`-Wall -Wextra -Werror`) and provides the following targets:
  - `all`: Builds the `server` and `client`.
  - `clean`: Removes object files.
  - `fclean`: Removes object files and executables.
  - `re`: Rebuilds everything.

- **server.c**  
  - Launches a server that prints its **PID** and waits for messages.  
  - Handles incoming bits using signal handlers and reconstructs the message character by character.  
  - Sends acknowledgment signals back to the client.

- **client.c**  
  - Sends a message to the server, bit by bit, using signals.  
  - Handles acknowledgment signals from the server to ensure reliable transmission.  
  - Includes input validation to ensure the correct **PID** format.

---

## ⚙️ **How to Compile**

Run the following command in the project directory to compile both the server and the client:

```bash
make
```

This will create two executables: `server` and `client`.

---

## 🚀 **How to Use**

1. **Start the server**:  
   In one terminal, run:  
   ```bash
   ./server
   ```  
   The server will print its **PID**. Make a note of this value.

2. **Send a message from the client**:  
   In another terminal, run:  
   ```bash
   ./client [PID] [MESSAGE]
   ```  
   Replace `[PID]` with the server's PID and `[MESSAGE]` with the message you want to send. For example:  
   ```bash
   ./client 12345 "Hello, Minitalk!"
   ```

---

## ⚒️ **Features**

- **Signal-based communication**:  
  Messages are transmitted one bit at a time using `SIGUSR1` and `SIGUSR2`.

- **Acknowledgments**:  
  The client waits for acknowledgment signals to ensure the server correctly receives each bit.

- **Robust error handling**:  
  - Validates the **PID** input.  
  - Detects if the message has been successfully received.

---

## 🔍 **Important Notes**

- **Signal Reliability**:  
  Ensure the process IDs (PIDs) are valid and that the server is running before launching the client. Signals might not be delivered in certain high-load conditions, so avoid sending excessively long messages.

- **Compilation Restrictions**:  
  The code adheres to strict 42 norms, ensuring compliance with `-Wall -Wextra -Werror` flags and line/variable restrictions.

---

## 📸 **Example**

```bash
# Terminal 1 (Server)
$ ./server
Server PID: 12345

# Terminal 2 (Client)
$ ./client 12345 "Hello, World!"
Message received by server! ✅
```

---

## 🎯 **Goals of the Project**

- Learn and implement IPC using signals.
- Deepen understanding of UNIX system calls (`kill`, `signal`, `sigaction`, etc.).
- Practice robust error handling and optimize signal usage.

---

Happy coding and good luck! 😊

