# SSH-Based Linux Process Manager

This project explores core Linux systems administration concepts, including
process management, networking with SSH, and remote development using a Linux virtual machine.

## Features
- SSH-based remote access from Windows to a Linux VM
- Secure file transfer using SCP
- Multi-process application written in C
- Parent process creates worker processes using fork()
- Worker processes execute system monitoring commands using exec()
- Commands used: ps, mpstat

## Technologies Used
- Linux (Ubuntu VM)
- SSH / SCP
- C Programming
- fork(), exec(), wait()
- Makefile

## How It Works
1. Source code is developed on Windows
2. Code is transferred to the Linux VM using SCP
3. Application is built and executed inside the Linux environment
4. Processes are monitored and managed remotely via SSH

## Learning Outcomes
- Understanding Linux process creation and management
- Working with SSH for secure remote access
- Using SCP for cross-platform file transfer
- Hands-on experience with Linux virtual machines
