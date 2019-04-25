<!DOCTYPE html>
<html>
	<head>
		<title>Sum of first n odd numbers</title>
		<link rel="stylesheet" href="body.css" type="text/css">
		
		<script>
			<?php
				$answer="";
				$error="";
				$valid=true;
				if(isset($_POST['s']))
				{
					if(empty($_POST['s']))
					{
						$error="Enter a value";
						$valid=false;
					}
					elseif(!is_numeric($_POST['s']))
					{
						$error="Enter a number";
						$valid=false;
					}
					else
					{		
						$n=$_POST['s'];
						$answer = "<b>Sum of first $n odd numbers is </b>".$n**2;
					}
				}
			?>		
		</script>
	</head>
	
	<body>
		<div style="background-color:green; color:white;">
			<h1>Program to calculate sum of first n odd numbers</h1>
		</div>
				
		<div>
			<form method="post">
				Enter string: <input type="text" name="s">
				<span style="color:red">
					<?php
						if(!$valid)
							echo $error;
					?>
				</span>
				<input type="submit" value="Calculate">
			</form>
		</div>
		
		<div>
			<?php
				if($valid)
					echo $answer;
			?>
		</div>
	</body>
</html>