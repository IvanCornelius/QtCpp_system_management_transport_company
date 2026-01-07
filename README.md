# Transport Company Management System (TCMS)

**English** | [Русский](README.ru.md)

A console and later GUI application for managing a fleet of vehicles, developed as part of a freelance project. The system allows tracking vehicle specifications, maintenance, and repairs.

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
3.  Removing written-off vehicles from the system.
4.  Output of the complete list of all vehicles.
5.  Output of a list of vehicles with a remaining resource less than a specified value.
6.  Output of a list of vehicles of a specified type.

## 🚀 Releases & Features by Version

Ready-to-use executables (`.exe`) are available in the [`/releases`](/releases) folder for each version.

| Version | Interface | Key Features | Download |
| :--- | :--- | :--- | :--- |
| **v1.0.0** (2022-05-21) | Console | Basic functionality for data management. | [v1.0.0](/releases/v1.0.0) |
| **v2.0.0** (2022-11-24) | Console | Output of a list sorted by registration year. Switched from `vector` to `map`/`multimap` containers. | [v2.0.0](/releases/v2.0.0) |
| **v3.0.0** (2022-12-10) | **Graphical (Qt)** | GUI, open/save database via dialog, extended sorting options. Database file extension changed to `.transp`. | [v3.0.0](/releases/v3.0.0) |
| **v4.0.0** (2022-12-15) | Graphical (Qt) | Added a dialog with a plot chart for vehicle remaining mileage. | [v4.0.0](/releases/v4.0.0) |

> **Note on Encoding:** Source code for v1.0.0 and v2.0.0 uses `windows-1251 / CP 1251` encoding.

## 🔧 For Developers (Source Code)

The complete C++/Qt source code for each iteration is available in the [`/src`](/src) directory.

*   **v1.0.0, v2.0.0:** Pure C++ (STL containers: map, multimap).
*   **v3.0.0, v4.0.0:** Qt-based GUI, featuring custom dialog windows, data sorting, and visualization with QCustomPlot library (v4.0.0).

## 📄 License

This project is open-source and available under the **MIT License**. See the [LICENSE](LICENSE) file for details.
