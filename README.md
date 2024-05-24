# Ethernet Frame Parser Project
It is a C++ program that can dissect and analyze Ethernet Frames with a focus on parsing IP and ARP packets. 

## Source Code:
You can checkthe source code for the program here [Src Code]() 

## Executable App:
You can check an execuatable file for the program here [App.exe](https://drive.google.com/drive/folders/12tRCj9zhd5ktrLP-qHS2EjkqtNq-1yOy?usp=sharing) 

## Demo Video:
You can check a detailed demo for the program here [demo]() 

## Running the Application:
To run the application using Visual Studio, follow these steps:

### Prerequisites
- **Visual Studio**: Ensure you have Visual Studio installed on your system. You can download it from the [official website](https://visualstudio.microsoft.com/).

### Steps to Run the Application

1. **Get the source code**: Either, clone the repository to your local machine using Git.
    ```bash
    git clone https://github.com/LoayMoh99/EthernetFrameParser.git
    cd EthernetFrameParser
    ```
    OR Download the source file from the drive, then
    `cd EthernetFrameParser`

2. **Open the Solution File**: Navigate to the project directory and open the `.sln` file in Visual Studio.
    - You can do this by double-clicking the `.sln` file or by opening Visual Studio, selecting `File -> Open -> Project/Solution`, and then navigating to the `.sln` file.

3. **Build the Solution**: Build the solution to ensure that all the project files are compiled.
    - Go to `Build -> Build Solution` or press `Ctrl + Shift + B`.

4. **Run the Application**: Start the application by selecting `Debug -> Start Debugging` or pressing `F5`.
    - Alternatively, you can start without debugging by selecting `Debug -> Start Without Debugging` or pressing `Ctrl + F5`.

5. **Choose an Action**: You will be prompted a 3 choices:
    - Action [1] for getting input and viewing output in the std console app
    - Action [2] for getting input and viewing output using files
    - Anything else to exit the program
    And it will instruct you how to input the inputs exactly..

    >**Note** for using the files prepare a `.txt` file and add to it the ethernet frames each in new line


# System Design

## Folders' Structure

```bash
.
├── IO (include all I/O classes)
│  ├── FileInput class              (Derived Class)
│  ├── FileOutput class             (Derived Class)
│  ├── Input class                  (Base Class)
│  ├── Output class                 (Base Class)
│  ├── StdInput class               (Derived Class)
│  └── StdOutput class              (Derived Class)
│
├── Packets (include all Packets classes)
│  ├── ARPPacket class              (Derived Class)
│  ├── IPPacket class               (Derived Class)
│  └── Packet class                 (Base Class)
|
├── Parser (include all Parser classes (either Frame or Packet-payload parsers))
│  ├── Parser class                 (Base Class - Frame Parser)
│  ├── IPPayloadParser class        (Abstract/Base Class - Packet-payload Parser)
│  ├── ICMPPayloadParser class      (Derived Class - Packet-payload Parser)
│  └── UDPPayloadParser class       (Derived Class - Packet-payload Parser)
|
├── Application Manager class       (Maestro Class)
├── DEFS.h                          (Global consts/defn/helper functions)
└── main.cpp                        (Main file)
```


## Structure Overview
The project is divided into several components, each with specific responsibilities:

- I/O Classes: Handle input and output operations.
- Packets Classes: Represent different types of network packets.
- Parser Classes: Parse the contents of packets or frames.
- Application Manager: Coordinates the entire application workflow.
- Global Definitions: Holds global constants, definitions, and helper functions.
- Main File: The entry point of the application.

## Components and Class Responsibilities
1. ### I/O Classes
    **Base Classes**:
    - Input: An abstract base class for input operations.
    - Output: An abstract base class for output operations.

    **Derived Classes**:
    - FileInput: Handles input operations from files.
    - FileOutput: Handles output operations to files.
    - StdInput: Handles input operations from standard input (i.e. cin).
    - StdOutput: Handles output operations to standard output (i.e. cout).

2. ### Packets Classes
    **Base Classes**:
    - Packet: A base class representing a generic network packet.

    **Derived Classes**:
    - ARPPacket: Represents an ARP packet.
    - IPPacket: Represents an IP packet.

3. ### Parser Classes
    **Base Classes**:
    - Parser: A base class for frame parsering.
    - IPPayloadParser: An abstract base class for parsing IP packet payloads.

    **Derived Classes**:
    - ICMPPayloadParser: Parses ICMP packet payloads.
    - UDPPayloadParser: Parses UDP packet payloads.

4. ### Application Manager
    The Application Manager orchestrates the entire application workflow, coordinating I/O operations, packet parsing, and output generation.

5. ### DEFS
    Contains global constants, definitions, and helper functions used throughout the project.

6. ### Main File
    The entry point of the application.