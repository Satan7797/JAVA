<html>

<head>
    <link rel="stylesheet" href="body.css" type="text/css">
    <script>
        <?php
		$valid=false;
		$answer="";
		$error1="";
		if(isset($_POST['sub']))
		{
            $valid=true;
			if(empty($_POST['val1']))
			{
				$error1="Enter a date";
				$valid=false;
			}
		}
		?>

    </script>
</head>

<body>
    <div style="color:white;background:green;">
        <h1>Birthday Countdown</h1>
    </div>
    <div>
        <form method="POST">
            Enter Birthday Date : <input type="text" placeholder="(yyyy-dd-mm)" name="val1">
            <span style="color:red;">
                <?php 
		          echo $error1;
		      ?>
            </span>
            <br><br>
            <br><br>
            <input type="submit" name="sub">
        </form>
    </div>
    <div>
    <?php
	if($valid==true)
	{
		$d=$_POST['val1'];	
		$bday = date_create($d);
        date_default_timezone_set("Asia/kolkata");
        $diff=date_diff(date_create(),$bday);
        echo $diff->format("%R%a days");
	}
	?>
    </div>
</body>

</html>
