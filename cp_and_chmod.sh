# This bash file puts led.cgi into the cgi-bin directory and changes the
# permission of the file to set uid (+s).

#!/bin/bash
echo " "
echo "Copying led.cgi to /usr/lib/cgi-bin/ directory: "
sudo cp ~/Final/Problem1/led.cgi /usr/lib/cgi-bin/
echo "Changing permissions to led.cgi: "
sudo chmod +s /usr/lib/cgi-bin/led.cgi
echo " "
