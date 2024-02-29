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

Virtualization: Parent (Host) OS + Guest OSs, all compiled natively.

Virtual Machine Manager: Virtualbox, ESXi, etc.

