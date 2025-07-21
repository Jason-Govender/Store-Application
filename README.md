# Store & Receiver Application (Qt/C++)

This project showcases real-time model serialization, UDP networking, and Qt GUI design without Qt Designer.

## Store Application

A Qt-based desktop app that:

- Manages customers and inventory (books and magazines)
- Records transactions with date/time and quantity
- Tracks stock availability and prevents overselling
- Displays all transactions grouped by customer using a QTreeView
- Serializes the full model to XML using `QXmlStreamWriter`
- Broadcasts the XML model to the network via UDP (port `50000`)
- Built with manual Qt widget setup (no `.ui` files)
- Features: splash screen, toolbar actions, help & about dialogs

##  Receiver Application

A lightweight Qt application that:

- Listens for broadcasted XML model data via `QUdpSocket`
- Displays received XML in a live-updating `QTextEdit`
- Built entirely without Qt Designer

##  Technologies & Concepts

- C++17, Qt 6.6, CMake
- Object-Oriented Design with parent-child memory management
- Custom serialization (Serializer pattern)
- Qt signals/slots (Observer pattern)
- Model-view architecture with QTreeView
- Multithread-safe UDP broadcasting and message handling

## Build Instructions

### Prerequisites
- Qt 6.x with CMake support
- CMake 3.14 or newer
- g++, clang++, or MSVC

### To Build Each App

```bash
mkdir build
cd build
cmake ..
make
