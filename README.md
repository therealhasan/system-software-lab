# System Software Lab

This repository contains C implementations of four system software and computer architecture exercises. Prebuilt Windows executables are included alongside the source code.

## Experiments

| Folder | Experiment | Description |
| --- | --- | --- |
| [01_Risc_Cise](01_Risc_Cise/) | RISC/CISC Addition | Compares a CISC-style direct addition with a RISC-style load/add/store operation |
| [02_translator](02_translator/) | Two-Pass Assembly Translator | Converts a fixed set of assembly instructions into 16-bit hexadecimal machine code |
| [03_Macroprocessor](03_Macroprocessor/) | Macro Processor | Reads macro definitions, stores them in the MDT, and expands macro calls in the input program |
| [04_Linker_loader](04_linker_loader/) | Linker/Loader | Demonstrates absolute loading of two object modules and external symbol resolution |

## Requirements

- A C compiler, such as GCC or MinGW
- Windows Command Prompt or PowerShell

## Compile and Run

Open a terminal in the repository root and run the commands below.

### RISC/CISC Addition

```powershell
gcc ".\01_Risc_Cise\01_Risc_cise_add.c" -o ".\01_Risc_Cise\01_Risc_cise_add.exe"
.\01_Risc_Cise\01_Risc_cise_add.exe
```

Enter two integers when prompted.

### Assembly-to-Machine-Code Translator

```powershell
gcc ".\02_translator\02_translator.c" -o ".\02_translator\02_translator.exe"
.\02_translator\02_translator.exe
```

The program translates `LOAD`, `STORE`, `ADD`, `SUB`, and `HALT` instructions.

### Macro Processor

The macro processor uses `MACIN.txt` as input and creates or updates `MACOUT.txt` and `MDT.txt`.

```powershell
Set-Location ".\03_Macroprocessor"
gcc ".\03_macroprocessor.c" -o ".\03_macroprocessor.exe"
.\03_macroprocessor.exe
Set-Location ".."
```

Run the executable from the `03_Macroprocessor` directory so the relative file names are resolved correctly.

### Linker/Loader

```powershell
gcc ".\04_Linker_loader\04_linker_loader.c" -o ".\04_Linker_loader\04_linker_loader.exe"
.\04_Linker_loader\04_linker_loader.exe
```

Enter a hexadecimal load address when prompted, for example `1000`.
