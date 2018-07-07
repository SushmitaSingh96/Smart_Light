# Smart_Light
Create a smart light using a Node_MCU dev kit: 
NodeMCU 1.0(ESP-12E Module) consists of only one ADC(analog to digital converter) pin which is the A0 pin. We connect the LDR sensor to A0 pin and LED to any GPIO pin. According to the value read by the LDR sensor we can manually set the value beyond which it will be considered as dark and the LED is turned ON accordingly. The connections are as shown in the image. We used a bread board, male to female and male to male jumper wires to set up the connection.
We upload a client program to the NodeMCU using USB which sends data (ie LDR value) to our server using the ESP8266 station. We used an Apache HTTP server. 
Send the data to the database using PHP.
Run the PHP file in  the location /var/www/html and create your databse in MariaDB or MySql. 
