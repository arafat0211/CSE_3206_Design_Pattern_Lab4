# 🧩 CSE 3206 Design Pattern Lab (Group 3)

**Rajshahi University of Engineering & Technology (RUET), Department of CSE**

Our group's patterns are **Adapter, Bridge and Composite**, each shown as a small C++ demo.

## 📌 Patterns

| Pattern | Category | Example | Source | Status |
|---|---|---|---|---|
| 🔌 Adapter | Structural | Type-C adapter for a Micro-USB device | [`Adapter/Adapter.cpp`](Adapter/Adapter.cpp) | ✅ Done |
| 🌉 Bridge | Structural | File viewers rendering to console or HTML | [`bridge.cpp`](bridge.cpp) | ✅ Done |
| 🌳 Composite | Structural | Files and nested directories | [`composite.cpp`](composite.cpp) | ✅ Done |

## 🚀 Build & Run

Any C++11 compiler works (`g++`, `clang++`):

```bash
g++ -std=c++11 Adapter/Adapter.cpp -o adapter     && ./adapter
g++ -std=c++11 bridge.cpp          -o bridge_demo && ./bridge_demo
g++ -std=c++11 composite.cpp       -o composite   && ./composite
```

## 🔌 Adapter

Lets a client that expects **USB Type-C** use a **Micro-USB** device. `USBAdapter` implements the Type-C interface and forwards calls to the Micro-USB object it wraps.

**Roles:** Target `USBTypeC` · Adaptee `MicroUSB` · Adapter `USBAdapter` · Client `main()`

```text
Adapter converting Type-C to MicroUSB...
MicroUSB connected.
```

## 🌉 Bridge

Separates *what is shown* from *how it is displayed*, so viewers and displays vary independently (2 viewers × 2 displays = 4 small classes, not one per combination).

**Roles:** Implementor `Display` · Concrete `ConsoleDisplay`, `HtmlDisplay` · Abstraction `FileViewer` · Refined `SimpleViewer`, `DetailedViewer`

```text
[Console] File: data.txt
<p>File: data.txt</p>
[Console] File: pic.png | Size: 120 KB
<p>File: pic.png | Size: 250 KB</p>
```

## 🌳 Composite

Treats a single file and a whole directory the same way. `Directory` holds `FileSystem*` children and calls `showDetails()` on each, so the tree prints recursively.

**Roles:** Component `FileSystem` · Leaf `File` · Composite `Directory`

```text
+ Directory: root
  - File: data.txt
  + Directory: images
    - File: pic.png
```
