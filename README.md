# Transport Company Management System (TCMS)

[Русский](README.ru.md) | **English**

A console and later GUI application for managing a fleet of vehicles (tractors, buses, trucks), developed as part of a freelance project. The system allows tracking vehicle specifications, maintenance, and repairs.

## 📋 Project Overview & Technical Specification

The system processes information about all vehicles in the fleet, which share common attributes:
*   State registration number
*   Inventory number
*   Year of registration

**Specific characteristics by vehicle type:**
*   **Tractor:** Brand, engine power, remaining engine resource.
*   **Bus:** Brand, passenger capacity, mileage, remaining mileage until repair.
*   **Truck:** Brand, load capacity, engine power, mileage, remaining mileage until repair.

Vehicles can be new or repaired. Repaired vehicles include additional data about the maintenance performed (repair type, work performed).

**Implemented functionality (as per technical assignment):**
1.  Input of data for a new vehicle.
2.  Re-adding a vehicle to the fleet after repair.
3.  Removing written-off vehicles from the system (with full information output, implemented using a destructor).
4.  Output of the complete list of all vehicles.
5.  Output of a list of vehicles with a remaining resource less than a specified value.
6.  Output of a list of vehicles of a specified type.

## 🚀 Releases & Features by Version

Ready-to-use executables (`.exe`) are available in the [`/releases`](/releases) folder for each version.

| Version | Interface | Key Features | Download |
| :--- | :--- | :--- | :--- |
| **v1** (2022-05-21) | Console | Basic functionality for data management. | [QtCpp_system_MTC_v1.exe](/releases/v1/QtCpp_system_MTC_v1.exe) |
| **v2** (2022-11-24) | Console | Output of a list sorted by registration year. Switched from `vector` to `map`/`multimap` containers. | [QtCpp_system_MTC_v2.exe](/releases/v2/QtCpp_system_MTC_v2.exe) |
| **v3** (2022-12-10) | **Graphical (Qt)** | GUI, open/save database via dialog, extended sorting options. Database file extension changed to `.transp`. | [QtCpp_system_MTC_v3.exe](/releases/v3/QtCpp_system_MTC_v3.exe) |
| **v4** (2022-12-15) | Graphical (Qt) | Added a dialog with a plot chart for vehicle remaining mileage. | [QtCpp_system_MTC_v4.exe](/releases/v4/QtCpp_system_MTC_v4.exe) |

> **Note on Encoding:** Source code for v1 and v2 uses `windows-1251 / CP 1251` encoding.

## 📁 Repository Structure
QtCpp_system_management_transport_company/
├── versions/ # Source code for each version (v1, v2, v3, v4)
├── releases/ # Compiled executables and runtime DLLs for each version
├── CHANGELOG.md # Development history (English)
├── CHANGELOG.ru.md # История изменений (Russian)
├── LICENSE # MIT License
└── README.md # This file


## 🔧 For Developers (Source Code)

The complete C++/Qt source code for each iteration is available in the [`/versions`](/versions) directory. This showcases the project's evolution from a console application to a full-fledged Qt GUI application with plotting capabilities.

*   **v1, v2:** Pure C++ (STL containers: map, multimap).
*   **v3, v4:** Qt-based GUI, featuring custom dialog windows, data sorting, and visualization with QCustomPlot library (v4).

## 📄 License

This project is open-source and available under the **MIT License**. See the [LICENSE](LICENSE) file for details.