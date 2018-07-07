<?php
    //to show errors
    /*error_reporting(E_ALL);
    init_set('display_errors',TRUE);
    init_set('display_startup_errors',TRUE);*/
	//Creates new record as per request
    	//Connect to database
	$servername = "YOUR_SERVER_NAME";
    	$username = "YOUR_USER_NAME";
    	$password = "YOUR_PASSWORD";
    	$dbname = "YOUR_DATABASE_NAME";
	
    	// Create connection
    	$conn = new mysqli($servername,$username,$password,$dbname);
    	// Check connection
    	if (mysqli_connect_errno($conn)) 
	{
        	echo "connection failed" . mysqli_connect_error();
		exit();
    	}
	
    	//Get current date and time
    	date_default_timezone_set("Asia/Kolkata");
	//Here we enter 20 values into the databse
	for($i=0;$i<20;$i++)
	{
    		$d = date("Y-m-d");
    		$t = date("H:i:s");
    		if(!empty($_GET['ldrStatus']))
    		{
        		$status = $_GET['ldrStatus'];
        		if($status>400)
            			$string="Status ON";
        		else
            			$string="Status OFF";
			$string="'".$string."'";
        		$sql = "INSERT INTO Sensor_Data VALUES('".$d."', '".$t."', $status,$string)";
			echo $sql;
	
        		if(mysqli_query($conn,$sql)==TRUE)
			{
				echo "data sent";
			}
			else
			{
				echo "error".mysqli_error($conn);
			}
    		}
		else
		{		
			echo "Something went wrong";
		}
	}
	mysqli_close($connect);
}
