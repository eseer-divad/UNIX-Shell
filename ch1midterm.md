# Operating Systems Midterm Review

## Lecture 1: Introduction to OS

### Operating System: acts as an intermediary between a user and the hardware.
* Execute user programs and make user problems easier.
* Make the computer system convenient to use
* Use the computer hardware in efficient manners.

Different OS types trade off efficiency w/ ease-of-use.

#### Four Components of Computer Systems:
* Hardware
* Application Programs
* Users
* OS
---

### Perspectives of the System:

#### User Perspective - makes computer system friendly to use.

    - Concurrent Programs.
    - Keep track of files.
    - Manage/add hardware devices.
    - Run large programs.

Key elements of OS-aided user experience:

* multiple concurrent programs
* large memory
* files and directories
* protections from other users/programs.
* communication with other users/programs.
* UI/UX/GUI

#### Application Programmer View:

OS supports common tasks like:
* Accessing hardware devices.
* Sharing system resources w/ other programs.
* Exchanging / coordinating inter-program comms.

#### OS Programmer View:

Supports running applications on hardware.

Program the coordination of programs & hardware.

---

### Different Computing Environments:

#### Traditional Desktop Systems

Standalone general-purpose machines + internet.

* Office environment:
    - Portals -> provide access to internal systems.
    - Network Computers / Thin Clients.
    - Mobile Computers connect via wireless networks.
* Networking becomes ubiquitous on these systems over time.
* Windows, Linux, OS X

#### Mobile Systems

* Originally intended to miniaturize the desktop.
* Now includes unique features like GPS/gyroscopes
* Allows for new apps like AR/VR
* Uses IEEE 802.11 wireless or cellular data.
* Android, iOS, Windows

#### Distributed Systems

* Collection of separate systems networked together.
    - LAN / WAN / MAN / PAN
    - TCP/IP most commonly.
* Made possible by network evolution of speeds.
* Two primary models:
    - Client-Server: Dumb terminals connected to server. Store/retrieve files, compute, etc.
    - Peer-to-Peer: each node may act as client or terminal. (Torrents, VoIP like Skype, etc.)

#### Virtual / Cloud Computing Systems

* Virtualization: Parent (Host) OS + Guest OSs, all compiled natively.
* Virtual Machine Manager: Virtualbox, ESXi, etc.
* Cloud computing *uses* virtualization as a basis for its functionality.
    - Delivers computing, storage, or apps across network.
    - EC2, various cloud VMs.
* Types of Cloud Computing:
    - Public, private, and hybrid cloud.
    - SaaS, PaaS, IaaS
* Composed of VMM, a traditional OS, and cloud management tools.
    - Load Balancers
    - Firewalls

#### Real-Time Embedded Systems

* Uses all sorts of weird OSs.
* Cars, fridges, phones (non-smart), elevators, card readers.
* Embedded Java or other languages.

---

#### System Software:
* Middleware: common software to all apps, layer between OS and apps.

### Four Views of the OS:
* The OS is an extended machine (hides details for abstraction.)
* The OS is a virtual machine. 
* The OS is a resource manager.
* The OS is a control program.

### Multiprogramming: 
Load and execute multiple programs utilizing time-multiplexed CPU, and space-multiplexed memory.
* technique for sharing the CPU among many processes
* process can be blocked on I/O while others need to complete
* while one process remains blocked, another should run

### Timesharing/multitasking
Uses multiprogramming to allow multiple users to interact with the computer system at the same time. Backbone of servers, cloud apps.
* illusion of multiple consoles
* propogates processes, optimizes response time

#### Time-Multiplexed: ability to dedicate resource to process for defined time period.

#### Space-Multiplexed: Ability to divide resource into units, processes utilize distinct units.

---

### What underlies OS design & evolution?
* Correctness: working as expected as much of the time as possible.
* Maintainability: Relates to the ability of software changing easily.
* Commercial Factors
* Standards/Open Systems/Competition
* Performance: response time, job thruput
* Protection & Security

#### Abstractions: easier to design/use at tradeoff of speed.

#### Security: prevent malicious access, fight internal & external threats, specify controls and allow processes exclusive access to resources.

### Basic OS Subsystems:
1. Devices Management
2. Process, Thread, and Resource Management
3. Memory Management
4. File Management

#### Requesting Kernel Services: System Calls
* normal function call as procedure
* corresponds to a stub function which traps to sudo
* kernel checks params & legality

#### Requesting Kernel Services: Message Passing
* user process constructs a message
* trusted send function interacts w OS
* if OK, switch to sudo
* user process waits for response message

#### One program counter per thread, specifying location of next instruction.