# 🚗 Parking Management System

## 📋 About the Project

The **Parking Management System** is a robust, console-based C++ application designed to streamline parking operations in a parking lot. This project efficiently handles vehicle entries, exits, and records total parking fees collected. It uses a linked list data structure to dynamically manage parking slots and vehicles, ensuring an intuitive and easy-to-use solution for small-scale parking lots.

Whether it's keeping track of vehicles currently parked or calculating parking charges based on entry and exit times, the system ensures that all operations are handled smoothly. Ideal for use in environments such as university parking lots, the system offers a simple yet effective solution to manage vehicle flow.

## ✨ Features

- **Vehicle Entry**: Record vehicle details such as registration number, driver name, make, model, and colour upon entry.
- **Vehicle Exit**: Calculate parking fees based on the time spent in the lot and update records by removing the exited vehicle.
- **Total Parking Fee**: Keep track of the total fees collected for all vehicles that have exited the parking lot.
- **Parking Statistics**: Display the registration numbers of all vehicles currently parked in the lot.

## ⚙️ How It Works

1. **Vehicle Entry**: When a vehicle enters, the system records its details and marks the entry time. The data is stored in a linked list, making it easy to track and manage multiple vehicles dynamically.
2. **Vehicle Exit**: Upon exit, the system calculates the parking fee based on the time difference between entry and exit. If the parking duration is less than a minute, the charge is 50 Rupees; otherwise, it's 70 Rupees.
3. **Fee Collection**: Every time a vehicle exits, the fee is added to the total collected amount.
4. **Parking Overview**: The system provides a live update of all vehicles currently parked.



<h2>🎯 Goal</h2>
<p>
  This project aims to create a simple yet efficient parking management solution for smaller parking lots, 
  such as those at universities or office complexes. The system is designed to be easy to use while maintaining 
  accuracy in billing and record management.
</p>
