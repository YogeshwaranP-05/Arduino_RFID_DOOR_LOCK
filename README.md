# [RFID Door Lock System Using Arduino](https://www.circuitdigest.com/microcontroller-projects/how-to-make-an-rfid-door-lock-system-using-arduino)

Welcome to the RFID Door Lock System project repository\! This project demonstrates how to build a secure and efficient door locking system using an Arduino and an RFID module. With this system, you can control access using RFID cards, ensuring only authorized users can unlock the door.

# 📦 Project Overview

This RFID Door Lock System integrates an RFID reader with an Arduino microcontroller to create a smart access control mechanism. When an authorized RFID tag is scanned, the system unlocks the door, ensuring security. This project is ideal for home automation, office security, and educational purposes.

# 🛠 Components Required

* Arduino Uno: The microcontroller used to process RFID data.  
    
* RFID Reader (MFRC522): Reads RFID tags to verify access.  
    
* RFID Tags/Cards: Used to authenticate users.  
    
* Solenoid Door Lock: Controls the locking mechanism.  
    
* Jumper Wires: For making connections.  
    
* Breadboard: For prototyping.

* 12V DC Power Supply.

# 📋 Schematic Diagram

You can find the schematic diagram of the circuit [here](https://circuitdigest.com/microcontroller-projects/how-to-make-an-rfid-door-lock-system-using-arduino#:~:text=Door%20Lock%20System.-,RFID%20Door%20Lock%20System%20using%20Arduino%20Circuit%20Diagram,-The%20below%20RFID) as well as in my repo.

## 

# 📂 Project Structure

**/code:** Contains the Arduino sketch **RFID\_DOOR\_LOCK\_UID\_SCAN.ino** to know the UID of authorized Tag and **RFID\_DOOR\_LOCK.ino** to operate the door lock system.

**/docs:** Documentation files, including setup instructions and diagrams. For more details check our official website for complete documentation of [Arduino RFID Door Lock System](https://circuitdigest.com/microcontroller-projects/how-to-make-an-rfid-door-lock-system-using-arduino).

**/images:** Complete Project images and circuit schematics can be found in our official website [Circuit Digest](https://circuitdigest.com/microcontroller-projects/how-to-make-an-rfid-door-lock-system-using-arduino#:~:text=or%20Access%20Denied.-,Components%20Required,-To%20build%20an).

# ⚙️ Installation and Setup

**Clone the Repository:**

* git clone [https://github.com/YogeshwaranP-05/Arduino\_RFID\_DOOR\_LOCK.git](https://github.com/YogeshwaranP-05/Arduino_RFID_DOOR_LOCK.git)  
    
* cd RFID-Door-Lock-System

**Connect Components:**

Refer to the schematic diagram for wiring the RFID reader, Solenoid Door Lock, and other components to the Arduino board.

**Upload the Code:**

* Open RFID\_DOOR\_LOCK.ino in the Arduino IDE.  
    
* Select the appropriate board and port.  
    
* Upload the sketch to your Arduino.

**Power Up:**

Once connected to power, the system is ready to function.

# 📜 Code Explanation

**RFID Reading:** The system reads the RFID tag and checks it against a stored list of authorized users.

**Access Control:** If the tag is authorized, the door unlocks; otherwise, an alert is triggered.

# 🤝 Contributing

Contributions are welcome\! Feel free to fork this repository, make improvements, and submit a pull request.

# 📧 Contact

For any questions or issues, visit our [documentation](https://www.circuitdigest.com/microcontroller-projects/how-to-make-an-rfid-door-lock-system-using-arduino) in our official website [https://www.circuitdigest.com](https://www.circuitdigest.com)

**Happy Building\! 🚀**

